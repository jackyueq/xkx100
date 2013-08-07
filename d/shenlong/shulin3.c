// /d/shenlong/shulin3.c
// Last Modified by winder on Jul. 12 2002

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "С����");
	set("long", @LONG
�����һƬС���֣������м���һС��յء��յ��ϳ��˿���
���⻹����һЩ��ͬ��С��ʯ�飬��Щʯ����涼�ȽϹ⻬�ƺ���
������Ϊ����һ̧ͷ���ֿյ����ܵ������϶�û����Ƥ��
LONG );

	set("exits", ([
		"southeast" : __DIR__"luanshi",
	]));
	set("outdoors", "shenlong");
	set("no_clean_up", 0);
	setup();
}

void init()
{
	add_action("do_kick", "kick");
	add_action("do_kick", "ti");
	add_action("do_pick", "take");
	add_action("do_pick", "pick");
}

int do_pick(string arg)
{
	object me = this_player();

	if( !arg || !(arg == "shikuai" || arg == "shitou") )
		return notify_fail("ʲô��\n");

	if( me->query_temp("sg/leg") > 1 )
		return notify_fail("�����ϰ�����ô��ʯ�顣\n");

	me->add("qi", (int)200 / (1 + me->query_str()));
	if( random(me->query_temp("sg/shikuai")) < 3 )
	{
		message_vision("$N����һ��ʯͷ�����˵������ҡ��ҡͷ�������ڵ��ϡ�\n", me);
		me->add_temp("sg/shikuai", 1);
		return 1;
	}
	me->delete_temp("sg/shikuai");
	if( !me->query_temp("sg/leg") )
	{
		message_vision("$N����һ��ʯͷ�����˵��������������������ϡ�\n", me);
		me->add_temp("sg/leg", 1);
		me->add_temp("apply/dodge", -10);
		return 1;
	}
	if( me->query_temp("sg/leg") > 0 )
	{
		message_vision("$N����һ��ʯͷ�����˵��������������������ϡ�\n", me);
		me->add_temp("apply/dodge", -10);
		me->add_temp("sg/leg", 1);
	}
	return 1;
}

int do_kick(string arg)
{
	object me = this_player();

	if( !arg || !(arg == "tree" || arg == "shu") )
		return notify_fail("ʲô��\n");

	message_vision("$N�ڿն���˫��������Χ���ɡ�\n", me);

	me->receive_damage("jing", 15, "�����ʴ�����");
	me->receive_damage("qi", 25, "��������");
//	me->improve_skill("kick", random(me->query_int()));

	if( me->query_temp("sg/leg") == 2 )
	{
		me->receive_damage("jing", 10, "�����ʴ�����");
		me->receive_damage("qi", 20, "��������");
		me->improve_skill("dodge", random(me->query_int()));
		return 1;
	}
	if( me->query_temp("sg/leg") == 1 )
	{
		me->receive_damage("jing", 8, "�����ʴ�����");
		me->receive_damage("qi", 16, "��������");
		me->improve_skill("dodge", random(me->query_int() / 2));
		return 1;
	}
	me->improve_skill("dodge", random(me->query_int() / 5));
	return 1;
}

int valid_leave(object me, string dir)
{
	if( me->query_temp("sg/leg") )
	{
		me->add_temp("apply/dodge", me->query_temp("sg/leg") * 10 );
		message_vision("$N���˰󣬽����ϵ�ʯ������һ�ߡ�\n", me);
		me->delete_temp("sg/leg");
		me->start_busy(1);
	}

	return ::valid_leave(me, dir);
}




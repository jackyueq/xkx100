// Room: /d/baituo/yuanzi5.c
// Last Modified by winder on May. 15 2001

#include <ansi.h>;
inherit ROOM;
void create()
{
	set("short", "Ժ��");
	set("long", @LONG
����ѷ����ϰٶѵ�ʯͷ����Щʯͷ�д���С������һ�䷿�ݣ�С��
һ��Ѽ������״���졣�㷢�ּ�����ʯ(stone)Χ��һȦ����֪������Щ
ʲô�Ź֡�
LONG);
	set("exits", ([
		"southwest" : __DIR__"yuanzi4",
		"southeast" : __DIR__"yuanzi3",
	]));
	set("item_desc", ([
		"stone": "\n���ʯͷ����Щ��������ſ����ɴ�����ȥ��\n",
	]));
	set("no_clean_up", 0);
	set("coor/x", -49910);
	set("coor/y", 20090);
	set("coor/z", 30);
	set("outdoors", "baituo");
	setup(); 
}

void init()
{
	object me = this_player();
	if(me->query_skill("poison", 1) < 50)
	me->apply_condition("snake_poison", me->query_condition("snake_poison") + 5);
	add_action("do_climb", "climb");
	add_action("do_climb", "pa");
	add_action("do_yun", "yun");
}

int do_climb(string arg)
{
	object me;
	me = this_player();
	if( !arg || arg=="" ) return 0;
	if (arg == "stone" )
	{
		message_vision("$N�ֽŲ��ã�˳�Ű���������ȥ��\n", me);
		message("vision", me->name() + "����һ�ݣ��Ѿ�������ʯ�ѡ�\n", environment(me), ({me}) );
		me->move(__DIR__"shidui");
		message("vision", me->name() + "���������˽�����\n", environment(me), ({me}) );
		return 1;
	}
}

int do_yun(string arg)
{
	object me;
	me = this_player();
	if( !arg || arg=="" ) return 0;
	if (arg == "hamagong" )
	{
		if(!me->query_temp("baituo_book"))
			return notify_fail("��ط���ʲô����\n");
		if(!me->query_skill("hamagong", 1))
			return notify_fail("ʲô��\n");
		message_vision(HIC "$N�׵�����Ǳ�˹�����ͻȻ���죺���ɣ�����������\n"NOR,me);
		tell_object(me,HIB "���Ȼ�о���������ϸ΢�ĸ������Ӿ�ʯ���ﴫ����\n" NOR );
		me->set_temp("baituo_yun", 1);
		return 1;
	}
}

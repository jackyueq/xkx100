// Room: /heizhao/shanlu5.c
// Date: Dec. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>;
void create()
{
	set("short", "����");
	set("long", @LONG
����Ӵ��һ�������˫�����������У�ֱû���ᣬ�㼱æ����
��Ծ��Ӳ��������ֻ�Ű��˳�����һ������ĳ�ζ���Ǵ̱ǡ���ǰ
��ȥ����ǰһ��ãã�����������é�� (house)���ƹ���é����
�����
LONG );
	set("outdoors", "heizhao");
	set("no_clean_up", 0);
	set("item_desc", ([
		"house" : "é��һ��һԲ�������������֮�У������޴���š�����
��ֻ������ȥ�ˡ�\n",
	]));
	set("exits", ([
		"southwest"  : __DIR__"shanlu4",
	]));
	set("coor/x", -5100);
	set("coor/y", -1500);
	set("coor/z", -5);
	setup();
}

void init()
{
        add_action("do_jump", "jump");
}

int do_jump(string arg)
{
	object me=this_player();

	if( me->is_busy() )
		return notify_fail("����һ��������û����ɣ�\n");

	if( !arg || (arg != "left" && arg != "right"))
		return notify_fail("��Ҫ��������������������\n");
	message_vision(HIY "$N����������߸�Ծ��Ծǽ������\n"NOR,me);

	if (random(me->query_skill("dodge",1)) < 60)
	{
message_vision(HIR"���ֻ��һ���ƺߣ�$N��ûԾ��ǽͷ�͵�����������...\n"NOR,me);
message_vision(HIB"�������һֻŮ�˵��֣�����$N�����죬һ�׾��׳�����ȥ�ˡ�\n"NOR,me);
		me->receive_damage("qi", 100);
		me->start_busy(random(50));
		me->move(__DIR__"shanlu1");
		return 1;
	}
	if (arg == "right")
	{
message_vision(HIC"ֻ��һ�����죬����˧���ˣ�$N������ˮ���\n"NOR,me);
message_vision(HIB"�������һֻŮ�˵��֣�����$N�����죬һ�׾��׳�����ȥ�ˡ�\n"NOR,me);
		me->receive_wound("qi", 200);
		me->receive_damage("qi", 200);
		me->start_busy(random(20));
		me->move(__DIR__"shanlu1");
		return 1;
	}
message_vision(HIY"$NԽ����ǽ������Ժ������ʵ���ϡ�\n"NOR,me);
	me->move(__DIR__"hzyuanzi");
	return 1;
}
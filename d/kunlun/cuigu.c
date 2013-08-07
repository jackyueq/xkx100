// Room: /d/kunlun/cuigu.c
// Last Modified by winder on Jun. 29 2001

#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", HIG"���"NOR);
	set("long", @LONG
���ö�������ǰ���Ǹ����Ž��صĴ�ȣ��컨������������ӳ����
��̤����������ϸ�ݣ������ŵ��������Ļ��㣬���ݼ�أ��ʹ���֦��
����õ����������Ķ�Ѩ֮�󣬾���������һ�����츣�أ��������
�ߴ���һɽ��(dong)��
LONG );
	set("outdoors", "hongmei");
	set("exits", ([
		"west"    : __DIR__"pubu",
		"south"   : __DIR__"xianjing",
		"eastup"  : __DIR__"shanbi",
	]));
	set("item_desc", ([
		"dong": "һ����֪��ǳ��ɽ����\n",
	]));
	set("objects", ([
		__DIR__"npc/sheep" : 2,
	]));
	set("coor/x", -100000);
	set("coor/y", 20050);
	set("coor/z", 40);
	setup();
}
void init()
{
	add_action("do_enter","enter");
}
int do_enter(string arg)
{
	object me = this_player();
	int n = me->query("str");
	if( !arg || arg != "dong")
	{
		write("�����ʲôѽ?\n");
		return 1;
	}
	message_vision("$N������һ�������������Ŷ�����������\n", me);
	me->move(__DIR__"pingtai");
	return 1;
}

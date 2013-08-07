// Room: /d/lingxiao/meiroad3.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
#include <ansi.h> 
void init();
int pick(string);
void create()
{
	set("short","÷��");
	set("long",@LONG
������������÷��վ������ƺ�����������������Զ�����ܿ���
�Ĵ���һ����һ��΢�紵��������÷�ĺ����е���һ��������ͬʱ����
�ɽ�����Ƣ�����㣬�͵�ÿ���˵����С����߾��������ǵĹ۾�ʤ��Ϸ
÷ͤ�ˡ�
LONG);
	set("outdoors", "lingxiao");
	set("exits",([ /* sizeof() == 1 */
		"west"  : __DIR__"meiroad1",
		"east"  : __DIR__"ting",
	]));
	set("objects", ([ 
		__DIR__"obj/ban" : 1,
	])); 
	set("coor/x", -30990);
	set("coor/y", -8890);
	set("coor/z", 140);
	setup();
}

void init()
{
	add_action("do_pick","pick");
}
int do_pick(string arg)
{
	object ob, me = this_player();

	if (!arg || arg!="hua" && arg!="flower")
		return notify_fail("��Ҫժʲô��\n");
	ob=new(__DIR__"obj/mei");
	ob->move(me);
	message_vision("$N��·�Ե�����ժ��һ��"+ob->query("name")+"��\n"NOR,me);
	return 1;
}


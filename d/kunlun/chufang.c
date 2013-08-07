// Room: /d/kunlun/chufang.c
// Last Modified by winder on Nov. 14 2000

#include <ansi.h>
inherit ROOM;

void init();
int do_tap(string arg);
int do_sit(string arg);
void delete_served(object me);

void create()
{
	set("short", "����");
	set("long", @LONG
���������ص����ò͵ĵط��������쳤�վã�ǽ�ڶ�����Ѭ���ˡ�
������ż������Σ���λ���ص������ڴ�Դ�ȣ��оƲ�ȭ��
LONG );
	set("exits", ([
		"east" : __DIR__"jiuqulang7",
	]));
	set("objects",([
		__DIR__"npc/puren" : 1,
		__DIR__"obj/rice" : 2,
		__DIR__"obj/baozi" : 2,
		__DIR__"obj/xiangcha" : 1,
		__DIR__"obj/kaoya" : 1,
	]));
	set("no_fight", 1);
	set("coor/x", -120010);
	set("coor/y", 40100);
	set("coor/z", 90);
	setup();
}

void init()
{
	add_action("do_tap", "tap");
	add_action("do_tap", "knock");
	add_action("do_sit", "sit");
}

int do_tap(string arg)
{

	object me;
	object cui;

	if (!arg || (arg != "desk" && arg != "table"))
	{
		return notify_fail("��Ҫ��ʲô��\n");
	}

	me = this_player();
	if( !objectp(cui = present("pu ren", environment(me))) )
		return notify_fail("�����������ӣ�ȴ����û�����㡣��ͻȻ�о��Լ������ġ�\n");

	if( !me->query_temp("marks/sit") )
		return notify_fail("�����������ӣ�ȴû�뵽�ж������˴���������������Ȼ�ؿ����㣬"
			+"\n��ͻȻ�о��Լ����޴���\n");

	 if( me->query_temp("marks/served") )
	 {
		  message_vision("���˲��ͷ��ض�$N˵�����ո����Ϲ�������ž�Ҫ��"+
				"�㲻�ۿ����۰���\n", me);
		  return notify_fail("");
	 }

	message_vision("$N��������ǰ��������������棬������æ�����к���\n", me);

	cui->serve_tea(me) ;

	 me->set_temp("marks/served", 1);
//  remove_call_out("delete_served");
	 call_out("delete_served", 10, me);

	return 1;
}


void delete_served(object me)
{
	if ( objectp(me) ) me->delete_temp("marks/served");
}


int do_sit(string arg)
{

	if ( !arg || (arg != "chair") )
		return notify_fail("��Ҫ��ʲô���棿\n");

	if (this_player()->query_temp("marks/sit"))
		return notify_fail("���Ѿ����˸���λ�ˡ�\n");

	this_player()->set_temp("marks/sit", 1);
	return notify_fail("�����˸���λ���£������ϲ衣\n");
}


int valid_leave(object me, string dir)
{

        if ( (dir == "west" || dir == "northwest" )
		&& ( present("xiang cha", this_player())
                || present("ci wan", this_player())
		|| present("kaoya", this_player()) 
		|| present("rice", this_player()) )
		&& objectp(present("pu ren", environment(me))) )
	switch ( random(2) )
	{
	case 0:
		message_vision("����������ס��$N�������ȰѶ������������߰ɡ�",me);
		return notify_fail("\n");
		break;
	case 1:
		message_vision("������ס$N���������ŷԸ�����ʳ���ô����跿��",me);
		return notify_fail("\n");
		break;
	}

	me->delete_temp("marks/sit");
	me->delete_temp("tea_cup");
	return ::valid_leave(me, dir);
}
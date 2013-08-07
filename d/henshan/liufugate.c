// liufugate.c
// Date: Nov.1997 by Venus

#include <room.h>
#include <ansi.h>
inherit ROOM;
int do_knock(string arg);

void create()
{
	set("short", "��������");
	set("long", @LONG
�������������š����������ˣ����Ǻ�ɽ���еĽ�����������Ī��
�����ĵڶ�����������������ү�ӡ����������������°ɣ�����(gate)
���գ��ܼҼҶ�Ҳ�������š�ֻ�����µ�д�� "����" ���ֵĴ�����
�е��������ζ����Գ����������
LONG);
	set("exits", ([
	    "south"  : __DIR__"hengyang1",
	]));
	set("item_desc", ([
	   "gate" : "���Ĵ��Ž����ţ�����(knock)���ɡ�\n"
	]));
	set("objects", ([
	        CLASS_D("henshan")+"/mi":1,
		CLASS_D("henshan")+"/xiang":1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", -400);
	set("coor/y", -1190);
	set("coor/z", 0);
	setup();
}
void init()
{
	add_action("do_knock", "knock");
	add_action("do_push", "push");
	add_action("do_push", "open");
}

int do_knock(string arg)
{
	object me;

	me = this_player();
message_vision("$N���ˣ��ˣ��ˣ����������������ţ�������ȴһ�㶯����û�С�\n", me);
	me->set_temp("marks/liufu",1);
	return 1;
}
int do_push(string arg)
{
    int n;
    object weapon,me=this_player();
    mapping fam;

    if (!me->query_temp("marks")) return notify_fail("�Źص����εģ����д򲻿���\n");
    if ( !arg || arg!="gate" ) return notify_fail("���Ǹ��\n");
    message_vision(HIY "$N�ߵ���ǰ���������һ�ƣ���Ȼ���ƿ��˴��ţ�\n"NOR,me);
    set("exits/enter",__DIR__"liufudayuan");
    remove_call_out("close");
    call_out("close", 5, this_object());
    return 1;
}
void close_out()
{
    if (query("exits/enter")) delete("exits/enter");
}

void close(object room)
{
    message("vision","һ������ѽѽ���죬�������˰Ѵ��Ÿ������ˡ�\n", room);
    room->delete("exits/enter");
}

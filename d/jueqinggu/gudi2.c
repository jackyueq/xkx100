// Room: /d/jueqinggu/gudi2.c
// Last Modified by winder on Feb. 17 2001

#include <ansi.h>;
#include <room.h>;

inherit ROOM;

void create()
{
	set("short", "����ȵ�");
	set("long", @LONG
��ֻ������ҫ�ۣ������˱ǣ����Ǳ�����أ�������������Ŀ��
�ˣ�ֻ��������ݣ�����ͬһ������Ļ�԰��Ȼ��Ӱ�������Ĺ����ˡ�
���־���ϲ�������ˮ����ʮ�������м���é�ݡ�
LONG
	);
	set("exits", ([
		"enter" : __DIR__"maowu",
	]));
	set("no_clean_up", 0);
	set("outdoors","jueqinggu");
	set("coor/x", -530);
	set("coor/y", -330);
	set("coor/z", 0);
	setup();
}
void init()
{
	add_action("do_jump","jump");
}

int do_jump(string arg)
{
	object me;
	me = this_player(); 
	if (arg != "tan di" ) return 0;
	if ( !arg ) return 0;
	if (!living(me)) return 0;

	message_vision("$N������̶���˽�ȥ��\n", me);
	me->move(__DIR__"hantan1");
	tell_room(environment(me), me->name() + "�Ӱ������˽�����\n", ({ me }));
	return 1;
}

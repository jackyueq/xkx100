// Room: /huanghe/caodi2.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "�ݵ�");
	set("long", @LONG
������һƬ������Ĳݵأ�����һ����ɫ��̺�����ڵ��ϡ��ݴ���
����һЩ��֪����С�����к�ġ��Ƶģ������ϵġ������ϡ���Ҷ�ϵ�
¶�����ž�Ө�Ĺ⡣
LONG );
	set("exits", ([
		"east" : __DIR__"caodi1",
		"west" : __DIR__"shulin1",
	]));
	set("objects", ([
		"/d/hangzhou/obj/eluanshi" : 1,
	]));
//	set("no_clean_up", 0);
	set("outdoors", "huanghe");
	set("coor/x", -200);
	set("coor/y", 100);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
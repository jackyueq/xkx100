// Room: /huanghe/caodi1.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "�ݵ�");
	set("long", @LONG
������һƬ������Ĳݵأ�����һ����ɫ��̺�����ڵ��ϡ��ݴ���
����һЩ��֪����С�����к�ġ��Ƶģ������ϵġ������ϡ���Ҷ�ϵ�
¶�����ž�Ө�Ĺ⡣���������ݳǵı��š�
LONG );
	set("exits", ([
		"east" : "/d/city/beimen",
		"west" : __DIR__"caodi2",
	]));
	set("no_clean_up", 0);
	set("outdoors", "huanghe");
	set("coor/x", -100);
	set("coor/y", 100);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
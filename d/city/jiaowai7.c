// Room: /d/city/jiaowai7.c
// Jan. 8.1998 by Venus
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�ݵ�");
	set("long", @LONG
�������ݽ����һƬ���ݵأ���Ӣ�ͷף������裬��¶Ϧ�⣬��
����Ƣ������̤��Զ���ʱ�⡣
LONG );
	set("exits", ([
		"east" : __DIR__"jiaowai6",
		"west" : __DIR__"dongmenqiao",
		"north" : __DIR__"jiaowai8",
	]));
	set("no_clean_up", 0);
	set("outdoors", "yangzhoue");
	set("coor/x", 40);
	set("coor/y", -50);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
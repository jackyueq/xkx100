// /beijing/hai_fang.c
// Last modified by winder 2003.10.10

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "���ι����᷿");
	set("long", @LONG
�����Ǻ��ι���������һ���᷿���������ι����Ŀ��˾�ס��
LONG );
	set("exits", ([
		"east" : __DIR__"hai_dayuan",
	]));

	set("sleep_room", "1");
	set("no_clean_up", 0);
	set("coor/x", -240);
	set("coor/y", 4050);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

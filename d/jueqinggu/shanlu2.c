// Room: /d/jueqinggu/shanlu2.c
// Last Modified by winder on Feb. 17 2001

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
����һ�����͵�ɽ·�����ɽ���Ѷ�ȥ��
LONG
	);

	set("exits", ([
                "westup"    : __DIR__"shanlu3",
                "southdown" : __DIR__"shanlu1",
	]));
	set("no_clean_up", 0);
	set("outdoors","jueqinggu");
	set("coor/x", -530);
	set("coor/y", -340);
	set("coor/z", 30);
	setup();
	replace_program(ROOM); 
}


// Room: /d/jueqinggu/huacong6.c
// Last Modified by winder on Feb. 17 2001

#include <room.h>;
inherit ROOM;
void create()
{
	set("short", "花丛");
	set("long", @LONG
这里是一片花丛，你感到已经很难辨清道路了。
LONG
	);

	set("exits", ([
		"south"     : __DIR__"huacong"+(random(10)+1),
		"east"      : __DIR__"huacong"+(random(10)+1),
		"north"     : __DIR__"huacong5",
		"west"      : __DIR__"huacong"+(random(10)+1),
		"northeast" : __DIR__"huacong"+(random(10)+1),
		"southwest" : __DIR__"huacong7",
	]));

	set("outdoors","jueqinggu");
	set("no_clean_up", 0);
	set("coor/x", -490);
	set("coor/y", -370);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
 

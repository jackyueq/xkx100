// Room: /d/jueqinggu/huacong11.c
// Last Modified by winder on Feb. 17 2001

#include <room.h>
inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
������һƬ���ԣ���е��Ѿ����ѱ����·�ˡ�
LONG
	);

	set("exits", ([
		"south"     : __DIR__"huacong"+(random(10)+1),
		"east"      : __DIR__"huacong"+(random(10)+1),
		"north"     : __DIR__"huacong"+(random(10)+1),
		"west"      : __DIR__"songtang",
		"northeast" : __DIR__"huacong"+(random(10)+1),
		"southwest" : __DIR__"huacong10",
	]));
	set("outdoors","jueqinggu");
	set("no_clean_up", 0);
	set("coor/x", -520);
	set("coor/y", -360);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
 

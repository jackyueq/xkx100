// Room: /d/jueqinggu/huacong1.c
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
		"north" : __DIR__"huacong"+(random(10)+1),
		"south" : __DIR__"huacong2",
		"west"  : __DIR__"huacong"+(random(10)+1),
		"east"  : __DIR__"huacong"+(random(10)+1),
		"out"   : __DIR__"wuxi",
	]));
	set("no_clean_up", 0);
	set("outdoors","jueqinggu");
	set("coor/x", -500);
	set("coor/y", -370);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
 

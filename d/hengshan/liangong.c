// Last Modified by Sir on May. 22 2001
// liangong.c ������

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����Ǻ�ɽ�ɵ��������ķ��䡣�����������ż��������õ�ľ�ˡ�
LONG );

	set("exits", ([
		"south" : __DIR__"byaeast",		
	]));
	
	set("objects", ([
		"/d/shaolin/npc/mu-ren" : 5,
	]));
	set("coor/x", 50);
	set("coor/y", 3220);
	set("coor/z", 100);
	setup();
}


// Room: /d/baihuagu/house1.c
// Last Modified by Winder on Mar. 5 2001

inherit ROOM;
#include <ansi.h>
 void create()
{
	 set("short", HIY"�ܲ�ͨ��"NOR);
	 set("long", 
"���Ǽ�ܼ�ª�����ӣ�����򵥣��ɴ˿ɼ�����ͯ���������
������ݽǱ߿���һ�Ŵ���\n");
	set("sleep_room", "1");
	set("exits", ([
		"east"  : __DIR__"house2",
		"north" : __DIR__"house3",
	]));
	set("objects", ([	   
	]));
	set("no_clean_up", 0);
	set("coor/x", -420);
	set("coor/y", -370);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

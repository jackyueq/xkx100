// Room: /d/jueqinggu/xiufang.c
// Last Modified by winder on Feb. 17 2001

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�巿");
	set("long", @LONG
�����ǹ���������巿�����������������࣬һ����Ů�����ڴ�ǰ
��˼��
LONG
	);

	set("exits", ([
		"north" : __DIR__"huilang2",
	]));
	set("objects", ([
		__DIR__"npc/gongsunlve" : 1,
	]));
	set("coor/x", -560);
	set("coor/y", -390);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
 

// Room: /d/jueqinggu/shufang.c
// Last Modified by winder on Feb. 17 2001

#include <room.h>;
inherit ROOM;

void create()
{
	set("short", "�鷿");
	set("long", @LONG
���ǹ���ֹ���鷿������Ϸ���һЩ�����ؼ���һ����������ܹ�
������
LONG
	);

	set("exits", ([
		"south" : __DIR__"sanqingxuan",
	]));
	set("no_clean_up", 0);
	set("coor/x", -540);
	set("coor/y", -350);
	set("coor/z", 20);
	setup();
	replace_program(ROOM); 
}


// Room: /d/jueqinggu/danfang.c
// Last Modified by winder on Feb. 17 2001

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����Ǿ�������Ƶ�ҩ�ĵط�������������һ�ɴ̱ǵ�ҩζ��
LONG
	);

	set("exits", ([
		"south" : __DIR__"huilang2",
	]));
	set("no_clean_up", 0);
	set("coor/x", -560);
	set("coor/y", -370);
	set("coor/z", 20);
	setup();
	replace_program(ROOM); 
}


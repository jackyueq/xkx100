// /beijing/weifu_zoulang1.c
// Last modified by winder 2003.10.10

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "Τ������");
	set("long", @LONG
����һ��ľ�Ƶ����ȣ�������ǹ⻬����������һ����Ⱦ������Τ
���������ڴ��߶��������Ǹ��޴�Ļ�԰��
LONG );
	set("exits", ([
		"north" : __DIR__"weifu_dayuan",
		"south" : __DIR__"weifu_men",
	]));
	set("objects", ([
		__DIR__"npc/shizhe" : 1,
	]));
	set("outdoors", "beijing");
	set("coor/x", -220);
	set("coor/y", 4100);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

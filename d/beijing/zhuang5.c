#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "ׯ������");
	set("long", @LONG
����һ�������ͨ���������䣬���ߵ�������Ů�����֮��������
����
LONG );
	set("exits", ([
		"east"  : __DIR__"zhuang6",
		"west"  : __DIR__"zhuang7",
		"north" : __DIR__"zhuang8",
		"south" : __DIR__"zhuang4",
	]));
	set("objects", ([
		__DIR__"npc/dizi": 2,
	]));
	set("outdoors", "huabei");
	set("coor/x", 100);
	set("coor/y", 4720);
	set("coor/z", 0);
	setup();
	replace_program(ROOM); 
}

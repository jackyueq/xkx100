#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���������������ȡ��Ĵ��ڳ����ġ�
LONG );
	set("exits", ([
		"north" : __DIR__"zhuang9",
		"south" : __DIR__"zhuang5",
	]));
	set("objects", ([
		__DIR__"npc/dizi": 1,
	]));
	set("outdoors", "huabei");
	set("coor/x", 100);
	set("coor/y", 4730);
	set("coor/z", 0);
	setup();
	replace_program(ROOM); 
}

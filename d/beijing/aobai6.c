// Room: /beijing/aobai6.c

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�����Է�");
	set("long", @LONG
�������ݵ��Է����������ڴ���˯���ˣ����������ش��ź��ࡣ
������һ����(door)��
LONG );
	set("exits", ([
		"east" : __DIR__"aobai4",
		"north" : __DIR__"aobai10",
	]));
	set("item_desc", ([
		"door" : "����һ�ȼ����ľ�š�\n",
	]));
	set("objects", ([
		__DIR__"npc/aobai" : 1,
	]));
	create_door("north", "ľ��", "south", DOOR_CLOSED);
	set("coor/x", -203);
	set("coor/y", 4050);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

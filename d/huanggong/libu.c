// libu.c ����

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
����������֮��--������Ա�򳯵ĳ���.
LONG
	);
	set("exits", ([
		"south" : __DIR__"youmen",
	]));
	set("objects", ([
		__DIR__"npc/suoetu" : 1,
	]));
	set("coor/x", -190);
	set("coor/y", 5210);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
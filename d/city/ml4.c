// Room: /city/milin.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һƬï�ܵ������֣�һ�߽�������·���ʧ�˷���
LONG );
	set("exits", ([
		"east" : __FILE__,
		"west" : __FILE__,
		"south" : __DIR__"dongmen",
		"north" : __DIR__"ml5",
	]));
	set("no_clean_up", 0);
	set("coor/x", 70);
	set("coor/y", 50);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
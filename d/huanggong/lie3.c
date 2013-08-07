// Room: /d/huanggong/lie3.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������Է��һƬ����Ĵ��Գ�, ���紵����, ���вݿ�ӥ�ۼ��ķ�
������.
LONG
	);

	set("outdoors", "huanggong");
	set("exits", ([ /* sizeof() == 4 */
		"west"  : __DIR__"lie2",
		"east"  : __DIR__"lie3",
		"north" : __DIR__"lie3",
		"south" : __DIR__"lie4",
	]));
	set("no_clean_up", 0);

	set("coor/x", -250);
	set("coor/y", 5270);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
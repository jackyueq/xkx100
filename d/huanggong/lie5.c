// Room: /d/huanggong/lie5.c

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
		"north" : __DIR__"lie6",
		"south" : __DIR__"lie5.c",
		"west" : __DIR__"lie5",
		"east" : __DIR__"lie4",
	]));
	set("no_clean_up", 0);

	set("coor/x", -260);
	set("coor/y", 5260);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
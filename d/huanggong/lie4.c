// Room: /d/huanggong/lie4.c

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
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __FILE__,
		"west"  : __DIR__"lie5",
		"south" : __DIR__"lie3",
		"north" : __FILE__,
	]));
	set("coor/x", -250);
	set("coor/y", 5260);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
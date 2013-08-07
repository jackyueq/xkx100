// Room: /d/huanggong/lie1.c

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
		"east"  : __DIR__"dadao",
		"west"  : __FILE__,
		"north" : __DIR__"lie2",
		"south" : __FILE__,
	]));
	set("coor/x", -260);
	set("coor/y", 5260);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
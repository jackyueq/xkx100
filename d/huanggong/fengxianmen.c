// Room: /d/huanggong/fengxianmen.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���ȵ�ͥԺ�Ĵ���.
LONG
	);
	set("outdoors", "huanggong");
	set("exits", ([
		"north"  : __DIR__"fengxiandian",
		"south"  : __DIR__"yuqinggong",
	]));
	set("no_clean_up", 0);
	set("coor/x", -190);
	set("coor/y", 5181);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
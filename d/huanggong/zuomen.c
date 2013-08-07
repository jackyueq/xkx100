// Room: /d/huanggong/zuomen.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����ͨ��������Ա����������. ���з�����Ǳ����̡�������.
LONG
	);
	set("outdoors", "huanggong");
	set("exits", ([
		"east"  : __DIR__"dianwai",
		"west"  : __DIR__"xingbu",
		"north" : __DIR__"bingbu",
		"south" : __DIR__"gongbu",
	]));
        set("no_clean_up", 0);
	set("coor/x", -210);
	set("coor/y", 5200);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
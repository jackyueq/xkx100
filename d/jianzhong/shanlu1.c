// Room: /d/jianzhong/qzroad1.c

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
������һ��ɽ·�ϡ�·�Ե�ɽ����ϡϡ����س��ż�������
LONG
	);

	set("exits", ([
		"west" : "/d/xiangyang/eastgate2",
                "northeast" : __DIR__"shanlu2",
	]));

	set("outdoors", "jianzhong");
	set("coor/x", -430);
	set("coor/y", -500);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
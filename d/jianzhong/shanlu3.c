// Room: /d/jianzhong/qzroad1.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
ɽ·�����ߵ��˾�ͷ��һƬï�ܵ����ֳ����������ǰ��
LONG
	);

	set("exits", ([
		"north" : __DIR__"shulin1",
                "west" : __DIR__"shanlu2",
	]));

	set("outdoors", "jianzhong");
	set("coor/x", -400);
	set("coor/y", -490);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
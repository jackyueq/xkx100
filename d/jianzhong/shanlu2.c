// Room: /d/jianzhong/qzroad1.c

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
������һ��ɽ·�ϡ�·�ߵ���ľ��ï��������ɽ·Խ����խ�ˡ�
LONG
	);

	set("exits", ([
		"east" : __DIR__"shanlu3",
                "southwest" : __DIR__"shanlu1",
                "northwest" : "/d/baihuagu/ent",
	]));

	set("outdoors", "jianzhong");
	set("coor/x", -420);
	set("coor/y", -490);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

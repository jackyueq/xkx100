// /d/taohuacun/road2.c
// Last Modifiedy by Zeratul June 2000

inherit ROOM;

void  create()
{
	set("short","���С·");
	set("long", @LONG
������������ϱ������һ��С·����������������ǰ����·����
������ǰ�������ֲ˵ĵط���
LONG
);
	set("exits", ([
		"north" : __DIR__"road3",
		"south" : __DIR__"road1",
		"east"  : __DIR__"caidi4",
		"west"  : __DIR__"caidi3",
	]));
        set("outdoors", "taohuacun");
	set("coor/x", -90);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
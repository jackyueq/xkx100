// /d/taohuacun/road1.c
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
		"north" : __DIR__"road2",
		"east"  : __DIR__"caidi2",
		"west"  : __DIR__"caidi1",
	]));
        set("outdoors", "taohuacun");
	set("coor/x", -90);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
// /d/taohuacun/road3.c
// Last Modifiedy by Zeratul June 2000

inherit ROOM;

void  create()
{
	set("short","���С·");
	set("long", @LONG
������С·�ľ�ͷ��������Զ���м�ũ�ᣬ��Լ�ɼ������Ĵ�����
��������ȥ��һ��С·��һ������������Ѷ�Զȥ��
LONG
);
	set("exits", ([
		"south" : __DIR__"road2",
		"north" : __DIR__"kitchen",
		"west"  : __DIR__"taohua6",
	]));
        set("outdoors", "taohuacun");
	set("coor/x", -90);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
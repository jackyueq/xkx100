// Room: /d/5lt/mubanlu.c

inherit ROOM;

void create()
{
	set("short", "ľ��·");
	set("long", @LONG
���ǵ���̨�½��̺õ�ľ��·������ȥ��֨��֨���졣
LONG	);
	set("outdoors", "5lt");
	set("exits", ([
		"enter" : __DIR__"dating",
		"south" : __DIR__"xiaodao",
	]));
	set("no_clean_up", 0);
	set("coor/x", -185);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

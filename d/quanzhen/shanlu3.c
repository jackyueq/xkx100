// shanlu3.c ɽ·
// Winder Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
������ɽ·�ľ�ͷ�����������һƬС���֣��۶��򶫣�������
��ɽ��ɽ���ˡ�
LONG
	);
	set("outdoors", "zhongnan");
	set("objects", ([
		CLASS_D("quanzhen")+"/lu" : 1,
	]));
	set("exits", ([
		"northwest" : __DIR__"shanlu1",
		"eastup"    : __DIR__"shanjiao",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3140);
	set("coor/y", -10);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

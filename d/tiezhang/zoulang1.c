// Room: /d/tiezhang/zoulang1.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������һ�������ϡ���������ڴ������������������
LONG );
	set("exits", ([ /* sizeof() == 3 */
		"north" : __DIR__"bqshi",
		"west"  : __DIR__"wztang",
		"east"  : __DIR__"zoulang4",
	]));
	set("no_clean_up", 0);

	set("coor/x", -2030);
	set("coor/y", -1960);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}
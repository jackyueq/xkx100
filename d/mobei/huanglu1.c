// Room: /d/mobei/huanglu1.c
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
���������ӹ�����Ļ�·������Զ���������ϡ�١�
LONG
	);
	set("no_clean_up", 0);
	set("outdoors","mobei");
	set("exits", ([ /* sizeof() == 2 */
		"south"     : "/d/changcheng/juyongguan",
		"northwest" : __DIR__"damo2",
	]));
	set("coor/x", -190);
	set("coor/y", 5100);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

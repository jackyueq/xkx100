// Room: /d/tiezhang/zoulang2.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������һ�������ϣ����ܻ谵һƬ���ž��쳣������������ƺ���
����Ļ�����һ���󴫳���
LONG );
	set("exits", ([ /* sizeof() == 2 */
		"west"  : __DIR__"zoulang3",
		"east"  : __DIR__"wztang",
		"north" : __DIR__"shufang",
	]));
	set("no_clean_up", 0);

	set("coor/x", -2050);
	set("coor/y", -1960);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}

// Room: /d/tiezhang/zoulang3.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������һ�������ϡ����洫�����󷹲˵���ζ��
LONG );
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"chufang",
		"east"  : __DIR__"zoulang2",
	]));
	set("no_clean_up", 0);

	set("coor/x", -2060);
	set("coor/y", -1960);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}
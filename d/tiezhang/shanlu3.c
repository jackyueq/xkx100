// Room: /d/tiezhang/shanlu3.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
������һ����᫵�ɽ·�ϣ�����ɽ����������ݹ������м�һ����
��С·������һ����ǿ��ȥ��
LONG	);
	set("exits", ([ /* sizeof() == 2 */
		"south"   : __DIR__"hhyuan1",
		"northup" : __DIR__"shanlu4",
	]));
	set("no_clean_up", 0);
	set("outdoors", "tiezhang");

	set("coor/x", -2040);
	set("coor/y", -1930);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}
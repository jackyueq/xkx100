// Room: /d/tiezhang/shanlu8.c
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
		"southdown" : __DIR__"dezj",
		"northup"   : __DIR__"shanlu9",
	]));
	set("no_clean_up", 0);
	set("outdoors", "tiezhang");

	set("coor/x", -2040);
	set("coor/y", -1790);
	set("coor/z", 80);
	setup();
	replace_program(ROOM);
}
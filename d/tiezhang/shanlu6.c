// Room: /d/tiezhang/shanlu6.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
������һ����᫵�ɽ·�ϣ�����ɽ����������ݹ������м�һ����
��С·������һ����ǿ��ȥ��
LONG );
	set("exits", ([ /* sizeof() == 2 */
		"southdown" : __DIR__"pingtai",
		"northup"   : __DIR__"shanlu7",
	]));
	set("no_clean_up", 0);
	set("outdoors", "tiezhang");

	set("coor/x", -2040);
	set("coor/y", -1900);
	set("coor/z", 60);
	setup();
	replace_program(ROOM);
}
// Room: /d/tiezhang/shanlu1.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
������һ����᫵�ɽ·�ϣ�����ɽ����������ݹ������м�һ����
��С·������һ����ǿ��ȥ��
LONG	);
	set("outdoors", "tiezhang");
	set("exits", ([ /* sizeof() == 2 */
		"north"     : __DIR__"shanlu2",
		"southdown" : __DIR__"shanmen",
	]));
	set("no_clean_up", 0);

	set("coor/x", -2040);
	set("coor/y", -1990);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
// Room: /d/tiezhang/shanlu2.c
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
		"north" : __DIR__"guangchang",
		"south" : __DIR__"shanlu1",
	]));
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 3 */
		__DIR__"npc/huiyi" : 2,
	]));
	set("outdoors", "tiezhang");

	set("coor/x", -2040);
	set("coor/y", -1980);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
// Room: /d/jiaxing/njroad3.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "����С·");
	set("long", @LONG
һ�����е�С·��·����һ���񷿣�����ܾ�û����ס�����ӡ���
������С·ͨ�򽭱ߡ�
LONG
	);
	set("outdoors","jiaxing");
	set("exits", ([
		"west" : __DIR__"njroad2",
		"east" : __DIR__"njeast",
		"north": __DIR__"yangjia",
		"south": __DIR__"njroad4",
	]) );

	set("no_clean_up", 0);
	set("coor/x", 1580);
	set("coor/y", -1050);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
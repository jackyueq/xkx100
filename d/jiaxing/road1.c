// Room: /d/jiaxing/road1.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
����һ���������·���������������ҵ�é�ݡ�·���ǽ���ˮ�絽
�������Լ�����С�ӡ�Զ���ƺ��������䡣
LONG
	);
	set("no_clean_up", 0);
	set("outdoors","jiaxing");

	set("exits", ([
		"northwest" : __DIR__"road",
		"south"     : __DIR__"road2",
	]) );

	set("coor/x", 1540);
	set("coor/y", -1030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
// Room: /d/jiaxing/road.c
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
		"northwest" : __DIR__"nanhu1",
		"southeast" : __DIR__"road1",
	]) );

	set("coor/x", 1530);
	set("coor/y", -1020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
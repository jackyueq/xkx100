// Room: /d/jiaxing/njwest.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "ţ�Ҵ��");
	set("long", @LONG
����һ��С���������ڡ����Ӻ�С��������һƬ�ž��С��ϱ���
Լ���Կ���һ���󽭡�
LONG
	);
	set("no_clean_up", 0);
	set("outdoors","jiaxing");

	set("exits", ([
		"northwest": __DIR__"road2",
		"east"     : __DIR__"njroad1",
	]) );

	set("coor/x", 1550);
	set("coor/y", -1050);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
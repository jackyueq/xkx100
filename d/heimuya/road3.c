// Room: /d/heimuya/road3.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short", "����·");
	set("long", @LONG
������һ������·�ϡ�������ȥ���������Կ���ƽ���ݡ���������
���ǿ쵽�ˡ�
LONG );
	set("outdoors", "huabei");
	set("exits", ([
		"east" : "/d/beijing/ximenwai",
		"west" : __DIR__"pingdingzhou",
	]));
	set("no_clean_up", 0);
	set("coor/x", -2000);
	set("coor/y", 4040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

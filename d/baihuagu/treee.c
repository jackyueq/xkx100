// Room: /d/baihuagu/treee.c
// Last Modified by Winder on Mar. 5 2001
inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
������һƬ�ڰ�����ɴ��۾���ֻ���ֵ���������������·�ˣ�
LONG);
	set("exits", ([ 
		"west" : __DIR__"tree"
	]));
	set("no_clean_up", 0);
	set("coor/x", -450);
	set("coor/y", -400);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

// Room: /d/quanzhou/yuanhetang.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "Դ����");
	set("long", @LONG
����Զ���������۽������̣���ɫˮ���������ǵļӹ����ζ���أ�
������壬�̶������������ɬ���ֿ��Գ��ڱ��棬Զ�������⡣
LONG );
	set("no_clean_up", 0);
	set("exits", ([
		"east"      : __DIR__"zhaiqu3",
		"northeast" : __DIR__"zhaiqu2",
	]));
	set("coor/x", 1830);
	set("coor/y", -6560);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

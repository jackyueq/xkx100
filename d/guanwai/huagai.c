// /guanwai/huagai.c

inherit ROOM;

void create()
{
	set("short", "���Ƿ�");
	set("long", @LONG
���׶�����߷壬�Թ����������Ƿ���Ƿ�������Ĺʵ���������
����ǡ���ƿ�����һ�㣬������������ˮ���죬һ����������׳���ģ�
�������Ƿ塣
LONG );
	set("exits", ([
		"north"     : __DIR__"tianhuo",
		"westdown"  : __DIR__"tianchi1",
	]));
	set("no_clean_up", 0);
	set("outdoors", "changbai");
	set("coor/x", 6200);
	set("coor/y", 5170);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}
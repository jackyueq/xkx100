// rope.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
һ�����ڲ����е�ϸ������
LONG );
	set("no_clean_up", 0);
	set("coor/x", -3180);
	set("coor/y", -40);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}


// Room: /d/baituo/cave1.c
// Last Modified by winder on May. 15 2001
inherit ROOM;

void create()
{
	set("short","�Ҷ���");
	set("long", @LONG
�������Ҷ��ڲ��������������Ž�׵�����ʯ��
LONG	);
	set("exits",([
		"south" : __DIR__"cave",
	]));
	set("no_clean_up", 0);
	set("coor/x", -50040);
	set("coor/y", 20080);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}



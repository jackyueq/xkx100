// tongmen.c
// Modified by Winder June.25 2000

inherit ROOM;

void create()
{
	set("short", "ͭ��");
	set("long", @LONG
����һ�����ε�ͭ�ţ����Եı������š��Ż����ء��ĸ����֡�
LONG );
	set("exits", ([
		"south" : __DIR__"shiji3",
		"west" : __DIR__"fangjian3",
	]));
	set("no_clean_up", 0);
	set("coor/x", -50000);
	set("coor/y", -21020);
	set("coor/z", -40);
	setup();
	replace_program(ROOM);
}
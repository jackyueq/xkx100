// Room: /d/nanshaolin/xiaolu-3.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "��ʯС·");
	set("long", @LONG
������һ����ʯ�̳ɵ�С·�ϣ������������ɽ�������������мд�
�������ķ��㣬���������������һƬ�ܴ�Ĳ�԰�ӡ�
LONG );
	set("outdoors", "nanshaolin");
	set("no_clean_up", 0);
	set("exits", ([
		"south" : __DIR__"cyzi-1",
		"north" : __DIR__"xiaolu-2",
	]));
	set("coor/x", 1870);
	set("coor/y", -6310);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}


// Room: /d/nanshaolin/xiaolu-2.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "��ʯС·");
	set("long", @LONG
������һ����ʯ�̳ɵ�С·�ϣ������������ɽ��������������
�д��������ķ��㣬���������
LONG );
	set("outdoors", "nanshaolin");
	set("exits", ([
		"south"     : __DIR__"xiaolu-3",
		"northwest" : __DIR__"xiaolu-1",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1870);
	set("coor/y", -6300);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}


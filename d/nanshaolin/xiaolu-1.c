// Room: /d/nanshaolin/xiaolu-1.c
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
	set("no_clean_up", 0);
	set("exits", ([
		"southeast" : __DIR__"xiaolu-2",
		"north"     : __DIR__"chufang2",
	]));
	set("coor/x", 1860);
	set("coor/y", -6290);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}


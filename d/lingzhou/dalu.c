// Room: /lingzhou/dalu1.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "���д�·");
	set("long", @LONG
����ɽ�����·����ǿ����ͨ��һ���󳵣�·��������������ĳ�
��ӡ��·��ɽ����ȫ�ǲ����ľ������ȥ�ܲ�͸�磬������ľ�������
ż��������в��ܴ��Ƽž�����·����������ת�˸��䡣
LONG );
	set("exits", ([
		"south"     : __DIR__"luorilin1",
		"north"     : __DIR__"xiaolu1",
		"northeast" : __DIR__"luorilin2",
	]));
	set("no_clean_up", 0);
	set("outdoors", "lingzhou");
	set("coor/x", -17930);
	set("coor/y", 32090);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
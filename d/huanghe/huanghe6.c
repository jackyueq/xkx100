// Room: /huanghe/huanghe6.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "�ƺӰ���");
	set("long", @LONG
�����ǻƺӰ��ߡ��ƺ����ʵ�����Ӵ���������ɫ�ĺ�ˮ�ھ���
������ȥ��ʹ������������ˮʱ�Ŀ�����
LONG );
	set("exits", ([
		"northeast" : __DIR__"huanghe7",
		"southwest" : __DIR__"huanghe5",
	]));
	set("objects", ([
		__DIR__"npc/zu" : 1,
	]));
	set("outdoors", "huanghe");
	set("coor/x", 300);
	set("coor/y", 800);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
// Room: /huanghe/huanghe5.c
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
		"east"      : "/d/taishan/daizong",
		"northeast" : __DIR__"huanghe6",
		"southwest" : __DIR__"huanghe4",
	]));
	set("no_clean_up", 0);
	set("outdoors", "huanghe");
	set("coor/x", 150);
	set("coor/y", 530);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
// wg_zhangfang.c

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�ʷ�");
	set("long", @LONG
����������ڵ�һ���ʷ�������һ���ʷ���������������������ʡ�
����ڵĴ�С��֧�����������
LONG);
	set("exits", ([
		"east" : __DIR__"wg_shilu-1",
	]));
	set("objects", ([
		__DIR__"npc/wg_fan" : 1,
		__DIR__"npc/wg_huashandizi" : 1,
	]) );
	
	set("coor/x", 31);
	set("coor/y", -50);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}



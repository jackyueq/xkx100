// room: liang.c

#include <room.h>

inherit ROOM;

void create()
{ 
	set("short","���ҷ���");
	set("long", @LONG
�����������ҵķ��������¹��ƣ���Χ����Щ��ľͷ��ש�ߡ�ͻȻ
��������깴���һ�����ġ�
LONG );
	set("exits", ([
		"down" : __DIR__"mishi",
	]));       
	set("objects", ([
		__DIR__"obj/jiasha" : 1,
		"/d/xingxiu/npc/snake" :1,
	]));       
	set("coor/x", 1820);
	set("coor/y", -6312);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

// Room: /d/jueqinggu/maowu.c
// Last Modified by winder on Feb. 17 2001

#include <ansi.h>; 
inherit ROOM;

void create()
{
	set("short", "é��");
	set("long", @LONG
ֻ�����еĳ����ª�����ྻ�쳣������ֻһ��һ����������ޱ�
����Ĺʯ���е�����һģһ����
LONG
	);
	set("exits", ([
		"out" : __DIR__"gudi2",
	]));
	set("objects", ([
		__DIR__"npc/yangguo" : 1,
		__DIR__"npc/longnv" : 1,
	]));
	set("coor/x", -530);
	set("coor/y", -330);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
 

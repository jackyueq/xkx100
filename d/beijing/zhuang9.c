#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "С����");
	set("long", @LONG
����һ��С���䣬���ϵ������򡣷���ֻ��һ��һ��������򵥣�
ȴʮ�ָɾ����������ű��졣
LONG );
	set("exits", ([
		"south" : __DIR__"zhuang8",
	]));
	set("objects", ([
		__DIR__"npc/furen": 1,
		__DIR__"npc/shuanger": 1,
	]));
	set("coor/x", 100);
	set("coor/y", 4740);
	set("coor/z", 0);
	setup();
	replace_program(ROOM); 
}

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", CYN"ʯ��"NOR);
	set("long", CYN @LONG
����һ��������ʯ������Χ���Ǽ�Ӳ��ʯ�ڡ� 
LONG NOR);
	set("exits", ([
		"north" : __DIR__"dong33",
		"south" : __DIR__"dong05",
                	]));
       set("objects", ([
              __DIR__"npc/lev"+(random(9)+1) : 1,
            __DIR__"npc/lev"+(random(9)+1) : 1,
                ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

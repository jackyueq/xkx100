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
		"east" : __DIR__"dong47",
		"west" : __DIR__"dong17",
                	]));
	set("no_clean_up", 0);
        set("objects", ([
              __DIR__"npc/lev"+(random(9)+1) : 1,
             __DIR__"npc/lev"+(random(9)+1) : 1,
                ]));
	setup();
	replace_program(ROOM);
}

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"�Ҷ�"NOR);
	set("long", YEL @LONG
    ��Χ���ǻƺ�ɫ����ʯ���о����Ѿ��ڵ��º���ĵط��ˡ� 
LONG NOR);
	set("exits", ([
		"north" : __DIR__"dong01",
		"south" : __DIR__"dong100",
                	]));
       set("objects", ([
              __DIR__"npc/lev"+(random(9)+1) : 1,
             
                ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

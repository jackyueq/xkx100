
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
		"east" : __DIR__"dong"+(random(17)+4),
		"south" : __DIR__"dong"+(random(12)+4),
                "west" : __DIR__"dong"+(random(7)+4),
                "north" : __DIR__"dong"+(random(2)+4),
	]));
 set("objects", ([
              "/clone/box/gbox" : random(2),
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{        
      set("short", RED"���Ҷ�"NOR);
	set("long", RED @LONG
    �����ҽ�����ɢ�������������˴�����������һЩǰ��
δ���ľ޴������������߶��š� 
LONG NOR);
	set("exits", ([
		"east" : __DIR__"dong25",
		"west" : __DIR__"dong05",
                	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

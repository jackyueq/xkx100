#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
		set("short", WHT"����ʯ��"NOR);
	set("long", WHT @LONG
 �������Ǽ�������ʯ�����ܲ�ͣ����ˮ����¡� 
LONG NOR);
	set("exits", ([
		"east" : __DIR__"dong48",
		"west" : __DIR__"dong49",
                	]));
 set("objects", ([
              "/clone/box/gbox" : random(2),
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

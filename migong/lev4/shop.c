#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
		set("short", BLU"ɽ��"NOR);
	set("long", HIG @LONG
       ������һ����ģ����������ȫ�����ӣ��Ӹ���ҩ�ﵽ
������ʳ��Ӧ�о��У�����Ǯ��...�ٺ٣�����Ҫ����Ǯ��Ҫ?
LONG NOR);
	set("exits", ([
		"west" : __DIR__"dong100",
                               	]));
         set("objects", ([
             __DIR__"npc/hygirl" : 1,
                ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

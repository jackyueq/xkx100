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
		"south" : __DIR__"dong1",
		"up" : "/d/migong/lev14/dong102",
                	]));
                set("no_clean_up", 0);
set("no_npc",1);
	setup();
	replace_program(ROOM);
}

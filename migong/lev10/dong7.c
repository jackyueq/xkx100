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
		"south" : __DIR__"dong69",
		"north" : __DIR__"dong76",
                	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

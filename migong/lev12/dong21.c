#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
		set("short", YEL"�Ҷ�"NOR);
	set("long", YEL @LONG
    ��Χ���ǻƺ�ɫ����ʯ���о����Ѿ��ڵ��º���ĵط���,
����������խ��ʯ���� 
LONG NOR);
	set("exits", ([
		"east" : __DIR__"dong1",
		"west" : __DIR__"dong22",
                "up" : "/d/migong/lev11/dong102",
                "newup" : "/d/migong/12gong/toby1",
                	]));
                set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

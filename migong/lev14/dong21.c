#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
		set("short", RED"���Ҷ�"NOR);
	set("long", RED @LONG
    �����ҽ�����ɢ�������������˴�����������һЩǰ��
δ���ľ޴������������߶���,ǰ���ʯ������һ�����ϵ�ͨ���� 
LONG NOR);
	set("exits", ([
		"east" : __DIR__"dong1",
		"west" : __DIR__"dong22",
                "up" : "/d/migong/lev13/dong102",
                	]));
                set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

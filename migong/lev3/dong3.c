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
		"west" : __DIR__"dong37",
		"east" : __DIR__"dong44",
                	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

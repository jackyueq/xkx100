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
		"south" : __DIR__"dong69",
		"north" : __DIR__"dong76",
                	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

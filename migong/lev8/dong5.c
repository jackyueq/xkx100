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
		"west" : __DIR__"dong53",
		"east" : __DIR__"dong60",
                	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

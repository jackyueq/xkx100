#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
		set("short", BLU"ɽ��"NOR);
	set("long", BLU @LONG
 ��Խ��Խ���Χ��ǽ���ƺ���Щ�����ˡ� 
LONG NOR);
	set("exits", ([
		"north" : __DIR__"dong99",
		"south" : __DIR__"dong10",
                "east" : __DIR__"dong101",
                	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

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
		"north" : __DIR__"dong102",
		"west" : __DIR__"dong100",
                                	]));
         set("objects", ([
               __DIR__"npc/boss" : 1,
                ]));
	set("no_clean_up", 0);
	setup();
	}
int valid_leave(object me, string dir)
{
        me = this_player();
        if ( dir == "north" && objectp(present("bai yuan", environment(me))))
                return notify_fail(HIW"��Գ"NOR"һԾ��ס���ȥ·��\n");

        return ::valid_leave(me, dir);
}

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
		"north" : __DIR__"dong102",
		"west" : __DIR__"dong100",
                                	]));
     set("objects", ([
              __DIR__"npc/lev"+(random(9)+1) : 1,
             __DIR__"npc/lev"+(random(9)+1) : 1,
              __DIR__"npc/boss" : 1,
                ]));
	set("no_clean_up", 0);
	setup();
	
}
int valid_leave(object me, string dir)
{
        me = this_player();
        if ( dir == "north" && objectp(present("sha shou", environment(me))))
                return notify_fail(HIR"ɱ��֮��"NOR"��Ц��������Ȼ�㷢�������������ų�ȥ?\n");
       if ( dir == "west" && objectp(present("sha shou", environment(me))))
                return notify_fail(HIR"ɱ��֮��"NOR"��Ц��������Ȼ�㷢�������������ų�ȥ?��\n");

        return ::valid_leave(me, dir);
}


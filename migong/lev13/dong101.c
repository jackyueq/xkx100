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
		"north" : __DIR__"dong102",
		"west" : __DIR__"dong100",
                                	]));
       set("objects", ([
              __DIR__"npc/lev"+(random(9)+1) : 1,
             __DIR__"npc/lev"+(random(9)+1) : 1,
             __DIR__"npc/lev"+(random(9)+1) : 1,
             __DIR__"npc/boss" : 1,
              "/clone/box/gbox" : random(3),
                            ]));
	set("no_clean_up", 0);
	setup();
	}
int valid_leave(object me, string dir)
{
        me = this_player();
        if ( dir == "north" && objectp(present("huo long", environment(me))))
                return notify_fail(HIR"����"NOR"һԾ��ס���ȥ·��\n");
       if ( dir == "west" && objectp(present("huo long", environment(me))))
                return notify_fail(HIR"����"NOR"һԾ��ס���ȥ·��\n");

        return ::valid_leave(me, dir);
}

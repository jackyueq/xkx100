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
		"out" : __DIR__"dong39",
                	]));
       set("objects", ([
              __DIR__"npc/boss1" : 1,
              "/clone/box/gbox" : 5,  
                             ]));
	set("no_clean_up", 0);
	setup();
	}
int valid_leave(object me, string dir)
{
        me = this_player();
        if ( dir == "out" && objectp(present("nie long", environment(me))))
                return notify_fail(BLU"����"NOR"һԾ��ס���ȥ·��\n");

        return ::valid_leave(me, dir);
}

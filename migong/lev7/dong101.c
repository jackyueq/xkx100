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
		"north" : __DIR__"dong102",
		"west" : __DIR__"dong100",
                                	]));
       set("objects", ([
              __DIR__"npc/boss" : 3,
                            ]));
	set("no_clean_up", 0);
	setup();
	}
int valid_leave(object me, string dir)
{
        me = this_player();
        if ( dir == "north" && objectp(present("pantu", environment(me))))
                return notify_fail(BLU"������ͽ"NOR"˵��������Ȼ���㷢���������ѵ���������߲��ɣ���\n");
        if ( dir == "west" && objectp(present("pantu", environment(me))))
                return notify_fail(BLU"������ͽ"NOR"˵��������Ȼ���㷢���������ѵ���������߲��ɣ���\n");

        return ::valid_leave(me, dir);
}

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
		set("short", RED"��������ͷ"NOR);
	set("long", RED @LONG
    �����Ѿ��Ƕ�Ѩ�ľ�ͷ�ˣ����ܶ��ǹ��̵��ҽ���һ��
��Ȼ����������·���룬����ɢ����������档 
LONG NOR);
	set("exits", ([
		"north" : __DIR__"dong3",
		                	]));
            set("objects", ([
             __DIR__"npc/boss" : 1,
             __DIR__"npc/lev1" : 1,
             __DIR__"npc/lev2" : 1,
             __DIR__"npc/lev3" : 1,
             __DIR__"npc/lev4" : 1,
             __DIR__"npc/lev5" : 1,
             "/clone/box/gbox" : 10,
         ]));
	set("no_clean_up", 1);
	setup();
	replace_program(ROOM);
}

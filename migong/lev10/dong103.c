#include <room.h>
#include <ansi.h>
inherit ROOM;

int do_climb(string arg);
void create()
{
		set("short", YEL"�Ҷ�"NOR);
	set("long", YEL @LONG
    ��Χ���ǻƺ�ɫ����ʯ���о����Ѿ��ڵ��º���ĵط��ˡ�
  �����и�С����(climb)��ȥ�ƺ�����ֱ����� ��
LONG NOR);
	set("exits", ([
		"east" : __DIR__"dong100",
                               	]));
	set("no_clean_up", 0);
	setup();
	}
void init()
{
 add_action("do_climb", "climb");
}
int do_climb(object me)
{
    me= this_player();
    me->move("/d/migong/migong3");
 message_vision(   "$N�ֽŲ��ã�һ�������������˶���\n", this_player());
}

#include <room.h>
#include <ansi.h>
inherit ROOM;

int do_climb(string arg);
void create()
{
		set("short", BLU"ɽ��"NOR);
	set("long", BLU @LONG
 ��Խ��Խ���Χ��ǽ���ƺ���Щ������,�����и�С����
��(climb)��ȥ�ƺ�����ֱ����� ��
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

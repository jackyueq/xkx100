// Room: /d/baihuagu/huagu7.c
// Last Modified by Winder on Mar. 5 2001

#include <ansi.h>;
inherit ROOM;
void create()
{
	set("short", RED"�ٻ���"NOR);
	set("long", 
HIC"��ת�˼����䣬ӭ������ɽ�ڼ������������������𣬵���
ɽ�ڼ䡣��Ϊ������Ȼ�����ϡ�\n"NOR);
	set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"huagu6",
	]));
	set("no_clean_up", 0);
	set("coor/x", -450);
	set("coor/y", -360);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_swear","swear");
	add_action("do_swear","han");
	add_action("do_swear","huhan");
}
int do_swear(string arg)
{
	if( !arg) return 0;
	if( arg == "����ͯ" ) 
	{
		message_vision(HIG "$N��������������ͯ��С���������������������\n"NOR, this_player());
		message_vision(HIY "ֻ��������Ǻǵ�Ц������������������������ˣ���������\n"NOR, this_player() );
		call_out("close_passage", 10);
		set("exits/enter", __DIR__"baihuagu");
		return 1;
	}
	else
	{
		message_vision(HIG"$N�����ߺ�����"+arg+"���������չȻ��������ò�����\n"NOR, this_player());
		return 1;
	}
}

void close_passage()
{
	object room;
	if( !query("exits/enter") ) return;
	delete("exits/enter");
}

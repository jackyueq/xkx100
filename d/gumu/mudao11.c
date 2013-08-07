// mudao11.c Ĺ��
// Java Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIG"Ĺ��"NOR);
	set("long", @LONG
�����ǹ�Ĺ�е�Ĺ���������ܲ�͸�磬����ǽ�ϻ谵�ĵƹ⣬����
��ǿ�ֱ������ǽ�����������ʯ���������ģ��Ӻϵ�������������
�Դ����ҳ�һ˿��϶���ƹ�������ʯ���ϣ���˸�ű����ĵĹ�㡣
    ������һ��ʯ��(door)��
LONG	);
	set("exits", ([
//		"north" : __DIR__"xiaoting",
		"south" : __DIR__"zhengting",
	]));
	set("item_desc", ([
		"door" : "һ�Ⱥ��ص�ʯ�ţ��������ȫû�а��֡������濴�˿��������űߵ�ʯ�����ƺ���ʲô��ť(niu)���Կ��š�\n",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3200);
	set("coor/y", -30);
	set("coor/z", 90);
	setup();
}

void init()
{
	add_action("do_an", "press");
	add_action("do_an", "an");
}

int do_an(string arg)
{
	object room, me = this_player();

	if( !arg || arg != "niu" )
	{
		message_vision("����ʯ�����Ұ�һ��������һ�ֻң�ɶҲû���š�\n", me);
		return 1;
	}
	if( query("exits/north"))
	{
		return notify_fail("ʯ���Ѿ��ǿ��ŵģ��㻹����ɶ��\n");
	}
	if( me->query_skill("yunv-xinfa", 1) > 10)
	{
		message_vision("$Nվ��ʯ��ǰ��Ҳ��֪�����ﰴ��һ�£�ʯ��֨֨���ţ��������ˡ�\n", me);
		if( !(room = find_object(__DIR__"xiaoting")) )
			room = load_object(__DIR__"xiaoting");
		set("exits/north", __DIR__"xiaoting");
		room->set("exits/south", __DIR__"mudao11");
		tell_room(room,"ֻ����ʯ����֨֨���б������򿪡�\n");
		remove_call_out("close");
		call_out("close", 5, me);
	}
	else
		message_vision("$N������ʯ���ϰ�����ȥ������ʯ����˿������ֻ�ð��ˡ�\n", me);
	return 1;
}

void close(object me)
{
	object room;

	tell_room(this_object(), "ʯ�Ż����ع��ϣ��ָ���ԭ״��\n");
	delete("exits/north");
	if( !(room = find_object(__DIR__"xiaoting")) )
		room = load_object(__DIR__"xiaoting");
	room->delete("exits/south");
	tell_room(room,"��ǽ��ʯ�Ż����ع����ˡ�\n");
}

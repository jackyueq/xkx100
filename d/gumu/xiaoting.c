// xiaoting.c С��
// Java Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
������һ��СС�����á����ߵ������Χ�Ĺ�������һЩ���㷢
������ȼ����һЩ�͵ơ�����Ĳ������������ª��һ��һ�ζ���ʰ��
����������������һ��ʯ��(door)��
LONG	);
	set("exits", ([
		"west"  : __DIR__"mudao09",
		"east"  : __DIR__"mudao12",
//		"south" : __DIR__"mudao11",
	]));
	set("item_desc", ([
		"door" : "һ�Ⱥ��ص�ʯ�ţ��������ȫû�а��֡������濴�˿��������űߵ�ʯ�����ƺ���ʲô��ť(niu)���Կ��š�\n",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3200);
	set("coor/y", -20);
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
	if( query("exits/south"))
	{
		return notify_fail("ʯ���Ѿ��ǿ��ŵģ��㻹����ɶ��\n");
	}
	if( me->query_skill("yunv-xinfa", 1) > 10)
	{
		message_vision("$Nվ��ʯ��ǰ��Ҳ��֪�����ﰴ��һ�£�ʯ��֨֨���ţ��������ˡ�\n", me);
		if( !(room = find_object(__DIR__"mudao11")) )
			room = load_object(__DIR__"mudao11");
		set("exits/south", __DIR__"mudao11");
		room->set("exits/north", __DIR__"xiaoting");
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
	delete("exits/south");
	if( !(room = find_object(__DIR__"mudao11")) )
		room = load_object(__DIR__"mudao11");
	room->delete("exits/north");
	tell_room(room,"��ǽ��ʯ�Ż����ع����ˡ�\n");
}

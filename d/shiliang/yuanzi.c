// Feb. 6, 1999 by Winder
inherit ROOM;
void init();
void close_gate();
int do_open(string arg);
int do_close(string arg);
string look_gate();
void create()
{
	set("short", "��Ժ");
	set("long", @LONG
���������լ���ŵ�һ����ͥԺ����������һ���ƽ����
����ʯ����ɼ��ˡ�Ժ�ӵ�����ܴ󣬿��ó���������˼���
�������Ĵ���(gate)�����š�
LONG
	);
	set("no_clean_up", 0);
	set("outdoors","shiliang");
	set("exits", ([ 
            "west" : __DIR__"xixiangfang",
            "east" : __DIR__"dongxiangfang",
            "north" : __DIR__"dating",
	]));
	set("item_desc",([
		"gate"		:	(: look_gate :),
	]));
	set("coor/x", 1610);
	set("coor/y", -1960);
	set("coor/z", 0);
	setup();
}
void init()
{
	add_action("do_open", "open");
	add_action("do_close", "close");
}
void close_gate()
{
	object room;
	if(!( room = find_object(__DIR__"gate")) )
		room = load_object(__DIR__"gate");
	if(objectp(room))
	{
		delete("exits/south");
			message("vision", "��������ǰ�����Ź����ˡ�\n", this_object());
		room->delete("exits/north");
		message("vision", "ƹ��һ�����������˰Ѵ��Ź����ˡ�\n", room);
	}
}
int do_close(string arg)
{
	if (!query("exits/south"))
		return notify_fail("�����Ѿ��ǹ��ŵ��ˡ�\n");
	if (!arg || (arg != "gate" && arg != "south"))
		return notify_fail("��Ҫ��ʲô��\n");
	message_vision("$N���˵�ͷ��\n", this_player());
	remove_call_out("close_gate");
	call_out("close_gate", 2);
	return 1;
}
int do_open(string arg)
{
	object room;
	if (query("exits/south"))
		return notify_fail("�����Ѿ��ǿ����ˡ�\n");
	if (!arg || (arg != "gate" && arg != "south"))
		return notify_fail("��Ҫ��ʲô��\n");
	if(!( room = find_object(__DIR__"gate")) )
		room = load_object(__DIR__"gate");
	if(objectp(room))
	{
		set("exits/south", __DIR__"gate");
		message_vision("$N�����Ѵ��Ŵ��˿�����\n", this_player());
		room->set("exits/north", __FILE__);
		message("vision", "֨��һ�����������˰Ѵ��Ŵ��ˡ�\n", room);
		remove_call_out("close_gate");
		call_out("close_gate", 10);
	}
	return 1;
}
string look_gate()
{
	return "һ���������ߵ����ɼľ��ͭ���š�\n";
}
int valid_leave(object me, string dir)
{
	if ( me->query("id") == "seng bing" &&  dir == "south" ) return 0;
	return ::valid_leave(me, dir);
}
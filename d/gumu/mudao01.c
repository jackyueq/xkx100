// mudao01.c Ĺ��
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
LONG	);
	set("exits", ([
		"north" : __DIR__"mumen",
		"south" : __DIR__"qianting",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3220);
	set("coor/y", 20);
	set("coor/z", 90);
	setup();
}

void init()
{
	add_action("do_move", "move");
	add_action("do_move", "luo");
	add_action("do_move", "tui");
}

int do_move(string arg)
{
	object room, me = this_player();

	if( !arg || arg != "shi" )
	{
		return notify_fail("��Ҫ�ƶ�ʲô��\n");
	}
	if( !query("exits/north"))
	{
		return notify_fail("����ʯ�Ѿ����£��㻹���ƶ�ʲô��\n");
	}
	if((int)me->query_str()>33)
	{
		message_vision("$Nվ�ڽ���ʯǰ��˫�Ʒ����ƶ�����ʯ��ֻ���ý���ʯ֨֨����������������ȥ����ס��Ĺ�š�\n", me);
		delete("exits/north");
		if( !(room = find_object(__DIR__"mumen")) )
			room = load_object(__DIR__"mumen");
		room->delete("exits/south");
		tell_room(room,"ֻ���ý���ʯ֨֨����������������ȥ����ס��Ĺ�š�\n");
	}
	else
		message_vision("$N���������ƾ�ʯ����ʯ��˿������ֻ�ð��ˡ�\n", this_player());
	return 1;
}


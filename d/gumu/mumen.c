// mumen.c Ĺ��
// Java Oct.10 1998

#include <ansi.h>
inherit ROOM;

int do_move(string arg);

void create()
{
	set("short", "Ĺ��");
	set("long", @LONG
���߹��˲ݵأ������Լ��������֮�У��������ɣ�������ˡ�
������Ƭ��С�Ŀ����أ�ͻأ��������һ��һ�˸ߵİ�ɫ����Բڣ��Ĺ
������ʯͷ�Ѿ��ವ�ˣ����ĳ�����������Ĺ��Ĺǰû��������Ҳû��
�κεı�ǡ�Ĺ������ɭɭ�����ֹ�ľ����ƽ��ʮ��������į����ɪ֮
�⡣Ĺ�Ž����ߣ������ǹ�Ĺ�����ڡ�Ĺ�ſڱ�һ�������Ĵ�ʯͷ
(shi)��յ�˿����͸��
    ��Ĺ������������������������ٳ�����Ů��Ľ��������˫���ϱ�
���⽭���ĺ��飬����ǧ��ĥ�Ѻ��ճɾ����������顣��Զǧ������Ͷ
�ݡ�
LONG	);
	set("outdoors", "gumu");
	set("exits", ([
		"east"  : __DIR__"xuanya",
		"west"  : __DIR__"huangshalin",
		"north" : __DIR__"caodi",
		"south" : __DIR__"mudao01",
	]));
	set("objects", ([
		__DIR__"npc/yufeng" : 1+random(3),
	]));
	set("item_desc", ([
		"shi": "���ǿ��ʯ���²���������£��������š�"+YEL"����ʯ"NOR+"�������֡�\n"
	]) );
	set("coor/x", -3220);
	set("coor/y", 30);
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
	if( !query("exits/south"))
	{
		return notify_fail("����ʯ�Ѿ����£��㻹���ƶ�ʲô��\n");
	}
	if((int)me->query_str()>33)
	{
		message_vision("$Nվ�ڽ���ʯǰ��˫�Ʒ����ƶ�����ʯ��ֻ���ý���ʯ֨֨����������������ȥ����ס��Ĺ�š�\n", me);
		delete("exits/south");
		if( !(room = find_object(__DIR__"mudao01")) )
			room = load_object(__DIR__"mudao01");
		room->delete("exits/north");
		tell_room(room,"ֻ���ý���ʯ֨֨����������������ȥ����ס��Ĺ�š�\n");
	}
	else
		message_vision("$N���������ƾ�ʯ����ʯ��˿������ֻ�ð��ˡ�\n", this_player());
	return 1;
}


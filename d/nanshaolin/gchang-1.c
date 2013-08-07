// Room: /d/nanshaolin/gchang-1.c
// Last Modified by Winder on May. 29 2001

#include <ansi.h>
inherit ROOM;
void init();
void close_gate();
int do_close(string arg);
string look_gate();
int do_open(string arg);

void create()
{
	set("short", "�㳡");
	set("long", @LONG
����ɽ�ţ���ǰ����ƽ�е���ʯ̨��ͨ��ǰ����һ���㳡��̨����
�����ο������룬���꣬�ɺ׵����ޣ���̬���涯�ˡ��㳡���з��Ÿ�
���˸ߵ���ͭ����¯��ǰ����Ÿ���̨����λ����������Ӱݡ�����
ǰ����������ϱ߾��������ֵ�ɽ��(gate)�ˡ�
LONG);
	set("item_desc",([
		"gate" : (: look_gate :),
	]));
	set("exits", ([
		"east"  : __DIR__"gchang-3",
		"west"  : __DIR__"gchang-2",
		"north" : __DIR__"qdian",
	]));

	set("outdoors", "nanshaolin");
	set("objects",([
		__DIR__"npc/seng-bing3" : 2,
	]));
	set("coor/x", 1820);
	set("coor/y", -6290);
	set("coor/z", 10);
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

	if(!( room = find_object(__DIR__"shanmen")) )
		room = load_object(__DIR__"shanmen");
	if(objectp(room))
	{
		delete("exits/south");
			message("vision", "ɮ����ǰ�Ѵ��Ź���������\n", this_object());
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

	message_vision("$N��ɮ�����˵�ͷ��\n", this_player());

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
	if(!( room = find_object(__DIR__"shanmen")) )
		room = load_object(__DIR__"shanmen");
	if(objectp(room))
	{
		set("exits/south", __DIR__"shanmen");
		message_vision("$Nʹ���Ѵ��Ŵ��˿�����\n", this_player());
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

// Room: /d/huanggong/mishi.c
#include <room.h>
inherit ROOM;

void close_gate();
int do_open(string arg);
int do_close(string arg);

void create()
{
	set("short", "����");
	set("long", @LONG
���ǿ������ĸ�����ı���µĵط�, Ѱ�����ǽ�������.
LONG
	);

	set("objects", ([
		"/d/beijing/obj/book14_8" : 1,
		__DIR__"obj/feicui" : 1,
	]));

	set("coor/x", -190);
	set("coor/y", 5281);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_open", "open");
	add_action("do_open", "unlock");
}

void close_gate()
{
	object room;

	if(!( room = find_object(__DIR__"yushufang")) )
		room = load_object(__DIR__"yushufang");
	if(objectp(room))
	{
		delete("exits/south");
		message("vision","ֻ��ƹ��һ���������Զ�����������\n", this_object());
		message("vision","���Ժ�������һ����ͷ�����ˣ�����ȥ�ˣ�\n", this_object());
		room->delete("exits/north");
		message("vision","ֻ��ƹ��һ���������Զ�����������\n",room);
		message("vision","���Ժ�������һ����ͷ����Ӵ���ֽ���ȥ�ˣ�\n", room );
	}
}

int do_open(string arg)
{
	object room;

	if (query("exits/south"))
		return notify_fail("�����Ѿ��ǿ����ˡ�\n");

	if (!arg || (arg != "door" && arg != "south"))
		return notify_fail("��Ҫ��ʲô��\n");

	if(!( room = find_object(__DIR__"yushufang")) )
		room = load_object(__DIR__"yushufang");

	if(objectp(room))
	{
		set("exits/south", __DIR__"yushufang");
		message_vision("$Nʹ���Ѱ��Ŵ��˿�����\n",this_player());
		room->set("exits/north", __FILE__);
		message("vision","�������˰Ѱ��Ŵ��ˡ�\n",room);
		remove_call_out("close_gate");
		call_out("close_gate", 10);
	}
	return 1;
}

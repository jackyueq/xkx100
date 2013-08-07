// Room: /d/huanggong/yushufang.c
#include <room.h>
inherit ROOM;

void close_gate();
int do_open(string arg);
void create()
{
	set("short", "���鷿");
	set("long", @LONG
�����ù���������鷿���ֽ����鷿�����鷿��Ҳ�ǻ��ӻ����Ƕ�
��ĵط���������ʥ�����ʵ�����(bian)�������������������(lian)��
�������������ż�����ܣ����濴������Щ����������㰵���룬ԭ��
�ʵ�Ҳ����ô����鰡���鷿�������ž����̴��ľ���������ϰ��ż�
�����澫�����顣
LONG 	);
 	set("item_desc", ([ 
		"bian" : "\n����ع��\n\n",
		"lian" : "
����������Ϊ��
����������Ϊ��\n\n",
 	]));
	set("objects", ([
		__DIR__"npc/kangxi" : 1,
		"/d/beijing/obj/book14_2" : 1,
	]));
	set("exits", ([
		"northwest" : __DIR__"qianqinggong",
	]));

	set("coor/x", -190);
	set("coor/y", 5280);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_open", "open");
}

int close_gate()
{
	object room;

	if(!( room = find_object(__DIR__"mishi")) )
	room = load_object(__DIR__"mishi");
	if(objectp(room))
	{
		delete("exits/north");
		message("vision","ֻ��ƹ��һ���������Զ������ˡ�\n", this_object());
		message("vision","���Ժ�������һ����ͷ����Ӵ���ֽ���ȥ�ˣ�\n", this_object());
		room->delete("exits/south");
		message("vision","ֻ��ƹ��һ���������Զ�����������\n", room);
		message("vision","���Ժ�������һ����ͷ�����ˣ�����ȥ�ˣ�\n", room );
	}
}


int do_open(string arg)
{
	object ob,room;
	if (query("exits/north"))
		return notify_fail("�����Ѿ��Ǵ򿪵ġ�\n");
	if (!arg || (arg != "bian"))
		return notify_fail("��Ҫ��ʲô��\n");
	set("exits/north", __DIR__"mishi");
	if(!( room = find_object(__DIR__"mishi")) )
		room = load_object(__DIR__"mishi");
	if(objectp(room))
	{
		set("exits/north", __DIR__"mishi");
		message_vision("$N��������������ң�ֻ��֨��һ����һ�����ſ��ˡ�\n",this_player());
		room->set("exits/south", __FILE__);
		message("vision","ֻ��֨��һ�������Ŵ�������ˡ�\n", room);
		remove_call_out("close_gate");
		call_out("close_gate", 10);
	}
	return 1;
}

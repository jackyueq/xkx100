// Room: /d/baituo/yuanzi4.c
// Last Modified by winder on May. 15 2001

#include <ansi.h>;
inherit ROOM;
void create()
{
	set("short", "Ժ��");
	set("long", @LONG
����ѷ����ϰٶѵ�ʯͷ����Щʯͷ�д���С������һ�䷿�ݣ�С��
һ��Ѽ������״��඼��Բ���Ρ��㷢�ִ���Щʯͷ֮��ķ�϶(fengxi)
��Ʈ��һ�ɹɵ��ȳ�ζ��ʹ���Ҫ��Ż�ˡ�
LONG);
	set("exits", ([
		"southeast" : __DIR__"yuanzi2",
		"northeast" : __DIR__"yuanzi5",
		"east"      : __DIR__"yuanzi3",
	]));
	set("item_desc", ([
		"fengxi": "\n��϶�������һƬ������ԼԼ��ɳɳ�����졣\n",
	]));
	set("outdoors", "baituo");
	set("no_clean_up", 0);
	set("coor/x", -49920);
	set("coor/y", 20080);
	set("coor/z", 30);
	setup(); 
}

void init()
{
	object me = this_player();
	if(me->query_skill("poison", 1) < 50)
	me->apply_condition("snake_poison", me->query_condition("snake_poison") + 5);
	if(me->query_temp("baituo_stone2"))
	{
		me->delete_temp("baituo_stone2");
		me->set_temp("baituo_wait", 1);
		remove_call_out("do_open");
		call_out("do_open", 30, me);
	}
	add_action("do_enter", "enter");
	add_action("do_enter", "zuan");
}

int do_enter(string arg)
{
	object me;
	me = this_player();

	if( !arg || arg=="" ) return 0;

	if (arg == "fengxi" )
	{
		message_vision("$N�ٿ���϶�ڵ���ʯ�ӡ�\n" NOR, me); 
		message("vision", me->name() + "һ��������϶�����˽�ȥ��\n", environment(me), ({me}) );
		me->move(__DIR__"fengxi2");
		message("vision", me->name() + "���������˽�����\n", environment(me), ({me}) );
		return 1;
	}
}

void do_wait()
{
	object me = this_player();
	if(environment(me) && me->query_temp("baituo_wait"))
	{
		remove_call_out("do_open");
		call_out("do_open", 1, me);
	}
}

int do_open()
{
	string dir;
	object room;	
	message("vision","ʯ����Ȼ������������������һ�໺���ƿ�������¶��һ���ڶ�������ڡ�\n", this_object() );
	set("exits/down", __DIR__"midao0");
	if( room = load_object(__DIR__"midao0") )
	{
		 room->set("exits/up", __FILE__);
		 message("vision",
 "ͷ���ϵ�ʯ����Ȼ����������������¶��һ���������Ķ��ڡ�\n",room );
	} 
	remove_call_out("close_door");
	call_out("close_door", 3);
	return 1;
}

void close_door()
{
	object room;

	if( !query("exits/down") ) return;
	message("vision","ʯ�������������������������ƻ�ԭ���������µĶ��ڸ�ס�ˡ�\n", this_object() );
	if( room = load_object(__DIR__"midao0") )
	{
		room->delete("exits/up");
		message("vision","ͷ���Ϸ���������������ʯ���ֻ��������˻�ȥ��������ʧ�ˡ�\n", room );
	}
	delete("exits/down");
}

int valid_leave(object me, string dir)
{	
	me->delete_temp("baituo_wait");
	return ::valid_leave(me, dir);
}

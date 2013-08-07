// Room: /d/taohua/fanting1.c
// Last Modified by winder on Nov. 17 2000

#include <ansi.h>
inherit ROOM;
int do_sit(string arg);
int do_stand();
void delete_served(object me);

void create()
{
	set("short", "����");
	set("long", @LONG
�����һ���������ÿ�ճԷ��ĵط������˵���ζ�������������䡣
�������һ�Ŵ�����(table)��һЩ����(chair)������վ�ż������͡�
LONG
	);

	set("exits", ([
		"north" : __DIR__"chufang1",
		"west" : __DIR__"chafang1",
		"east" : __DIR__"lianwuchang",
	]));
	
	set("item_desc", ([
		"table" : "һ�Ŵ���������������һЩ�롢�̡��ꡢ�׵����ߡ�\n",
		"chair" : "���Ƶ����Σ�����ȥ��Щҡҡ�λΡ�\n",
	]));
	                                

	set("no_fight", 1);
	
	set("coor/x", 8970);
	set("coor/y", -3010);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_stand", "stand");
	add_action("do_stand", "zhan");
	add_action("do_sit", "sit");
	add_action("do_sit", "zuo");
}

int serve_food(object me)
{
	if (!present(me, this_object())) return 0;
	message_vision("�����߹�������$N������һ���׷���\n", me);
	
	new(__DIR__"obj/mifan")->move(me);

	me->set_temp("marks/food_served", 1);
	call_out("delete_served", 120, me);
	return 1;
}

void delete_served(object me)
{
	if ( objectp(me) ) me->delete_temp("marks/food_served");
}

int do_sit(string arg)
{
	object me = this_player();
	string time = NATURE_D->game_time();

	if(me->is_busy() || me->is_fighting()) return notify_fail("����æ���أ�\n");
	if(arg == "table" || arg == "zhuozi")
		return notify_fail("��Ҫ���������ϣ����Ȱ����������ٶ������ɡ�\n");	
	if( !arg || (arg != "chair" && arg != "yizi") )
		return notify_fail("��Ҫ���ڵذ��ϣ��и��ԣ���ϧ�������Ӱ���һ���������\n");	
	if (me->query_temp("marks/sit"))
		return notify_fail("���Ѿ�������λ���ˡ�\n");	
	message_vision("$N���˸���λ���£����ųԷ���\n", me);	
	if( (strsrch(time, "��ʱ") == 0) && (strsrch(time, "��ʱ") == 0) && (strsrch(time, "��ʱ") == 0) ) 
	{
		message_vision("�����߹�����$N�����ƣ���ʾ���ڲ��ǳԷ�ʱ�䡣\n", me);
		message_vision("$N���ε���վ��������\n", me);	
		return notify_fail("");
	}
	if( me->query_temp("marks/food_served") )
	{
		message_vision("�����߹�����$N�����ƣ���ʾ�Ա��˵ľͲ�Ҫ�ٳ��ˡ�\n",me);
		message_vision("$N�������˵��۹ⶼ�ڶ����Լ���æվ�����������ε�˵����ֻ�����������ӽ�ʵ����ʵ��\n", me);
		return notify_fail("");
	}
	me->set_temp("marks/sit", 1);
	call_out("serve_food", 1, me);
	return 1;
}

int do_stand()
{
	object me = this_player();

	if (!me->query_temp("marks/sit"))
		return notify_fail("���Ѿ�վ���ˣ��ǲ���վ�����е㷢�谡��\n");	
	message_vision("$N����ƨ�ɣ�վ��������\n", me);	
	me->delete_temp("marks/sit");
	return 1;
}

int valid_leave(object me, string dir)
{
	if (me->query_temp("marks/sit"))
		return notify_fail("�����������Ҳ���ȥ��\n");	
	if ((dir == "north") && present("dami fan", me))
//	if (random(3)) 
		return notify_fail("�����ܹ��������ƣ���ʾ���ܰ�û����Ĵ��ߡ�\n");
	return ::valid_leave(me, dir);
}

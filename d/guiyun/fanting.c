// Room: /d/guiyun/fanting.c
// Last Modified by winder on Jul. 9 2001

#include <ansi.h>
inherit ROOM;

int do_sit(string arg);
int do_stand();
void delete_served(object me);

void create()
{
	set("short", "����");
	set("long", @LONG
���ǹ���ׯ������ÿ�ճԷ��ĵط������˵���ζ�������������䡣
�������һ�Ŵ�����(table)��һЩ����(chair)������վ�ż������ۡ�
LONG
	);
	set("exits", ([
		"east"  : __DIR__"chufang",
		"west"  : __DIR__"chafang",
		"north" : __DIR__"lianwuchang",
	]));
	set("item_desc", ([
		"table" : "һ�Ŵ���������������һЩ�롢�̡��ꡢ�׵����ߡ�\n",
		"chair" : "���Ƶ����Σ�����ȥ��Щҡҡ�λΡ�\n",
	]));
	set("no_fight", 1);
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
	mixed *local;

	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���أ�\n");
	if (arg == "table" || arg == "zhuozi")
		return notify_fail("��Ҫ���������ϣ����Ȱ����������ٶ������ɡ�\n");	

	if ( !arg || (arg != "chair" && arg != "yizi") )
		return notify_fail("��Ҫ���ڵذ��ϣ��и��ԣ���ϧ�������Ӱ�����ׯ������\n");	
	if (me->query_temp("marks/sit"))
		return notify_fail("���Ѿ�������λ���ˡ�\n");	
	message_vision("$N���˸���λ���£����ųԷ���\n", me);	
	local = localtime(time() * 60);
	if (local[2] < 6) {
		message_vision("�����߹�����$N˵�����ҹ������С��ȥ����Ū�Եİ���\n", me);
		message_vision("$N���ε���վ��������\n", me);	
		return notify_fail("");
	}
	else if (local[2] > 8 && local[2] < 11) {
		message_vision("�����߹�����$N˵�������緹ʱ���������������ɡ�\n", me);
		message_vision("$N���ε���վ��������\n", me);	
		return notify_fail("");
	}
	else if (local[2] > 13 && local[2] < 17) {
		message_vision("�����߹�����$N˵�������緹ʱ���������������ɡ�\n", me);
		message_vision("$N���ε���վ��������\n", me);	
		return notify_fail("");
	}
	else if (local[2] > 20) {
		message_vision("�����߹�����$N˵��������ʱ������������һ�ްɡ�\n", me);
		message_vision("$N���ε���վ��������\n", me);	
		return notify_fail("");
	}
	if( me->query_temp("marks/food_served") ) {
		message_vision("�����߹�����$N˵���Ա��˵ľͳ�ȥ�ɣ���ռ�ŵط���\n", me);
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
		return notify_fail("�����ܹ���˵��û�����Ҳ����߰�������һ�±����\n");
	
	return ::valid_leave(me, dir);
}

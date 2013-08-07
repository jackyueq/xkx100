// Room: /d/guiyun/chafang.c
// Last Modified by winder on Jun. 29 2001

#include <ansi.h>
inherit ROOM;

int do_sit(string arg);
int do_stand();
void delete_served(object me);

void create()
{
	set("short", "�跿");
	set("long", @LONG
���ǹ���ׯ�����ǺȲ���Ϣ�ĵط������ݵĲ��㣬������Ƣ������
���ż�������(table)������(chair)�����ż������ںȲ��������Ů��
�ӡ������м���Ѿ������æ��Ϊ����ϲ衣
LONG );
	set("exits", ([
		"east" : __DIR__"fanting",
	]));
	set("item_desc", ([
		"table" : "���ŵ���ľС�����������ˮ���̺��������ߡ�\n",
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

int serve_tea(object me)
{
	if (!present(me, this_object())) return 0;
	message_vision("Ѿ���߹�������$N������һ�����򻨲衣\n", me);
	
	new(__DIR__"obj/huacha")->move(me);

	me->set_temp("marks/tea_served", 1);
	call_out("delete_served", 120, me);
	return 1;
}

void delete_served(object me)
{
	if ( objectp(me) ) me->delete_temp("marks/tea_served");
}

int do_sit(string arg)
{
	object me = this_player();

	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���أ�\n");
	if (arg == "table" || arg == "zhuozi")
		return notify_fail("��Ҫ���������ϣ����Ȱ��㼷��֭�ٶ������ɡ�\n");	

	if ( !arg || (arg != "chair" && arg != "yizi") )
		return notify_fail("��Ҫ���ڵذ��ϣ��и��ԣ���ϧ�������Ӱ�����ׯ������\n");	
	
	if (me->query_temp("marks/sit"))
		return notify_fail("���Ѿ�������λ���ˡ�\n");	
			
	message_vision("$N���˸���λ���£������ϲ衣\n", me);	
	if( me->query_temp("marks/tea_served") ) {
		message_vision("Ѿ���߹�����$N˵���ȱ��˵ľͳ�ȥ�ɣ���ռ�ŵط���\n", me);
		message_vision("$N�������˵��۹ⶼ�ڶ����Լ���æվ�����������ε�˵����ֻ�����������ӽ�ʵ����ʵ��\n", me);
		return notify_fail("");
	}
	me->set_temp("marks/sit", 1);

	call_out("serve_tea", 1, me);
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

	if (dir == "east" && present("moli huacha", me))
//	if (random(3)) 
		return notify_fail("Ѿ���ܹ���˵��û�����Ҳ����߰�������һ�±����\n");
	
	return ::valid_leave(me, dir);
}

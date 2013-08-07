// Room: /d/baituo/shidui.c
// Last Modified by winder on May. 15 2001

#include <ansi.h>;
inherit ROOM;
void create()
{
	set("short", "��ʯ��");
	set("long", @LONG
����������Χȫ�Ǿ�ʯ���������������ҵ���ʯ�ӣ����Ǳ��˻���
��ʯ������������顣����һ��ƽ������ʯ���϶���һֻѩ�׵ĸ�󡡣
LONG);	
	set("objects", ([
		__DIR__"npc/chanchu" : 1,
	]));
	set("item_desc", ([
		"stone": "\n��Щ��ʯ���а��棬���ó��Ǳ��������������õġ�\n",
	]));
	set("outdoors", "baituo");
	set("coor/x", -49910);
	set("coor/y", 20090);
	set("coor/z", 40);
	setup(); 
}

void init()
{
	object me = this_player();	
	if(me->query("id") != "xuanbing chanchu") 
	if(me->query_skill("xidu-poison",1) < 50) 
	{
		message_vision(HIW"�������ͻȻ���𣬶���$Nһ�ڶ��������\n"NOR,this_player()); 
		tell_object(me, HIB"��е�����һ�����Σ���ʱ���˹�ȥ��\n" NOR );
		me->unconcious();
		me->move(__DIR__"yuanzi5");
		tell_room(environment(me),me->name()+"ͻȻ�Ӿ�ʯ֮��ֱ�����������ȡ���һ��ˤ�ڵ��ϣ�\n", ({ me }));
		me->add("max_neili", -1);
	}
	add_action("do_climb", "climb");
	add_action("do_climb", "pa");
	add_action("do_strike", "strike");
}

int do_climb(string arg)
{
	object me;
	me = this_player();
	if( !arg || arg=="" ) return 0;
	if (arg == "stone" )
	{
		message_vision("$N�ֽŲ��ã������˾�ʯȥ��\n", me);
		message_vision("$N����һ�ݣ��Ѿ����˳�ȥ��\n", me);
		me->move(__DIR__"yuanzi5");
		message("vision", me->name() + "���������˳�����\n",environment(me), ({me}) );
		return 1;
	}
}

int do_strike(string arg)
{
	object me = this_player();
	int improve, cost, lvl, exp;

	lvl = me->query_skill("strike",1);
	exp = me->query("combat_exp");
	improve = me->query_int() / 10 + random(me->query_int() * 5 / 6);
	if( !arg || arg=="" ) return 0;
	if (arg == "stone" )
	{
		if(!me->query_skill("hamagong", 1))
			return notify_fail("������ָ�����ƾ�ʯ������¶��һ˿�ѿ�����ɫ��\n");
		if(me->query_skill("hamagong", 1) > 100)
			return notify_fail("��һ�����ʯ��ȥ��ֻ�����һ������ʯ��������������룡\n");
		cost = 300 / (int)me->query("int");
		cost = 300 / (int)me->query("int");

		if((int)me->query("qi") < cost || (int)me->query("jing") < cost)
		{
			message_vision("$N��������, һ�����������������$N���˹�ȥ��\n",me);
			me->unconcious();
			return 1;
		} 
		message_vision("$NĬ�и�󡹦�ھ���������˫��֮�ϣ�һ�������ʯ��ȥ��\n"NOR,this_player());
		if ( lvl < 100 && lvl*lvl*lvl/10 < exp)
			me->improve_skill("strike", improve/4); 
		me->improve_skill("hamagong", improve);
		me->receive_damage("jing", cost);
		me->receive_damage("qi", cost);			
		return 1;
	}
}


// Room: /d/baituo/shetan.c
// Last Modified by winder on May. 15 2001

#include <ansi.h>;
inherit ROOM;
void create()
{
	set("short", BLU"��̶"NOR);
	set("long", @LONG
һ���������ˮ̶��ˮ��������ɸߡ���о���ˮ���ж�����������
�������������ߣ�����(jumpup)�ɣ�
LONG);
	set("objects", ([
		    __DIR__"npc/jumang" : 2
	]));
	set("outdoors", "baituo");
	set("coor/x", -49900);
	set("coor/y", 20060);
	set("coor/z", 10);
	setup(); 
}

void init()
{
	object ob;       
	if (interactive(ob = this_player()))
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}       
	add_action("do_jumpup", "jumpup");
}

int do_jumpup(string arg)
{
	object me, ob;
	me = this_player();
	if(me->query("qi") < 100 ) 
		return notify_fail("���Ѿ�û����������ȥ�ˡ�\n");

	if (objectp(present("ju mang", environment(me))))
	{
		if( me->query_dex() > 20 && me->query_dex() < 26)
		{
			message_vision( HIR"$N��������һ�ݣ�ȴ�ֱ�������ס��˫������������\n"NOR, me);
			me->receive_damage("qi", 150);
			me->receive_wound("qi", 50);
			return 1;
		}
		if(me->query_dex() >= 26 && me->query_dex() < 32)
		{
			message_vision( HIY"$N��������һ�ݣ������ֱ�������ס��˫�㣬�������ӳ�����̶��\n"NOR, me);
			me->receive_damage("qi", 150);
			me->receive_wound("qi", 50);
			me->move(__DIR__"yuanzi1");
			tell_room(environment(me),me->name()+"����̶֮��������������һ����ɫ�԰׵������ڵء�\n", ({ me }));
			return 1;
		}
		if(me->query_dex() >= 32)
		{
			message_vision(HIR"$N��������һ�ݣ���������̶��\n"NOR, me);
			me->receive_damage("qi", 50);
			me->receive_wound("qi", 10);
			me->move(__DIR__"yuanzi1");
			tell_room(environment(me),me->name()+"����̶֮������������ģ���Ǳ�������\n", ({ me }));
			return 1;
		}
		else
		{ 
			message_vision("$Nʹ��һ��������������ȥ��\n", me);
			return 1;
		}
	}
	else
	{ 
		message_vision("$Nʹ��һ�ݣ���������̶��\n", me);
		me->receive_damage("qi", 50);
		me->move(__DIR__"yuanzi1");
		tell_room(environment(me),me->name()+"ͻȻ����̶֮�����˳����������־�֮ɫ��\n",({ me }));
		return 1;
	}
}

int greeting(object ob)
{
	object me = this_player();	
	if( (int)me->query_temp("baituo_climb") )
	{
		message_vision(HIR"$N��ǽ���������������������˾������ϣ���\n"NOR,me);
		message_vision(HIR"$N��û�ع��������Ѿ���������ס�ˣ�\n"NOR,me);
		write(BLU"�㱻������ס��Խ��Խ��������\n��е�һ�����ﶼ��ʼ����Զ�����ȥ�ˡ�����\n"NOR);
		me->delete_temp("baituo_climb");
		me->unconcious();
		return 1;
	}
	if((int)me->query_temp("baituo_climb1") )
	{
		message_vision(HIR"$N��ǽ���������������������˾������ԣ���\n"NOR,me);
		message_vision(HIR"$N����һ����˫��ȴ���Ǳ�������ס��\n"NOR,me);
		write(BLU"�㱻������ס��Խ��Խ���������ٲ��뷨���ܾ������ˣ�\n"NOR);
		me->receive_damage("qi", 500);
		me->receive_wound("qi", 200);
		me->delete_temp("baituo_climb1");
		return 1;
	}
	if( (int)me->query_temp("baituo_climb2") )
	{
		message_vision(HIR"$N�ոշ��ݹ������ͷ�������̶���о�������\n"NOR,me);
		write(BLU"�㿴������������˹��������ߣ�\n"NOR);
		message_vision( HIY"$N���ڰ��˫��һ�ӣ����������ֱ�ɳ�ȥ����������̶��\n"NOR, me);
		me->add("neili", -100);
		me->move(__DIR__"yuanzi1");
		tell_room(environment(me),me->name()+"����̶֮�з�Ծ���������ϴ��ž���֮ɫ��\n",({ me }));
		me->delete_temp("baituo_climb2");
		return 1;
	}      
}

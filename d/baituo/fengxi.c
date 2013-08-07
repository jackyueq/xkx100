// Room: /d/baituo/fengxi.c
// Last Modified by winder on May. 15 2001

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "��϶");
	set("long", @LONG
������ʯ����ʯ��֮��ļз죬���߻谵�������Ըо������ܵ�ɳɳ
���Ǹ��ֶ������е�������һ�ɹ���ζ��Ҳ������һЩ�̱ǵ���Ϣ���㷢
��ǰ����һʯ��(shikuai) �������������Ĺ�â��
LONG);
	set("objects", ([
		__DIR__"npc/yanjing" : 2
	]));
	set("exits", ([
		"north" : __DIR__"fengxi1",
		"out"   : __DIR__"yuanzi2",
	]));
	set("item_desc", ([		    
		"shikuai":BLU"\n���ʯͷ������ɫ��ɢ������������ʯ���ϰ��ݽ�ȥ���Ǹ����������Ρ�\n"NOR,
	]));
	set("coor/x", -49910);
	set("coor/y", 20070);
	set("coor/z", 20);
	setup(); 
}

void init()
{
	add_action("do_push", "tui");
	add_action("do_push", "push");      
}

int do_push(string arg)
{
	object me;
	me = this_player();
	if( !arg || arg=="" ) return 0;
	if( (int)me->query_temp("baituo_stone") ) 
		return notify_fail("���Ѿ��ƶ�����ʯ�顣\n");
	if (arg == "shikuai" )
	{
		message_vision("$N�������˿�����������ְ�סʯ���ϵ���ӡ������������ȥ��\n", me); 
		me->set_temp("baituo_stone", 1);
		message_vision("$N��ʯ�鰴�´�������ԼԼ�������´���һ���¡����\n", me); 
		me->start_busy(5);
		call_out("poisoned", 5, me);
		return 1;
	}
}

int poisoned()
{
	object me = this_player();
	if ((int)me->query_skill("poison", 1) < 50 &&
		!me->query_skill("hamagong", 1))
	{
		tell_object(me, BLU"��е�ʯ���ϵ�����˳���ֱ���������������\n\n" NOR );
		message_vision("$NͻȻ����һ�������������˺�����\n", me);
		me->apply_condition("cold_poison", 50);
		return 1;
	}
	if (me->query_skill("hamagong", 1) ||
		me->query_skill("poison", 1) >= 50)
	{
		tell_object(me, BLU"��Ȼһ������˳���ֱ۴�ʯ������������������\n\n" NOR );
		tell_object(me, HIW"����æ�˹��������������ֱ۵ĺ����������˳�ȥ��\n" NOR );
		return 1;
	}
}

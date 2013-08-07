// Room: /d/baituo/fengxi1.c
// Last Modified by Winder on May. 15 2001

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
		__DIR__"npc/fushe" : 2
	]));
	set("exits", ([
		"south" : __DIR__"fengxi",
		"west"  : __DIR__"fengxi2",
		"out"   : __DIR__"yuanzi3",
	]));
	set("item_desc", ([		    
		"shikuai":RED"\n���ʯͷ�ʺ칯ɫ��ɢ��������������ʯ���ϰ��ݽ�ȥ�Ĳ����Ǹ����������Ρ�\n"NOR,
	]));
	set("coor/x", -49900);
	set("coor/y", 20080);
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
	if( !me->query_temp("baituo_stone") ) return 0;
	if( (int)me->query_temp("baituo_stone1") ) 
		return notify_fail("���Ѿ��ƶ�����ʯ�顣\n");
	if (arg == "shikuai" )
	{
		message_vision("$N�������˿�����������ְ�סʯ���ϵ���ӡ������������ȥ��\n", me);	    
		me->set_temp("baituo_stone1", 1);
		message_vision("$N��ʯ�鰴�´�������ԼԼ�������´���һ���¡����\n", me);
		me->start_busy(5);      
		call_out("poisoned", 5, me);
		return 1;
	}     
}

int poisoned()
{
	object me = this_player();
	if ((int)me->query_skill("poison", 1) < 80 &&
		!me->query_skill("hamagong", 1))
	{
		tell_object(me, RED"��е�ʯ���ϵ�����֮��˳���ֱ���������������\n\n" NOR );
		message_vision("$NͻȻ����һ���������������ȶ���\n", me);
		me->apply_condition("hot_poison", 50);
		me->delete_temp("baituo_stone");
		return 1;
	}   
	if (me->query_skill("hamagong", 1) ||
		me->query_skill("poison", 1) >= 80)
	{
		tell_object(me, RED"��Ȼһ������֮��˳���ֱ۴�ʯ������������������\n\n" NOR );
		tell_object(me, HIW"����æ�˹��������������ֱ۵�����֮���������˳�ȥ��\n" NOR );
		me->delete_temp("baituo_stone");
		return 1;
	}	       
}

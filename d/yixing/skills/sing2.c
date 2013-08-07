// /d/yixing/skills/sing2.c ��
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>

//inherit F_CLEAN_UP;
inherit F_DBASE;
inherit F_SSERVER;

int exert(object me, object target)
{
	object obj, weapon;
	int ap, dp; 

	seteuid(getuid());

	if( userp(me) )
		return notify_fail("it is only for npcs.\n");
	if( me->is_busy() )
		return notify_fail("you are busy now.\n");
	if( !objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("id") != "lubo" )
		return notify_fail("��δִ���������������󳪡�\n");

	if( !objectp(obj = present("kulou guan", me)) ||
		!obj->query("equipped") )
		return notify_fail("��δ�����ùڣ����������󳪡�\n");
	if( !objectp(obj = present("rentou lian", me)) ||
		!obj->query("equipped") )
		return notify_fail("��δ����ͷ�������������󳪡�\n");
	if( !living(target)) return notify_fail("�����һ�㣬�ǲ����ǻ��\n");
	if( target->query("race") != "����" )
		return notify_fail(target->query("name")+"������������\n");

	if( (int)me->query("neili") < 300 )
		return notify_fail("�������������\n");

	if( (int)me->query_skill("necromancy", 1) < 30 )
		return notify_fail("��Ľ���������������\n");

	if( (int)me->query_skill("lamaism", 1) < 30 )
		return notify_fail("��������ķ�����������\n");

	if( (int)me->query_skill("longxiang-banruo", 1) < 30 )
		return notify_fail("����������������������\n");

	if( environment(me)->query("no_fight") )
		return notify_fail("�����ﲻ�ܳ���\n");

	if( target->query_temp("cursed", 1) ||
		target->query_temp("block_msg/all", 1))
		return notify_fail("�����ѱ�������\n");

	if( (int)me->query_temp("curser") ) 
		return notify_fail("�㽵������һ���ˣ�\n");

	me->add("neili", -50);
	me->receive_damage("qi", 50);

	message_vision( BLU "$Nҡͷ���ԣ����б��д�˷𾭣����������������䡣���������ٴ죬�����з����������ɡ�\n" NOR, me);
	tell_object(target, "�����������ȹ�޻��������Դ���һ�����ң���ǰһ�ѹ�Ӱ��������������������֫��������Ȼ��˯��\n");
		
	ap = (int)me->query("neili") + (int)me->query("max_neili") +
		(int)me->query_skill("necromancy", 1) * 10 +
		(int)me->query_skill("lamaism", 1) * 10;
	dp = (int)target->query_skill("force") * 10;

	ap *= (int)me->query("combat_exp")/1000 + 1;
	dp *= (int)target->query("combat_exp")/1000 + 1;

	if( random(ap + dp) > dp ) {
		tell_object(target, HIR"\n��ֻ������ǰ��һ����������Զȥ����Ļ�����Ҫ���ϣ������������ס�\n"NOR);

		target->start_busy(2 + random(2));
		target->set_temp("cursed", 1);
		target->set_temp("yield", 1);
//		target->set_temp("block_msg/all", 1);
		me->set_temp("curser", 1);

		message_vision(HIR"\n$NͻȻ��ʼ���۷�ֱ������������ǰ����\n"NOR, target);

		remove_call_out("del_sung");
		call_out("del_sung", 3 + random(3), me, target);
	} else{
		me->start_busy(1 + random(3));
		if( !target->is_killing(me->query("id")) ) 
			target->kill_ob(me);
	}

	return 1;
}

void del_sung(object me, object target)
{
	if( target ) {
	if (target->query_temp("cursed", 1))
		target->delete_temp("cursed");
	if (target->query_temp("block_msg/all", 1))
		target->delete_temp("block_msg/all");
	if (target->query_leader() ) 
		target->set_leader(0);
	if( target->query_temp("yield") )
		target->delete_temp("yield");

	message_vision("$N���������ѹ����������ֻص����Լ������ϡ�\n", target);
	}

	if( me ) {
	if ( me->query_temp("curser") )
		me->delete_temp("curser");
	}
}


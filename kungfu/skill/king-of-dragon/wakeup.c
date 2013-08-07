// wakeup.c
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

int exert(object me, object target)
{
	if ((!target)||target->query("id")==me->query("id"))
		return notify_fail("��Ҫ����������˭��\n");
/*
	if( me->is_fighting() || target->is_fighting())
		return notify_fail("ս�����޷��˹����ˣ�\n");
*/
	if(target == me)
		return notify_fail("�㲻��Ϊ�Լ������Լ���\n");

	if( (int)me->query("max_neili") < 1000 )
		return notify_fail("���������Ϊ������\n");

	if( (int)me->query("neili") < 1000 )
		return notify_fail("�������������\n");

	if( (int)target->query("eff_qi") < (int)target->query("max_qi") / 5 )
		return notify_fail( target->name() +
			"�Ѿ����˹��أ����ܲ�����������𵴣�\n");

	message_combatd(HIY "$N�������������ڹ�������������$n���ģ������ؽ���������$n����....\n\n���˲��ã�$N��ͷ��ð������ĺ��飬$n�³�һ����Ѫ����ɫ������������ˡ�\n$n���������ѹ�����\n" NOR, me, target );

	target->receive_curing("qi", 10 + (int)me->query_skill("force")/3 );
	target->add("qi", 10 + (int)me->query_skill("force")/3 );
	if( (int)target->query("qi") > (int)target->query("eff_qi") ) target->set("qi", (int)target->query("eff_qi"));

           target->remove_call_out("revive");
           target->revive();
           target->reincarnate();
 
	me->add("neili", -150);
	me->set("jiali", 0);
//                me->start_busy(5);
//                target->start_busy(5);
	return 1;
}

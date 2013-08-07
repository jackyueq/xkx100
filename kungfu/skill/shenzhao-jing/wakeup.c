// wakeup.c
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

int exert(object me, object target)
{
  if ( userp(me) && !wizardp(me) && 
  !me->query("can_perform/shenzhao-jing/wakeup") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("����ʹ�õ��ڹ���û�����ֹ��ܡ�");

	if ( !target || !target->is_character() )
		return notify_fail("��Ҫ����������˭��\n");

	if( me->is_fighting() || target->is_fighting())
		return notify_fail("ս�����޷��˹����ˣ�\n");

	if(target == me)
		return notify_fail("�㲻��Ϊ�Լ������Լ���\n");

	if(!target->query_temp("noliving/unconcious") )
		return notify_fail("��ֻ�ܾ��ѻ��Բ��ѵ��ˣ�\n");

	if(!userp(target))
		return notify_fail("��ֻ�ܾ�����ң�\n");

	if( (int)me->query_skill("shenzhao-jing", 1) < 100 )
		return notify_fail("������վ���Ϊ������\n");

	if( (int)me->query("max_neili") < 1000 )
		return notify_fail("���������Ϊ������\n");

	if( (int)me->query("neili") < 1000 )
		return notify_fail("�������������\n");

	if( (int)target->query("eff_qi") < (int)target->query("max_qi") / 5 )
		return notify_fail( target->name() + "�Ѿ����˹��أ����ܲ�����������𵴣�\n");

	message_combatd(HIY"$N���������������վ��ڹ�������������$n���ģ������ؽ���������$n����....\n\n���˲��ã�$n���������ѹ�����\n" NOR, me, target );

//	target->receive_curing("qi", 10 + (int)me->query_skill("force")/3 );
//	target->add("qi", 10 + (int)me->query_skill("force")/3 );
//	if( (int)target->query("qi") > (int)target->query("eff_qi") )
//		target->set("qi", (int)target->query("eff_qi"));

	target->remove_call_out("revive");
	target->revive();
	target->reincarnate();
 
	me->add("neili", -150);
	me->set("jiali", 0);
	me->start_busy(5);
	target->start_busy(5);
	return 1;
}
int help(object me)
{
	write(WHT"\n���վ�֮����"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		���ѻ����е�����

	����Ҫ��
		���վ�100��
		����1000
HELP
	);
	return 1;
}


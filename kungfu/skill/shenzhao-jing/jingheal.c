// jingheal.c
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

int exert(object me, object target)
{
/*
	if ((!target) || target->query("id")!=me->query("id"))
		return notify_fail("��Ҫ������Ϊ˭������\n");
*/
  if ( userp(me) && !wizardp(me) && 
  !me->query("can_perform/shenzhao-jing/jingheal") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("����ʹ�õ��ڹ���û�����ֹ��ܡ�");

	if (!target) target = me;

	if( me->is_fighting() || target->is_fighting())
		return notify_fail("ս�����޷��˹�������\n");

	if( (int)me->query_skill("shenzhao-jing",1) < 50 )
		return notify_fail("������վ��ڹ���Ϊ������\n");

	if( me->is_busy() )
		return notify_fail("��������æ���أ����п��˹���\n");

	if( target->is_busy())
		return notify_fail(target->name()+"������æ���أ�\n");

	if( (int)me->query("max_neili") < 200)
		return notify_fail("���������Ϊ������\n");

	if( (int)me->query("neili") < 200)
		return notify_fail("�������������\n");

	if( (int)target->query("eff_jing") >= (int)target->query("max_jing"))
		return notify_fail("ֻ�о����������Ҫ������\n");

	if( (int)target->query("eff_jing") < (int)target->query("max_jing") / 5)
		return notify_fail("����������أ����ܲ��������𵴣�\n");

  if ( me != target)
	message_combatd( HIC "$N���������������վ��ڹ���������������$n�����ţ�������ס$n��������ؽ���ת����....\n\n"HIY "���˲��ã�$n��ͷ��ð������ĺ��飬���ϵ�ƣ��ģ��Ҳ������ˡ�\n" NOR, me, target);
  else 
 	message_combatd( HIC "$N���������������վ��ڹ��������������ں����ţ�������ס��������ؽ���ת����....\n\n"HIY "���˲��ã�$N��ͷ��ð������ĺ��飬���ϵ�ƣ��ģ��Ҳ������ˡ�\n" NOR, me);

  
	target->receive_curing("jing", 10 + (int)me->query_skill("force")/2 );
	if( (int)target->query("jing") > (int)target->query("eff_jing") )
		target->set("jing", (int)me->query("eff_jing"));

	me->add("neili", -50);
	me->start_busy(3);
	target->start_busy(2);
	return 1;
}

int help(object me)
{
	write(WHT"\n���վ�֮�ƾ�"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		Ϊ�Լ������˻���

	����Ҫ��
		���վ�50��
		����200
HELP
	);
	return 1;
}


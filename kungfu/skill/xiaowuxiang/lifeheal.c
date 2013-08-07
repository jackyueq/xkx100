// lifeheal.c
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

int exert(object me, object target)
{
  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/lifeheal") &&
  !me->query("can_perform/xiaowuxiang/lifeheal") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("����ʹ�õ��ڹ���û�����ֹ��ܡ�");

	if( !target || !target->is_character() || target == me )
		return notify_fail("��Ҫ������Ϊ˭���ˣ�\n");

	if( me->is_fighting() || target->is_fighting())
		return notify_fail("ս�����޷��˹����ˣ�\n");

	notify_fail("������Ҫץ���ˣ���ʲô���֣�\n");
	if (!userp(target) && !target->accept_hit(me)) return 0;

	if( me->is_busy() )
		return notify_fail("��������æ���أ����п��˹���\n");

	if( target->is_busy())
		return notify_fail(target->name()+"������æ���أ�\n");

	if( (int)me->query_skill("xiaowuxiang", 1) < 30 )
		return notify_fail("���С���๦��Ϊ������\n");

	if( (int)me->query("max_neili") < 300 )
		return notify_fail("���������Ϊ������\n");

	if( (int)me->query("neili") < 150 )
		return notify_fail("�������������\n");
/*
	if( (int)target->query("eff_qi") >= (int)target->query("max_qi") )
		return notify_fail( target->name() + "ֻ�����ˣ�û�����ˣ�������������������ˣ�\n");
*/
	if( (int)target->query("eff_qi") < (int)target->query("max_qi") / 5 )
		return notify_fail( target->name() + "�Ѿ����˹��أ����ܲ�����������𵴣�\n");

	message_combatd( HIY "$N�������������ڹ�������������$n���ģ������ؽ���������$n����....\n\n���˲��ã�$N��ͷ��ð������ĺ��飬$n�³�һ����Ѫ����ɫ������������ˡ�\n" NOR, me, target );

	target->receive_curing("qi", 10 + (int)me->query_skill("force")/3 );
	target->add("qi", 10 + (int)me->query_skill("force")/3 );
	if( (int)target->query("qi") > (int)target->query("eff_qi") )
		target->set("qi", (int)target->query("eff_qi"));

	me->add("neili", -50);
	me->start_busy(1);
	if ( userp(target)) target->start_busy(2);

	return 1;
}

int help(object me)
{
	write(WHT"\nС���๦֮���ƣ�"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		Ϊ��������

	����Ҫ��
		С���๦30��
	        ����300
HELP
	);
	return 1;
}


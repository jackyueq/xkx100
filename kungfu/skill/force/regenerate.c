// regenerate.c
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>;
//inherit SSERVER;

int exert(object me, object target)
{
	int n, j;

	if (me != target)
		return notify_fail("��ֻ�����ڹ������Լ��ľ�����\n");

	if ((int)me->query("neili") < 20)
		return notify_fail("�������������\n");

	j = (int)me->query("eff_jing") - (int)me->query("jing");
	if (j < 10)
		return notify_fail("�������������档\n");
	n = 100 * j / me->query_skill("force");
	if (n < 20)
		n = 20;
	if ((int)me->query("neili") < n) {
		j = j * (int)me->query("neili") / n;
		n = (int)me->query("neili");
	}

	me->add("neili", -n);
	me->receive_heal("jing", j);
	
        message_combatd("$N�������˼����������������ö��ˡ�\n", me);

        if( me->is_fighting() ) me->start_busy(1);
	
	return 1;
}
int help(object me)
{
	write(WHT"\n�����ڹ�֮������"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		��ֲ�Լ����õľ���

	����Ҫ��
		�����ڹ�
		����20
HELP
	);
	return 1;
}


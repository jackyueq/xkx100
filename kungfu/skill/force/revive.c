// revive.c
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>;
//inherit SSERVER;

int exert(object me, object target)
{
	int n, t;

	if (me != target)
		return notify_fail("��ֻ�����ڹ��ָ��Լ���������\n");

	if ((int)me->query("neili") < 20)
		return notify_fail("�������������\n");

	t = (int)me->query("max_tili") - (int)me->query("tili");
	if (t < 10)
		return notify_fail("�������������档\n");
	n = me->query_skill("force");
	if (n < 20) n = 20;
	if ((int)me->query("neili") < n) n = (int)me->query("neili");

	me->add("neili", -n);
	me->add("tili", (int)(n/10));
	if( me->query("tili") > me->query("max_tili"))
		me->set("tili", me->query("max_tili"));
	
        message_combatd("$N���˿�������������������֫��ȫ��Ҳ��������������\n", me);

        if( me->is_fighting() ) me->start_busy(1);
	
	return 1;
}
int help(object me)
{
	write(WHT"\n�����ڹ�֮����������"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		�����Լ����ĵ�������

	����Ҫ��
		�����ڹ�
		����20
HELP
	);
	return 1;
}


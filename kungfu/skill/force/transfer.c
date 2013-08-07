// transfer.c ת����
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

int exert(object me, object target)
{
	int force, trans;

	if( query_ip_name(target)==query_ip_name(me))
		return notify_fail("��ֻ�ܽ���������������ҡ�\n");

	if( !target || target==me ||
		!living(target) || target->query_temp("noliving") )
		return notify_fail("��Ҫ������������λ��\n");

	if(me->query_skill_mapped("force")!=target->query_skill_mapped("force"))
		return notify_fail(target->name()+"��ʹ�õ��ڹ����㲻ͬ�����ܴ�������\n");

	if( (int)me->query("neili") <= (int)me->query("max_neili")/3 )
		return notify_fail("����������㡣\n");

	if( (int)me->query("max_neili") <= (int)target->query("max_neili") )
		return notify_fail("��������������˼Ҷ࣬������ȥ��\n");

	if ((int)target->query("neili") >= (int)target->query("max_neili")*2)
		return notify_fail("�Է����������棬����Ҫ���������\n");
  if (target->is_busy())
   return notify_fail("�Է���æ���ء�\n");
	force = me->query("neili") - (me->query("max_neili")/3);

	if( (int)force/3 < 1 ) return notify_fail("����������㡣\n");
	me->add("neili", -(int)force/3 );
	me->start_busy(3);
	if( (int)me->query("max_neili") <= (int)target->query("max_neili")*5/4 )
		me->add("max_neili", -1);

	message_combatd(HIW"$Nһ������$n���ģ�˳�������������������͹�ȥ��\n"NOR, me,target);
	target->add("neili", (int)force/3);
	target->start_busy(3);
	tell_object(target, HIW "�����һ��������"+me->name()+"�������д��˹�����\n" NOR);
	return 1;
}

int help(object me)
{
	write(WHT"\n�����ڹ�֮����������"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		���Լ����������͵��������ڡ�
		�����ܷ��������޴ﵽ���ͷ��İ˳ɣ�����Ĵ��ͷ���������

	����Ҫ��
		�����ڹ�
		����20
		˫���ǲ�ͬ��ip
		˫����ϰͬһ���ڹ�
		���ܷ��������С�ڴ��ͷ�
HELP
	);
	return 1;
}


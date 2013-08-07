// qudu.c
// Last Modified by sir on 5.4.2002

#include <ansi.h>

int exert(object me, object target)
{
  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/qudu") &&
  !me->query("can_perform/beiming-shengong/qudu") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("����ʹ�õ��ڹ���û�����ֹ��ܡ�");

	if( (!target))
		return notify_fail("��Ҫ������Ϊ˭������\n");

	if( me->is_fighting() || target->is_fighting())
		return notify_fail("ս�����޷��˹�������\n");

	if( me->is_busy() )
		return notify_fail("��������æ���أ����п��˹���\n");

	notify_fail("������Ҫץ���ˣ���ʲô���֣�\n");
	if (!userp(target) && !target->accept_hit(me)) return 0;

	if( target->is_busy())
		return notify_fail(target->name()+"������æ���أ�\n");

	if( !target->query_condition("ss_poison"))
		return notify_fail(target->name()+"��û������������\n");
		
	if( (int)me->query_skill("beiming-shengong",1) < 50 )
		return notify_fail("��ı�ڤ����Ϊ������\n");

	if( (int)me->query("max_neili") < 150 )
		return notify_fail("���������Ϊ������\n");

	if( (int)me->query("neili") < 150)
		return notify_fail("�������������\n");

	if( (int)me->query_skill("force") < (int)target->query_skill("force") / 3 )
		return notify_fail( target->name() + "�ж��Ѿ��������ڹ���Ϊ���½ⲻ��������������\n");

	if (me != target)
	message_combatd( HIC"$N������������ڤ�񹦣�����������$n���ģ������ؽ���������$n����....\n\n���˲��ã�$N��ͷ��ð������ĺ��飬$nָ������һ�ư�ɫ��������ɫ������������ˡ�\n" NOR, me, target );
    else
    message_vision( HIC"$N����������֮�����ģ�����������֮�����ˣ���ʼ���л���������֮��....\n\n������ã�$Nֻ��������Ȫ��Ѩ��һ������֮���Ȼ���⣬�ؽ���˵���������ʡ�\n"NOR,me);

//	target->set("qi", (int)target->query("eff_qi"));
	target->clear_condition("ss_poison",0);

	me->add("neili", -100);
	me->start_busy(1);
	if ( userp(target)) target->start_busy(2);

	return 1;
}

int help(object me)
{
	write(WHT"\n��ڤ��֮������"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		��������

	����Ҫ��
		��ڤ��50��
	        ����150
	        ˫�������ڹ����ⲻ��
HELP
	);
	return 1;
}


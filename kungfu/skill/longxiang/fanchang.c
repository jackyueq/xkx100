// fanchang.c
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

inherit F_SSERVER;
int exert(object me, object target)
{
	int sp, dp;

  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/fanchang") &&
  !me->query("can_perform/longxinag/fanchang") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("����ʹ�õ��ڹ���û�����ֹ��ܡ�");

	if( environment(me)->query("no_fight") )
		return notify_fail("���ﲻ�ܹ�������! \n");
		
	if( !objectp(target) ) target = offensive_target(me);

	if( !target || !target->is_character() || target == me ) 
		return notify_fail("��Ҫ��˭ʹ���󳪣�\n");
	notify_fail("������Ҫץ���ˣ���ʲô���֣�\n");
	if (!userp(target) && !target->accept_hit(me)) return 0;

	if( (int)me->query_skill("longxiang",1) < 50 )
		return notify_fail("�����������������������������񹥻��Է���\n");

	if( (int)me->query("neili",1) < 50 )
		return notify_fail("�����������������ʹ�������������\n");

	message_combatd(HIW "$N���ޱ��飬�������󳪰����$n���У�\n\n" NOR, me, target );

        if( living(target) && !target->query_temp("noliving") )
		if( !target->is_killing(me) )
			target->kill_ob(me);

	sp = me->query_skill("force") + me->query_skill("lamaism") + me->query_skill("longxiang",1)/2;
	dp = target->query_skill("force");
	
	if (( random(sp) > random(dp) ) ||
		!living(target) || target->query_temp("noliving") )
	{
		tell_object(target, HIW"���Ȼ��������һƬ�հף�����������������赸������\n" NOR);
		tell_object(me, HIB"�㿴��" + target->name() + "������ĸ��������㵸��ʮ�ֿ�Ц��\n" NOR);

		target->receive_damage("jing", 10 + random((int)me->query_skill("longxiang", 1)) );
		
		if( target->query("combat_exp") >= me->query("combat_exp") )
				me->add("potential", 1);

		me->start_busy(2);
		target->start_busy(random(3));
		me->add("neili", -50);

	}
	else
	{	
		message_combatd(HIY "����$p��Ϊ$P����������������Ȼ��ͬ���죡\n" NOR, me, target);
		me->start_busy(4);
	}

	return 1;
}
int help(object me)
{
	write(WHT"\n���������֮�󳪣�"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		���˶Է�����
		���ͶԷ�����

	����Ҫ��
		���������50��
		����50
HELP
	);
	return 1;
}


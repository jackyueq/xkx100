// poqi.c ����ʽ
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit F_SSERVER;

int perform(object me)
{
	string msg;
	object weapon, target;
	int skill, ap, dp, neili_wound, qi_wound;

	if(me->query("family/master_id") != "feng qingyang" && userp(me))
		return notify_fail("�㲻�Ƿ�����ĵ��ӣ�����ʹ�þ��У�\n");
	skill = me->query_skill("lonely-sword",1);
  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/poqi") &&
  !me->query("can_perform/lonely-sword/poqi") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�");

	if( !objectp(target) ) target = offensive_target(me);
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	  !living(target) || target->query_temp("noliving") )
		return notify_fail("������ʽ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if( skill < 100)
		return notify_fail("��Ķ��¾Ž��ȼ�����, ����ʹ������ʽ��\n");
	if( me->query("max_neili") < 500 )
		return notify_fail("���������Ϊ�������޷����á�����ʽ����\n");
	if( me->query("neili") < 250 )
		return notify_fail("��������������޷����á�����ʽ����\n");
	msg = HIC "$NǱ�˶��¾Ž�������ʽ���������ὣʹ���������ۣ����޻��ε�ֱ
��$n�ĵ��\n";
	message_combatd(msg, me, target);
	ap = me->query_skill("sword") + skill;
	dp = target->query_skill("force") / 2;
	if( dp < 1 ) dp = 1;
	if( random(ap) > dp )
	{
		if(userp(me)) me->add("neili",-150);
		msg ="$N��������ʽ��������б���Է�С����$n��ʱ������ǰһ��������Ѩ\n��΢΢һʹ��ȫ��������й������\n" NOR;
		neili_wound = 300 + random(skill);
		if(neili_wound > target->query("neili"))
			neili_wound = target->query("neili");
		qi_wound = skill+(int)me->query_skill("sword",1)/2;
		qi_wound = qi_wound/2 + random(qi_wound);
		if(qi_wound > target->query("qi")) qi_wound = 100;
		target->add("neili", -neili_wound);
		target->receive_damage("qi", qi_wound,me);
		target->receive_wound("qi", qi_wound/2,me);
		target->set_temp("lonely-sword/poqi",1);
		target->start_busy(2);
		me->start_busy(2);
	}
	else
	{
		if(userp(me)) me->add("neili",-100);
		msg = "����$n������$N����ͼ�������ؽ��Ż��������������ڻ��е�����\n"NOR;
		me->start_busy(3);
	}
	message_combatd(msg, me, target);
	return 1;
}
int help(object me)
{
	write(WHT"\n���¾Ž�֮����ʽ��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		�ƽ���߸����ڹ��ĵ���֮�书�����˵���Ѫ

	����Ҫ��
		��Ϊ������մ�����
		���¾Ž�100��
		������Ϊ500
		����250
HELP
	);
	return 1;
}


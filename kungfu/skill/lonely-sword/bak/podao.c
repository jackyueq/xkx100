// podao.c �Ƶ�ʽ
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

inherit F_SSERVER;

int perform(object me)
{
	string msg;
	object weapon, weapon2, target;
	int skill, ap, dp, damage;


	if(me->query("family/master_id") != "feng qingyang")
	   return notify_fail("�㲻�Ƿ�����ĵ��ӣ�����ʹ�þ��У�\n");

	me->clean_up_enemy();
	target = me->select_opponent();

	skill = me->query_skill("lonely-sword",1);

	if( !(me->is_fighting() ))
	    return notify_fail("���Ƶ�ʽ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
	    return notify_fail("��ʹ�õ��������ԡ�\n");

	if (!objectp(weapon2 = target->query_temp("weapon"))
	|| (string)weapon2->query("skill_type") != "blade")
	    return notify_fail("�Է�û��ʹ�������ò��ˡ��Ƶ�ʽ����\n");

	if( skill < 50)
	    return notify_fail("��Ķ��¾Ž��ȼ�����, ����ʹ�á��Ƶ�ʽ����\n");

	if( me->query("neili") < 50 )
	    return notify_fail("��������������޷����á��Ƶ�ʽ����\n");

	msg = HIC "$N��ʹ���¾Ž����Ƶ�ʽ���ƽ�$n���ὣ�ó����ؽ�Ӱ������˿
����$n��ȥ��\n";
	message_combatd(msg, me, target);

	damage = 10 + random(skill / 2);
	ap = me->query_skill("sword") + skill;
	dp = target->query_skill("blade") / 2;
	if( dp < 1 )
	    dp = 1;
	    dp = 1;
	if( random(ap) > dp)
	{
	    if(userp(me))
		 me->add("neili",-50);
	    msg = "$n��ʱ����ѹ������������һ�飬����";
	    msg += weapon2->name();
	    msg += "���ֶ�����\n" NOR;
	    me->start_busy(random(2));
	    target->receive_damage("qi", damage);
	    target->start_busy(2);
	    weapon2->move(environment(me));
/*
	    if (weapon2->query("ownmake")==1)
	    {
		weapon2->move(target);
		msg += "�ǿ���$n������һ$n��һ�콫���������\n" NOR;
	    }
*/
	}
	else
	{
	    if(userp(me))
		 me->add("neili",-30);
	    msg = "����$n������$N�Ľ�·�����̲�ȡ���ƣ�ʹ$N���Ƶ�ʽû�������á�\n"NOR;
	    me->start_busy(4);
	}
	message_combatd(msg, me, target);

	return 1;
}
int help(object me)
{
	write(WHT"\n���¾Ž�֮�Ƶ�ʽ��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		�ƽ��ҿɻ����ֳֵ�������ĵ���֮���������˵���Ѫ

	����Ҫ��
		��Ϊ������մ�����
		���¾Ž�50��
		����50
HELP
	);
	return 1;
}


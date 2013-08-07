// jinglisuck.c
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

inherit F_SSERVER;
int exert(object me, object target)
{
	int sp, dp;
	int my_max, tg_max;

  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/jinglisuck") &&
  !me->query("can_perform/huagong-dafa/jinglisuck") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("����ʹ�õ��ڹ���û�����ֹ��ܡ�");
	if ( target == me ) target = offensive_target(me);


	if( environment(me)->query("no_fight") )
		return notify_fail("�����ﲻ�ܹ������ˡ�\n");

	if( !objectp(target) ||
		target->query("id") == "gongping zi" ||
		target->query("id") == "zhang men" ||
		target->query("id") == "mu ren" ||
		target->query("id") == "shi ren" ||
		target->query("id") == "jiguan ren" ||
		target->query("id") == "xiangpi ren" ||
		target->query("id") == "jin ren" ||
		target->query("id") == "du jiangshi")
		return notify_fail("��Ҫ��ȡ˭�ľ�����\n");
	notify_fail("������Ҫץ���ˣ���ʲô���֣�\n");
	if (!userp(target) && !target->accept_hit(me)) return 0;
	
	if (target->query("race") != "����")
		return notify_fail("����ˣ�ֻ���˲����о�����\n");

	my_max = me->query("max_jingli");
	tg_max = target->query("max_jingli");

	if ( me->query_temp("sucked") )
		return notify_fail("��ո���ȡ��������\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("�������ֲ���ʩ�û��������˾�����\n");

//	if( !me->is_fighting() || !target->is_fighting())

	if( (int)me->query_skill("huagong-dafa",1) < 100 )
		return notify_fail("��Ļ����󷨹���������������ȡ�Է��ľ�����\n");

	if( (int)me->query("neili",1) < 20 )
		return notify_fail("�����������������ʹ�û����󷨡�\n");

	if( (int)target->query("max_jingli") < 10 )
		return notify_fail( target->name() +
			"������ɢ������δ�ۣ����޷�����������ȡ�κζ�����\n");

	if( (int)target->query("max_jingli") < (int)me->query("max_jingli")/10 )
		return notify_fail( target->name() +
			"���ڹ���ΪԶ�����㣬���޷�����������ȡ������\n");

	message_combatd(
		HIR "$Nȫ��ǽڱ��죬˫�۱������ߣ���Ե�͵���$n������������ȥ��\n\n" NOR,
		me, target );

        if ( living(target) && !target->query_temp("noliving") )
	{
		if( !target->is_killing(me) ) target->kill_ob(me);
	}

	sp = me->query_skill("force") + me->query_skill("dodge") + me->query_skill("zhaixinggong",1)/2;
	dp = target->query_skill("force") + target->query_skill("dodge");

	me->set_temp("sucked", 1);		

	if (( random(sp) > random(dp) ) ||
		!living(target) || target->query_temp("noliving") )
	{
		tell_object(target, HIR"��ֻ���춥���ѣ�ȫ�������Զ���������ѩ����ʧ����Ӱ���٣�\n" NOR);
		tell_object(me, HIG"�����" + target->name() + "�ľ���������ԴԴ���������˽�����\n" NOR);

		target->add("max_jingli", -1*(1+(me->query_skill("huagong-dafa", 1)-100)/5) );
		if ((int)me->query("max_jingli") <
                    ((int)me->query_skill("taoism",1) * 10))
		{
			me->add("max_jingli", 1*(1+(me->query_skill("huagong-dafa", 1)-100)/5) );
			me->add("jingli", 1*(1+(me->query_skill("huagong-dafa", 1)-100)/5) );
		}
		if( target->query("max_jingli") <1) target->set("max_jingli",0);

//		if( (int)me->query("potential") - (int)me->query("learned_points") < 90 ) 
		me->add("potential",  3);
		me->add("combat_exp", 10);

		me->start_busy(7);
		target->start_busy(random(7));
		me->add("neili", -10);

		call_out("del_sucked", 10, me);
	}
	else
	{	
		message_combatd(HIY "����$p������$P����ͼ�������͵�һ�𣬽������˿�ȥ��\n" NOR, me, target);
		me->start_busy(7);
		call_out("del_sucked", 20, me);
	}

	return 1;
}

void del_sucked(object me)
{
	if ( me->query_temp("sucked") )
	me->delete_temp("sucked");
}

int help(object me)
{
	write(WHT"\n������֮��ȡ������"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		��ȡ�Է�����
		��ǿ�Լ�����

	����Ҫ��
		������100��
		����20
HELP
	);
	return 1;
}


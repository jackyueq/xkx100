// nuoyi.c
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit F_SSERVER;
#define PNAME "Ų��"
int perform(object me, string arg)
{
        string who1, who2;
        object target, victim;
        int damage, lvl, form, skill, i;
        string msg;
	int flag;
	string fskill,sskill,bskill,pfname,pskill;

	sskill = explode(__FILE__,"/")[<2];
	pfname = explode(__FILE__,"/")[<1][0..<3];
  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/nuoyi") &&
  !me->query("can_perform/qiankun-danuoyi/nuoyi") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�");
	 
	 if (!me->is_fighting())
   return notify_fail("��Ǭ����Ų�ơ�ֻ����ս����ʹ�á�\n");
        if( (int)me->query("max_neili", 1) < 1500 )
		return notify_fail("���������Ϊ������ʹ��Ǭ��Ų�ƴ󷨡�\n");
        if( (int)me->query("neili", 1) < 1000 )
		return notify_fail("����������̫��������ʹ��Ǭ��Ų�ƴ󷨡�\n");


	fskill = "jiuyang-shengong";
	bskill = "dodge";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 50 )
		return notify_fail("���"+to_chinese(fskill)+"δ������޷�ʩչ"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 50 )
		return notify_fail("���"+to_chinese(sskill)+"��Ϊ������С���߻���ħ��\n");

	if( !arg )
	{
		target = offensive_target(me);
  	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	  !living(target) || target->query_temp("noliving") )
			return notify_fail("Ǭ����Ų�ƴ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
		form = 1;
	}
	
	else
	{
		target = offensive_target(me);
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
			return notify_fail("Ǭ����Ų��ֻ��ս���ж���ʹ�á�\n");
		victim = present(arg, environment(me));
		if( !victim || !victim->is_character() || victim==me) 
			return notify_fail("����Ų�ƹ����Ķ��������\n");
	   if((victim->name())=="��ƽ��")
	    	return notify_fail("�㲻���ԶԹ�ƽ��ʹ��Ǭ����Ų�ơ�\n");
  	notify_fail("�㲻�ܹ�������ˡ�\n");
		if (!userp(victim) && !victim->accept_hit(me)) return 0;
		form = 2;
	}

	skill = (int)me->query_skill("dodge", 1);
	lvl = random((int)(skill/30));

	if( form == 1 ) /* �������� */
	{
		msg = CYN "$NĬ���񹦣�ʹ��Ǭ����Ų�ƴ󷨡�\n"NOR;
		me->start_busy(3);
		if(random(me->query("neili")) > target->query("neili")/3 )
		{
			target->start_busy(random(3));
			damage = skill/2 + lvl*target->query("jiali",1);
			target->receive_damage("qi", damage,me);
			target->receive_wound("qi", damage/3,me);
			me->add("neili", -damage);
			msg += CYN "��$n"CYN"������ȫ��������ȥ��\n" NOR;
			if( damage < 20 )
				msg += HIY "���$n"HIY"�ܵ�$N"HIY"�����������ƺ�һ����\n"NOR;
			else if( damage < 40 )
				msg += HIY "���$n"HIY"��$N"HIY"���������𣬡��١���һ������������\n"NOR;
			else if( damage < 80 )
				msg += RED "���$n"RED"��$N"RED"������һ���ؿ������ܵ�һ���ش�����������������\n"NOR;
			else
				msg += HIR "���$n"HIR"��$N"HIR"������һ����ǰһ�ڣ���һ������һ���ɳ�ȥ�ü���Զ��\n"NOR;
		}
		else 
		{
			msg += CYN"����$n"CYN"�������˿����Ϊ������\n"NOR;
			me->add("neili", -100);
		}
		message_combatd(msg, me, target);
		return 1;
	}
	else
	{
		write( CYN "��Ĭ���񹦣�ʹ��Ǭ����Ų�ƴ󷨣���ͼ��" + target->name() + CYN+"�Ĺ���Ų�Ƶ�" + victim->name() + CYN+"���ϡ�\n"NOR);
		tell_object(victim, CYN"��Ȼ���㷢����һ����ֵ���������Ϯ����\n"NOR);
		me->start_busy(3);
		if(random(me->query("neili")) > target->query("neili")/2)
		{
			write( CYN"�������ɹ��ˣ�\n"NOR);
			if( target == victim)
			{
				tell_object(target, CYN"�����ɼ���һ�л����Լ���\n"NOR);
				message("combatd",CYN+target->name()+"��Ȼ����ħһ�㣬���л����Լ���\n\n"NOR, environment(me), target);
				for(i = 0; i < lvl; i++)
					COMBAT_D->do_attack(target, victim, target->query_temp("weapon") );
			}
			else
			{
				tell_object(target, CYN"�����ɼ�����" + victim->name() + CYN+"��ȥ��\n"NOR);
				message("vision", CYN"\n" + target->name() + CYN+"��Ȼ��" + victim->name() +CYN+"��ȥ��\n\n"NOR, environment(me), ({target, victim}) );
					tell_object(victim, CYN"\n" + target->name() + "��Ȼ����������\n\n"NOR);
				COMBAT_D->do_attack(target,victim,target->query_temp("weapon"));
				if(random(me->query("combat_exp")) >
					(int)victim->query("combat_exp")/2 )
				{
					target->delete("env/combatd");
					victim->delete("env/combatd");
					if(!victim->is_killing(target))
						victim->kill_ob(target);
				}
				else
				{
					tell_object(victim, CYN"��һ����ԭ����" + me->name() + CYN+"�ڵ���\n"NOR);
					tell_object(target, CYN"���ã��ҿ�"+victim->name()+CYN+"�����ϵ���û���ϵ���\n"NOR);
					write( CYN "���ã���" + victim->name() + CYN+"�����ˣ�\n"NOR);
					if(!victim->is_killing(me))
						victim->kill_ob(me);
				}
				target->start_busy(random(3));
				me->add("neili", -300);
			}
		}
		else
		{
			write( CYN"��ϧû�ɹ���\n"NOR);
			tell_object(target, CYN"��ǿ���������ڿ���ס�Լ���\n"NOR);
			me->add("neili", -100);
		}
		return 1;
	}
}

int help(object me)
{
	write(WHT"\nǬ����Ų��֮Ų��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		nuoyi :  �����������ֵĹ�����
		nuoyi <����> :  ��������ǰ��������Ĺ���Ų�Ƶ��������ϡ�
				���԰ѵ��ֵĹ���Ų�Ƹ�������
	����Ҫ��
		������50��
		Ǭ����Ų��50��
		������Ϊ1500
		����1000
HELP
	);
	return 1;
}


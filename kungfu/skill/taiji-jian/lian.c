// lian.c ̫�������������־�
// Last Modified by sega on 4.10 2000
//������10��,��Ȼ̫�����˵�.

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
#define PNAME "�������־�"
int perform(object me, object target)
{
	object weapon;
	string msg;
	int i, attack_time,sword_lvl;
	int flag;
	string fskill,sskill,bskill,pfname,pskill;

	sskill = explode(__FILE__,"/")[<2];
	pfname = explode(__FILE__,"/")[<1][0..<3];
  if (userp(me) && !wizardp(me) &&
   !me->query("perform/"+pfname) &&
   !me->query("can_perform/"+sskill+"/"+pfname) &&
   !me->query_temp("murong/xingyi") &&
   !SCBORN_D->valid_perform(me,sskill,pfname))
   return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	fskill = "taiji-shengong";
	bskill = "sword";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 70 )
		return notify_fail("���"+to_chinese(fskill)+"��򲻹���ʹ����"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 50 )
		return notify_fail("���"+to_chinese(sskill)+"û����쵽��ʹ"+PNAME+"��\n");

	if( (int)me->query("neili") < 300 )
		return notify_fail("������������ˣ�����ʹ�á������־���\n");

	msg = HIY "$Nʹ��̫�������������־�����ʽ��Ȼ��졣\n";

	if(random(me->query("combat_exp"))>(int)target->query("combat_exp")/20)
	{
		attack_time = random((int)me->query_skill("sword", 1) / 20);
	        sword_lvl =(int)me->query_skill("sword", 1)/15;
         	if(attack_time < 2) attack_time = 2;
		if(attack_time >10) attack_time = 10;
		if(attack_time > 5) 
		{ attack_time = attack_time - 4;
		  attack_time = 5 + random(attack_time);
		 } 
		msg += CYN " ���$p��$P���˸����ֲ������������˲�Ͼ��\n" NOR;
		message_combatd(msg, me, target);
		for(i = 0; i < attack_time; i++)
		{
			if (flag == 1) target = offensive_target(me);
			if (!objectp(target)) break;
			me->add_temp("apply/dodge",sword_lvl);
			me->add_temp("apply/attack",sword_lvl);
			me->add_temp("apply/sword",sword_lvl);
			COMBAT_D->do_attack(me,target,me->query_temp("weapon"),0);
		}
		me->add_temp("apply/dodge",-i*sword_lvl);
		me->add_temp("apply/attack",-i*sword_lvl);
		me->add_temp("apply/sword",-i*sword_lvl);
		me->start_busy(1);
		me->add("neili", -30*i);
	}
	else
	{
		msg += "����$p������$P����ͼ������������ס��$P���������С�\n" NOR;
		message_combatd(msg, me, target);
		me->start_busy(2);
		me->add("neili", -150);
	}

//	if(!target->is_fighting(me)) target->fight_ob(me);
	if(flag != 1) target->fight_ob(me);
	return 1;
}
string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		�������������Է�

	����Ҫ��
		̫����70��
		̫������50��
		����150
HELP
	);
	return 1;
}


// chan.c ��Ѫǹ�������ơ���
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

inherit F_SSERVER;
#define PNAME "�����ơ���"
int perform(object me, object target)
{
	string msg;
	object weapon;
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

	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "spear")
		return notify_fail("��ʹ�õ��������ԡ�\n");
		
	fskill = "guiyuan-tunafa";
	bskill = "spear";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 50 )
		return notify_fail("���"+to_chinese(fskill)+"��򲻹���ʹ����"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 50 )
		return notify_fail("���"+to_chinese(sskill)+"��򲻹���ʹ����"+PNAME+"��\n");

	if (me->query("max_neili") < 300 )
		return notify_fail("���������Ϊ���㣬ʹ���������ơ�����\n");

	if (me->query("neili") < 200 )
		return notify_fail("����������㣬ʹ���������ơ�����\n");

	if( target->is_busy() )
		return notify_fail(target->name()+"Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");

	msg = CYN "$N"CYN"ʹ����Ѫǹ�������ơ���������"+weapon->name()+CYN"������Ť������$n"CYN"������·���������á�����\n";

	me->start_busy(random(3));
	me->add("neili", -150);
	if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/2)
	{
		msg += "���$p��$P���������ң���æ����������\n" NOR;
		target->start_busy( (int)me->query_skill(bskill) / 40);
	} else {
		msg += "$p����$P�����У�����û��˿�����͡�\n" NOR;
	}
	message_combatd(msg, me, target);

	if(!target->is_fighting(me)) target->fight_ob(me);
	return 1;
}

int help(object me)
{
	write(WHT"\n��Ѫǹ��֮���ƾ�"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		���ͶԷ�����

	����Ҫ��
		��Ԫ���ɷ�50��
		��Ѫǹ��50��
		������Ϊ300
		����200
HELP
	);
	return 1;
}


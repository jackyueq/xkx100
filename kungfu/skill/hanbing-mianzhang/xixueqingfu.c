// xixueqingfu.c ��Ѫ����
// Last Modified by winder on Mar. 10 2000
 
#include <ansi.h>
 
inherit F_SSERVER;
#define PNAME "����Ѫ����"
int perform(object me,object target)
{
	string msg;
	object weapon;
	int skill, ap, dp, neili_wound, qi_wound;
	int flag;
	string fskill,sskill,bskill,pfname,pskill;

	sskill = explode(__FILE__,"/")[<2];
	pfname = explode(__FILE__,"/")[<1][0..<3];
  if (userp(me) && !wizardp(me) &&
   !me->query("perform/"+pfname) &&
   !me->query("can_perform/"+sskill+"/"+pfname) &&
   !me->query_temp("murong/xingyi") &&
   !SCBORN_D->valid_perform(me,sskill,pfname) )
   return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"ֻ�ܶ�ս���еĶ���ʹ�á�\n"); 

//	if (me->query("family/family_name") != "����")
//		return notify_fail("�����̵��ӣ��޷��޷����á���Ѫ���𡹡�\n");

	if (objectp(weapon = me->query_temp("weapon")))
		return notify_fail("��ʹ����������\n");

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
		return notify_fail("���"+to_chinese(fskill)+"�������޷�����"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 60 )
		return notify_fail("���"+to_chinese(sskill)+"�ȼ�����, ����ʹ��"+PNAME+"��\n");

	if( (int)me->query_skill(bskill, 1) < 150 )
		return notify_fail("���"+to_chinese(bskill)+"�������޷�����"+PNAME+"��\n");

	if( me->query("neili") < 200 )
		return notify_fail("��������������޷����á���Ѫ���𡹣�\n");

	msg = HIC "$N"HIC"ͻȻ��ͬ����Ѫ���𡹣��۽�$n"HIC"����ǰ���������$n"HIC"���ʺ�ҧȥ��\n"NOR;
	message_combatd(msg, me, target);
 
	ap = me->query("combat_exp") + skill * 400;
	dp = target->query("combat_exp") / 2;
	if( dp < 1 ) dp = 1;
	if( random(ap) > dp )
	{
		if(userp(me))
			me->add("neili",-100);

		msg = HIG "$n"HIG"ֻ�����ʺ�һ���ʹ��$N"HIG"���ڿ���$n"HIG"����Ѫ��\n"NOR;
		neili_wound = 100 + random(skill);

		qi_wound = neili_wound * 2;
		if(qi_wound > target->query("qi"))
			qi_wound = target->query("qi");
		target->receive_wound("qi", qi_wound,me);

		if(neili_wound > target->query("neili"))
			neili_wound = target->query("neili");
		target->add("neili", -neili_wound);

		target->start_busy(2);
		me->start_busy(random(2));
	}
	else
	{
		msg = HIG "ֻ��$n"HIG"���Ų�æ������һ���������$N"HIG"�����ݣ�\n"NOR;
		if(userp(me)) me->add("neili",-100);
		me->start_busy(4);
	}
	message_combatd(msg, me, target);
	if(!target->is_fighting(me)) target->fight_ob(me);

	return 1;
}
string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		���˶Է���Ѫ
		���ͶԷ�����

	����Ҫ��
		������50��
		��������60��
		�����Ṧ150��
		����200
HELP
	);
	return 1;
}


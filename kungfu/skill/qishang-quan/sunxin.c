// sunxin.c ���ľ�
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

inherit F_SSERVER;
#define PNAME "��" HIR "���ľ�" NOR "��"
int perform(object me,object target)
{
	string msg;
	object weapon;
	int skill, ap, dp, attack_decrease;
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

	if (objectp(weapon = me->query_temp("weapon")))
		return notify_fail("�������ֲ���ʹ�á����ľ�����\n");

	fskill = "jiuyang-shengong";
	bskill = "cuff";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 60 )
		return notify_fail("���"+to_chinese(fskill)+"��Ϊ���㣬�������ʹ��"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 60 )
		return notify_fail("���"+to_chinese(sskill)+"����Ϊ���������ܹ����"+PNAME+"��\n");

	if( (int)me->query_skill(bskill, 1) < 60 )
		return notify_fail("���"+to_chinese(bskill)+"�������ң��޷���������ȭ��"+PNAME+"��\n");

	if( (int)me->query("neili") < 500 )
		return notify_fail("��������������ߣ�\n");

	skill = me->query_skill(bskill,1) + me->query_skill("force",1);

	msg = HIY"$N��������ʹ������ȭ�ܾ��еġ�" HIR "���ľ�" HIY "����˫ȭ������������$n��ȥ��\n"NOR;
	message_combatd(msg, me, target);

	ap = me->query("combat_exp") + skill * 500;
	dp = target->query("combat_exp") / 4;
	if( dp < 1 ) dp = 1;
	if( random(ap) > dp )
	{
		if(userp(me)) me->add("neili",-500);
		msg = HIG "$N����ȭ������ף�$n"HIG"����$N"HIG"��ɽ��ʯ��һȭ����ʱ������𣬲���������У�\n"NOR;
		attack_decrease = (int)target->query("apply/attack") ;
		if (attack_decrease > 0)
		target->add_temp("apply/attack", -attack_decrease);
		target->start_busy(2);
		me->start_busy(random(3));
	}
	else
	{
		msg = HIG "ֻ��$n"HIG"���Ų�æ������һ���������$N"HIG"�ı�ɱһ����\n"NOR;
		if(userp(me)) me->add("neili",-200);
		me->start_busy(4);
	}
	message_combatd(msg, me, target);

	return 1;
}
string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		�𺦶��ֵĹ�������

	����Ҫ��
		������60��
		����ȭ��60��
		����ȭ60��
		����500
HELP
	);
	return 1;
}



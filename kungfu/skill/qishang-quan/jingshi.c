// jingshi.c ��ʧ��
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

inherit F_SSERVER;
#define PNAME "��" HIR "��ʧ��" NOR "��"
int perform(object me,object target)
{
	string msg;
	object weapon;
	int skill, ap, dp, jing_wound, eff_jing_wound, neili_wound;
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
		return notify_fail("�������ֲ���ʹ�á���ʧ������\n");

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

	if( (int)me->query_skill(fskill, 1) < 150 )
		return notify_fail("���"+to_chinese(fskill)+"��Ϊ���㣬�������ʹ��"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 150 )
		return notify_fail("���"+to_chinese(sskill)+"����Ϊ���������ܹ����"+PNAME+"��\n");

	if( (int)me->query_skill(bskill, 1) < 150 )
		return notify_fail("���"+to_chinese(bskill)+"�������ң��޷���������ȭ��"+PNAME+"��\n");

	if( (int)me->query("neili") < 900 )
		return notify_fail("��������������ߣ�\n");

	skill = me->query_skill(bskill,1) + me->query_skill("force",1);
	
	msg = HIY"$N��������ʹ������ȭ�ܾ��еġ�" HIR "��ʧ��" HIY "����˫ȭ������������$n��ȥ��\n"NOR;
	message_combatd(msg, me, target);

	ap = me->query("combat_exp") + skill * 500;
	dp = target->query("combat_exp") / 4;
	if( dp < 1 ) dp = 1;
	if( random(ap) > dp )
	{
		if(userp(me)) me->add("neili",-500);

		msg = HIG "$N"HIG"��ȭֻ�������������$n"HIG"����$N"HIG"����������һ˲����������$n���ڣ�\n$nֻ�����е�ƣ��������\n"NOR;
		neili_wound = 100 + random(skill);
		if(neili_wound > target->query("neili"))
			neili_wound = target->query("neili");

		jing_wound = random((int)skill);
		eff_jing_wound = random((int)skill / 3);
		target->receive_wound("jing", jing_wound);
		target->receive_damage("jing", eff_jing_wound);
		me->start_busy(2);
	}
	else
	{
		msg = HIG "ֻ��$n���Ų�æ������һ���������$N�ı�ɱһ����\n"NOR;
		if(userp(me)) me->add("neili",-200);
		me->start_busy(3);
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
		���˶Է�����

	����Ҫ��
		������150��
		����ȭ��150��
		����ȭ150��
		����900
HELP
	);
	return 1;
}


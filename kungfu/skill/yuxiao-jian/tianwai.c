// tianwai.c ��������
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit F_SSERVER;
#define PNAME "������������"
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
   !SCBORN_D->valid_perform(me,sskill,pfname))
   return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"ֻ�ܶ�ս���еĶ���ʹ�á�\n");
		
	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	fskill = "bibo-shengong";
	bskill = "sword";

	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");

	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 120 )
		return notify_fail("���"+to_chinese(fskill)+"�ȼ�����, ����ʹ��"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 90 )
		return notify_fail("���"+to_chinese(sskill)+"�ȼ�����, ����ʹ��"+PNAME+"��\n");

	skill = me->query_skill("sword", 1);

	if( me->query("neili") < 250 )
		return notify_fail("��������������޷����á�������������\n");

	msg = HIC "$Nһ����Х����������������һ����������������һʽ��������������"+weapon->name()+HIC+"������ֹ����Ӱ��ҹĻ������$n��\n";
	message_combatd(msg, me, target);

	ap = 2 * skill;
	dp = target->query_skill("force", 1) / 2;
	if( dp < 1 ) dp = 1;
	if( random(ap) > dp )
	{
		if(userp(me)) me->add("neili",-150);
		msg ="$n��ʱ������ǰ�����������˫��������������֪����һ���ʹ������һ�㣡\n" NOR;
		qi_wound = 2 * skill;
		qi_wound = qi_wound/2 + random(qi_wound);
		target->receive_damage("qi", qi_wound,me);
		target->receive_wound("qi", qi_wound/2,me);
		target->start_busy(2);
		me->start_busy(1+random(3));
	}
	else
	{
		if(userp(me)) me->add("neili", -100);
		msg = "����$n���ľ��������ֻ�������$N������Ʋ��һ�ߡ�\n"NOR;
		me->start_busy(2+random(3));
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

	����Ҫ��
		�̲���120��
		���｣��90��
		����250
HELP
	);
	return 1;
}


// Last Modified by winder on Jul. 9 2001
#include <ansi.h>

inherit F_SSERVER;
#define PNAME "��"+HIW"��÷Ʈ��"NOR+"��"
int perform(object me,object target)
{
	string msg;
	object weapon;
	int neili_wound, qi_wound;
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

	fskill = "bingxue-xinfa";
	bskill = "sword";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 80 )
		return notify_fail("���"+to_chinese(fskill)+"����������ʹ��"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 80 )
		return notify_fail("���"+to_chinese(sskill)+"��Ϊ����, ����ʹ��"+PNAME+"��\n");

	if( me->query("max_neili") < 400 )
		return notify_fail("���������Ϊ�������޷����á�"+HIW"��÷Ʈ��"NOR+"����\n");

	if( me->query("neili") < 300 )
		return notify_fail("��������������޷����á�"+HIW"��÷Ʈ��"NOR+"����\n");

	msg = HIW"$N��Хһ����ʹ������÷Ʈ�㡹�����б��������������ѩ����ǰ����ǵص���ȥ��\n�ڰ�ãã��һƬ�У���Ȼ�������÷���ν�������͸ѩĻ��������˷����������\n" NOR;
	message_combatd(msg, me, target);

	if( random(me->query_skill("force"))>target->query_skill("force")/2 || 
		random(me->query("combat_exp"))>target->query("combat_exp")/3 )
	{
		me->start_busy(2);
		target->start_busy(2+random(2));
		qi_wound = me->query_skill(bskill, 1);
		qi_wound = qi_wound + random(qi_wound/2);
		target->receive_damage("qi", qi_wound/2,me);
		target->receive_wound("qi", qi_wound,me);
		target->receive_damage("jing", qi_wound,me);
		target->receive_wound("jing", qi_wound/2,me);
		if(userp(me)) me->add("neili",-300); 
		msg = HIC"����÷���⻪���ó�������������$nȫ�������ֵ�����ʵʵ��$n�������У�\nֻ���������������Լ�����˿˿������һʱȫ���ʹ����Ѫ�ɽ��õ������ǡ�\n��ͬ���֮�̣��Ҳ����ԡ�\n" NOR; 
  	message_combatd(msg, me, target);
		COMBAT_D->report_status(target);
	}
	else
	{
		if(userp(me)) me->add("neili",-100);
		msg = "����$n��ݵ����Ա�һ�����ܹ�����һ����\n"NOR;
  	message_combatd(msg, me, target);
		me->start_busy(2);
	}
	return 1;
}
string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		�˺��Է���������Ѫ

	����Ҫ��
		��ѩ�ķ�80��
		ѩɽ����80��
		������Ϊ400
		����300
HELP
        );
        return 1;
}



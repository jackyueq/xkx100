// dieying.c �ɼ��Ӱ
// Last Modified by sir on 4/25/2001



#include <ansi.h>

inherit F_SSERVER;
#define PNAME "���ɼ��Ӱ��"
int perform(object me,object target)
{
	string msg;
	object weapon ;
	int skill, /*ap,*/ dp, neili_wound, qi_wound;
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

	fskill = "qingming-xuangong";
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

	if( (int)me->query_skill(sskill, 1) < 150 )
		return notify_fail("���"+to_chinese(sskill)+"�ȼ�����, ����ʹ��"+PNAME+"��\n");

	if( me->query("neili") < 300 )
		return notify_fail("��������������޷����á��ɼ��Ӱ����\n");

	msg = HIG "$N"HIG"����Ϣ��������������һʽ���ɼ��Ӱ����"+weapon->name()+HIG "���ǧ��佣������Ӱ���������$n"HIG"��\n";
	message_combatd(msg, me, target);

	skill = me->query_skill(bskill,1);
  dp = target->query_skill("force");
	if( dp < 1 ) dp = 1;
//	if( random(skill) > dp/2 ) //��ͬ100������ random(100) > 150/2  �õ�...
	if ( random(skill) > dp/4 ) // random(100) > 150/4  now
	{
		if(userp(me)) me->add("neili", -150);
		msg ="$n��ʱ������ǰ��ӰƮ�ɣ�˫������������ȫ������һ���ʹ������һ�㣡\n" NOR;
		qi_wound = 2 * skill;
		qi_wound = qi_wound/2 + random(qi_wound);

		target->receive_damage("qi", qi_wound,me);
		target->receive_wound("qi", qi_wound/2,me);
		target->start_busy(2);
   	me->start_busy(1+random(3));
	}
	else
	{
		me->add("neili",-50);
		msg = "����$n���ľ�����������Σ�Ծ����Ӱ��\n"NOR;
		me->start_busy(1+random(3));
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
		�˵���Ѫ��ʹ����ʱ���ܶ�����

	����Ҫ��
		��ڤ����120��
		�ɷ罣��150��
		����300
HELP
	);
	return 1;
}

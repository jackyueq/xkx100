// duo.c ���������
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#include <xiaoyao.h> 

inherit F_SSERVER;
#define PNAME "���������"
int perform(object me,object target)
{
	string msg;
	object weapon, weapon2;
	int skill, dp, damage;
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
		return notify_fail("�������֡�\n");

	if (!objectp(weapon2 = target->query_temp("weapon")))
		return notify_fail("�Է�û�б��У��㲻�õ��ġ�\n");

	fskill = "beiming-shengong";
	bskill = "hand";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 50 )
		return notify_fail("���"+to_chinese(fskill)+"��Ϊ����, ����"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 50 )
		return notify_fail("���"+to_chinese(sskill)+"��򲻹�, ����"+PNAME+"��\n");

	if( (int)me->query_skill(bskill, 1) < 50 )
		return notify_fail("���"+to_chinese(bskill)+"��򲻹�, ����"+PNAME+"��\n");

	if( me->query("neili") < 50 )
		return notify_fail("��������������޷���������У�\n");

	skill = me->query_skill(bskill, 1);

	msg = CYN "$N"CYN"�����Ϣ������ʩչ��������еľ�����\n";
	message_combatd(msg, me);
 
	dp = target->query_skill("parry", 1);
	if( dp < 1 )
		dp = 1;
	if (fam_type(me)=="xiaoyao") dp /= 2;
	if( random(skill) > dp *4/5)
	{
		me->add("neili",-50);
		msg ="$Nʹ����������еľ���, $n��ʱ������ǰһ��������һ�飬���б������ֶ�����\n" NOR;
		target->start_busy(2);
		weapon2->move(me);
		if (weapon2->query("ownmake")==1||weapon2->query("no_get"))
		{
			weapon2->move(environment(me));
			msg += "ֻ��һ�����죡������ء�\n" NOR;
		}
		me->start_busy(2);
	}
	else
	{
		msg = "����$n�Ŀ�����$N����ͼ�����̲�ȡ���ƣ�ʹ$Nû�ܶ��±��С�\n"NOR;
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
		�ٶ�Է�����

	����Ҫ��
		��ڤ��50��
		��ɽ��÷��50��
		�����ַ�50��
		����50
HELP
	);
	return 1;
}


// duo.c ��ڶ���
// Last Modified by winder on Nov. 16 2000
 
#include <ansi.h>
inherit F_SSERVER;
#define PNAME "��ڶ���"
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
   !SCBORN_D->valid_perform(me,sskill,pfname) )
   return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "stick")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if (!objectp(weapon2 = target->query_temp("weapon")))
		return notify_fail("�Է�û�б��У��㲻�õ��ġ�\n");

	fskill = "huntian-qigong";
	bskill = "stick";
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
		return notify_fail("���"+to_chinese(sskill)+"��򲻹�, ����"+PNAME+"��\n");
	if( !me->query_temp("murong/xingyi") )
	{
		if ((int)me->query_skill("dagou-bang",1)< 50)
			return notify_fail("��򹷰�����򲻹�, ������ڶ��ȣ�\n");
		if ((int)me->query_skill("huntian-qigong",1) < 50)
			return notify_fail("�����������򲻹���ʹ������ڶ��ȡ�\n");
	}
	if(me->query("max_neili") < 300)
		return notify_fail("���������Ϊ����������ʹ����ڶ��ȡ�\n");
	if(me->query("neili") < 200 )
		return notify_fail("��������������޷���ڶ��ȣ�\n");
 
	skill = me->query_skill(bskill,1);
	msg = HIY"$N"HIY"������ǰ�˳���������ָ�Ѵ�ס"+weapon2->query("name")+HIY"��\n";
	message_combatd(msg, me);
 
	dp = (int) (target->query_skill("parry", 1)/3);
	if( random(skill) > dp )
	{
		if(userp(me)) me->add("neili", -150);
		msg = HIG"$n"HIG"��Ȼ��$N"HIG"���Ʒɽ�������������ͳ�һ��������"+weapon2->query("name")+HIG"������\n$N"HIG"����ʳ�ж�ָٿȡ$n"HIG"��˫Ŀ��ͬʱ���㷭���ѽ�"+weapon2->query("name")+HIG"ѹס��\n$n"HIG"Ϊ�����飬ֻ�����֡�\n" NOR;
		target->start_busy(2);
		weapon2->move(me);
		if(weapon2->query("ownmake")==1||weapon2->query("no_get"))
		{
			weapon2->move(environment(me));
			msg += "ֻ��һ�����죡������ء�\n" NOR;
		}
		me->start_busy(2);
	}
	else
	{
		msg = HIR"����$n"HIR"�ֱ�һ�񣬽�$N���ֵ��˿�ȥ��\n"NOR;
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
		��������50��
		�򹷰���50��
		������Ϊ300
		����200
HELP
	);
	return 1;
}


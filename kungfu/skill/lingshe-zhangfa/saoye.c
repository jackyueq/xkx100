// Last Modified by winder on May. 15 2001
// saoye.c ���ɨ��Ҷ
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
#define PNAME "�����ɨ��Ҷ��"
int perform(object me, object target)
{
	string msg;
	string *staff_msg = ({
	YEL"$N���μӿ죬����֮�����������" NOR,
	YEL"$Nͻ�������Ĵӿ��������������$n��ǰ����һ�ȣ�" NOR,
	YEL"$N���Ȼ�������$n��࣬����һ����" NOR,
	YEL"$N����������һ�������Ӹ����£���ͷ����һ�ȣ�" NOR,
	YEL"���ڰ�գ�$N����Ϊ�ƣ���ʵΪ�ȣ���$n��̹�ȥ��" NOR,
	YEL"$N�������裬�ܲ�͸�磬ʹ$n�����е�͸����������" NOR,
	YEL"$N���л��ɳˣ�һ�Ƚ���һ�ȣ�����������" NOR,
	YEL"$N�������֮�����������Ⱦ���ǧ����˳�$n��ȥ��" NOR,
	});
	int extra,attack_time,i;
	object weapon,ob;
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
		(string)weapon->query("skill_type") != "staff")
		return notify_fail("��ʹ�õ��������ԡ�\n");
		
	fskill = "hamagong";
	bskill = "staff";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 180 )
		return notify_fail("���"+to_chinese(fskill)+"��Ϊ�������޷�ʹ��"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 170 )
		return notify_fail("���"+to_chinese(sskill)+"��򲻹����޷�ʹ��"+PNAME+"��\n");

	if( (int)me->query("neili") < 1200 )
		return notify_fail("�������������\n");

	if( !userp(me))
		return notify_fail("ֻ����Ҳ���ɨ��Ҷ��\n");

	extra = me->query_skill("staff", 1);
	extra = extra / 3;

	me->add_temp("apply/attack",extra);
	me->add_temp("apply/damage",extra*2);
	weapon = me->query_temp("weapon");

	msg = HIY"$N���������⣬ͻȻһ�����ȣ���------ �� ----- �� ----- ɨ ----- �� ----- Ҷ ----- ��������" NOR;
	message_combatd(msg, me, target);		
	
	attack_time = 3 + random(6);
	for(i = 0; i < attack_time; i++)
	{
		if (flag == 1) target = offensive_target(me);
		if (!objectp(target)) break;
		msg=staff_msg[i];
		message_combatd(msg, me, target);
		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),0);
	}
	me->add("neili", -90*i);
	me->start_busy(2+random(4));		  
	me->add_temp("apply/attack",-extra);
	me->add_temp("apply/damage",-extra*2);
	return 1;
}

string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		�������ְ���

	����Ҫ��
		��󡹦180��
		�����ȷ�170��
		����1200
HELP
	);
	return 1;
}


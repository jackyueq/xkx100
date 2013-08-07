// pili.c ��������
// Last Modified by winder on May. 15 2001

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
#define PNAME "���������Ρ�"
inherit F_SSERVER;
 
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon,ob;
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

	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail(PNAME"ֻ�ܿ���ʹ�á�\n");		
		
	fskill = "hamagong";
	bskill = "cuff";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}
	if( (int)me->query_skill(fskill, 1) < 50 )
		return notify_fail("���"+to_chinese(fskill)+"��Ϊ�������޷�ʹ��"+PNAME+"��\n");
	if( (int)me->query_skill(sskill, 1) < 20 )
		return notify_fail("���"+to_chinese(sskill)+"��򲻹����޷�ʹ��"+PNAME+"��\n");
	if( (int)me->query("neili") < 100 )
		return notify_fail("�������������\n");
		
	extra = me->query_skill(bskill, 1);
	me->add_temp("apply/attack",extra/2);
	me->add_temp("apply/damage",extra/2);
	weapon = me->query_temp("weapon");

	msg = BLU"$N"BLU"�Ųȸ�󡲽���������ɳ��⣬����ͣ�٣�ͻȻ��ȭ����$n"BLU"�����������������֮ʽ��" NOR;
	message_combatd(msg, me, target);
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add_temp("apply/attack",-extra/2);
	me->add_temp("apply/damage",-extra/2);
	me->add("neili", -100);
	me->start_busy(1);
	return 1;
}
string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		������ȭ

	����Ҫ��
		��󡹦50��
		���ȭ20��
		����100
HELP
	);
	return 1;
}


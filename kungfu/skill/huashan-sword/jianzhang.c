// jianzhang.c ����������
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
#define PNAME "��������������"
inherit F_SSERVER;
 
int perform(object me, object target)
{
	object weapon, ob;
        string msg, string1;
        int count;
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
		(string)weapon->query("skill_type") != "sword")
		return notify_fail(PNAME"��ʼʱ��������һ�ѽ���\n");

	fskill = "zixia-shengong";
	bskill = "sword";
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

	if( (int)me->query_skill(sskill, 1) < 50 )
		return notify_fail("���"+to_chinese(sskill)+"�������ң��޷�ʹ��"+PNAME+"��\n");

	if( (int)me->query_skill(bskill, 1) < 50 )
		return notify_fail("���"+to_chinese(bskill)+"�������ң��޷�ʹ��"+PNAME+"��\n");

	if( (int)me->query("neili") < 100 )
		return notify_fail("�������������\n");

	msg = HIY "$N"HIY"��Ȼ�����ˡ������ڽ���֮���壬ʹ����ɽ�ɾ�������������������
����Ȼ�ӿ죡\n" NOR;
	message_combatd(msg, me);

	for (count = 0; count<5 ;count++)
	{
		if (flag == 1) target = offensive_target(me);
		if (!objectp(target)) break;
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
	}

	me->add("neili", -100);
	me->start_busy(1+random(5));

//	if(!target->is_fighting(me)) target->fight_ob(me);
	if(flag != 1) target->fight_ob(me);
	return 1;
}
string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		�������������彣

	����Ҫ��
		��ϼ��50��
		��������50��
		��ɽ����50��
		����100
HELP
	);
	return 1;
}


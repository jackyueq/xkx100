// Last Modified by Winder on May. 21 2001
// feiwu.c

#include <ansi.h>
inherit F_SSERVER;
#define PNAME "�����衹"
int perform(object me, object target)
{
	object weapon;
	int i,count;
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

	fskill = "hanbing-zhenqi";
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
		return notify_fail("���"+to_chinese(fskill)+"����̫ǳ���޷�ʹ��"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 120 )
		return notify_fail("���"+to_chinese(sskill)+"����̫ǳ���޷�ʹ��"+PNAME+"��\n");

	if( (int)me->query_skill(bskill, 1) < 120 )
		return notify_fail("���"+to_chinese(bskill)+"����̫ǳ���޷�ʹ��"+PNAME+"��\n");

	if( (int)me->query("max_neili") < 1500 )
		return notify_fail("���������Ϊ̫ǳ���޷����蹥����\n");

	if( (int)me->query("neili") < 500 )
		return notify_fail("��������������޷����蹥����\n");
		
	if( me->query_temp("ss_feiwu") )
		return notify_fail("���ʹ�꡸���衹��Ŀǰ��Ѫ��ӿ���޷��ٴ����ã�\n");

	me->add("neili", -300);

	message_combatd(BLU"\n$N"BLU"ͻȻ��Хһ�������������������ٽ�ͦ�̣��ڰ���л����������⣬����������������������$n"BLU"��Ϯ��ȥ��\n" NOR,me, target);

	me->add_temp("apply/damage", 50);
	for(count=0;count<5;count++)
	{
		if (flag == 1) target = offensive_target(me);
		if (!objectp(target)) break;
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
	}
	me->add_temp("apply/damage", -50);
	me->set_temp("ss_feiwu", 1); 
	i = (int)me->query_skill(bskill, 1)/30;
	if( 15 - i <= 4) i = 4;
	call_out("remove_effect", i, me);
	me->start_busy(1);

	return 1;
}

void remove_effect(object me)
{
	if (!me) return;
	me->delete_temp("ss_feiwu");
	tell_object(me, HIG"\n�㾭��һ��ʱ�������Ϣ���ֿ���ʹ�á����衹�ˡ�\n"NOR); 
}
string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		���ֳ����Ľ�

	����Ҫ��
		��������120��
		��ɽ����120��
		��������120��
		������Ϊ1500
		����500
HELP
	);
	return 1;
}


// zhangdao.c �����Ʒ� ���Ƶ���
// Last Modified by winder on Aug. 28 2001

#include <ansi.h>
inherit F_SSERVER;
#define PNAME "���Ƶ���"
void remove_effect(object me, int amount);

int perform(object me, object target)
{
	int skill;
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
/*
	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"ֻ�ܶ�ս���еĶ���ʹ�á�\n");
*/	
	if( objectp(me->query_temp("weapon")) )
		return notify_fail("�������ֲ���ʹ�á��Ƶ�����\n");
		
	fskill = "guiyuan-tunafa";
	bskill = "strike";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 120 )
		return notify_fail("���"+to_chinese(fskill)+"�ȼ���������ʹ����"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 120 )
		return notify_fail("���"+to_chinese(sskill)+"��������죬ʹ����"+PNAME+"��\n");

	if (me->query_skill_mapped("force") != fskill)
		return notify_fail("����ʹ�õ��ڹ����ԡ�\n");

	if (!me->query_temp("murong/xingyi"))
	{
		if (me->query_skill_prepared("strike") != "tiezhang-zhangfa" ||
			me->query_skill_mapped("strike")!= "tiezhang-zhangfa" ||
			me->query_skill_mapped("parry") != "tiezhang-zhangfa")
			return notify_fail("�������޷�ʹ�á��Ƶ�����\n");
	}
	if((int)me->query_str() < 30 )
		return notify_fail("�������������ǿ����ʹ�������Ƶ�������\n");

	if((int)me->query("neili") < 500 ) 
		return notify_fail("�������������\n");

	if((int)me->query_temp("tzzf") ) 
		return notify_fail("���Ѿ����Ƶ����˹��С�\n");

	skill = me->query_skill(bskill, 1) / 2;
	me->add("neili", -(me->query_skill(bskill)+100));
	message_combatd(YEL"$NͻȻ��ɫ�԰ף�˫�ֲ������漴�������һ����һ˫������ɫ���ѩ�ף�����һ����ֵĹ�â��\n" NOR, me, target);
	me->set_temp("tzzf", 1);
	me->add_temp("apply/attack", skill);
	me->add_temp("apply/damage", skill);
	me->start_call_out( (: call_other, this_object(), "remove_effect", me, skill :), skill/2);
	if( me->is_fighting() ) me->start_busy(1);
	return 1;
}

void remove_effect(object me, int amount)
{	
	me->delete_temp("tzzf");
	me->add_temp("apply/attack", -amount);
	me->add_temp("apply/damage", -amount);
	message_combatd(YEL"\n$N�Ƶ��˹���ϣ�˫���𽥻ָ���ԭ״��\n"NOR, me);
}

string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		��ǿ���ֹ�����

	����Ҫ��
		��Ԫ���ɷ�120��
		�����Ʒ�120��
		�����Ʒ�140��
		��������30��
		����500
HELP
	);
	return 1;
}


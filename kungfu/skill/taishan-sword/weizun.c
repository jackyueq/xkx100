// weizun.c  ����Ϊ��
// Last Modified by winder on Aug. 25 2001

#include <ansi.h>;
inherit F_SSERVER;
#define PNAME "������Ϊ��"
int perform(object me,object target)
{
	string msg;
	object weapon;
	int skill, ap, dp, neili_wound, qi_wound,attack_time,i;
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

	fskill = "panshi-shengong";
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
		return notify_fail("���"+to_chinese(fskill)+"��Ϊ����, ����ʹ��"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 60 )
		return notify_fail("���"+to_chinese(sskill)+"��Ϊ����, ����ʹ��"+PNAME+"��\n");

	if( me->query("neili") < 300 )
		return notify_fail("��������������޷���������Ϊ��\n");

	if( me->query("max_neili") < 400 )
		return notify_fail("���������Ϊ�������޷���������Ϊ��\n");

	skill = me->query_skill(bskill,1);
	message_combatd(HIW"$Nʹ��̩ɽ�����ġ�����Ϊ�𡹣�����Ȼ�ӿ죬����һת���������������������\n" NOR, me, target);

	me->add("neili", -100);
	attack_time = 3 + random(3);
	for(i = 0; i < attack_time; i++)
	{
		if (flag == 1) target = offensive_target(me);
		if (!objectp(target)) break;
		COMBAT_D->do_attack(me,target,me->query_temp("weapon"),0);
	}
	me->start_busy(2+random(3));
	return 1;
}
string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		���������彣

	����Ҫ��
		��ʯ��50��
		̩ɽ����60��
		������Ϊ400
		����300
HELP
	);
	return 1;
}



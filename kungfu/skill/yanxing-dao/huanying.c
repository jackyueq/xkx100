// huanying.c  ���е��������λ�Ӱ��
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

inherit F_SSERVER;
#define PNAME "�����λ�Ӱ��"
int perform(object me, object target)
{
	int damage;
	string msg;
	object weapon;
	int flag;
	int count;
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
		(string)weapon->query("skill_type") != "blade")
		return notify_fail(RED"��ʲô��Ц��ûװ������ôʹ�����λ�Ӱ����\n"NOR);

	fskill = "linji-zhuang";
	bskill = "blade";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 90 )
		return notify_fail("���"+to_chinese(fskill)+"��򲻹���"+PNAME+"������ʽ��\n");

	if( (int)me->query_skill(sskill, 1) < 60 )
		return notify_fail("���"+to_chinese(sskill)+"������죬ʹ����"+PNAME+"��\n");

	if ((int)me->query("max_neili")<300)
		return notify_fail(RED"���������Ϊ���㣬�޷����㡸���λ�Ӱ����������\n"NOR);

	if ((int)me->query("neili")<200)
		return notify_fail(HIC"����������������û�ܽ������λ�Ӱ��ʹ�꣡\n"NOR);

	msg=HIC "$N���һ����ȫ���Ĵ��ζ���$nֻ����$N����������Ӱ�����쵶\n"NOR;
	msg += HIC"��ϯ�������$n����һ�ܣ���$N������·��$nֻ��סһ����\n"NOR;
	message_combatd(msg, me, target);

	for(count=0;count<5;count++)
	{
		if (flag == 1)target = offensive_target(me);
		if (!objectp(target)) break;
 		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
 	}
	me->add("neili", -100);
	me->start_busy(random(5));
	if(!target->is_fighting(me)) target->fight_ob(me);
	return 1;
}
string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		���������嵶

	����Ҫ��
		�ټ�ʮ��ׯ90��
		���е���60��
		����300
HELP
	);
	return 1;
}


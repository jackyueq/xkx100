// yuyin.c ��������
// Last Modified by winder on Aug. 13 2000

#include <ansi.h>
#define PNAME "������������"
inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon;
	string msg;
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
		return notify_fail("��ʹ�õ��������ԡ�\n");
		
	if( target->is_busy() )
		return notify_fail(target->name()+"Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");

	fskill = "baiyun-xinfa";
	bskill = "sword";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 140 )
		return notify_fail("���"+to_chinese(fskill)+"��򲻹���ʹ����"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 140 )
		return notify_fail("���"+to_chinese(sskill)+"����죬ʹ����"+PNAME+"��\n");

	if( (int)me->query("neili") < 300 )
		return notify_fail("�����������������ʹ��"PNAME"��\n");

	msg = HIG"$N"HIG"ʹ���������������������н�����$n"HIG"�����ϣ�������ת�����಻����ʹ$n"HIG"һʱ�޷����С�\n";

	me->add("neili", -200);

	if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/3)
	{
		msg += HIR "���$p��$P�ָ���æ���ң�����ʧ�룬���ڵ�������֪���Ӧ�ԣ�\n" NOR;
		target->start_busy((int)me->query_skill(bskill, 1)/30);
	} else {
		msg +=HIY"����$p������$P����ͼ������㣬һ������$P�Ľ���ȫ��Ӧ�����硣\n" NOR;
		me->start_busy(1);
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
		���ͶԷ�����

	����Ҫ��
		�����ķ�50��
		��ɽ����40��
		����300
HELP
	);
	return 1;
}


// menda.c  �������ƴ�
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

inherit F_SSERVER;
#define PNAME "��"+HIC"��"NOR+HIG"��"NOR+HIY"��"NOR+HIR"��"NOR+"��"
int perform(object me, object target)
{
	int damage;
	string msg;
	int flag;
	object weapon;
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
		(string)weapon->query("skill_type") != "club")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	bskill = "club";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(bskill, 1) < 188 )
		return notify_fail("���"+to_chinese(fskill)+"̫�ˣ�ʹ����"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 188 )
		return notify_fail("���"+to_chinese(sskill)+"��������������ʹ��"+PNAME+"��\n");

	if( (int)me->query("neili") < 500 )
		return notify_fail("���������Ϊ�������ߡ�\n");

	msg = HIW "$NͻȻ�����ˣ�$n"HIW"���ɻ�㶼䣬ȴ��$N��Ȼת��ʩչ����"+HIC"��"NOR+HIG"��"NOR+HIY"��"NOR+HIR"��"NOR+"����"+HIW"�������»������߼䣬������Ӱ��ѹ��ɵ����ǵ�$n"HIW"��\n"NOR;

	if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/5)
	{
		me->start_busy(1);
		target->start_busy(random(8));

		damage= (int)me->query_skill(bskill, 1)*5;
		damage = damage + random(damage);

		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage/2);
		me->add("neili", -500);
		msg += HIR"
$nֻ�����춼����Ӱ�������޴��мܣ�ֻ�а���ķݶ������ÿһ�ȶ������У�ֱ�����ͷѪ��������Ѫ���������������౻�ش�����Ѫ����������������ݣ��ۿ���Ҫˤ���ڵأ�����\n"NOR;
	} else
	{
		me->start_busy(1);
		msg += HIG"����$p������$P����ͼ����æ��ͷ��ܰ�������һ�ߡ�\n"NOR;
	}
	message_combatd(msg, me, target);

	return 1;
}

int help(object me)
{
	write(WHT"\n���Ź�֮�����ƴ�"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		���˶Է���Ѫ
		���ͶԷ�����

	����Ҫ��
		���Ź�188��
		�����ȷ�188��
		����500
HELP
	);
	return 1;
}


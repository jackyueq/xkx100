// 2wu.c ������ɫ
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit F_SSERVER;
#define PNAME "��������ɫ��"
int perform(object me,object target)
{
	string msg;
	object weapon1, weapon2;
	int skill, ap, dp, neili_wound, qi_wound;
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
		
	if( !objectp(weapon1 = me->query_temp("weapon")) ||
		(string)weapon1->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
/*	if( !objectp(weapon2 = me->query_temp("secondary_weapon"))
		|| (string)weapon2->query("skill_type") != "sword")
		return notify_fail("������ʹ�õ��������ԡ�\n");
*/
	fskill = "xuantian-wuji";
	bskill = "sword";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 100 )
		return notify_fail("���"+to_chinese(fskill)+"��Ϊ����������ʹ��"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 120 )
		return notify_fail("���"+to_chinese(sskill)+"��Ϊ����������ʹ��"+PNAME+"��\n");

	if( (int)me->query_skill(bskill, 1) < 100 )
		return notify_fail("���"+to_chinese(bskill)+"��Ϊ������ʹ����"+PNAME+"��\n");

	if( me->query_skill("dodge", 1) < 80)
		return notify_fail("������Ṧ��Ϊ������ʹ����"PNAME"��\n");

	if( me->query("neili") < 250 )
		return notify_fail("��������������޷�����"PNAME"��\n");

	if( me->query("max_neili") < 500 )
		return notify_fail("���������Ϊ�������޷�����"PNAME"��\n");
	
	skill = me->query_skill(bskill,1);

	msg = HIB "$N����һ������ͻȻʹ��һ�С�������ɫ��������"+weapon1->name()+HIB"��ע������ͬ�ھ��� ������ǡǡ�෴�����������ĵ���֮�����ƿ�֮����һ���໥������������Ϣ����$n�����ȥ��\n";
	message_combatd(msg, me, target);

	ap = skill * 3;
	dp = target->query_skill("force", 1) * 2;
	if( dp < 1 ) dp = 1;
	if( random(ap) > random(dp) )
	{
		if(userp(me)) me->add("neili", -250);//400
		msg = HIR "$nͻ�����л���֮�������޴����ܣ�\n" NOR;
		qi_wound = skill * 2;
		qi_wound = qi_wound + random(qi_wound);
//	target->receive_damage("qi", qi_wound/3);
		target->receive_damage("qi", qi_wound*3/4);
		target->receive_wound("qi", qi_wound/3);
		target->start_busy(2);
		me->start_busy(1+random(2));
	}
	else
	{
		me->add("neili", -100);
		msg = HIY"$n"HIY"�͵�һ�ݶ���ֻ��һ�����죬���գ������������$N"HIY"�Ľ��⻮���ˡ�\n"NOR;
		me->start_busy(2+random(1));
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
		���˶Է���Ѫ

	����Ҫ��
		�����޼���100��
		���ǽ���120��
		��������100��
		�����Ṧ80��
		������Ϊ500
		����250
		
HELP
	);
	return 1;
}


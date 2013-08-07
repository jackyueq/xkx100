// cixin.c  ��а���������ġ�
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#define PNAME "�����ġ�"
inherit F_SSERVER;
int perform(object me, object target)
{
	int damage;
	string msg;
	object weapon;
	int flag;
	string fskill,sskill,bskill,pfname;

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
		
	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��Ҫʹ��"PNAME"��������ȻҪ�н���\n");

	fskill = "kuihua-xinfa";
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
		return notify_fail("���"+to_chinese(fskill)+"��򲻹���ʹ����"+PNAME+"��\n");
	if( (int)me->query_skill(sskill, 1) < 180 )
		return notify_fail("���"+to_chinese(sskill)+"������죬ʹ����"+PNAME+"��\n");
	if ((int)me->query("max_neili") < 1000)
		return notify_fail(RED"��������Ϊ���㣬�޷�����������\n"NOR);
	if ((int)me->query("neili") < 600)
		return notify_fail("����������������û�ܽ�"PNAME"ʹ�꣡\n");

	msg = HIC "ͻȻ֮�䣬$N"HIC"һ����ȣ�"+weapon->name()+HIC"������ǰ��ֱ��$n"HIC"�Ŀڣ�\n"NOR;

	if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/4)
	{
		me->start_busy(2);
		me->add("neili", -500);
		target->start_busy(random(3));
		damage = (int)me->query_skill(bskill, 1);
		damage = damage + random(damage);
		target->receive_damage("qi",damage+random(damage/2),me);
		target->receive_wound("qi", damage,me);
    target->receive_damage("jing",damage/3+random(damage/3),me);
		target->receive_wound("jing", damage/3,me);
		msg += HIC "$n"HIC"��֮�£�æ�����мܣ����ﻹ���ü���߲��һ���������Ѵ���$n"HIC"�Ŀڡ�\n"NOR;
		message_combatd(msg, me, target);
	} else
	{
		me->start_busy(2);
		me->add("neili", -300);
		msg += HIY"$n"HIY"�鼱������̧��Ҳ��$N"HIY"�Ŀڴ�ȥ���ȵ�$P�ؽ�Ծ����\n"NOR;
		message_combatd(msg, me, target);
	}
	if(!target->is_fighting(me)) target->fight_ob(me);
	return 1;
}
string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		ʩ�д̶Է����Ŀ�
		����Ϊ��а��������֮����ն���
		���˶Է���Ѫ�;���

	����Ҫ��
		��а����180��
		�����ķ�100��
		�������1000
		����600
HELP
	);
	return 1;
}


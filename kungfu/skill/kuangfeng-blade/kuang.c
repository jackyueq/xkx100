//kuang.c -������ʮһʽ��
// Last Modified by winder on Mar. 10 2000
#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
#define PNAME "������ʮһʽ��"
int perform(object me, object target)
{
	int damage;
	object weapon;
	string msg;
	int flag;
	string fskill,sskill,bskill,pfname,pskill;

	sskill = explode(__FILE__,"/")[<2];
	pfname = explode(__FILE__,"/")[<1][0..<3];
/*  if (userp(me) && !wizardp(me) &&
   !me->query("perform/"+pfname) &&
   !me->query("can_perform/"+sskill+"/"+pfname) &&
   !me->query_temp("murong/xingyi") &&
   !SCBORN_D->valid_perform(me,sskill,pfname))
   return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");
*/
	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "blade")
		return notify_fail("�������ȥ��һ�ѵ���\n");

	bskill = "blade";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}


	if( (int)me->query_skill(sskill, 1) < 70 )
		return notify_fail("���"+to_chinese(sskill)+"��������죬�޷�ʹ��"+PNAME+"��\n");

	if( (int)me->query("neili") < 400 )
		return notify_fail("�������������\n");

	msg = HIC"$N"HIC"��ȻһЦ�����Ϳ�ݾ��׵ĵ�����Ȼ��ø���������������һ˲֮�䣬"+ "$N��������ʮһ�����������ŷ磬���ﺬ�ŵ�Ӱ��$n"HIC"ֻ����������ֹͣ�ˣ�\n"NOR;
	me->start_busy(2);

	if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/2)
	{
		damage = random(me->query_skill(bskill, 1) * 2);
		me->add("neili", -300);
		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage/2,me);
		msg += RED "ֻ��$n"HIC"�ѱ�$N"HIC"�е����������Ѫ�������ȫ�����������\n"NOR;
	} else {
		msg += HIC "����$p��æ����㿪��$P����û�еóѡ�\n" NOR;
	}
	message_combatd(msg, me, target);
	if(userp(target)) target->fight_ob(me);
	else if( !target->is_killing(me) ) target->kill_ob(me);

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
		��絶��70��
		����400
HELP
	);
	return 1;
}


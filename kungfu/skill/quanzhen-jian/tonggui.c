// tonggui.c ȫ�潣�� ͬ�齣��
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
#define PNAME "��ͬ�齣����"
int perform(object me, object target)
{
	object weapon;	
	string msg;
	int d_count, count, qi, maxqi, skill,damage;
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

	if( !objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "sword")
		return notify_fail("û�н�������ô����ͬ�齣����\n");
		
	fskill = "xiantian-qigong";
	bskill = "sword";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 10 )
		return notify_fail("���"+to_chinese(fskill)+"��Ϊ����������ʹ"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 150 )
		return notify_fail("���"+to_chinese(sskill)+"��Ϊ̫ǳ��δ���"+PNAME+"��\n");

	if( (int)me->query("neili") < 500 )
		return notify_fail("���������������\n");

	qi = me->query("qi");
	maxqi = me->query("max_qi");
	if(qi > (maxqi * 0.4))
		return notify_fail("�����ڵ�����״���޷�����ͬ�齣����\n");

	skill = (int) (me->query_skill(bskill, 1) / 3);
	count = me->query_str();
	d_count = (int)me->query_dex() / 2;

	msg = HIY"$Nʹ����ͬ�齣�����������ݺᣬֻ�����أ�����ƴ�����׺�Σ��֮����\n" NOR;
	if ( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 )
	{
		me->start_busy(2);
		target->start_busy(random(3));
		damage = target->query("qi");
		target->receive_damage("qi", damage-10,me);
		target->receive_wound("qi", damage-10,me);
		msg += HIC "$n��æбԾ����������磬ֻ��һ�����ľ�ʹ������������ǰ����Ѫ�ɽ���\n"NOR;
		me->set("neili",0);
	}
	else
	{
		me->start_busy(2);
		me->set("neili",100);
		msg += HIY"����$n΢΢һЦ���������У�������䣬�������С�\n"NOR;
	}

	message_combatd(msg, me, target);
	if(userp(target)) target->fight_ob(me);
	return 1;
}
string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		�ľ�ȫ������������һ��

	����Ҫ��
		��������100��
		ȫ�潣��150��
		����500
HELP
	);
	return 1;
}


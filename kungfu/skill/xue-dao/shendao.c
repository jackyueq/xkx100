// shendao.c  Ѫ������Ѫ�񵶡�

#include <ansi.h>

inherit F_SSERVER;
#define PNAME "����Ѫ�񵶡�"
int perform(object me, object target)
{
	int damage, power;
	string msg;
	object weapon;
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
		(string)weapon->query("skill_type") != "blade")
		return notify_fail(RED"װ��������ʹ��"PNAME"��\n"NOR);

	fskill = "longxiang";
	bskill = "blade";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 60 )
		return notify_fail("���"+to_chinese(fskill)+"��򲻹���ʹ����"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail("���"+to_chinese(sskill)+"������죬ʹ����"+PNAME+"��\n");

	if ((int)me->query("max_neili") < 600)
		return notify_fail(RED"��������Ϊ���㣬�޷�����������\n"NOR);

	if ((int)me->query("neili") < 600)
		return notify_fail(HIC"����������������û�ܽ�����Ѫ�񵶡�ʹ�꣡\n"NOR);

	msg = HIR"$N���ֳֵ������һ�գ�һ��Ѫ�齦�����棬�������ұ��ճ���һƬ
Ѫ���ס��Ӱ��$n��ͷ���䣬\n"NOR;
	if ( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 )
	{
		if ((int)me->query("shen") <= -100000) power = -100000;
		else if ((int)me->query("shen") < -1000 && 
			(int)me->query("shen")>-100000)
			power = (int)me->query("shen");
		else power = -1000;

		damage =random((int)(power/-100))+(int)(power/-200);
		me->add("neili", -600);
		me->receive_wound("qi", me->query("qi")/10);
		me->start_busy(3);
		target->start_busy(random(3));
		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage/2,me);
msg += HIR"$n��æ������ã���Ѫ��������ֻ����ǰһ��Ѫ�죬����������£���Ѫ��
���������󺿣�\n"NOR;
	} else
	{
		me->start_busy(2);
		me->receive_wound("qi", me->query("qi")/20);
msg += HIY"����$n������ã����Ų�æ�������$N��Ѫ����\n"NOR;
		me->add("neili", -200);
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
		���˼���������
		���˶Է���Ѫ

	����Ҫ��
		���������60��
		Ѫ������100��
		����600
HELP
	);
	return 1;
}


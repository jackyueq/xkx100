// zhen.c ̫��ȭ�����־�
// Last Modified by suncity on JUN. 5 2002

#include <ansi.h>

inherit F_SSERVER;
#define PNAME "�����־�"
int perform(object me, object target)
{
	int damage;
	string msg;
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
		
	if( objectp(me->query_temp("weapon")) )
		return notify_fail("�������ֲ���ʹ�á����־���\n");

	fskill = "taiji-shengong";
	bskill = "unarmed";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 30 )
		return notify_fail("���"+to_chinese(fskill)+"�����ߣ��������������˵С�\n");

	if( (int)me->query_skill(sskill, 1) < 30 )
		return notify_fail("���"+to_chinese(sskill)+"������죬ʹ����"+PNAME+"��\n");

	if( (int)me->query("neili", 1) < 100 )
		return notify_fail("����������̫��������ʹ�á����־���\n");

	msg = CYN "$N"CYN"Ĭ���񹦣�ʹ��̫��ȭ�����־�����ͼ����������$n��\n"NOR;

	if (random(me->query_skill("force")) > target->query_skill("force")/4 )
	{
		me->start_busy(3);
		target->start_busy(random(3));

		damage = (int)me->query_skill("force", 1);
		damage = damage + (int)me->query_skill(bskill,1);
		
		damage = damage/2 + random(damage);

		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage/3,me);
		me->add("neili", -damage/5);

		if( damage < 60 )
			msg += HIY"���$n�ܵ�$N�����������ƺ�һ����\n"NOR;

		else
			if( damage < 80 )msg += HIY"���$n��$N���������𣬡��١���һ������������\n"NOR;
			else if( damage < 160 ) msg += RED"���$n��$N������һ���ؿ������ܵ�һ���ش�����������������\n"NOR;
				else msg += HIR"���$n��$N������һ����ǰһ�ڣ��������ɳ�������\n"NOR;

	} else
	{
		me->start_busy(1);
		msg += CYN"����$p������$P����ͼ����û���ϵ���\n"NOR;
                me->add("neili", -50);
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
		̫����30��
		̫��ȭ30��
		����100
HELP
	);
	return 1;
}


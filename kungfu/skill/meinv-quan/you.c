// you.c ��Ůȭ-��Ĺ�ľ�
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

inherit F_SSERVER;
#define PNAME "����Ĺ�ľӡ�"
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
		return notify_fail("������ȷ������еı�����\n");

	fskill = "yunv-xinfa";
	bskill = "unarmed";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 40 )
		return notify_fail("���"+to_chinese(fskill)+"��δ��죬����ʹ��"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 50 )
		return notify_fail("���"+to_chinese(sskill)+"���𲻹�������ʹ��"+PNAME+"��\n");

	if( (int)me->query("neili", 1) < 150 )
		return notify_fail("����������̫��������ʹ�ù�Ĺ�ľӡ�\n");

	msg = HIW"$N"HIW"����֧�ã���������ӳ�����̾һ����ʹ������Ĺ�ľӡ������ּ���֮�⡣\n"NOR;

	if (random(me->query_skill(bskill)) > target->query_skill("force")/3 )
	{
		me->start_busy(random(3));
		damage = (int)me->query_skill("force", 1) + (int)me->query_skill(bskill, 1);
//		damage=damage/2;
		damage = damage/2 + random(damage/2) + random(damage/4);

		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage/3,me);
		target->start_busy(3);
		me->add("neili", -100);

		if( damage < 30 )
			msg += HIY"���$n"HIY"��$N"HIY"����һ�����ƺ�һ����\n"NOR;
		else if( damage < 55 )
			msg += HIY"���$n"HIY"��$N"HIY"������һ���������ڡ����˳�������\n"NOR;
		else if( damage < 80 )
			msg +=RED"���$n"HIY"��$N"HIY"������һ�����ؿ������ܵ�һ���ش�����ѪΪ֮һ�ϣ�\n"NOR;
		else
			msg +=HIR"���$n"HIY"��$N"HIY"������һ������ǰһ�ڣ�������Ѫ���ڣ����������¯һ�㣡\n"NOR;
	}
	else
	{
		me->start_busy(3);
		msg += CYN"����$p������$P����ͼ����Ȼ����̩ɽ��̧��һ�ܸ񿪡�\n"NOR;
	}
	message_combatd(msg, me, target);
	return 1;
}
string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		���˶Է���Ѫ
		���ͶԷ�����

	����Ҫ��
		��Ů�ķ�40��
		��Ůȭ50��
		����150
HELP
	);
	return 1;
}


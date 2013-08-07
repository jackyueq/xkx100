// throw.c �����ȷ��綾
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

inherit F_SSERVER;
#define PNAME "�綾"

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
   !SCBORN_D->valid_perform(me,sskill,pfname))
   return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
//	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
  	return notify_fail("��Ҫ��˭�綾? \n");

	if( environment(me)->query("no_fight") )
		return notify_fail("���ﲻ�ܹ������ˣ�\n");
  notify_fail("�㲻�ܹ�������ˡ�\n");
	if (!userp(target) && !target->accept_hit(me)) return 0;
	
	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "staff")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	fskill = "hamagong";
	bskill = "staff";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 40 )
		return notify_fail("���"+to_chinese(fskill)+"������죬����"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 40 )
		return notify_fail("���"+to_chinese(sskill)+"������죬����"+PNAME+"��\n");

	if( (int)me->query("neili", 1) < 400 )
		return notify_fail("������������������綾��\n");

	if( (string)weapon->query("id") != "she zhang" )
		return notify_fail("������û�����ȣ������綾��\n");

	me->add("neili", -200);

	msg = MAG "$N"MAG"��䷢���̶��ĸ�����죬����ǰͷ��С���͵���ͷ��һ��ۺ춾�������������$n"MAG"��\n";

	me->start_busy(1);

	if( random( (int)me->query_skill(bskill, 1)) >
		random(target->query_skill("dodge", 1)) )
	{
		msg += MAG "���$p��$P��ͷС��һ�����У�\n" NOR;
		if (target->query("neili") < me->query("neili"))
		{
			msg += MAG "$pֻ�ŵ�һ�����㣬��ǰ��ģ��������\n" NOR;
			target->receive_damage("qi",(int)me->query_skill("staff", 1),me);
			target->receive_wound("qi",15 + random(10),me);
			target->receive_wound("jing", 10,me);
			target->apply_condition("snake_poison", random(me->query_skill(bskill, 1)/10) + 1 + target->query_condition("snake_poison"));
			target->start_busy(1 + random(2));
		}
		else
		{
			msg += CYN "$p����������һ���������߶���ȥ����ʱ�߶�����$PƮ�˻�ȥ��\n" NOR;
			msg += MAG "$Pֻ�ŵ�һ�����㣬��ǰ��ģ��������\n" NOR;
			me->receive_damage("qi", me->query_skill(bskill, 1),target);
			me->receive_wound("qi", 15 + random(10),target);
			me->receive_wound("jing", 10,target);
			me->apply_condition("snake_poison", random(me->query_skill(bskill, 1)/10) + 1 +
			me->query_condition("snake_poison"));
			me->start_busy(1 + random(2));
		}
	} else {
		msg += CYN"����$p��æ����һ�ԣ����˿�ȥ��\n" NOR;
		me->start_busy(3);
	}
	message_combatd(msg, me, target);
	if( !target->is_killing(me) ) target->kill_ob(me);
	return 1;
}
string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		�˺��Է�����
		ʹ�������߶�
		���书���������ܷ����亦

	����Ҫ��
		��󡹦40
		�����ȷ�40
		�ֳ�����
		����400
HELP
	);
	return 1;
}

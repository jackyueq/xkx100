// Last Modified by winder on Sep. 12 2001
// zhuihun.c һ��׷��

#include <ansi.h>;
inherit F_SSERVER;
#define PNAME "һ��׷��"
int perform(object me, object target)
{
	object weapon;
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
		
	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	fskill = "honghua-shengong";
	bskill = "sword";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 120 )
		return notify_fail("���"+to_chinese(fskill)+"�����ߣ�����ʹ��"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 120 )
		return notify_fail("���"+to_chinese(sskill)+"������죬����ʹ��"+PNAME+"��\n");

	damage = (int)me->query_skill("force", 1);
	damage += (int)me->query_skill(bskill, 1)*3/2;

	if( (int)me->query("max_neili") < damage + 100)
		return notify_fail("���������Ϊ̫����ʹ������һ��׷�꡹��\n");

	if( (int)me->query("neili") < damage )
		return notify_fail("����������̫��������ʹ�á�һ��׷�꡹��\n");
			
	msg = CYN "$N΢΢һЦ������һ����������Ծ��"+weapon->name()+CYN"���޳�������������$n��\n"NOR;

	if (random(me->query_skill("force")) > target->query_skill("force")/5 )
	{
		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage/2,me);
		me->add("neili", -(damage/4));
		msg += HIR "$nֻ��������ҹĻ������ǵذ�ѹ����һʱ����ǰһ���������������޴��мܣ���\n"NOR;
		me->start_busy(1);
	} else 
	{
		msg += CYN"����$p�������죬����Ծ����$P�Ľ�����\n"NOR;
		me->add("neili", -100);
		me->start_busy(1+random(1));
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
		�˺��Է���Ѫ

	����Ҫ��
		�컨��120��
		׷�������120��
		�㹻��������Ϊ
		�㹻������
HELP
	);
	return 1;
}


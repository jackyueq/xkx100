// xian.c  ��������
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

inherit F_SSERVER;
#define PNAME "���������֡�"
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

	fskill = "yunlong-shengong";
	bskill = "sword";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 50 )
		return notify_fail("���"+to_chinese(fskill)+"�����ߣ�������"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 50 )
		return notify_fail("���"+to_chinese(sskill)+"������죬����ʹ��"+PNAME+"��\n");

	if( (int)me->query("neili", 1) < 300 )
		return notify_fail("����������̫��������ʹ�á��������֡���\n");

	msg = CYN "$N΢΢һЦ������һ��������ʹ������Ԧ����������$n��\n"NOR;


	if (random(me->query_skill("force")) > target->query_skill("force")/5 )
	{
		if (!target->is_busy())
		target->start_busy( (int)me->query_skill(bskill, 1) / 30 + 1);

		damage = (int)me->query_skill("force", 1);
		damage +=  2 * (int)me->query_skill("sword", 1);

		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage/2,me);
		me->add("neili", -damage/2);
		msg += HIY "ֻ��$N���н������һ���������ڿն���ٿ������$n"HIY"��$n"HIY"ֻ��һ�ɴ�������ǵذ�ѹ������ʱ��ǰһ���������������۵����һ��"HIR"��Ѫ����\n"NOR;
		me->start_busy(2);
	} else 
	{
		msg += CYN"����$p�͵����һԾ��������$P�Ĺ�����Χ��\n"NOR;
		me->add("neili", -100);
		me->start_busy(4);
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
		������50��
		��������50��
		����300
HELP
	);
	return 1;
}


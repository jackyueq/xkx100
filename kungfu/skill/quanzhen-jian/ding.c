// ding.c ȫ�潣-������
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

inherit F_SSERVER;
#define PNAME "������"
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

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
		
	fskill = "yunv-xinfa";
	bskill = "sword";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 40 &&
		  (int)me->query_skill("xiantian-qigong", 1) < 40 &&
			(int)me->query_skill("yunv-xinfa", 1) < 40 )
		return notify_fail("����ڹ�������죬����ʹ��"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 40 )
		return notify_fail("���"+to_chinese(sskill)+"������죬����ʹ��"+PNAME+"��\n");

	if( (int)me->query("neili", 1) < 150 )
		return notify_fail("����������̫��������ʹ�ö����롣\n");

	msg = HIC "$N�������Ž���������̤��һ�С������롱����б�̣�"
	     +weapon->name()+HIC"��ȻԾ����ٿ�Ļ��������ǹ⣬����$n��\n"NOR;
// "$N�������Ҽ�����������������������һʽ�������롹бб�̳���\n"NOR;

	if (random(me->query_skill("force")) > target->query_skill("force")/2 )
	{
		me->start_busy(2);
		damage = (int)me->query_skill("sword", 1) + (int)me->query_skill("force",1);
		damage = damage/2 + random(damage/2);

		target->receive_damage("qi", damage,me);
		target->start_busy(4);
		me->add("neili", -100);

		msg += HIR"$n����$N������ǧ����һ��������֪����мܣ�\n"NOR;

	}
	else
	{
		me->start_busy(3);
		msg += CYN"����$p������$P����ͼ��бԾ�ܿ���\n"NOR;
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
		������������Ů�ķ�40��
		ȫ�潣��40��
		����150
HELP
	);
	return 1;
}


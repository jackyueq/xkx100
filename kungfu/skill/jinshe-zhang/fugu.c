s// fugu.c ����������-���ǲ���
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

inherit F_SSERVER;
#define PNAME "�����ǲ���"
int perform(object me, object target)
{
	object weapon;
	int damage;
	string msg;
	int i;
	int flag;
	string fskill,sskill,bskill,pfname,pskill;

	sskill = explode(__FILE__,"/")[<2];
	pfname = explode(__FILE__,"/")[<1][0..<3];
  if (userp(me) && !wizardp(me) &&
//   !me->query("perform/"+pfname) &&
   !me->query("can_perform/"+sskill+"/"+pfname) &&
   !me->query_temp("murong/xingyi") &&
   !SCBORN_D->valid_perform(me,sskill,pfname) )
   return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"ֻ�ܶ�ս���еĶ���ʹ�á�\n");
		
	if( me->query_temp("weapon"))
		return notify_fail("�㲻�ǿ��֣�����ʹ��"PNAME"��\n");

	bskill = "strike";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail("���"+to_chinese(sskill)+"������죬����ʹ��"+PNAME+"��\n");

	if( (int)me->query("neili", 1) < 300 )
		return notify_fail("����������̫��������ʹ�ø��ǲ���\n");

	msg = HIC "$N���һ���������������һ̽��ס$n"HIC"������������ɱ�֣�\n"NOR;
	message_combatd(msg, me, target);


	if(random(me->query_skill(bskill,1))>target->query_skill("dodge",1)/2)
	{
		for (i=0;i<3;i++)
		{
			if (flag == 1) target = offensive_target(me);
			if (objectp(target))
				COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
		}
		me->add("neili", -50);
		me->start_busy(2+random(2));
		msg=HIR"���$n��$N���������ƣ��ڡ����ǲ����£���Ȼ�޷����֣�\n"NOR;
	}
	else
	{
		me->start_busy(3);
		msg=CYN"����$pʶ����$P��һ�У�����һ�ͣ������˶Է����ơ�\n"NOR;
	}
	message_combatd(msg, me, target);
	if( !target->is_fighting(me) ) target->fight_ob(me);

	return 1;
}
string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}
int sp() {return 1;}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		������������

	����Ҫ��
		����������100��
		����300
HELP
	);
	return 1;
}


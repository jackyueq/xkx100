// xunlei.c
// Last Modified by winder on Feb. 28 2001

#include <ansi.h>;
#include <combat.h>;
#define PNAME "��Ѹ�ס�"
inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;
	int i, j, z;
	object weapon;
	int flag;
	string fskill,sskill,bskill,pfname,pskill;

	sskill = explode(__FILE__,"/")[<2];
	pfname = explode(__FILE__,"/")[<1][0..<3];
  if (userp(me) && !wizardp(me) &&
   !me->query("perform/"+pfname) &&
   !me->query("can_perform/"+sskill+"/"+pfname) &&
   !me->query_temp("murong/xingyi") &&
   !SCBORN_D->valid_perform(me,sskill,pfname) )
   return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"ֻ�ܶ�ս���еĶ���ʹ�á�\n");
		
	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("�������ʹ�ý�ʱ����ʹ��"PNAME"��\n");

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

	if( (int)me->query_skill(fskill, 1) < 160 )
		return notify_fail("���"+to_chinese(fskill)+"��Ϊ������ʹ����"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 160 )
		return notify_fail("���"+to_chinese(sskill)+"������죬ʹ����"+PNAME+"��\n");

	if( (int)me->query_str() < 32)
		return notify_fail("���������������ʹ������Ѹ�ס���\n");

	if( (int)me->query_dex() < 30)
		return notify_fail("�������������ʹ������Ѹ�ס���\n");

	if( (int)me->query("max_neili") < 1800 )
		return notify_fail("����������̫����ʹ������Ѹ�ס���\n");

	if( (int)me->query("neili") < 900 )
		return notify_fail("����������̫����ʹ������Ѹ�ס���\n"); 

	j = me->query_skill(bskill, 1);
	z = me->query_skill("force", 1);
 
	me->add_temp("apply/damage", z/8);
	me->add_temp("apply/dodge",-j/10);
	me->add_temp("apply/attack", j/6); 
 
	msg = BLU"\n$N�����е�"+weapon->name()+BLU"������$nһѹ����Ȼ����һ���� һ����Ϊ�Ľ������籼�׳��繥��$n��\n\n"NOR;
	message_combatd(msg, me, target);
	for (i=0;i<4;i++)
	{
		if (flag == 1) target =  offensive_target(me);
		if (!objectp(target)) break;
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	}

	me->add("neili",-j*2);
	me->add_temp("apply/damage", -z/8);
	me->add_temp("apply/dodge", j/10);
	me->add_temp("apply/attack", -j/6);

	me->start_busy(random(3)+1);
	return 1;
}

string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		�����ؽ�����

	����Ҫ��
		��Ů�ķ�160��
		��������160��
		������Ϊ1800
		����900
		��������32
		������30
HELP
	);
	return 1;
}


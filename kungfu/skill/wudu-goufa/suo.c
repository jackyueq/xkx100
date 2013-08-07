// suo.c ������
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
#define PNAME "������"
int perform(object me, object target)
{
	object ob,weapon,myweapon;
	string msg, string1;
	int skill,myskill,attack_time,i;
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
	|| (string)weapon->query("skill_type") != "hook")
		return notify_fail(PNAME"��ʼʱ��������һ�ѹ���\n");

	if (!objectp(weapon = target->query_temp("weapon")))
		return notify_fail("�Է����в�û�б�����\n");

	fskill = "wudu-shengong";
	bskill = "hook";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 50 )
		return notify_fail("���"+to_chinese(fskill)+"�������ң�ʹ����"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 50 )
		return notify_fail("���"+to_chinese(sskill)+"�������ң�ʹ����"+PNAME+"��\n");

	if( (int)me->query_skill(bskill, 1) < 50 )
		return notify_fail("���"+to_chinese(bskill)+"�������ң�ʹ����"+PNAME+"��\n");

	if( (int)me->query("neili") < 500 )
		return notify_fail("�������������\n");

	weapon=target->query_temp("weapon");
	myweapon=me->query_temp("weapon");
	message_combatd(HIR"\n$N���һ�У�����"+myweapon->query("name")+HIR"����һ���������Ѵ���$n��"+weapon->query("name")+HIR"�ϣ�\n" NOR,me,target);
	skill = target->query_skill("parry", 1);
	myskill = me->query_skill(bskill, 1);
	if(random(myskill) < random(skill)||me->query("max_neili") <random(target->query("max_neili")))
	{
		msg = HIY "����$n"HIY"����׼������æ����������\n" NOR;
		message_combatd(msg, me,target);
		me->start_busy(2);
		me->add("neili",-100);
		return 1;
	}

	msg = HIR"ֻ��$N˳��һ�ʣ��ͺ�һ���������֣���$nֻ���û���һ���ʹ��\n����"+weapon->query("name")+HIR"���һ�����ڵ��ϣ�\n" NOR;
	msg += "$N����һЦ���������ˣ����н��ƣ�\n" NOR;
	message_combatd(msg, me,target);
	weapon->move(environment(me));

	attack_time = 3 + random(3);
	for(i = 0; i < attack_time; i++)
		COMBAT_D->do_attack(me,target,me->query_temp("weapon"),0);
	target->start_busy(random(2));
	me->add("neili", -450);
	me->start_busy(2);
	return 1;
}

string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		���������平
		����Է�����

	����Ҫ��
		�嶾��50��
		��������50��
		�嶾����50��
		����500
		ʹ���嶾�̵Ĺ�
HELP
	);
	return 1;
}


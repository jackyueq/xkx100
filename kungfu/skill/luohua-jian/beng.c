// Last Modified by winder on Sep. 12 2001
// beng.c ���־�

#include <ansi.h>;
inherit F_SSERVER;
#define PNAME "�������־�"
int perform(object me,object target)
{
	object weapon, weapon2;
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

	if(!objectp(weapon = me->query_temp("weapon")) ||
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

	if( (int)me->query_skill(fskill, 1) < 80 )
		return notify_fail("���"+to_chinese(fskill)+"�������ң��޷�ʹ��"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 80 )
		return notify_fail("���"+to_chinese(sskill)+"�������ң��޷�ʹ��"+PNAME+"��\n");

	if( (int)me->query("max_neili") < 600 )
		return notify_fail("���������Ϊ������\n");

	if( (int)me->query("neili") < 500 )
		return notify_fail("�������������\n");

	if(!objectp(weapon2 = target->query_temp("weapon")))
		return notify_fail("�Է�û���ñ��У����ò��ˡ������־���\n");

	msg = HIY "$N��ס���Σ���������������һ�ᣬʹ���仨���������־���\n"NOR;
	message_combatd(msg, me);
	
	if ( random(me->query("str")) > (int)target->query("str")/2 &&
		me->query("combat_exp") > (int)target->query("combat_exp")/4*3 )
	{
		msg = HIY"$n"HIY"ֻ���û��ھ�ʹ������";
		msg += weapon2->name();
		msg += HIY"��ʱ����ס���ַ��˳�ȥ��\n" NOR;
		me->add("neili", -150);
		target->start_busy(2);
		weapon2->move(environment(me));
	}
	else
	{
		me->add("neili",-50);
		msg = HIY"����$n"HIY"������$N"HIY"����ͼ���������ϼӾ�����" + weapon2->name() + HIY"��������һ����\n˫�����е�����һ��,�������ķ���һ�����졣\n"NOR;
		me->start_busy(2);
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
		����Է�����

	����Ҫ��
		�컨��80��
		�仨ʮ����80��
		������Ϊ600
		����500
HELP
	);
	return 1;
}


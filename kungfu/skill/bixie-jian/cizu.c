// cizu.c ����
// Last Modified by winder on Oct. 28 2000

#include <ansi.h>
#define PNAME "�����㡹"
inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;
	object weapon;
	int flag;
	string fskill,sskill,bskill,pfname;

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
		
	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "sword")
		return notify_fail(HIY "û������ʲô����ȥ���˼ң�\n" NOR);

	fskill = "kuihua-xinfa";
	bskill = "sword";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}
	if( (int)me->query_skill(fskill, 1) < 100 )
		return notify_fail("���"+to_chinese(fskill)+"��򲻹���ʹ����"+PNAME+"��\n");
	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail("���"+to_chinese(sskill)+"��������������ʹ��"+PNAME+"��\n");
	if((int)me->query("max_neili") < 500)
		return notify_fail(HIY "���������Ϊ���������\n" HIY);
	if((int)me->query("neili") < 300)
		return notify_fail(HIY "�������������㡣\n" HIY);
	if (target->query_temp("bixie/cizu"))
		return notify_fail(HIR"�Է��Ѿ�����"PNAME"�ˣ�\n"NOR);

	msg = HIC "$N"HIC"ͻȻǰ��һ̽��"+weapon->name()+HIC"������׷�£�Ѹ���쳣������$n"HIC"���ף�\n"NOR;
	if (random(me->query_dex()) > target->query_dex()/2)
	{
		msg += HIC"$n"HIC"ֻ���ý���һʹ��һ���ӣ����ڵ��£�\n"NOR;
		message_combatd(msg, me, target);
		me->add("neili", -250);
		target->set_temp("bixie/cizu", 1);
		call_out("cizu_end", (int) 4+random(6), me, target);
	} else
	{
		me->add("neili", -100);
		me->start_busy(2);
		msg += HIY"$n"HIY"��æһ̧�ȣ�ǡǡ�ܹ���$N"HIY"�ĳ���һ����\n"NOR;
		message_combatd(msg, me, target);
	}
	if(!target->is_fighting(me)) target->fight_ob(me);
	return 1;
}

void cizu_end(object me, object target)
{
	message_combatd(HIR"$Nǿ�̽��Ͼ�ʹ�����ڲ���ΡΡ��վ��������\n"NOR, target);
	target->delete_temp("bixie/cizu");
	return;
}
string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		ʩ�д̶Է���˫��ҪѨ
		��ʱ��ʹ�Է�ʧȥ��������
		��ʱ��ʹ���ֲ����ƶ�

	����Ҫ��
		��а����100��
		�����ķ�100��
		�������500
		����300
HELP
	);
	return 1;
}


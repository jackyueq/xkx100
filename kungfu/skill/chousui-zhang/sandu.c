// sandu.c ������ɢ��
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#define PNAME "ɢ��"
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
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
	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || target == me ||	
//	  	!me->is_fighting(target) ||
  	  !living(target) || target->query_temp("noliving") )
  	return notify_fail("��Ҫ��˭ɢ����\n");

	if( !(int)me->query_condition("poison_sandu"))
		return notify_fail("������û����ɢ��\n");

	if( environment(me)->query("no_fight") )
		return notify_fail("���ﲻ�ܹ������ˣ�\n");

	if( !userp(target) || wizardp(target) )
		return notify_fail("ɢ��ֻ�ܶ����ʹ�á�\n");
		
	// �������־���

	if( (int)target->query("combat_exp") < (int)me->query("combat_exp")/2 )
		return notify_fail("������ɢ����û�õġ�\n");

	if( (int)me->query_skill("huagong-dafa", 1) < 40 )
		return notify_fail("��Ļ����󷨲�����죬����ɢ����\n");

	if( (int)me->query_skill("chousui-zhang", 1) < 40 )
		return notify_fail("��ĳ����Ʋ�����죬����ɢ����\n");

	msg = GRN "ֻ����$N"GRN"�Ĺǽڸ�����죬$N�����͵س��˰�ߣ���Ȼһ��ץס$n"GRN"��
�󣬽������������ģ�ԴԴ���ϴ���$n"GRN"���ڡ�\n";

	me->start_busy(1);
	if( random( (int)me->query_skill("chousui-zhang",1)) > random(target->query_skill("dodge") ) )
	{
		msg += CYN "���$p����������$P�ı�����������ɢ��$n���ڣ�\n" NOR;
		target->receive_damage("qi",20,me);
		target->receive_wound("qi",15 + random(10),me);
		target->apply_condition("poison_sandu", 1000);
		me->clear_condition("poison_sandu");
		if (!target->is_busy())
		target->start_busy(1 + random(2));
	} else {
		msg += "����$p������������һ�𣬽�$N�������˿�ȥ��\n" NOR;
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
		������������һ��ˮ׼������������������ɢ��
		��ɢ���߱��������
		��ɢ������

	����Ҫ��
		������40��
		������40��
HELP
	);
	return 1;
}


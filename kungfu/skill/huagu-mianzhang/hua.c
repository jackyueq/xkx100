// hua.c ��������
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#define PNAME "�����ֻ��ǡ�"
inherit F_SSERVER;
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
   !SCBORN_D->valid_perform(me,sskill,pfname) )
   return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( me->query_temp("weapon") )
		return notify_fail("ֻ�п��ֲ���ʩչ"PNAME"��\n");

	fskill = "dafa";
	bskill = "strike";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 50 )
		return notify_fail("���"+to_chinese(fskill)+"������죬����ʹ��"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 40 )
		return notify_fail("���"+to_chinese(sskill)+"������죬����ʹ��"+PNAME+"��\n");

	if( (int)me->query("neili", 1) < 300 )
		return notify_fail("����������������ܻ��ǡ�\n");

	msg = MAG "$N"MAG"�Ƴ������������$n"MAG"��ͷ�ϡ�\n"NOR;

  me->add("neili", -100);
	me->start_busy(1);
	if( random( (int)me->query_skill(sskill,1)) > random(target->query_skill("dodge"))/2 )
	{
		msg += MAG "���ֻ���˵�һ����$p��$Pһ�����У�\n" NOR;
		msg += MAG "$pֻ����ȫ��ů����ģ��е��е���Ʈ�����ᡣ\n" NOR;
		target->add_temp("apply/attack", -10);
		target->add_temp("apply/dodge", -10);
		target->add_temp("apply/defense", -10);
	} else {
		msg += CYN"����$p��æ����һ�ԣ����˿�ȥ��\n" NOR;
		me->start_busy(3);
	}
	message_combatd(msg, me, target);
	if( !target->is_fighting(me) ) target->fight_ob(me);
	return 1;
}
string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		���˶Է��Ĺ������ͷ�����

	����Ҫ��
		������50��
		��������40��
		����300
HELP
	);
	return 1;
}


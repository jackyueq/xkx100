// chang3.c
// Last Modified by winder on Mar. 10 2000
// Last Modified by sir on 4/26/2001
#include <ansi.h>

inherit F_SSERVER;
#define PNAME "���ɷ����־�"
int perform(object me, object target)
{
	int skill, ap, dp,i,neili,damage;
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
		
	fskill = "dulong-dafa";
	bskill = "staff";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 90 )
		return notify_fail("���"+to_chinese(fskill)+"������죬����ʹ��"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail("���"+to_chinese(sskill)+"������죬����ʹ��"+PNAME+"��\n");

	if( (int)me->query("neili") < 500 )
		return notify_fail("���Ѿ����þ�ƣ����,���������ˡ�\n");

	neili = me->query("neili");	
	if( neili/2 + random(neili/2) < (int)target->query("neili")/10) 
		return notify_fail("���˵���������߳�̫�࣬�˲��ˣ�\n");

	me->receive_damage("qi", 10);

	me->start_busy(random(5));

	message_combatd(HIY"$N�������һ��������Ȼ���쳤Х��������У�����������Ψ�Ҳ��ܣ�\n" NOR, me);

	damage = me->query("max_neili") / 5;
	ap = me->query_skill(bskill) * 2;
	dp = target->query_skill("force") / 2;
	if( dp < 1 ) dp = 1;
	if( random(ap) > dp )	
	{
		target->receive_damage("jing", damage/2,me);
		target->receive_damage("qi", damage,me);
		target->receive_wound("jing", damage/3,me);
		target->receive_wound("qi", damage,me);
		if (userp(me)) me->add("neili", -500);
		message_combatd( HIR "$Nֻ������һ���ʹ��������ð��������������������ǰ�趯��\n" NOR, target);
	}
	else
	{
		message_combatd(HIR "$Nֻ������΢ʹ���ƺ�����һ�����ˡ�\n" NOR, target);
		target->receive_damage("jing", 50 ,me);
		target->receive_damage("qi", 50 ,me);
		target->receive_wound("qi", 10 ,me);
		if (userp(me)) me->add("neili", -250);
	}
	if( !target->is_killing(me) ) target->kill_ob(me);
	return 1;
}
string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		���˶��־�������Ѫ

	����Ҫ��
		������90��
		�����ȷ�100��
		����500
HELP
	);
	return 1;
}


// yunkai.c �ƿ�����
// Last Modified by winder on Sep. 12 2001

#include <ansi.h>;
inherit F_SSERVER;
#define PNAME "���ƿ����ء�"
int perform(object me,object target)
{
	string msg;
	object weapon;
	int skill, ap, dp, neili_wound, qi_wound;

	int flag;
	string fskill,sskill,bskill,pfname;

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
		
	if( objectp(me->query_temp("weapon")) )
		return notify_fail("�������ֲ���ʹ��"PNAME"��\n");
		
	fskill = "honghua-shengong";
	bskill = "hand";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}
	if( (int)me->query_skill(fskill, 1) < 60 )
		return notify_fail("���"+to_chinese(fskill)+"�ȼ�����������ʹ��"+PNAME+"��\n");
	if( (int)me->query_skill(sskill, 1) < 60 )
		return notify_fail("���"+to_chinese(sskill)+"�ȼ�����������ʹ��"+PNAME+"��\n");
	if( me->query("max_neili") < 200 )
		return notify_fail("���������Ϊ�������޷�ʹ"PNAME"��\n");
	if( me->query("neili") < 150 )
		return notify_fail("��������������޷�����"PNAME"��\n");
 
	msg = HIC "$N"HIC"Ǳ�ˡ��ƿ����ء���˫��Ю������ķ���֮����$n"HIC"��ȥ��\n"NOR;
	message_combatd(msg, me, target);
	skill = me->query_skill(bskill, 1);
 
	ap = me->query("combat_exp") + skill * 400;
	dp = target->query("combat_exp") / 2;
	if( dp < 1 ) dp = 1;
	if( random(ap) > dp )
	{
		msg=HIR"$n"HIR"ֻ������ǰһ���ʹ�����ۡ���һ�����һ����Ѫ��\n"NOR;
		neili_wound = 100 + random(skill);
		qi_wound = neili_wound * 2;
		if(qi_wound > target->query("qi"))
			qi_wound = target->query("qi");
		if(neili_wound > target->query("neili"))
			neili_wound = target->query("neili");
		if(userp(me)) me->add("neili",-(100+neili_wound/2));
		
		target->add("neili", -neili_wound);
		target->receive_damage("qi", qi_wound,me);
		target->start_busy(2);
		me->start_busy(random(2));
	}
	else
	{
		msg = HIG"ֻ��$n���Ų�æ������һ���������$N�ı�ɱһ����\n"NOR;
		if(userp(me)) me->add("neili",-100);
		me->start_busy(4);
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
		�˺��Է���Ѫ������

	����Ҫ��
		�컨��60��
		������60��
		������Ϊ200
		����150
HELP
	);
	return 1;
}


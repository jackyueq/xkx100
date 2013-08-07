// kuai.c �콣

#include <ansi.h>

inherit F_SSERVER;
#define PNAME "���콣��"
int perform(object me, object target)
{
	object weapon;
	int dodge, parry, sword, busy_time;
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
		
	if (target->query_temp("pfm-target/xunlei-kuai"))	     
	        return notify_fail("�����ѱ����ء��콣���ķ�������\n");	

	weapon = me->query_temp("weapon");

	if( !objectp(weapon) || weapon->query("skill_type") != "sword" )
		return notify_fail("�������޽����������á��콣���ķ�����\n");

	fskill = "xuantian-wuji";
	bskill = "sword";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 120 )
		return notify_fail("���"+to_chinese(fskill)+"��Ϊ���δ����ʩչ"+PNAME+"ֻ���˼�����\n");

	if( (int)me->query_skill(sskill, 1) < 120 )
		return notify_fail("���"+to_chinese(sskill)+"��Ϊ����������δ����"+PNAME+"��\n");

	if( me->query_skill_mapped("force") != fskill)
		return notify_fail("�������ڹ��롸�콣���ķ���㣣�\n");

	if( me->query("max_neili") <= 1500 )
		return notify_fail("���������Ϊ���㣬����������ʩչ���콣����\n");

	if( me->query("neili") <= 700 )
		return notify_fail("�����������������������ʩչ���콣����\n");

	if( me->query("qi") <= 200 )
		return notify_fail("�����Ѫ���ޣ�������ʩչ���콣����\n");
	
	dodge = target->query_skill("dodge", 1)/3;
	parry = target->query_skill("parry", 1)/3;
	sword = me->query_skill(bskill, 1)/3;
	busy_time = me->query_skill(bskill, 1)/30;	
	
	message_combatd(HIW"$NƮ�����ʹ�����ؾ������콣���ķ�����ʱ�������Ʈ�ݣ�����ǧ�������裬\n" NOR, me, target);
	
	if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/5)
	{ 
		message_combatd(HIW"����ͷ����������$n"HIW"�ۻ����ң������˸����ֲ�����\n" NOR, me, target);
		target->add_temp("apply/dodge", -dodge);
		target->add_temp("apply/parry", -parry);
		target->add_temp("apply/attack", -sword);
		target->start_busy(busy_time);
		target->set_temp("pfm-target/xunlei-kuai", 1);			
		me->add("neili", -300);
		me->add("qi", -100);
		target->start_call_out( (: call_other, __FILE__, "remove_effect",me,target, dodge, parry,  sword :), sword/3);
	}
	else
	{
		message_combatd(HIW"��$n"HIW"��������˿����Ϊ������\n"NOR, me, target);
		me->start_busy(1);
		me->add("neili", -200);
		me->add("qi", -100);
	}
	return 1;
}

void remove_effect(object me,object victim, int dodge, int parry, int sword)
{
	if (objectp(victim))
	{
		victim->delete_temp("pfm-target/xunlei-kuai",1);
		victim->add_temp("apply/dodge", dodge);
		victim->add_temp("apply/parry", parry);
		victim->add_temp("apply/attack", sword);
	}
	
	if (objectp(me) && objectp(victim) && victim->is_fighting(me))
	{
		message_combatd(HIY "\n\n$N"HIY"������Ӧ��$n"HIY"�Ľ�·������������ˡ�\n" NOR, victim, me);
	}
}
string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		�𺦶Է�����
		���ͶԷ�����

	����Ҫ��
		�����޼���120��
		Ѹ��ʮ����120��
		����1500
		��Ѫ200
HELP
	);
	return 1;
}


// jinglei.c ��ָ����
// Last Modified by winder on Mar. 10 2000
 
#include <ansi.h>
 
inherit F_SSERVER;
#define PNAME "����ָ���ס�"
int perform(object me,object target)
{
	string msg;
	object weapon2 ;
	int skill, dp, wound;
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

	if( me->query_temp("weapon"))
		return notify_fail("��ʹ����������\n");

	fskill = "bibo-shengong";
	bskill = "finger";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 100 )
		return notify_fail("���"+to_chinese(fskill)+"δ�����, ����ʹ��"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 120 )
		return notify_fail("���"+to_chinese(sskill)+"�ȼ�����, ����ʹ��"+PNAME+"��\n");

	if( me->query("neili") < 150 )
		return notify_fail("��������������޷����á���ָ���ס���\n");
 
	skill = me->query_skill(bskill, 1);
	msg = HIC "$N"HIC"ʹ����ָ��֮ͨ����ָ���ס�, ��ʱ���ھ��Ⱪ�䣬\n" NOR;
	message_combatd(msg, me, target);
 
	dp = target->query("combat_exp")/4;
	if( dp < 1 ) dp = 1;
	if( random(me->query("combat_exp")) > dp)
	{
		if (target->query_temp("hmg_dzjm"))
		{
			msg += HIM "$n΢΢һЦ��������ϣ�ȫȻ����$N�Ĺ��ƣ�$Nһָ����$n������Ѩ�ϣ�$n�ƺ�����֪��������ʹ��ɱ�֣��������С�\n"NOR;
			me->start_busy(random(5) + 1);
			me->add("neili", -150);
		} else {
			if(userp(me)) me->add("neili",-150);
			msg =HIC"$n"HIC"ֻ������ǰһ��������Ѩ��΢΢һʹ��ȫ��������й������\n"NOR ;
			if ( objectp(weapon2 = target->query_temp("weapon")))
			{
				msg += HIC"ͬʱ����һ�飬����";
				msg += weapon2->name();
				msg += HIC"���ֶ�����\n" NOR;
				weapon2->move(environment(me));
			}
			wound = skill + random(400);
			if((int)target->query("neili") < wound)
				wound = target->query("neili");
			target->add("neili", -wound);
			target->receive_damage("jing", wound/2 + random(100),me);
			target->receive_wound("jing", wound/2,me);
			if (!target->is_busy())
			target->start_busy(5);
			me->start_busy(2);
		}
	}
	else
	{
		msg ="����$n�Ŀ�����$N����ͼ�����̲�ȡ���ƣ�ʹ$P�ġ���ָ���ס�û�������á�\n"NOR;
		me->start_busy(3);
	}
	message_combatd(msg, me, target);

	if(!target->is_fighting(me)) target->fight_ob(me);
//	if(userp(target)) target->fight_ob(me);
//	else if( !target->is_killing(me) ) target->kill_ob(me);

	return 1;
}
string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		���˶Է���Ѫ
		����Է�����
		����Է�����

	����Ҫ��
		�̲���100��
		��ָ��ͨ120��
		����150
HELP
	);
	return 1;
}


// qiankun.c һ��ָ ��һָǬ����
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

inherit F_SSERVER;
#define PNAME "��һָǬ����"
int perform(object me, object target)
{
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
		
	if((int)me->query_str() < 28)
		return notify_fail("����������������ʹ����һ������\n");

	if ( me->query_temp("weapon"))
		return notify_fail("��ֻ�ܿ��ֳ���һָǬ������\n");

	fskill = "kurong-changong";
	bskill = "finger";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 90 &&
			(int)me->query_skill("kurong-changong",1) < 90 &&
			(int)me->query_skill("xiantian-qigong",1) < 90)
		return notify_fail("����ڹ���Ϊ�������޷�ʹ��"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 90 )
		return notify_fail("���"+to_chinese(sskill)+"��Ϊ���������ܳ���"+PNAME+"��\n");

	if((int)me->query("max_neili") < 850)
		return notify_fail("��������Ϊ����������ʹ��һָǬ����\n");

	if((int)me->query("neili") < 200)
		return notify_fail("���������ڲ���������ʹ��һָǬ����\n");

	if( target->is_busy() )
		return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɢ�\n");

	msg = HIY "$N"HIY"ʹ��һ��ָ������һָǬ��������ס��$n"HIY"��ȫ��ҪѨ, ʹ$n"HIY"�������á�\n";

	if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/3)
	{
		if (target->query_temp("hmg_dzjm"))
		{
			msg += HIY "$Pһָ����$p�Ĵ�Ѩ��$pֻ��΢΢һ�飬Ѹ���ж��糣��\n"NOR;
			me->start_busy(random(3) + 1);
			me->add("neili", -200);
		} else {
			msg += HIG"���$p��$P���˸����ֲ���! һʱ���ܶ���! \n"NOR;
			target->start_busy( random((int)me->query_skill(bskill,1)/ 20));
			me->add("neili", -250);
		}
	}
	else
	{
		msg += HIM "����$p������$P����ͼ����û���ϵ���\n" NOR;
		me->add("neili", -200);
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
		���ͶԷ�����

	����Ҫ��
		�����������������90��
		һ��ָ90��
		����850
		��������28
HELP
	);
	return 1;
}


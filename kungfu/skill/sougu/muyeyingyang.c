// muyeyingyang.c ��Ұӥ��
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit F_SSERVER;
#define PNAME "��Ұӥ��"
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
		
	if( me->query_temp("weapon"))
		return notify_fail("��ֻ�ܿ��ֲ���ʩչ��Ұӥ�\n");

	if((int)me->query_str() < 30)
		return notify_fail("���������������ʹ����Ұӥ�\n");

	fskill = "jiuyang-shengong";
	bskill = "claw";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 100 )
		return notify_fail("���"+to_chinese(fskill)+"��Ϊ������Ŀǰ������ʹ��"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 150 )
		return notify_fail("���"+to_chinese(sskill)+"��Ϊ������Ŀǰ������ʹ��"+PNAME+"��\n");

	if((int)me->query("neili") < 800)
		return notify_fail("���������ڲ���������ʹ����Ұӥ�\n");

	if( target->is_busy() )
		return notify_fail(target->name()+"Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");

	msg = HIY "$N"HIY"ʹ���ѹ�ӥצ����������Ұӥ���˫צ���ץ��$n"HIY"��ȫ��ҪѨ��\n";

	if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/4)
	{
		if (target->query_temp("hmg_dzjm"))
		{
	  		msg += HIY "$p��˼��������������ӭ�ϣ���$P��ס����ҪѨ���ж�ȴ˿����Ϊ֮���衣\n"NOR;
			me->start_busy(random(4) + 1);
			me->add("neili", -100);
		} else {
			msg += HIG "���$p��$P����ҪѨ����ʱ��������! \n" NOR;
			target->start_busy((int)me->query_skill(bskill,1)/25+2);
			me->add("neili", -100);
		}
	} else {
		msg += HIG "����$p������$P����ͼ����û���ϵ���\n" NOR;
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
		������100��
		�ѹ�ӥצ��150��
		����800
		��������30
HELP
	);
	return 1;
}


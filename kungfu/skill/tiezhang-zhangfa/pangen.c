// pangen.c �����Ʒ� �������̸���
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit F_SSERVER;
#define PNAME "�������̸���"
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
		
	if( me->query_temp("weapon") )
		return notify_fail("ֻ�п��ֲ���ʩչ�������̸�����\n");

	fskill = "guiyuan-tunafa";
	bskill = "strike";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 100 )
		return notify_fail("���"+to_chinese(fskill)+"��Ϊ����������ʹ"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail("���"+to_chinese(sskill)+"��Ϊ����������ʹ"+PNAME+"��\n");

	if((int)me->query("max_neili") < 500)
		return notify_fail("��������Ϊ����������ʹ�ÿ����̸���\n");

	if((int)me->query("neili") < 300)
		return notify_fail("���������ڲ���������ʹ�ÿ����̸���\n");

	if( target->is_busy() )
		return notify_fail(target->name()+"Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");
	msg = HIY"$Nʹ�������Ʒ��ġ������̸����������͵���$n��˫��ץȥ��\n"NOR;
	if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/3)
	{
		if (target->query_temp("hmg_dzjm"))
		{
			msg += HIY"���$P����$p�������Ѫ��֮���$pһ���������ˡ�\n"NOR;
			me->start_busy(random(3) + 1);
			me->add("neili", -200);
		} else {
			msg += HIG"���$p��˫�ֱ�$Pһ����ס���������ã�\n"NOR;
			target->start_busy( random((int)me->query_skill(bskill, 1) / 30) + 2);
			me->add("neili", -300);
		}
	}
	else
	{
		msg += HIY "���$p���ּ��գ�$P�ĳ������˸��գ�\n"NOR;
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
		��Ԫ���ɷ�100��
		�����Ʒ�100��
		������Ϊ500
		����300
HELP
	);
	return 1;
}


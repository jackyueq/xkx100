//lianhuan.c ���� perform
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>

inherit F_SSERVER;
#define PNAME "����������"
int perform(object me, object target)
{
	int damage;
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
		
	if( target->is_busy() )
		return notify_fail(target->name() + "Ŀǰ����ͷת�򣬳˻������ɢ�\n");

		//�������־���ʹ��

	fskill = "dulong-dafa";
	bskill = "leg";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 60 )
		return notify_fail("���"+to_chinese(fskill)+"��Ϊ������������"+PNAME+"��\n");

	if( (int)me->query_skill(bskill, 1) < 40 )
		return notify_fail(PNAME"��Ҫ��տ��"+to_chinese(bskill)+"��ϣ�������Чʩչ��\n");

	if( (int)me->query_skill(sskill, 1) < 40 )
		return notify_fail("���"+to_chinese(sskill)+"��Ϊ���㣬������ʹ��"+PNAME+"��\n");

	if( !me->query_temp("murong/xingyi") )
	{
		if( me->query_skill_mapped("strike") != "huagu-mianzhang" )
			return notify_fail("�����õĲ��ǻ������ƣ�������������������ʩչ��\n");
		if( me->query_skill_prepared("strike") != "huagu-mianzhang" )
			return notify_fail("�������Ĳ��ǻ������ƣ�������������������ʩչ��\n");
	}
	if( me->query("neili") <= 300 )
		return notify_fail("�����������ʹ����������\n");

	msg = HIY "\n ͻȻ��$N"HIY"�����ڿն��������$n"HIY"�������߼��ȣ�\n" NOR;
	if( random(me->query("combat_exp")) > (int)target->query("combat_exp") /2)
	{

		target->start_busy((int)me->query_skill(bskill, 1) / 20);
		damage = (int)me->query_skill(bskill, 1);
		damage = damage/2 + random(damage);
		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage/3,me);
		me->add("neili", -damage/10);
		if( damage < 40 )
			msg += HIY"���$n"HIY"��$N"HIY"���������ߵ���ͷת�򣡢�\n" NOR;
		else msg += HIR"���$n"HIY"��$N"HIY"������������Ҫ�������ۣ�����һ����Ѫ��ӿ������\n"NOR;
	}
	else
	{
		msg += "����$p������$P����ͼ������ö��˿�ȥ��\n" NOR;
		me->start_busy(1 + random(3));
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
		���˶Է���Ѫ

	����Ҫ��
		������60��
		�����ȷ�40��
		������40��
		����300
		������������
HELP
	);
	return 1;
}


// Last Modified by winder on Aug. 25 2001
// 18pan.c ̩ɽʮ���� 

#include <ansi.h>;
inherit F_SSERVER;
#define PNAME "��̩ɽʮ���̡�"
int perform(object me,object target)
{
	string msg;
	object weapon;
	int skill, ap, dp, neili_wound, qi_wound;
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
		
	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	fskill = "panshi-shengong";
	bskill = "sword";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 70 )
		return notify_fail("���"+to_chinese(fskill)+"��Ϊ������ʹ����"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 80 )
		return notify_fail("���"+to_chinese(sskill)+"��Ϊ������ʹ����"+PNAME+"��\n");

	if( me->query("neili") < 300 )
		return notify_fail("��������������޷�����̩ɽʮ���̣�\n");

	if( me->query("max_neili") < 400 )
		return notify_fail("���������Ϊ�������޷�����̩ɽʮ���̣�\n");

	if( target->is_busy() )
		return notify_fail(target->name()+"�Ѿ��Թ˲�Ͼ�ˣ��ŵ������ɣ�\n");

	skill = me->query_skill(bskill,1);
	msg = CYN "$Nʹ��̩ɽʮ���̽���֮����ʽ��һ�ѽ�����ʮ�˵���Ӱ��\n";
	me->start_busy(1);
	me->add("neili",-100);
	if( random(me->query("combat_exp") + skill*1000) > (int)target->query("combat_exp")/3 )
	{
		msg += HIY"���$n�������������ã�\n" NOR;
		target->start_busy( skill / 40 + 2);
	} else
	{
		msg += HIC"����$n������$N�Ľ��У�һš��Ծ���˽�Ӱ��\n" NOR;
		msg += HIY"$Nȴһ��ʧȥƽ�⣬�������˱�����\n" NOR;
		me->start_busy(3);
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
		���Ͷ��ֳ���

	����Ҫ��
		��ʯ��70��
		̩ɽ����80��
		������Ϊ400
		����300
HELP
	);
	return 1;
}


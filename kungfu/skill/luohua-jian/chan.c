// Last Modified by winder on Sep. 12 2001
// chan.c ���־�

#include <ansi.h>

inherit F_SSERVER;
#define PNAME "�������־�"
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

	if( target->is_busy() )
		return notify_fail(target->name()+"Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");

	fskill = "honghua-shengong";
	bskill = "sword";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 40 )
		return notify_fail("���"+to_chinese(fskill)+"������죬ʹ����"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 40 )
		return notify_fail("���"+to_chinese(sskill)+"������죬����ʹ��"+PNAME+"��\n");

	if( (int)me->query("max_neili") < 300 )
		return notify_fail("���������Ϊ������\n");

	if( (int)me->query("neili") < 200 )
		return notify_fail("�������������\n");

	msg = HIG"$Nʹ���仨ʮ�����������־�����������������ͼ����$n�Ĺ��ơ�\n";

	me->start_busy(1);
	if( random(me->query("combat_exp"))>(int)target->query("combat_exp")/3 )
	{
		msg += HIR "���$p��$P���˸����ֲ�����\n" NOR;
		target->start_busy( (int)me->query_skill(bskill,1) / 30 );
	} else {
		msg += "����$p�����У�������$P����ͼ��\n" NOR;
	}
	me->add("neili", -100);
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
		�컨��40��
		�仨ʮ����40��
		������Ϊ300
		����200
HELP
	);
	return 1;
}


// ruhe.c  ������
// Last Modified by winder on Aug. 25 2001

#include <ansi.h>;
inherit F_SSERVER;
#define PNAME "�������Ρ�"
int perform(object me,object target)
{
	string msg;
	object weapon ;
	int ap, dp, neili_wound, qi_wound;
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

	if( (int)me->query_skill(fskill, 1) < 150 )
		return notify_fail("���"+to_chinese(fskill)+"��Ϊ����������ʹ��"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 180 )
		return notify_fail("���"+to_chinese(sskill)+"��Ϊ����������ʹ��"+PNAME+"��\n");

	if( (int)me->query_skill(bskill, 1) < 120 )
		return notify_fail("���"+to_chinese(bskill)+"��Ϊ������ʹ����"+PNAME+"��\n");

	if( me->query("neili") < 250 )
		return notify_fail("��������������޷����������Σ�\n");

	if( me->query("max_neili") < 500 )
		return notify_fail("���������Ϊ�������޷����������Σ�\n");

	message_combatd( HIY"$N����"+weapon->name()+HIY"бָ���£�������ָ������ָ��������һ�����壬�ն���ȭ���ֽ�Ĵָ������ζ�ʳָ��������ָȫչ����������Ĵָ����ʳָ��������ָ��Ȼ������"+weapon->name()+HIY"���Ⱪ������$n���̶�ȥ��\n"NOR,me,target);

	me->add("neili", -250);
	me->start_call_out( (: call_other, __FILE__, "hit_him", me, target :), /*random(5)+*/3);
	me->start_busy(3);
	return 1;
}
void hit_him(object me, object target)
{
	string msg;
	int skill = me->query_skill("sword", 1);

	if(me->is_fighting(target) && target->is_fighting(me) &&
		environment(me) == environment(target))
	{
		msg = HIY"$Nʹ��̩ɽ������һ�����е�"+HIR "������" +HIY"������$n�ܸ�Ծ�ͣ��任��λ�����޴����ܣ�ֻ������ǰһ����һ��"HIR"Ѫ��"HIY"��ӿ������\n" NOR;
		message_combatd(msg, me, target);
		target->receive_damage("qi",skill*2+me->query_skill("force",1),me);
		target->receive_wound("qi",skill+me->query_skill("force",1),me);
	}
	return ;
}
string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		���˶Է���Ѫ��ÿ������

	����Ҫ��
		��ʯ��150��
		̩ɽ����180��
		��������120��
		������Ϊ500
		����250
HELP
	);
	return 1;
}


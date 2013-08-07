// sui.c ̫������ [��]�־�
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int a_amount, int d_amount);

inherit F_SSERVER;
#define PNAME "���桹�־�"
int perform(object me, object target)
{
	object weapon;
	int skill;
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
/*
	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"ֻ�ܶ�ս���еĶ���ʹ�á�\n");
*/
	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	fskill = "taiji-shengong";
	bskill = "sword";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 90 )
		return notify_fail("���"+to_chinese(fskill)+"��򲻹���ʹ����"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 60 )
		return notify_fail("���"+to_chinese(sskill)+"û����쵽����"+PNAME+"��\n");

	if( (int)me->query("neili") < 300  ) 
		return notify_fail("�������������\n");

	if( (int)me->query_temp("tjj_sui") ) 
		return notify_fail("���Ѿ����˹����ˡ�\n");

	skill = me->query_skill(bskill);
	msg = HIB "$Nʹ��̫���������桹�־�����Ȧ����С������ס��\n"NOR;
	message_combatd(msg, me, target);

	me->add_temp("apply/attack", -skill/4);
	me->add_temp("apply/dodge", skill/3);
	me->set_temp("tjj_sui", 1);

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/4, skill/3 :), skill/4);

	me->add("neili", -100);
	if( me->is_fighting() ) me->start_busy(2);

	return 1;
}

void remove_effect(object me, int a_amount, int d_amount)
{
	me->add_temp("apply/attack", a_amount);
	me->add_temp("apply/dodge", - d_amount);
	me->delete_temp("tjj_sui");
	tell_object(me, HIY "������־�������ϣ��������ջص��\n");
}
string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		�����Լ��ķ����������͹�����

	����Ҫ��
		̫����90��
		̫������60��
		����300
HELP
	);
	return 1;
}


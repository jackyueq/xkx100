// kongming.c ����ȭ ����
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#include <skill.h>
#include <combat.h>

inherit F_SSERVER;
#define PNAME "��������"
void remove_effect(object me, int aamount, int damount);

int perform(object me, object target)
{
  	string msg;
	int skill;
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

	//�������־���
	
	if( (int)me->query_temp("kongming") ) 
		return notify_fail(HIG"���Ѿ����˶����������ˡ�\n"NOR);

	fskill = "xiantian-qigong";
	bskill = "unarmed";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 150 )
		return notify_fail("���"+to_chinese(fskill)+"��Ϊ��������������"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 150 )
		return notify_fail("���"+to_chinese(sskill)+"����Ϊ��������������"+PNAME+"��\n");

	if( !me->query_temp("murong/xingyi") )
	{
		if( me->query_skill_mapped("parry") != "kongming-quan") 
			return notify_fail("��δ���м��м�������ȭ���޷�ʹ�ÿ�����\n");
	}

	if( (int)me->query("neili") < 1200 )
		return notify_fail("���������������\n");
	
	msg = HIY "$Nʹ������ȭ�ľ��������мܣ�ȭ������ʵʵ��\n" NOR;

	skill = (int) (me->query_skill(bskill, 1) / 3);

	if((int)random(me->query("combat_exp")) >
		(int)target->query("combat_exp") / 2)
	{	
		me->set_temp("kongming", 1);
		me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 1, 0:), skill);
		msg += HIY "$n�׺ݵ�������������֮�أ���������ڿ����У�\n" NOR;
// ��Ч��combatd.c������
	}
	else{
		msg += HIR "��$n"HIR"����$N"HIR"ȭ����ʵ�����Ƴ�ӿ��ʣ�\n" NOR;
	}
	me->add("neili", -1000);
	message_combatd(msg, me, target);
	return 1;
}

void remove_effect(object me, int i, int j)
{
	if ( (int)me->query_temp("kongming") ) 
	{
		me->delete_temp("kongming");
		tell_object(me, HIY "��Ŀ���������ϣ��������ջص��\n" NOR);
	}
}
string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		����˸գ�ʹ���ֳ��д����ڿմ�

	����Ҫ��
		��������150��
		����ȭ150��
		����1200
HELP
	);
	return 1;
}


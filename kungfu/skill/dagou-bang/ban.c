// ban.c �򹷰��������־�
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#define PNAME "�����־�"
inherit F_SSERVER;
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
   !SCBORN_D->valid_perform(me,sskill,pfname) )
   return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "stick")
			return notify_fail("��ʹ�õ��������ԡ�\n");

//	if( target->is_busy() )
//		return notify_fail(target->name()+"Ŀǰ���Թ˲�Ͼ���ŵ������ɢ�\n");
	fskill = "huntian-qigong";
	bskill = "stick";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}
	if( (int)me->query_skill(fskill, 1) < 120 )
		return notify_fail("���"+to_chinese(fskill)+"������񣬲���ʹ��"+PNAME+"��\n");
	if( (int)me->query_skill(sskill, 1) < 120 )
		return notify_fail("���"+to_chinese(sskill)+"������죬����ʹ��"+PNAME+"��\n");
	if(me->query("max_neili") < 800)
		return notify_fail("���������Ϊ����������ʹ��"PNAME"��\n");
	if(me->query("neili") < 400)
		return notify_fail("���������Ϊ����������ʹ��"PNAME"��\n");
	msg = HIY "$N"+weapon->name()+HIY"һ�ϣ�$n"HIY"��æԾ��˫����ذ�ߣ�\n";
 
	me->start_busy(2);
	me->add("neili", -200);
	if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/2)
	{
		msg += HIR "�պð���һ���������ɵı㽫$n"HIR"���ˡ�\n" NOR;
		target->receive_damage("qi", 200,me);
		target->receive_damage("jing", 200,me);
		target->start_busy(3);
	} else {
		msg += HIG"����$n"HIG"ȫ���������̣�ֻ��"+weapon->name()+HIG"������������Ծ����$N"HIG"��֮������\n" NOR;
	}
	message_combatd(msg, me, target);

	if(!target->is_fighting(me)) target->fight_ob(me);
	return 1;
}
string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
        ��ĶԷ�����Ѫ�뾫��

	����Ҫ��
		��������120��
		�򹷰���120��
		������Ϊ800
		����400
HELP
	);
	return 1;
}


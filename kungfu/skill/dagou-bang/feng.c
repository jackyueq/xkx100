// feng.c �򹷰������⡹�־�
// Last Modified by winder on Nov. 16 2000

#include <ansi.h>
inherit F_SSERVER;
#define PNAME "�����־���"
int perform(object me, object target)
{
	string msg;
	object weapon;
	int skill;
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

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "stick")
		return notify_fail(HIY "����Ҫ���ʵı����ŷ��ס��\n" NOR);
	if (target->query_temp("dagou/feng"))
		return notify_fail(HIR"���Ѿ�ʹ�����⡱�־��ˣ�\n"NOR);
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
	if( (int)me->query_skill(fskill, 1) < 180 )
		return notify_fail("���"+to_chinese(fskill)+"��Ϊ�������޷�ʹ��"+PNAME+"��\n");
	if( (int)me->query_skill(sskill, 1) < 180 )
		return notify_fail("���"+to_chinese(sskill)+"��������죬�޷�ʹ��"+PNAME+"��\n");

	if((int)me->query("max_neili") < 500)
		return notify_fail(HIY "���������Ϊ���������\n" NOR);
	if((int)me->query("neili") < 500)
		return notify_fail(HIY "�������������㡣\n" NOR);
	skill = me->query_skill(bskill,1);
	skill = (int)(skill/4)+ random((int)(skill/4));

	msg = HIC "$N"HIC"�����Զ���һҧ������������"+weapon->name()+HIC"��������ס�Ż���\n"NOR;

	if (random(me->query_dex()) > target->query_dex()/2)
	{
		msg += HIC"ʹ�����⡱�־�����ӰƮƮ����ʱ��$n"HIC"��ǰ����֮�ؾ�����ס�ˡ�\n"NOR;
		message_combatd(msg, me, target);
		me->add("neili", -400);
		me->add_temp("apply/defense", skill);
		target->set_temp("dagou/feng", 1);
		call_out("feng_end", (int) 6+random(6), me, target, skill);
	} else
	{
		me->start_busy(2);
		me->add("neili", -300);
		msg += HIY"$n��Ȼһ���֣�ǡǡ��ס��$N"HIY"�ķ��־���\n"NOR;
		message_combatd(msg, me, target);
	}
	if(!target->is_fighting(me)) target->fight_ob(me);
	return 1;
}

void feng_end(object me, object target, int skill)
{
	if (objectp(me) && objectp(target))
	message_combatd(HIR"$n��$N��һ��и����$N�ķ��־���ͻΧ������\n"NOR, me, target);
	if (objectp(me))
	me->add_temp("apply/defense", -skill);
	if (objectp(target))
	target->delete_temp("dagou/feng");
	return;
}
string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		��ʱ��ʹ�����Լ��м�����
		��ʱ��ʹ���ֲ��������⹦

	����Ҫ��
		��������180��
		�򹷰���180��
		������Ϊ500
		����500
HELP
	);
	return 1;
}


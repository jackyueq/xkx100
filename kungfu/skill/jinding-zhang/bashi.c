// bashi.c ������ ��ʽ��һ
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
#define PNAME "����ʽ��һ��"
void remove_effect(object target, int aamount, int damount);

int perform(object me, object target)
{
	object weapon;
	int damage;
	string msg;
	int count,d_count,qi, maxqi, skill;
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
		
	if( (int)target->query_temp("bashi") )
		return notify_fail("�Է��Ѿ����ˡ���ʽ��һ���ˡ�\n");

//	���ֱ�������

	fskill = "linji-zhuang";
	bskill = "strike";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 40 )
		return notify_fail("���"+to_chinese(fskill)+"����Ϊ����������ʹ��"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail("���"+to_chinese(sskill)+"�İ�ʽ��ϰ��ȫ���޷�ʹ��"+PNAME+"��\n");

	if( (int)me->query("neili") < 200 )
		return notify_fail("��������������ߣ�\n");

	msg = HIY "$N"HIY"��������һ����������ȫ��Ĺ�����˫�ƣ�ֻ����$N"HIY"����һ���죡\n" NOR;
	me->add("neili",-100);

	if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/2)
	{
		damage = (int)me->query_skill("force", 1)/2;
		damage = damage + (int)me->query_skill(bskill, 1);
		target->set_temp("bashi", 1);
		target->add_temp("apply/attack", -damage/3);
		target->add_temp("apply/dodge", -damage/3);
		msg += HIR "$N"HIR"�ڿն���ʹ���ˡ���ʽ��һ�����������Ӱ��Ʈ������������$n"HIR"ȫ�������λ��\n" NOR;
    target->start_call_out( (: call_other, __FILE__, "remove_effect",target,damage/3, damage/3:), damage/30);
		target->start_busy(3);
	}
	else {
		msg += CYN"����$p�͵���ǰһԾ,������$P�Ĺ�����Χ��\n"NOR;
		me->start_busy(1);
	}
	message_combatd(msg, me, target);
	if( !target->is_killing(me) ) target->kill_ob(me);
	return 1;
}

void remove_effect(object target,int aamount, int damount)
{
	target->add_temp("apply/attack", aamount);
	target->add_temp("apply/dodge", damount);
	target->delete_temp("bashi");
	if (target->is_fighting())
	message_combatd(HIG"$N�����ҵĹ����а����˳�����������������ס�˽Ų���\n"NOR, target);
}

string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		���ͶԷ��Ĺ������ͷ�����

	����Ҫ��
		�ټ�ʮ��ׯ40��
		������100��
		����200
HELP
	);
	return 1;
}


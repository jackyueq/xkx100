// wuguang.c ���Ʊ޷��������޹⡹
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

inherit F_SSERVER;
#define PNAME "�������޹⡹"
int perform(object me, object target)
{
	int damage, power;
	string msg;
	object weapon;
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
		|| (string)weapon->query("skill_type") != "whip")
		return notify_fail(HIR"װ���޲���ʹ�á������޹⡹��\n"NOR);

	fskill = "xiantian-qigong";
	bskill = "whip";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}
	if( (int)me->query_skill(fskill, 1) < 150 )
		return notify_fail("���"+to_chinese(fskill)+"��򲻹���ʹ����"+PNAME+"��\n");
	if( (int)me->query_skill(sskill, 1) < 120 )
		return notify_fail("���"+to_chinese(sskill)+"������죬ʹ����"+PNAME+"��\n");
	if ((int)me->query("max_neili") < 600)
		return notify_fail(RED"��������Ϊ���㣬�޷�����������\n"NOR);
	if ((int)me->query("neili") < 600)
		return notify_fail(HIC"����������������û�ܽ�"PNAME"ʹ�꣡\n"NOR);
	msg = HIC "$N"HIC"һ����ȣ�����һ������"+weapon->query("name")+HIC"���ַɳ���ֻ�������Ӱ���������ƣ��ڱ����գ���ͷ������$n"HIC"������ȥ��\n"NOR;
	if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/2)
	{
		if ((int)me->query("shen") > 1000000) 
			power = 1000000;	
		else if ((int)me->query("shen")>0) 
			power = (int)me->query("shen");
		else power = 3000;
		if ((int)target->query("shen") <0) 
			power=power*2;
		damage = random((int)(power/1000))+(int)(power/3000);
		me->add("neili", -600);
		me->start_busy(2);
		target->start_busy(random(3));
		target->receive_damage("qi", damage,me);		
		target->receive_wound("qi", damage/2,me);
		target->receive_damage("jing", damage/4,me);
msg += HIR"$n��æ�����Ծ�������Ƽ��������������Ӱ��ѹ��֮�ƶ�����ȫ������
�׻���һʱ��֪���˶��ٱޣ���������������\n"NOR;
	} else
	{
		me->start_busy(2);
		me->receive_wound("qi", me->query("qi")/20,me);
		msg += HIY"����$n"HIY"һ�����ɣ�һ�¾�Ծ����$N�ı�Ӱ��\n"NOR;
		me->add("neili", -200);
	}
	msg += HIC+weapon->query("name")+HIC+"���£������ڵ��ϣ�����ȻŪ�����졣\n"NOR;
	weapon->move(environment(me));
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
		���˶Է�����
		���ͶԷ�����

	����Ҫ��
		��������150��
		���Ʊ޷�120��
		����600
HELP
	);
	return 1;
}


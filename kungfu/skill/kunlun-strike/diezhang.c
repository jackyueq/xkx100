// diezhang.c �����Ʒ�  perform ��ɽ����

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";
#define PNAME "����ɽ���ơ�"
int perform(object me, object target)
{
	string msg, *limbs;
	int p,count, damage = 0;
	int arg;
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
		
	if( objectp( me->query_temp("weapon")) )
		return notify_fail("ֻ�п��ֲ���ʩչ"PNAME"��\n");

	fskill = "xuantian-wuji";
	bskill = "strike";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 140 )
		return notify_fail("���"+to_chinese(fskill)+"��Ϊ�������޷�ʹ��"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail("���"+to_chinese(sskill)+"������죬����ʹ��"+PNAME+"��\n");

	if( (int)me->query_skill(bskill, 1) < 100 )
		return notify_fail("���"+to_chinese(bskill)+"������죬����ʹ��"+PNAME+"��\n");

	if( !me->query_temp("murong/xingyi") )
	{
		if (me->query_skill_prepared("strike") != "kunlun-strike" || 
			me->query_skill_mapped("parry") != "kunlun-strike")
			return notify_fail("�������޷�ʹ�á���ɽ���ơ����й�����\n");
	}
	if( (int)me->query_str() < 26 )
		return notify_fail("�����������ǿ������ʹ�á���ɽ���ơ���\n");
	arg = (int)(me->query_skill(bskill, 1) / 30);

	if( arg <= 1 )
		return notify_fail("����Ҫ�����вſ����"PNAME"��\n");

	if( (int)me->query("max_neili", 1) < 1500 )
		return notify_fail("��������Ϊ����������ʹ��"PNAME"��\n");

	if( (int)me->query("neili", 1) < 200 )
		return notify_fail("����������̫��������ʹ��"PNAME"��\n");

	if( (int)me->query("neili", 1) < 100 * arg )
		return notify_fail("�����ڵ�����ʩչ������ô���С�\n");

	message_combatd(HIG"$N"HIG"����һ���������һ������������"+ chinese_number(arg) +"�ƣ���������ǰ�У�����������һ������$n"HIG"��\n\n"NOR, me, target);
	if( random(me->query("combat_exp")) > target->query("combat_exp")/2 )
	{
		limbs = target->query("limbs");
		for(count = 0; count < arg; count++)
		{
			message_combatd( replace_string( SKILL_D("kunlun-strike")->query_action(me, me->query_temp("weapon"))["action"], "$l", limbs[random(sizeof(limbs))]) + "��\n\n", me, target);
			damage = damage+100+random(500);
		}
		damage = (1 + me->query("jiali")/300) * damage / 2;
	
		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage/2,me);
		p = (int)target->query("qi")*100/(int)target->query("max_qi");
		msg = damage_msg(damage, "����");
		msg += "( $n"+eff_status_msg(p)+" )\n";

		me->add("neili", -100 * arg/2);
		me->start_busy(2);
	}
	else
	{
		me->start_busy(arg/2+1);
		me->add("neili", -200);
		target->add("neili", -100);
		msg =HIY"\n$n"HIY"���μ��ٺ��ˣ�˳���Ʒ����һ�����㿪���⹥����\n" NOR;
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
		�˵���Ѫ����ʹ��������

	����Ҫ��
		�����Ʒ�100��
		�����Ʒ�100��
		�����޼�140��
		��������26
		����1500
		���������Ʒ�Ϊ�мܼ���
		���������Ʒ�Ϊ�Ʒ�����
		ָ���Ʒ�����(prepare)
HELP
	);
	return 1;
}


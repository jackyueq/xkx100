// shenjian.c �һ�Ӱ�����

#include <ansi.h>
inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h"
#define PNAME "�һ�Ӱ�����"
int perform(object me, object target)
{
	string msg;
	object weapon;
	int damage, rand, p;
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
		
	if( objectp(me->query_temp("weapon")) )
		return notify_fail("��������ʹ���һ�Ӱ����񽣣�\n");

	fskill = "bibo-shengong";
	bskill = "strike";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 80 )
		return notify_fail("���"+to_chinese(fskill)+"��򲻹����޷�ʩչ"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 80 )
		return notify_fail("���"+to_chinese(sskill)+"������죬�޷�ʹ��"+PNAME+"��\n");

	if ( (int)me->query("neili") < 120)
		return notify_fail("��������������޷�ʹ���һ�Ӱ����񽣡�\n");

	if (!me->query_temp("murong/xingyi"))
	{
		if (me->query_skill_prepared("strike") != "luoying-zhang" ||
			me->query_skill_mapped("strike") != "luoying-zhang")
			return notify_fail("�������޷�ʹ���һ�Ӱ����񽣽��й�����\n");
	}
	
	msg = CYN "\n$N˫������Ĭ�˱̺�����������Ե���ƽ���һ������˿˿��"GRN"����"CYN"���ֱ����������ն��$n��\n"NOR;
	rand = random(me->query("combat_exp"));
	if( rand > (int)target->query("combat_exp")/4 )
	{
		me->add("neili", -100);
		me->start_busy(2);
		damage = (int)me->query_skill(bskill, 1)*3/2;
		damage += random(damage);
//		if (damage > target->query("neili") / 8)
//			damage -= target->query("neili") / 15;
		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage/3,me);
		p = (int)target->query("qi")*100/(int)target->query("max_qi");
		msg += damage_msg(damage, "����");
		msg += "( $n" + eff_status_msg(p) + " )\n";
	}
	else
	{
		me->add("neili", -50);
		me->start_busy(3);
		msg += HIY"$n���һ�����˲�������־����п�����������У������ų���һ���亹��\n" NOR;
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
		���˶�����Ѫ

	����Ҫ��
		��Ӣ����80��
		�̲���80��
		����120
HELP
	);
	return 1;
}


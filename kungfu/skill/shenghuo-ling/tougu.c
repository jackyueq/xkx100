// tougu.c ͸����
// Last Modified by winder on Mar. 10 2000
 
#include <ansi.h>
 
inherit F_SSERVER;
#define PNAME "��͸���롹"
int perform(object me,object target)
{
	string msg;
	object weapon, weapon2;
	int skill, ap, dp, damage;
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
		(string)weapon->query("id") != "shenghuo ling" ||
		weapon->query("ownmake") == 1)
		return notify_fail("��û��ʥ�������ʹ�þ��У�\n");
		
	if (!objectp(weapon2 = target->query_temp("weapon")))
		return notify_fail("�Է�û�б��У��㲻��ʹ͸���롣\n");

	fskill = "jiuyang-shengong";
	bskill = "sword";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 100 )
		return notify_fail("���"+to_chinese(fskill)+"��򲻹���ʹ����"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail("���"+to_chinese(sskill)+"�ȼ�����, ����ʹ"+PNAME+"��\n");

	if( me->query("neili") < 300 )
		return notify_fail("��������������޷�ʹ��"PNAME"��\n");
 
	skill = me->query_skill(bskill,1);
	msg = CYN"$N"CYN"ʹ�˳���͸���롱���ھ���$n"CYN"ֻ����һ�ɼ�����������������һ�㣬��"+weapon->query("name")+CYN+"�ϴ�����������롣\n"HIR;

	message_combatd(msg, me, target);
 
	ap = me->query("combat_exp") / 1000;
	dp = target->query("combat_exp") / 2000;
	if( dp < 1 ) dp = 1;
	if( random(ap) > dp )
	{
		if(userp(me)) me->add("neili", -100);
		msg="$n�ؿ�һʹ���ƺ���һö��ϸ�ļ������һ��, ��ʹֱ�����ķΣ�
��һ�ɣ�"+weapon2->query("name")+"�㱻"+weapon->query("name")+"���˹�ȥ��\n"NOR;
		target->start_busy(random(2));
		target->receive_damage("qi", skill+random(skill/2));
		weapon2->move(me);
		if (weapon2->query("ownmake")==1||weapon2->query("no_get"))
		{
			weapon2->move(environment(me));
			msg += "ֻ��һ�����죡������ء�\n" NOR;
		}
		me->start_busy(2);
	}
	else
	{
		msg = HIY"$n�����䣬�����ң����������ȣ�����$N, $N��Ծ�ܿ���\n"NOR;
		me->start_busy(3);
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
		���˶Է���Ѫ
		�ٶ�Է�����

	����Ҫ��
		ʥ���100��
		������100��
		����300
		ʹ��ʥ����
HELP
	);
	return 1;
}


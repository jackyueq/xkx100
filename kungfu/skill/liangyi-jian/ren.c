// ren.c  ���ǽ��������ͬ�ʡ�
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

inherit F_SSERVER;
#define PNAME "�����ͬ�ʡ�"
int perform(object me, object target)
{
	int damage;
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
   !SCBORN_D->valid_perform(me,sskill,pfname))
   return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "sword")
		return notify_fail("��ûװ��������ʹ"PNAME"��\n"NOR);

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
		return notify_fail("���"+to_chinese(fskill)+"�Ļ�򲻹����޷�ʹ"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 60 )
		return notify_fail("���"+to_chinese(sskill)+"δ��죬ʹ����"+PNAME+"��\n");

if ((int)me->query("max_neili")<400)
		return notify_fail(RED"��������Ϊ���㣬�޷�����������\n"NOR);

	if ((int)me->query("neili")<200)
		return notify_fail("���������㣬û�ܽ�"PNAME"ʹ�꣡\n");

	msg = HIC"$N����"+weapon->query("name")+HIC"��âԾ�������Ⱪ������������ƺ������Ҵ���$n��
$n��������ƫ�󣬼�������ת����ֻ��һɲ������ɲʱϮ�����ף�\n"NOR;

	if (random(me->query_skill("force")) > target->query_skill("force")/2|| 
	random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 )
	{
		me->start_busy(2);
		if (!target->is_busy())
		target->start_busy(random(3));
		damage = me->query_skill("sword", 1) * 2;
		damage = damage/2 + random(damage);
		target->receive_damage("qi", damage/2,me);
		target->receive_wound("qi", damage/3,me);
		msg +=HIC"$n��æ��ת��ȴ����$N��"+weapon->query("name")+HIC"����û����ƫ�������ͬ�ʡ���
��$n��������һ��"HIR"Ѫ��"HIC"��$nһ��ͷ���㿴���ؿ���ѪӿȪ�����\n"NOR;
		me->add("neili", -damage/5);
	} else
	{
		me->start_busy(2);
		msg +=HIY"����$p����һЦ��������ת����Ȼ$P�Ľ�ʽͻȻ��չ����$p��ǰ\n�����������硣һ����ë��û�˵���\n"NOR;
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
		���ͶԷ�����

	����Ҫ��
		̫����90��
		���ǽ���60��
		����400
HELP
	);
	return 1;
}


// mie.c  �ط�����������𽣡�
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#define PNAME "���𽣡�"
inherit F_SSERVER;
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
   !SCBORN_D->valid_perform(me,sskill,pfname) )
   return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"ֻ�ܶ�ս���еĶ���ʹ�á�\n");
		
	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "sword")
		return notify_fail(RED"��ʲô��Ц��ûװ��������ʹ"PNAME"��\n"NOR);

	fskill = "linji-zhuang";
	bskill = "sword";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 60 )
		return notify_fail("���"+to_chinese(fskill)+"��򲻹���"+PNAME+"������ʽ��\n");

	if( (int)me->query_skill(sskill, 1) < 60 )
		return notify_fail("���"+to_chinese(sskill)+"����������죬��ʹ����"+PNAME+"��\n");

	if ((int)me->query("max_neili") < 400)
		return notify_fail(RED"���������Ϊ���㣬�޷�����"PNAME"��������\n"NOR);

	if ((int)me->query("neili")<400)
		return notify_fail(HIC"����������������û�ܽ�"PNAME"ʹ�꣡\n"NOR);

	msg = HIC "$N����"+weapon->query("name")+HIC+"��âԾ�������Ⱪ�����ó�������ɫ�ʣ����⽥\n"NOR;
	msg += HIC"���ƽ�$n"HIC"��$n"HIC"�������콣�⣬�����Ծ��ֻ��һɲ�����콣\n"NOR;
	msg += HIC"Ӱ��Ϊһ��ֱ��$n"HIC"ǰ�أ�������ף�ֻ��һ����\n"NOR;
	if (random(me->query_skill("force"))>target->query_skill("force")/2 || 
		random(me->query("combat_exp"))>target->query("combat_exp")/3)
	{
		me->start_busy(2);
		target->start_busy(random(3));
		damage = (int)me->query_skill(bskill, 1);
		damage = damage + random((int)(damage*3/5));
//		if (me->query("sex/number")) damage/=10;
		target->receive_damage("qi", (int)(damage/2),me);
		target->receive_wound("qi", damage,me);
		target->receive_damage("jing", damage,me);
		target->receive_wound("jing", (int)(damage/2),me);
		msg +=HIC"$n����û����ܣ�һʽ���ط���������ľ��С��𽣡��˶���\n��������$n�ؿڣ�$nһ��ͷ���㿴���������ؿ�Ю"HIR"Ѫ"HIC"�γ���\n"NOR;
		me->add("neili", -400);
	} else
	{
		me->start_busy(4);
		msg +=HIY"����$p����һЦ��������ת�������ָ��������$P�Ľ��ϣ���\n����$p��໮�����������ˡ�\n"NOR;
		me->add("neili", -200);
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
		���˶Է���������Ѫ

	����Ҫ��
		�ټ�ʮ��ׯ60��
		�ط������60��
		����400
HELP
	);
	return 1;
}


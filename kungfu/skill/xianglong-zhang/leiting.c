//leiting.c  ������һ����
//last modified by suncity may 30th,2002
#include <ansi.h>

inherit F_SSERVER;
#define PNAME "��"+HIY"��"NOR+HIC"��"NOR+HIG"һ"NOR+HIR"��"NOR+"��"
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

	if (objectp(weapon = me->query_temp("weapon")))
		return notify_fail("�������ֲ���ʹ������һ����\n");

	fskill = "huntian-qigong";
	bskill = "strike";
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
		return notify_fail("���"+to_chinese(sskill)+"��������������ʹ��"+PNAME+"��\n");

	if( (int)me->query("neili") < 500 )
		return notify_fail("���������Ϊ�������ߡ�\n");

	msg = HIC "$NĬ�˻���������ʩչ����"+HIY"��"NOR+HIC"��"NOR+HIG"һ"NOR+HIR"��"NOR+"����ȫ����ת��������Խ��Խ�죬������һ�����磬��Ȼ�䣬$N�Ѿ��������÷�����$n��\n"NOR;  

	if( random(me->query("combat_exp"))>(int)target->query("combat_exp")/3)
	{ 
		me->start_busy(3);
		target->start_busy(random(3));

		damage = (int)me->query_skill(bskill, 1)*2+(int)me->query_skill("force", 1);

		damage = damage + random((int)damage/2);

		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage/2,me);
		me->add("neili", -500);
		msg += HIR"$nֻ��һ������Ӱ�ж�Ȼ�ֳ�$N��˫ȭ��������������ܣ������ػ��У������������ڲ��ݣ�������Ѫ��������������\n"NOR;
	}
	else
	{
		me->start_busy(1);
                me->add("neili",-200);
		msg += HIG"����$p������$P����ͼ��������һ�ߡ�\n"NOR;
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

	����Ҫ��
		��������100��
		����ʮ����100��
		����500
HELP
	);
	return 1;
}


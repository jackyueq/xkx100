// anran.c ��Ȼ����
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit F_SSERVER;
#define PNAME "��"+BBLU"��Ȼ����"NOR +"��"

int perform(object me, object target)
{
	int damage;
	string msg;
	int flag;
	string fskill,sskill,bskill,pfname;

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
		return notify_fail("�������ֲ���ʹ��"PNAME"��\n");

	fskill = "yunv-xinfa";
	bskill = "unarmed";
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
	if( (int)me->query_skill(sskill, 1) < 150 )
		return notify_fail("���"+to_chinese(sskill)+"��������������ʹ��"+PNAME+"��\n");
	if( (int)me->query("neili") < 1500 )
		return notify_fail("�������������\n");
//	if (!userp(me) && me->query("id")!="yang guo")
//	  return notify_fail("ֻ����Һ������������Ȼ���ˡ�\n");

	msg = HIB"$N"HIB"����˫Ŀ����Ȼ���£������㱣��������У������ǰֱ�ͣ��Ʒ����̹Ǻ������缱���������$n"HIB"��Ϯ������ \n"NOR;
	damage = (int)me->query_skill(bskill, 1)*4; 
	damage = damage + random(damage); 
	if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/3)
	{
		me->start_busy(3);
		target->start_busy(random(3));
		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage/2,me);
		me->add("neili", -1000);
		msg += RED"$n"RED"�޴��ɶ㣬��$N"RED"˫����ӡ�ؿ��ϣ�һ����Ѫ���������\n"NOR;
	}
	else
	{
		me->start_busy(5);
		msg +=HIG"$n"HIG"��֮�£��������ɣ��Ŵ��Ʒ������������ֻ�����ϱ��Ʒ�ε����ۡ�\n"NOR;
		target->receive_damage("qi",damage/10,me);
		target->receive_wound("qi",damage/20,me);
		me->add("neili", -500);
	}
	message_combatd(msg,me,target);
	if(userp(target)) target->fight_ob(me);
	else if( !target->is_killing(me) ) target->kill_ob(me);
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
		��Ů�ķ�150��
		��Ȼ������150��
		����1500
HELP
	);
	return 1;
}


// cuixin.c ���ľ� 
// Last Modified by winder on Aug. 10 2000

#include <ansi.h>
#define PNAME "�����ľ���"
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

//	if (me->query_temp("weapon") )
//		return notify_fail(PNAME"��ʼʱ�������ű�����\n");

	//�������־���

	fskill = "qingming-xuangong";
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
		return notify_fail("���"+to_chinese(fskill)+"��򲻹���ʹ����"+PNAME+"��\n");
	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail("���"+to_chinese(sskill)+"������죬ʹ����"+PNAME+"��\n");
	if ((int)me->query("neili")<400 || (int)me->query("max_neili")<400)
		return notify_fail(RED"��������Ϊ���㣬�޷�����������\n"NOR);
	msg = HIG "$N"HIG"�͵�һ������һ����ת��$n"HIG"���������$n"HIG"����ӡ����ȥ��\n"NOR;

	if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/4)
	{
		me->start_busy(2);
		target->start_busy(random(3));
		damage = (int)me->query_skill(bskill, 1) * 2;// if 300 strike
		damage = damage + random(damage);  //  damage ƽ�� 900
		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage*2/3,me);
		msg +=HIR"$n"HIR"��æת��ȴ�Ѳ���������һ��ֻ���ú�ͷһ��һ��Ѫ˿����ǹ���������\n"NOR;
		me->add("neili", -damage/5);
	} else
	{
		me->start_busy(2);
		msg += HIY"����$pҲ����ת���ܿ��˺���Ҫ����\n"NOR;
		me->add("neili", -50);
	}
	message_combatd(msg, me, target);
	if(!target->is_fighting(me)) target->fight_ob(me);
//	if(userp(target)) target->fight_ob(me);
//	else if( !target->is_killing(me) ) target->kill_ob(me);
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
		��ڤ����80��
		������100��
		����400
HELP
	);
	return 1;
}


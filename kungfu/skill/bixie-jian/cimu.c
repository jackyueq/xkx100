// cimu.c  ��а��������Ŀ��
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#define PNAME "����Ŀ��"

inherit F_SSERVER;
int perform(object me, object target)
{
	int damage;
	string msg;
	object weapon;
	int flag;
	string fskill,sskill,bskill,pfname;

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
		
		// �������־���
		
	bskill = "sword";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}
	if( (int)me->query_skill(sskill, 1) < 80 )
		return notify_fail("���"+to_chinese(sskill)+"������죬ʹ����"+PNAME+"��\n");

	if ((int)me->query("max_neili") < 400)
		return notify_fail(RED"��������Ϊ���㣬�޷�����������\n"NOR);

	if ((int)me->query("neili") < 200)
		return notify_fail("����������������û�ܽ�"PNAME"ʹ�꣡\n");

	if (target->query_temp("bixie/cimu"))
		return notify_fail(HIR"�Է��Ѿ�����"PNAME"�ˣ�\n"NOR);

	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "sword")
		msg = HIC"$N"HIC"������ָ��£���ֱ۱�����Ѹ���쳣�ִ�$n"HIC"˫Ŀ��\n"NOR;
	else msg = HIC"$N"HIC"���г���һ�񣬽���һ�㱩�����ִ�$n"HIC"����˫Ŀ��\n"NOR;


	if ((int)me->query("dex")>35 && 
	    (int)me->query_skill("bixie-jian", 1) > 400 &&
	    (int)me->query_skill("kuihua-xinfa", 1) > 350 &&
	    me->query("family/master_id") == "dongfang bubai")
	{
		me->start_busy(2);
		target->start_busy(random(5));
		damage = (int)me->query_skill("sword", 1);
		damage = damage*2 + random(damage);
		target->receive_damage("qi", damage*2,me);
		target->receive_wound("qi", damage,me);
		msg += HIC "$nֻ��������һ�㣬˫Ŀһ���ʹ����ǰһ�ڣ���ʱ����ʹ����������Ҳ�����������ˣ�\n"NOR;
		message_combatd(msg, me, target);
	  me->add("neili", -200);
		target->set_temp("bixie/cimu", 1);
		target->set_temp("block_msg/all",1);
//		call_out("cimu_end", (int) 2+random(6), me, target);
	}
	else if (random(me->query_skill("force"))>target->query_skill("force")/2 ||
		random(me->query("combat_exp")) > (int)target->query("combat_exp")/3)
	{
		me->start_busy(2);
		target->start_busy(random(3));
		damage = (int)me->query_skill("sword", 1);
		damage = damage/2 + random(damage);
		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage/2,me);
		msg += HIC "$nֻ��������һ�㣬˫Ŀһ���ʹ����ǰһ�ڣ���ʲôҲ�������ˣ���ʱ����ʹ��������\n"NOR;
		message_combatd(msg, me, target);
		me->add("neili", -200);
		target->set_temp("bixie/cimu", 1);
		target->set_temp("block_msg/all",1);
		call_out("cimu_end", (int) 2+random(6), target);
	} 
	else
	{
		me->start_busy(2);
		me->add("neili", -100);
		msg += HIY"$p�鼱������̧��Ҳ$P���۴�ȥ���ȵ�$P�ؽ�Ծ����\n"NOR;
		message_combatd(msg, me, target);
	}
	
	if(!target->is_fighting(me)) target->fight_ob(me);
	return 1;
}

void cimu_end(object target)
{
	message_combatd(HIY"$N"HIY"Ĩ��Ĩ����"HIR"��Ѫ"HIY"�������ܿ����ˡ�\n"NOR, target);
	target->set_temp("block_msg/all", 0);
	tell_object(target,HIR"������Ĩ������ǰ����Ѫ���ܿ����ˡ�\n"NOR);
	target->delete_temp("bixie/cimu");

	return;
}
string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		ʩ�д̶Է�����Ŀ��ʹ�Է����˲���ʱ��ä
		���˶Է���Ѫ

	����Ҫ��
		��а����80��
		�������400
		����200
HELP
	);
	return 1;
}


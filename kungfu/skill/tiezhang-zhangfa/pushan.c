// pushan.c �����Ʒ� ���������ơ�

#include <ansi.h>

inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";
#define PNAME "���������ơ�"
int perform(object me, object target)
{
	int damage, p;
	string msg, dodge_skill;
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
		
	if( me->query_temp("weapon") )
		return notify_fail("�������ֲ���ʹ���������ƣ�\n");

	if( (int)me->query("max_neili") < 1500 )
		return notify_fail("������������Ϊ���㣬ʹ�������������У�\n");

	if( (int)me->query("neili") < 1200 )
		return notify_fail("�������������㣬ʹ�����������ƾ��У�\n");

	fskill = "guiyuan-tunafa";
	bskill = "strike";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 150 )
		return notify_fail("���"+to_chinese(fskill)+"��������������ʹ"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 150 )
		return notify_fail("���"+to_chinese(sskill)+"��������������ʹ��"+PNAME+"��\n");

	if( (int)me->query_skill(bskill, 1) < 100 )
		return notify_fail("���"+to_chinese(bskill)+"������죬ʹ����"+PNAME+"��\n");

	if( me->query_temp("tiezhang_pushan") )
		return notify_fail("���ʹ���������ƾ��У�Ŀǰ��Ѫ��ӿ���޷��ٴ����ã�\n");

	msg = RED"\n$N���Ӱ�࣬����ֱ�ƶ�����ʹ������$N�����Ʒ��и�����ٱ���������ƣ��Ʒ����һ������ֱ��$n��ȥ��\n"NOR;	
	me->set_temp("tiezhang_pushan", 1);
	if (random(me->query_skill("force")) > target->query_skill("force") /4 )
	{
		me->start_busy(1);
		target->start_busy(1); 
		me->add("neili", -800);
		me->receive_damage("jing", 10);
		damage = (int)me->query_skill(bskill, 1);
		damage = damage*2 + random(damage);
		if(me->query("neili") > target->query("neili")*2 )
			damage += random(damage);
		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage/2,me);
		p = (int)target->query("qi")*100/(int)target->query("max_qi");
		msg += damage_msg(damage, "����");
		msg += "( $n"+eff_status_msg(p)+" )\n";
		call_out("perform2", 2, me, target, p);
	} 
	else
	{
		me->start_busy(2);
		target->start_busy(1);
		me->add("neili", -300);
		tell_object(target, HIY"�㵫��һ���ȷ��������������ǿ���Ѽ���������Ϣ����������æԾ�����ߡ�\n" NOR);
		dodge_skill = target->query_skill_mapped("dodge");
		if( !dodge_skill ) dodge_skill = "dodge";
		msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
		call_out("remove_effect", me->query_con()/6, me);
	}
	message_combatd(msg, me, target); 
	return 1;
}

int perform2(object me, object target, int p)
{
	int damage;
	string msg, dodge_skill;
	
	if (!objectp(target) || target->is_ghost() || 
		environment(target)!=environment(me) || 
		!living(me) || me->query_temp("noliving") || me->is_ghost())
	{
		call_out("remove_effect", me->query_con()/6, me);
		return 1;
	}
	if( !living(target) || target->query_temp("noliving") )
	{
		message_combatd("$N�Ѿ�������ս���ˣ�\n", target);
		call_out("remove_effect", me->query_con()/6, me);
		return 1;
	}
	if( me->query("neili") < 400 )
	{
		message_combatd("$N��Ҫ�����ڶ��ƣ�ȴ�������������ˣ�\n", me);
		call_out("remove_effect", me->query_con()/6, me);
		return 1;
	}
	
	msg = RED"\n$N���ƾ���δ��������Ҳ��������������������������ƿ�쭰�ӿ��$n��\n"NOR;	
	if(random(me->query_skill("force")) > target->query_skill("force")/4 &&
		me->query_skill("strike", 1) > 199 )
	{
		me->start_busy(1);
		target->start_busy(1);
		me->add("neili", -200);
		me->receive_damage("jing", 20);
		damage = (int)me->query_skill("strike", 1);		
		damage = damage*3 + random(damage)*2;
		if(me->query("neili") > target->query("neili")*2 )
			damage += random(damage);
		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage/2,me);
		p = (int)target->query("qi")*100/(int)target->query("max_qi");
		msg += damage_msg(damage, "����");
		msg += "( $n"+eff_status_msg(p)+" )\n";		
		call_out("perform3", 2, me, target, p);
	} 
	else 
	{
		me->start_busy(2);
		me->add("neili", -200);
		tell_object(target, HIY"�㴭Ϣδ�����־�һ�ɾ�������������ż⼲�㣬Ծ�����߱ܿ���\n" NOR);
		dodge_skill = target->query_skill_mapped("dodge");
		if( !dodge_skill ) dodge_skill = "dodge";
		msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
		call_out("remove_effect", me->query_con()/4, me);
	}
	message_combatd(msg, me, target); 
	return 1;
}

int perform3(object me, object target, int p)
{
	int damage;
	string msg, dodge_skill;

	if (!objectp(target) || target->is_ghost() || 
		environment(target)!=environment(me) || 
		!living(me) || me->query_temp("noliving") || me->is_ghost())
	{
		call_out("remove_effect", me->query_con()/4, me);
		return 1;
	}
	if( !living(target) || target->query_temp("noliving") )
	{
		message_combatd("$N�Ѿ�������ս���ˣ�\n", target);
		call_out("remove_effect", me->query_con()/4, me);
		return 1;
	}
	if( me->query("neili") < 700 )
	{
		message_combatd("$N��Ҫ���������ƣ�ȴ�������������ˣ�\n", me);
		call_out("remove_effect", me->query_con()/4, me);
		return 1;
	}
	msg = RED"\n$N˫��һ�ţ�˫���ಢ��ǰ�����˳���$n��ͬ��ǰ���ķ�Բ����ȫ���������ƾ�������֮�£�\n"NOR;
	if(random(me->query_skill("force")) > target->query_skill("force")/4 &&
		me->query_skill("strike", 1) > 249 )
	{
		me->start_busy(2);
		target->start_busy(random(3));
		me->add("neili", -300);
		me->receive_damage("jing", 30);
		damage = (int)me->query_skill("strike", 1);		
		damage = damage*5 + random(damage)*2;
		if(me->query("neili") > target->query("neili")*2 )
			damage += random(damage);
		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage/2,me);
		p = (int)target->query("qi")*100/(int)target->query("max_qi");
		msg += damage_msg(damage, "����");
		msg += "( $n"+eff_status_msg(p)+" )\n";
	}
	else 
	{
		me->start_busy(4);
		target->start_busy(1);
		me->add("neili", -300);
		target->add("jing", -100);
		tell_object(target, HIY"���þ�ȫ����������һ��һ����ҡҡ������վ��������������㿪����������һ����\n" NOR);
		dodge_skill = target->query_skill_mapped("dodge");
		if( !dodge_skill ) dodge_skill = "dodge";
		msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
	}
	call_out("remove_effect", me->query_con()/2, me);
	message_combatd(msg, me, target); 
	return 1;
}

void remove_effect(object me)
{
	if (!me) return;
	me->delete_temp("tiezhang_pushan");
	tell_object(me, HIC"\n�㾭��һ��ʱ�������Ϣ���ֿ���ʹ���������ƾ����ˡ�\n"NOR); 
}

int help(object me)
{
	write(WHT"\n�����Ʒ�֮�������ƣ�"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		�����������ƣ���ʽ�������ƶ���������ٱ

	����Ҫ��
		��Ԫ���ɷ�150��
		�����Ʒ�150��
		������Ϊ1500
		����1200
HELP
	);
	return 1;
}


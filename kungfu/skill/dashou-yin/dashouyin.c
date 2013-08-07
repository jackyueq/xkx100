// dashouyin.c ����ӡ
// Last Modified by winder on Feb. 17 2001

#include <ansi.h>
#include <combat.h>
#include "/kungfu/skill/eff_msg.h";
inherit F_SSERVER;
#define PNAME "������ӡ��"
int perform(object me, object target)
{
	string msg, dodge_skill;					  
	int damage, jiali, attack, defense, p;
	object armor;
	object piece;
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
		
	if( objectp(me->query_temp("weapon")) )
		return notify_fail("��������ʹ�á�����ӡ����\n");

	fskill = "longxiang";
	bskill = "hand";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}
	if( (int)me->query_skill(fskill, 1) < 120 )
		return notify_fail("���"+to_chinese(fskill)+"�ȼ�����������ʹ��"+PNAME+"��\n");
	if( (int)me->query_skill(sskill, 1) < 120 )
		return notify_fail("���"+to_chinese(sskill)+"��������죬�޷�ʹ��"+PNAME+"��\n");
	if( (int)me->query_skill(bskill, 1) < 120 )
		return notify_fail("���"+to_chinese(bskill)+"������죬����ʹ��"+PNAME+"��\n");

	if( !me->query_temp("murong/xingyi") )
	{
		if (me->query_skill_prepared("hand") != "dashou-yin" ||
			me->query_skill_mapped("hand") != "dashou-yin" ||
			me->query_skill_mapped("parry") != "dashou-yin")
			return notify_fail("������û����ַ��ͻ����мܼ�������ӡ��\n");
	}
	if( (int)me->query_str() < 35 )
		return notify_fail("�����������ǿ������ʹ��"PNAME"��\n");
	if( (int)me->query("max_neili") < 1200 )
		return notify_fail("���������Ϊ̫��������ʹ��"PNAME"��\n");
	if( (int)me->query("neili") < 800 )
		return notify_fail("�������̫���ˣ��޷�ʹ�ó�"PNAME"��\n");
	if( (int)target->query_condition("dashouyin"))
		return notify_fail("�Է���������"PNAME"�����ˣ�\n");   
	

	jiali = me->query("jiali")+1;
	attack = me->query("combat_exp")/1000;
	attack += me->query_skill(bskill);
	attack += me->query("neili")/5;
	defense = target->query("combat_exp")/1000;
	defense += target->query_skill("dodge");
	defense += target->query("neili")/7;
	attack = (attack+random(attack+1))/2;
	
	damage = me->query_skill(bskill, 1)/40 * jiali;
	if(damage > 1500) damage = 1500;
	
	message_combatd(BLU"\n$N"BLU"ͻȻ��ɫ���죬����Ĭ���������ԣ�˫�۹ǽ�һ���죬\n��Ȼ�ڿն���������$n"BLU"��ǰ��ȥ����һʽ���ڡ�����ӡ����\n"NOR,me,target);
 
	if( attack > defense )
	{ 
		if( objectp(armor = target->query_temp("armor/cloth")) &&
			armor->query("armor_prop/armor") < 200 &&
			damage > 500)
		{
			message_combatd( HIY"ֻ���⶷�����ӡ����ӡ��$N��$n"HIY"�ϣ�Խ��Խ�󣬾�������÷��飬�ѳ�һ�����ڵ��ϣ�\n"NOR, target, armor);
			armor->unequip();
      seteuid(getuid());
      piece = new("/clone/misc/piece");
      piece->set_name( "�����"+armor->query("name"), ({armor->query("id"),"piece"}) );
      piece->move(environment(target));
      destruct(armor);
			target->reset_action();
		}
		tell_object(target, RED"��ֻ���û����ؿ�һ���ʹ���Ѿ���������ǰ�أ�\n"NOR);
		target->apply_condition("dashouyin", 1+(me->query_str()/8));
		target->receive_damage("qi", damage,  me); 
		target->receive_wound("qi", damage/4, me);
		p = (int)target->query("qi")*100/(int)target->query("max_qi");
		msg = damage_msg(damage, "����");
		msg += "( $n"+eff_status_msg(p)+" )\n";
		message_combatd(msg, me, target);
		me->add("neili", -jiali);
	}
	else
	{
		dodge_skill = target->query_skill_mapped("dodge");
		if( !dodge_skill ) dodge_skill = "dodge";
		message_combatd(SKILL_D(dodge_skill)->query_dodge_msg(target, 1), me, target);
	}
	me->add("neili", -200);
	me->start_busy(2+random(2));		
	return 1;
}
string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
        write(@HELP

	ʹ�ù�Ч��
		�𺦶��־�������Ѫ
		�¶��ִ���ӡ��

	����Ҫ��
		���������120��
		���ڴ���ӡ120��
		�����ַ�120��
		��������35
		����800
		������Ϊ1200
HELP
        );
        return 1;
}
 

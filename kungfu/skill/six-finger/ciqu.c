// ciqu.c ��ȥ����

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";
#define PNAME "����ȥ������"
int perform(object me, object target)
{
	string msg, *limbs;
	int a,b,p,count, damage = 0;
	int arg=(int)(me->query_skill("finger", 1) / 30);
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
		return notify_fail("�������ֲ���ʹ�á���ȥ��������\n");

	fskill = "kurong-changong";
	bskill = "finger";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 160 )
		return notify_fail("���"+to_chinese(fskill)+"��Ϊ�������޷�ʹ��"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 120 )
		return notify_fail("���"+to_chinese(sskill)+"��������죬�޷�ʹ��"+PNAME+"��\n");

		if( (int)me->query_skill("force", 1) < 160 )
			return notify_fail("����ڹ��ȼ�����������ʹ�á���ȥ��������\n");

	if( (int)me->query_str() < 26 )
		return notify_fail("�����������ǿ������ʹ�á���ȥ��������\n");

	if( (int)me->query("neili", 1) < 200 * arg )
		return notify_fail("�����ڵ���������ʹ�á���ȥ���������й�����\n");
	
	if ( !userp(me) && me->query("family/family_name")!="����μ�")
		return notify_fail("ֻ����Һʹ������Ͽ���ʹ�á�\n");

	a=me->query("max_neili",1);
	b=target->query("max_neili",1);

	message_combatd(MAG "$N"MAG"ʮָ������������������򰴣���������������������$N"MAG"ָ����ӿ��������ȥ�����������޾���\n" NOR, me, target);

	if( random(me->query("combat_exp")) > target->query("combat_exp")/2 )
	{
		limbs = target->query("limbs");
		for(count = 0; count < arg; count++)
		{
			message_combatd( replace_string( SKILL_D("six-finger")->query_action(me, me->query_temp("weapon"))["action"], "$l", limbs[random(sizeof(limbs))]) + "��\n\n", me, target);
			damage = damage+200+random(100);
		}    
		damage = (1 + me->query("jiali")/300) * damage*a/b ;
		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage,me);
		p = (int)target->query("qi")*100/(int)target->query("max_qi");
		msg = damage_msg(damage, "����");
		msg += "( $n"+eff_status_msg(p)+" )\n";  

		me->add("neili", -200 * arg);
		me->start_busy(2);
	}
	else
	{
		me->start_busy(arg/2+1);
		me->add("neili", -100*arg);
		target->add("neili", -100);
		msg =RED"\n$n�͵�һ�����㿪�˹������ŵ���ɫ�Ұס�\n" NOR;
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
		����������������������

	����Ҫ��
		������120��
		��������160��
		�����ڹ�160��
		��������26
		�����㹻
HELP
	);
	return 1;
}


// Last Modified by winder on Jul. 9 2001
// yanxue.c  ����ѩ��÷��
#include <ansi.h>

inherit F_SSERVER;
#define PNAME "��"HIW"��ѩ��÷"NOR"��"
int perform(object me, object target)
{
	int damage;
	string msg;
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
		
		//�������־���
		
	fskill = "bingxue-xinfa";
	bskill = "strike";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 50 )
		return notify_fail("���"+to_chinese(fskill)+"��򲻹���ʹ����"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 50 )
		return notify_fail("���"+to_chinese(sskill)+"��������������ʹ��"+PNAME+"��\n");

	if( (int)me->query("max_neili") < 500 )
		return notify_fail("���������Ϊ�������ߡ�\n");

	if( (int)me->query("neili") < 400 )
		return notify_fail("�������������\n");

	msg = HIW"$N"HIW"��ѩ�ķ���תһ���죬ȫ��ֻ��һ�ɺ���������������Хһ����\n�������,ʩչ����"+HIW"��ѩ��÷����˫��һ��һ��,һ��������Ѫ��\n�����$n"HIW"����ǵ�ϯ���ȥ��\n"NOR;
	if(random(me->query_skill(bskill, 1)) > target->query_skill("parry",1)/3)
	{ 
		me->start_busy(1+random(1));
		target->start_busy(random(3));
		damage = (int)me->query_skill(bskill, 1)+(int)me->query_skill("force",1)*2;
		damage = damage/2 + random(damage);
		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage/2,me);
		me->add("neili", -300);
		msg +=HIC"$nֻ����������ϯ����������޿ɶ㣬��һ�Ӵ����㱻���������Ѫ������߷������Ʈȥ��\n"NOR;
	} else
	{
		me->start_busy(2+random(1));
		msg += HIC"����$p������$P����ͼ�������������һ�ߡ�\n"NOR;
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
                �˵���Ѫ

        ����Ҫ��
                ��ѩ�ķ�50��
                ��ѩӳ÷��50��
                ������Ϊ500
                ����400
HELP
        );
        return 1;
}


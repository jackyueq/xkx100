// ningxue.c ��Ѫ��צ
// Last Modified by sir on 5/5/2001

#include <ansi.h>
inherit F_SSERVER;
#define PNAME "��Ѫ��צ"
int perform(object me, object target)
{
	string msg;
	int damage,skill;
	object weapon;
	string limb;
	mapping limbs;
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
		return notify_fail("���������˹���\n");

	if((int)me->query_str() < 30)
		return notify_fail("����������������ʹ����Ѫ��צ��\n");

	fskill = "yunlong-shengong";
	bskill = "claw";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 120 )
		return notify_fail("���"+to_chinese(fskill)+"��Ϊ������Ŀǰ������ʹ��"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 150 )
		return notify_fail("���"+to_chinese(sskill)+"��Ϊ������Ŀǰ������ʹ��"+PNAME+"��\n");

	if((int)me->query("neili") < 800)
		return notify_fail("���������ڲ���������ʹ����Ѫ��צ��\n");

	if( target->is_busy() )
		return notify_fail(target->name()+"Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");

	msg = HIR "$Nʹ������צ��������Ѫ��צ����������ע˫צץ��$n��\n"NOR;

	if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/4)
	{
    if (arrayp(limbs = target->query("limbs")))
         limb = limbs[random(sizeof(limbs))];
    else
         limb = "Ҫ��";
		msg+=HIR "$n��æ��Ų������Ȼ�������ꡱһ����$N"
         HIR "��ָ��ץ��$n" HIR "��" + limb + "��ֻ����$n"
         HIR "һ���ҽУ���Ѫ��ɡ�\n" NOR;
 		skill = me->query_skill(bskill, 1) * 2;
		damage = skill + (int)me->query_skill("force", 1)/2;
		me->add("neili", -300);
		me->start_busy(2);
		target->start_busy(random(3));
		target->receive_damage("qi", damage,me);		
		target->receive_wound("qi", damage/4,me);
		target->receive_damage("jing", damage*7/10,me);
		target->receive_wound("jing", damage/3,me);
		target->add("neili", -600);
	}
	else {
		msg += HIG "����$p������$P����ͼ������ܿ�,��û�����С�\n" NOR;
		me->start_busy(4);
		me->add("neili", -100);
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
                �˵���Ѫ�;���

        ����Ҫ��
                ������120��
                ����צ150��
                ��������30
                ����800
HELP
        );
        return 1;
}


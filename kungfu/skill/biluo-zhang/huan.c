
#include <ansi.h>
 
inherit F_SSERVER;
#define PNAME "��"HIG"�û�����"NOR "��"

int perform(object me,object target)
{
	string msg;
	object weapon, weapon2;
	int skill, ap,dp, damage;
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

	//���ֱ�������

	fskill = "huiyan-xinfa";
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
	if( (int)me->query_skill(bskill, 1) < 100 )
		return notify_fail("���"+to_chinese(sskill)+"��Ϊ����, ʹ����"+PNAME+"��\n");
	if(target->is_busy())
		return notify_fail(target->name() +"Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");
	if( me->query("neili") < 100 )
		return notify_fail("�������������ʹ����"PNAME"��\n");
        msg = HIC "\n$N" HIC "˫�ƶ�Ȼ������ת��һ��"PNAME+HIC"��˫�ƴ��磬�ѽ�$n" HIC "�������Ʒ�֮�С�\n" NOR;
 
   ap = me->query_skill(bskill,1);
   dp = target->query_skill("parry",1);
	if( dp < 1 )		dp = 1;
	if( random(ap) > dp/3 )
	{
		msg += HIR "���$n" HIR "Ŀ��Ͼ�ӣ���ʱ��$N" HIR "��"
                      "����������ʱ��Ŵ��ҡ�\n" NOR;
		target->start_busy(ap/30+2);
		me->start_busy(1);
		me->add("neili",-200);
	}
	else
	{
     msg += HIY "$n" HIY "����$N" HIY "�⼸�е���·����"
                      "�ھ��������Ʒ�Ϭ����Ҳֻ��С�ĵֵ���\n" NOR;          
		me->start_busy(2);
		me->add("neili",-50);
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
		���ͶԷ�����

	����Ҫ��
		�����ķ�100��
		������100��
		�����Ʒ�100��
		����100
HELP
	);
	return 1;
}


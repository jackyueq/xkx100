// Last Modified by ahda on Aug.30 2001
// jinghan.c

#include <ansi.h>
inherit F_SSERVER;
#define PNAME "���󾪺�"
int perform(object me, object target)
{
	string msg;
	int skill, damage, plvl;
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
		
	//���ֱ�������

	fskill = "huiyan-xinfa";
	bskill = "hand";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 50 )
		return notify_fail("���"+to_chinese(fskill)+"��Ϊ����������ʹ��"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 30 )
		return notify_fail("���"+to_chinese(sskill)+"��Ϊ����������ʹ��"+PNAME+"��\n");

	if( (int)me->query("max_neili")< 300 )
		return notify_fail("���������Ϊ������\n"); 

	if( (int)me->query("neili")< 200 )
		return notify_fail("�������������\n"); 

	msg = HIC"���۳����������֮�������󾪺������Ϻ���֮�֡�"HIM"
$N"HIM"ʹ���������ֵľ��������󾪺�������$n"HIM"�����Ŀ�϶�������$n"HIM"��ȫ��ҪѨ��\n"NOR;

	message_combatd(msg, me, target);
	plvl = target->query_skill("parry",1),
	skill = me->query_skill(sskill,1);
	me->start_busy(2);
	me->add("neili", -100);
	if( random(me->query("combat_exp")*(skill/30+1)) >
		(int)target->query("combat_exp")*(plvl/50+1)) 
	{
		msg = HIW"$n��$N��籩����˫������ҪѨ����ʱ������ɢ��\n"NOR;
		damage =80+random((int)me->query("str")*(int)me->query_skill(bskill) /10);
		message_combatd(msg, me, target);
		target->receive_damage("qi", damage,me);
		COMBAT_D->report_status(target);
		return 1;
	} else
	{
		msg = HIG "���$p������$P����ͼ�����к�Ծ����û���ϵ���\n" NOR;
		message_combatd(msg, me, target);
	}
	return 1;
}

string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		�𺦵�����Ѫ

	����Ҫ��
		�����ķ�50��
		��������30��
		������Ϊ300
		����200
HELP
	);
	return 1;
}


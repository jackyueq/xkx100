// Last Modified by winder on May. 15 2001
// diaoshou.c ��������

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
#define PNAME "���������Ρ�"
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
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
		return notify_fail("��������ʹ�á��������Ρ���\n");

	fskill = "hamagong";
	bskill = "hand";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 100 )
		return notify_fail("���"+to_chinese(fskill)+"������죬�޷�ʩչ��"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail("���"+to_chinese(sskill)+"������죬�޷�ʩչ��"+PNAME+"��\n");

	if ( (int)me->query("max_neili") < 500)
		return notify_fail("��������������޷�ʩչ�����������Ρ���\n");

	if ( (int)me->query("neili") < 100)
		return notify_fail("��������������޷�ʩչ�����������Ρ���\n");

	extra = me->query_skill(bskill, 1);
  me->add_temp("apply/strength", extra);
	me->add_temp("apply/attack", extra);
	me->add("neili", -100);
	msg=YEL"$Nȭ���������֣��������ޣ���ɫ����Ļ�������ֵĹ���$n��\n"NOR;
	msg+=HIC"$N��$n��ߴ�������ͻȻ����$n�ұߣ�"NOR;
	message_combatd(msg, me, target);
	COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg=HIR"$N��$n�ұߴ�������ͻȻ����$n��ߣ�"NOR;
	message_combatd(msg, me, target);
	COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg=HIB"$N��$n�ϱߴ�������ͻȻ����$n�±ߣ�"NOR;
	message_combatd(msg, me, target);
	COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add_temp("apply/strength", -extra);
	me->add_temp("apply/attack", -extra);
	me->start_busy(2);
	return 1;
}

string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		����������������

	����Ҫ��
		��󡹦100��
		���ε���100��
		������Ϊ500
		����100
HELP
	);
	return 1;
}


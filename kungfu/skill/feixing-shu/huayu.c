// huayu.c
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit F_SSERVER;
#define PNAME "���컨��"

int perform(object me, object target)
{
	int skill, i;
	string msg;
	object weapon, *ob;
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
		
	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "throwing")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	fskill = "huagong-dafa";
	bskill = "throwing";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}
	if( (int)me->query_skill(fskill, 1) < 100 )
		return notify_fail("���"+to_chinese(fskill)+"������죬����ʹ��"+PNAME+"��\n");
	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail("���"+to_chinese(sskill)+"������죬����ʹ��"+PNAME+"��\n");
	if( (int)me->query("neili") < 300 )
		return notify_fail("�����������ˡ�\n");
	skill = me->query_skill(bskill, 1);
	
	target->receive_damage("qi", (int)skill/ 3,me);

	msg= HIY"ֻ��һ�ɾ����$N"HIY"���Ҳ෢����$N"HIY"���е�"+weapon->name()+"���������$n"HIY"���ֹ�ȥ��\n"NOR;
	
	if(random(skill)>target->query_skill("parry")/2)
	{
		msg += "���$p��$P���˸����ֲ�����\n" NOR;
		target->receive_wound("qi", skill+random(skill),me);
		target->start_busy(1+random(2));
		me->start_busy(1);
		me->add("neili", -200);
	} else {
		msg += "����$p�����$P�����һ����\n" NOR;
		me->start_busy(2);
		me->add("neili", -250);
	}
	message_combatd(msg, me, target);
	ob = all_inventory(me);	 //use out all throwing
	for(i=sizeof(ob)-1; i>=0; i--)
	{
		if( (string)ob[i]->query("equipped")!="wielded" ) continue;
		ob[i]->unequip();
		ob[i]->move(environment(me));
	}
	me->reset_action();
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
		������100��
		������100��
		����300
HELP
	);
	return 1;
}


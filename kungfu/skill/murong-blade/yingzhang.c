// yingzhang.c ��Ӱ��
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
#define PNAME "����Ӱ�ơ�"
int perform(object me, object target)
{
	object weapon, ob;
	string msg, string1;
	int count;
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
 
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("����Ӱ�ơ���ʼʱ��������һ�ѵ���\n");

	fskill = "shenyuan-gong";
	bskill = "blade";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 100 )
		return notify_fail("���"+to_chinese(fskill)+"�������޷�ʹ��"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail("���"+to_chinese(sskill)+"�����������޷�ʹ��"+PNAME+"��\n");
	
	if( (int)me->query_skill(bskill, 1) < 100 )
		return notify_fail("���"+to_chinese(bskill)+"�������ң��޷�ʹ��"+PNAME+"��\n");

	if( !me->query_temp("murong/xingyi") )
	{
		if( (int)me->query_skill("xingyi-strike",1) < 100 )
			return notify_fail("��������Ʋ�����ͨ���޷�ʹ������Ӱ�ơ���\n");
		if( (int)me->query_skill("strike",1) < 100 )
			return notify_fail("��Ļ����Ʒ���Ϊ�������޷�ʹ������Ӱ�ơ���\n");
	}

	if( (int)me->query("neili") < 100 )
		return notify_fail("�������������\n");

	msg = HIC
"$Nһ����Х������"+weapon->query("name")+HIC"��ʱ����һ��ɱ����"HIR"��Ӱ��"HIC"��ɲ�Ǽ�
ɱ������ӿ��,�Ѷ�������һȦ��Ļ֮�С� \n" NOR;
	message_combatd(msg, me, ob);
//	me->clean_up_enemy();
//	ob = me->select_opponent();
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);

	me->add("neili", -50);
	me->start_busy(random(2));

	if(!target->is_fighting(me)) target->fight_ob(me);
	return 1;
}

string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		������������

	����Ҫ��
		��Ԫ��100��
		��������100��
		Ľ�ݵ���100��
		�����Ʒ�100��
		������100��
		����100
HELP
	);
	return 1;
}


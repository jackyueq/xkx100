// lianhuan.c ����
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
#define PNAME "���߽�������"
int perform(object me, object target)
{
	object weapon, ob;
	string msg, string1;
	int count,attack_time,i;
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
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("���߽���������ʼʱ��������һ�ѽ���\n");

	fskill = "shenyuan-gong";
	bskill = "sword";
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
		if( (int)me->query_skill("canhe-finger",1) < 100 )
			return notify_fail("��Ĳκ�ָ������ͨ���޷�ʹ�����߽���������\n");
		if( (int)me->query_skill("finger",1) < 100 )
			return notify_fail("��Ļ���ָ����Ϊ�������޷�ʹ�����߽���������\n");
	}

	if( (int)me->query("neili") < 500 )
		return notify_fail("�������������\n");

	msg = HIC "$N"HIC"����Ľ������������ˮ��˳����Ȼ���ķ�������"+weapon->query("name")+ HIC"��ʱ��â�������������಻��ӿ����ͷ�����ɶ�ֹ����������ʹ�˳�����˲Ϣ֮�䣬ȫ���������һ����Ļ֮�С�\n" NOR;
	message_combatd(msg, me);
	attack_time = 6 + random(2);
	for(i = 0; i < attack_time; i++)
	{
		if (flag==1) target = offensive_target(me);
		if (!objectp(target)) break;
		COMBAT_D->do_attack(me,target,me->query_temp("weapon"),0);
	}
	me->add("neili", -50*i);
	me->start_busy(2+random(3));

	if(!target->is_fighting(me)) target->fight_ob(me);
	return 1;
}

string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		�����������߽�

	����Ҫ��
		��Ԫ��100��
		��������100��
		Ľ�ݽ���100��
		����ָ��100��
		�κ�ָ100��
		����500
HELP
	);
	return 1;
}


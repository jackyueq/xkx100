// banruo-zhang's perform yipai(һ����ɢ)
// Last Modified by winder on Feb. 17 2001

#include <ansi.h>
#define PNAME "һ����ɢ"
inherit F_SSERVER;

#include "/kungfu/skill/eff_msg.h";

int perform(object me, object target)
{
	int damage, p,t_neili,m_neili,t_force,m_force,m_exp,t_exp,
	m_skill,t_skill,m_max_neili,t_max_neili;
	string msg;
	int flag;
	string fskill,sskill,bskill,pfname;

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
		return notify_fail("�������ֲ���ʹ��"PNAME"��\n");

	fskill = "yijinjing";
	bskill = "strike";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}
	if( (int)me->query_skill(bskill, 1) < 120 )
		return notify_fail("���"+to_chinese(bskill)+"������죬ʹ����"PNAME"��\n");
	if( (int)me->query_skill(sskill, 1) < 120 )
		return notify_fail("���"+to_chinese(sskill)+"����������������ʹ��"PNAME"���жԵУ�\n");
	if( (int)me->query_skill(fskill, 1) < 120 )
		return notify_fail("���"+to_chinese(fskill)+"����������������ʹ��"PNAME"���жԵУ�\n");
	if( (int)me->query("max_neili", 1) < 1500 )
		return notify_fail("��������Ϊ���㣬ʹ����"+to_chinese(sskill)+"�ľ��У�\n");
	if( (int)me->query("neili", 1) < 1000 )
		return notify_fail("�������������㣬ʹ����"+to_chinese(sskill)+"�ľ��У�\n");

	t_neili=target->query("neili");
	m_neili=me->query("neili");
	t_max_neili=target->query("max_neili");
	m_max_neili=me->query("max_neili");
	t_force=target->query_skill("force",1);
	m_force=2*me->query_skill("force",1);
	m_exp=me->query("combat_exp");
	t_exp=target->query("combat_exp");
	m_skill=2*me->query("strike",1);
	t_skill=target->query_skill("parry",1);
	msg = WHT"\n$N"WHT"�����ȵ���"HIY"������һ�ƣ���"WHT"˫����������ת�˸�ԲȦ��������$n"WHT"���˹�����\n����δ����$n"WHT"�Ѹ�����������������֮�䣬$N"WHT"��������ŭ������ӿ��������\n\n"NOR;	
	if ((random(m_force) > t_force/2) && (random(m_exp)>t_exp/3))
	{
		me->start_busy(1);
		target->start_busy(1); 
		damage=(m_force+me->query("jiali")+m_skill+(m_max_neili-t_max_neili)/10); 
		damage = damage*3/2 + random(damage);
		target->receive_damage("qi", damage,me);
		target->receive_wound("jing", damage/3,me);
		me->add("neili", -1000);
		p =(int)target->query("qi")*100/(int)target->query("max_qi");
		msg += damage_msg(damage, "����");
		msg += "( $n"+eff_status_msg(p)+" )\n";
		call_out("perform2", 0, me, target, p);    
	} else 
	{
	msg += BLU "$p"BLU"���л��ƣ�����ӭ�˹�ȥ�����������ཻ������������ֻ�������顱��һ����\n˫��������������\n" NOR;
		if (t_neili>m_neili )
		{
			me->start_busy(2);
			target->start_busy(1);
			me->add("neili", -500);
			target->add("neili",-500);
		}
		else
		{
			me->start_busy(2);
			target->start_busy(1);
			me->add("neili", -t_neili/2);
			target->add("neili",-t_neili);
		}
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
		�ش����־�������Ѫ

	����Ҫ��
		�׽120��
		������120��
		�����Ʒ�120��
		����1000
		������Ϊ1500
HELP
	);
	return 1;
}


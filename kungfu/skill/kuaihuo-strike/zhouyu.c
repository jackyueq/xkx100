// Last Modified by winder on Aug. 25 2001
// zhouyu.c ��������

#include <ansi.h>
inherit F_SSERVER;
#define PNAME "���������꡹"
int perform(object me, object target)
{
	string msg;
	int skill, damage, ap, dp;
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
		
	if( me->query_temp("weapon") )
		return notify_fail("ֻ�п��ֲ���ʩչ���������꡹��\n");

	fskill = "panshi-shengong";
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
		return notify_fail("���"+to_chinese(fskill)+"��Ϊ����������ʹ��"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 50 )
		return notify_fail("���"+to_chinese(sskill)+"��Ϊ����������ʹ��"+PNAME+"��\n");

	if( (int)me->query("max_neili")< 300 )
		return notify_fail("���������Ϊ������\n"); 

	if( (int)me->query("neili")< 200 )
		return notify_fail("�������������\n"); 

	me->add("neili", -100);

	if( random(me->query("max_neili")) < 50 )
	{
		write("��⣬û�ɹ���\n");
		return 1;
	}
	
	skill = me->query_skill(bskill, 1);
		msg = HIC"\n$N"HIC"һ��ƽ��������ݵ����飬���д����һ����ʩչ�����������꡹��˫�����·��ɣ�\n$nֻ�������ܶ���$N"HIC"˫�Ƶ�Ӱ�ӣ�������֪����мܣ�������˵�����ˣ�\n\n" NOR;

	ap = skill;
	ap = ( ap * ap * ap / (4 * 400) ) + (int)me->query("qi");
	ap = ap*250 + (int)me->query("combat_exp");
	dp = target->query_skill("parry",1);
	dp = ( dp * dp * dp / (4 * 400) ) + (int)target->query("qi");
	dp = dp*250 + target->query("combat_exp");
	if( random(ap + dp) > dp )
	{
		damage = (int)me->query("max_neili") / 10 + random((int)me->query("eff_qi") /50);
		damage -= (int)target->query("max_neili") / 10 + random((int)target->query("eff_qi") / 50);
		if( damage > 0 )
		{
			msg += HIC "���һ�ƽ��ʵʵȫ��������$n"HIC"��������$n"HIC"�Ĺ�ͷ����ɢ�ˣ�\n" NOR;
			damage +=random((damage*(int)me->query_skill("strike"))/50);
			target->receive_damage("jing", damage, me);
			target->receive_wound("jing", damage/4, me);
			target->receive_damage("qi", damage, me);
			target->receive_wound("qi", damage/3, me);
		}
		else
		{
			msg += HIC "�����$n"HIC"������������$N"HIC"����������࣬˫�����˲��ᣡ\n" NOR;
			damage -=random((-damage*(int)target->query_skill("strike"))/80);
			me->receive_damage("jing", -damage, target);
			me->receive_damage("qi", -damage, target);
			me->improve_skill("kuaihuo-strike", 1, 1);
		}
	}
	else msg += "���Ǳ�$n�㿪�ˡ�\n";

	message_combatd(msg, me, target);
	if( damage > 0 ) COMBAT_D->report_status(target);
	else if( damage < 0 ) COMBAT_D->report_status(me);

	if( !target->is_fighting(me) ) target->fight_ob(me);

	me->start_busy(3);
	return 1;
}

string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		�𺦵��־�������Ѫ����Ҳ���ܱ����ַ����ܴ�

	����Ҫ��
		��ʯ��50��
		���ʮ����50��
		������Ϊ300
		����200
HELP
	);
	return 1;
}



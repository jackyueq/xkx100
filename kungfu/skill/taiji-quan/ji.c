// ji.c ̫��ȭ�������־�
// Last Modified by winder on Aug. 18 2002

#include <ansi.h>

inherit F_SSERVER;
#define PNAME "�������־�"
string *taiji_msg = ({"��ȸβ","����","��������","�׺�����","§ϥ����","��������","��̽��","����ʽ","������","�𼦶���","��Ů����","��������","�乭�仢","������ɽ",});

int perform(object me, object target)
{
	int damage, force;
	string msg, *limbs;
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

	if( me->query_temp("weapon"))
		return notify_fail("���ȷ������е�������˵�ɣ���\n");     
		
	fskill = "taiji-shengong";
	bskill = "unarmed";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 100 )
		return notify_fail("���"+to_chinese(fskill)+"�����ߣ������������˵С�\n");

	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail("���"+to_chinese(sskill)+"������죬ʹ����"+PNAME+"��\n");

	if( (int)me->query("neili", 1) < 500 )
		return notify_fail("����������������ǿ��ʹ�á������Ƿ��Ӳ������������ģ�\n");

	if( (int)me->query("jing", 1) < 100 )
		return notify_fail("�����ھ���������ǿ��ʹ�á������Ƿ��Ӳ������������ģ�\n");		     
		
	limbs = target->query("limbs");
	msg = CYN"\n$Nʹһ��̫��ȭ��"+taiji_msg[random(sizeof(taiji_msg))]+"�����ҽ�ʵ������飬����"RED"������"CYN"�־���ճ��ճ�棬�����Ѵ�ס$p"+limbs[random(sizeof(limbs))]+"��\n"NOR;
	
	force = me->query_skill("force", 1) + target->query_skill("force", 1);

	if(random(me->query_skill("unarmed", 1)) > target->query_skill("parry",1)/3)
	{
		me->start_busy(2);
		if(!target->is_busy()) target->start_busy(random(2));
		damage = (int)me->query_skill("force", 1) * 2;
		damage = damage+ (int)me->query_skill(bskill, 1);
		if(me->query("max_neili") > target->query("neili")*2)
			damage *= 2;
		else if(me->query("max_neili") > target->query("neili")*3/2)
			damage += random(damage);
		else if(me->query("max_neili")*2 < target->query("neili")) damage /= 2;
		else if(me->query("max_neili") < target->query("neili")) damage -= random(damage);
		else damage = damage/2 + random(damage);
		if(damage> 1000) damage = 1000; 
		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage/2,me);
		me->add("neili", -(damage/4));
		me->add("jing", -50);
		msg += HIR "����$P�ᾢ������$p����ôһ�������ӱ��Լ��ľ������ò���������ǰһ�壬���������\n"NOR;       
		} 
	else{
		me->start_busy(3);
		me->add("jing", -25);
		me->add("neili", -150);
		msg += HIY"$p�����龰��һ�����棬��æ�ջ��Լ��ľ�����������ã�\n"NOR;
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
		���˶Է���Ѫ
		����������ΪԽ���˺���Խ��

	����Ҫ��
		̫����100��
		̫��ȭ100��
		����500
HELP
	);
	return 1;
}


// zuida.c ������� [�������]
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

inherit F_SSERVER;
#define PNAME "���������"
void remove_effect(object me, int amount, int amount1);

int perform(object me, object target)
{
	object weapon;	
  	string msg;
	int count, count1, cnt, skill;
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
/*
	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"ֻ�ܶ�ս���еĶ���ʹ�á�\n");
*/
	if (!objectp(weapon = me->query_temp("weapon")) || 
	(string)weapon->query("skill_type") != "club")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if( (int)me->query_temp("jingang") ) 
		return notify_fail("���Ѿ����˴�����ͨ�ˡ�\n");

	if( (int)me->query_temp("zuida") ) 
		return notify_fail("���Ѿ����˹����ˡ�\n");

	if( (int)me->query_temp("powerup"))
		return notify_fail(HIG "���Ѿ������ڹ������ˣ�û�и��������ʹ�ð������\n"NOR);

	if( (int)me->query_str() < 25 )
		return notify_fail("��ı���������Ŀǰ����ʹ�ô˾�����\n");
		
	fskill = "hunyuan-yiqi";
	bskill = "club";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 60 )
		return notify_fail("���"+to_chinese(fskill)+"��Ϊ�������޷�ʹ��"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 90 )
		return notify_fail("���"+to_chinese(sskill)+"��������죬�޷�ʹ��"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 90 )
		return notify_fail("���"+to_chinese(sskill)+"��Ϊ����������ʹ��"+PNAME+"��\n");

	if( (int)me->query("neili") < 500 )
		return notify_fail("����������㣡\n");

	cnt =(int)( (int)me->query_condition("drunk") / 3 );
	if( cnt < 2 )
		return notify_fail("������ⲻ�㼤�����\n");

	msg = HIY"$Nʹ����������ľ�����������򡹣�������Ȼ����, ����Ȼ�ӿ죡\n" NOR;
	
   	message_combatd(msg, me, target);
	skill = me->query_skill("club", 1);
	count = me->query("str") * random(cnt + 1);
	count1 = me->query("dex") * random(cnt + 1);
	if (count > 100);
	   else (count = 100);
	if (count < 50);
	   else (count =50);
	if (count1 > 60);
	   else (count1 = 60);
	if (count1 < 50);
	    else (count1 =50);
	me->add_temp("apply/strength", count);
	me->add_temp("apply/dexerity", count1);
	me->set_temp("zuida", 1);

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, count, count1 :), skill /3 );

	me->add("neili", -150);
   	return 1;
}

void remove_effect(object me, int amount, int amount1)
{
	if ( (int)me->query_temp("zuida") ) 
	{
		me->add_temp("apply/strength",-amount);
		me->add_temp("apply/dexerity",-amount1);
		me->delete_temp("zuida");
		tell_object(me, HIY "��İ�������˹���ϣ��������ջص��\n" NOR);
		me->start_busy(4);
	}
}
string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		��ǿ�Լ��Ĺ������ͷ�����

	����Ҫ��
		��Ԫһ����60��
		�������90��
		��������90��
		����500
		��������25
		����
HELP
	);
	return 1;
}


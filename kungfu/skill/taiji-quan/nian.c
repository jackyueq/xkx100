// nian.c ̫��ȭ��ճ���־�
// Last Modifyed by Winder on Jan. 14 2002

#include <ansi.h>

inherit F_SSERVER;
#define PNAME "��ճ���־�"
int perform(object me, object target)
{
	object ob;
	string msg;
	int skill,busytime=0;
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

	if( objectp(ob = me->query_temp("nian")) )
	{
		if( ob->is_fighting(me) )
		return notify_fail("���Ѿ���ճ��ճ������ˡ�\n");
	}

	if (objectp(me->query_temp("weapon")))
		return notify_fail("�������֡�\n");
		
	if( (string)target->query("race") != "����" )
 		return notify_fail("�������Ҫô��\n");

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
		return notify_fail("���"+to_chinese(fskill)+"��Ϊ����������ʹ��"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail("���"+to_chinese(sskill)+"������죬����ʹ��"+PNAME+"��\n");

	if( !me->query_temp("murong/xingyi") )
	{
		if( !me->query_temp("taiji") && (int)me->query("jiali") )
			return notify_fail("̫��ȭ�������У�����������������ʹ������ճ���־���\n");
	}
	if(me->query("neili")<100)
		return notify_fail("����������㡣\n");
  skill = (int)me->query_skill(sskill, 1);
	msg = HIY"\n$N���ִ���$n�����֣�ת��һ����Ȧ��һ�ɼ�ǿ������������$p���֣�����̫�����֡�\n";

	me->recieve_damage("qi", 50);
	me->recieve_damage("jing", 50);
	me->add("neili",-60);

	if( random(me->query("combat_exp") * me->query_int() / 100) 
		> (int)target->query("combat_exp") * target->query_int() / 200 )
	{
//		msg += "���$p��$Pճ���õ���ײײ�������������㲻�ȣ������оƻ��ԡ�\n" NOR;
		msg += "���������಻�ϣ�һȦ��������һȦ��$n��˫���ƺ�ȫ��$Pճס�ˡ�\n"NOR;
		me->set_temp("nian", target);
		me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), skill/6);      
	}
	else
	{
		switch( random(3) )
		{
			case 0: msg += "$p��æʹ����ǧ��׹��֮����ס���Ρ�\n" NOR; break;
			case 1: msg += "$p���ұ�ӣ�б��������\n" NOR; break;
			case 2: msg += "$nȫ������һ��$P˫�ְ�����ס����$pԾ��Ȧ�⣡\n" NOR; break;
		}
		me->start_busy(1 + random(3));
	}
	message_combatd(msg, me, target);
	return 1;
}

void remove_effect(object me)
{
	if( objectp(me->query_temp("nian")) )
	{
		me->delete_temp("nian");
		if( me->is_fighting() )
			message_combatd("\n$N����һ�ɣ�ճ��жȥ��\n", me);
	}
}
/*
�뵽�������һ������Ҳ���Լ����˳��������ɵú������¡�����һ�ɣ�ճ��жȥ��
�ϵþ�ƣ���������Ѷ�����
*/

string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		ʹ�����޷��뿪

	����Ҫ��
		̫����100��
		̫��ȭ100��
		��̫���ķ��򲻼���
HELP
	);
	return 1;
}


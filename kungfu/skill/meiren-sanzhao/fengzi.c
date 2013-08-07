// fengzi.c
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit F_SSERVER;
#define PNAME "��������"
int perform(object me, object target)
{
	int level;
	string msg;
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

	if( (me->query("gender") != "Ů��" || me->query_per() < 20) &&	!wizardp(me) )
		return notify_fail("�����⸱���ݣ���������ô����Ҳû�˶࿴��һ�۵ġ�\n");

	if( target->query("gender") != "����" )
		return notify_fail("��ô�ˣ���Ū��ɧҲҪ�Ҹ���ȷ����ɣ�\n");

	fskill = "dulong-dafa";
	bskill = "sword";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 50 )
		return notify_fail("���"+to_chinese(fskill)+"������죬����ʹ��"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 60 )
		return notify_fail("���"+to_chinese(sskill)+"������죬����ʹ��"+PNAME+"��\n");

	if( (int)me->query("neili") < 300 )
		return notify_fail("����������㣬����û����ʲô�����ˡ�\n");

	if( target->query_temp("shenlong/fengzi") )
		return notify_fail("���Ѿ�������㵹�ˣ��㻹�˷�ʲô���飿\n");

	level = target->query_cps()/2;
	me->add("neili", -200);
	me->start_busy(1);
	if( target->query_cps() < random(me->query_per() * 2) )
	{
		message_combatd(HIC"�����У�ȴ��$N"HIC"æ�в��ң�����$n"HIC"����չ��¶��һЦ���˵����������������ϼ����ɫ�������ޣ�$n���в���һ������Ȼ����һ���׽��ĸо�������Ҳ������ã������\n" NOR, me, target);
		target->set_temp("shenlong/fengzi", 1);
		target->add_temp("apply/composure", -level);
		target->start_busy(random(3)+1);
		target->start_call_out( (: call_other, __FILE__, "remove_effect", target, level:), 30);
	}
	else
	{
		message_combatd(HIY"ֻ��$N"HIY"����$n"HIY"����¶��һЦ��¶����������һ˿û����ȥ��"HIG"��Ҷ"HIY"��\n" NOR, me, target);
	}
	return 1;
}
void remove_effect(object target, int level)
{
	target->delete_temp("shenlong/fengzi");
	target->add_temp("apply/composure", level);
	message_combatd(HIG"$N��ã�������Ȼһ������ͷ�͵�һ��æ��£����������\n" NOR, target);
}
string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		�ķ��Լ�������
		������ͶԷ��Ķ���

	����Ҫ��
		������50��
		��������60��
		����ΪŮ��
		����Ϊ����
		����300
HELP
	);
	return 1;
}


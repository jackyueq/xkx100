// yingxiong.c
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit F_SSERVER;
#define PNAME "����Ӣ��"
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
		
		//�������־���
		
	if( me->query("gender") != "����" && !wizardp(me))
		return notify_fail("�����⸱����ǻ��Ҳ�������������ˡ����¸����ʵ�ɡ�\n");

	fskill = "dulong-dafa";
	bskill = "finger";
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
		return notify_fail("����������㣬����û����Ӣ���ˡ�\n");

	if( me->query_temp("shenlong/yingxiong") )
		return notify_fail("���Ѿ��ڴ��Ӣ�۵����ˣ�����������\n");

	level = me->query_cor()/3;
	me->add("neili", -200);
	me->start_busy(1);
	if( target->query_cor() < random(me->query_cor() * 2) )
	{
		message_combatd(HIY"$N"HIY"Խ��Խ�����ͣ�������������һ����������Ӣ�ۣ�������һ�ɺ�����$N�������𣬶�ʱ�����׺�������\n" NOR, me, target);
		me->set_temp("shenlong/yingxiong", 1);
		me->add_temp("apply/courage", level);
		target->start_busy(random(3)+1);
		me->start_call_out( (: call_other, __FILE__, "remove_effect", me, level:), 30);
	}
	else
	{
		message_combatd(HIG"�����е�$N����$n�󺰣���������������������δ�ˣ��ͱ�$n�ȵ���æ���ҡ�\n" NOR, me, target);
	}
	return 1;
}
void remove_effect(object me, int level)
{
	me->delete_temp("shenlong/yingxiong");
	me->add_temp("apply/courage", -level);
	message_combatd(HIY"$NͻȻ�е��ĵ�һ��ʧ�䣺������Ӣ�ۣ������ڣ����һ��ˣ���ʱ������Ȼ��\n" NOR, me);
}
string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		�ķ��Լ�������
		�������Լ��ĵ�ʶ

	����Ҫ��
		������50��
		Ӣ������60��
		����Ϊ����
		����300
HELP
	);
	return 1;
}


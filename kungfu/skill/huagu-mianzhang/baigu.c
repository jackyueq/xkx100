// baigu.c �׹�ɭȻ 
// Last Modified by sir on 4/27/2001

#include <ansi.h>
#define PNAME "���׹�ɭȻ��"
inherit F_SSERVER;
int perform(object me, object target)
{
	int damage;
	string msg;
	object weapon;
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

	if( me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail(PNAME"��ʼʱ�������ű�����\n");

	fskill = "dafa";
	bskill = "strike";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 100 )
		return notify_fail("���"+to_chinese(fskill)+"��򲻹���ʹ����"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 150 )
		return notify_fail("���"+to_chinese(sskill)+"������죬ʹ����"+PNAME+"��\n");

	if ((int)me->query("neili")<400 || (int)me->query("max_neili")<400)
		return notify_fail(RED"��������Ϊ���㣬�޷�����������\n"NOR);

	msg = BLU "$N"BLU"���ޱ��飬��Ȼ������ϣ�����$n"BLU"��ת��Ȧ���͵�����һ����ת��$n"BLU"��ǰ�����ֻ���һ����Ȧ����$n"BLU"����ӡ����ȥ��\n"NOR;

	if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/3)
	{
		me->start_busy(2);
		target->start_busy(random(3));
		damage = (int)target->query("neili")/2;
		if (damage < 300) damage = 300;
		if (damage > target->query("neili")) damage = target->query("neili");
		target->add("neili",-damage);		
		msg +=CYN"$n"CYN"��æ����ȴ�Ѳ�����ֻ�����������Ѿۣ�������������̱����\n"NOR;
		me->add("neili", -damage/4);
	} else
	{
		me->start_busy(2);
		msg += HIY"����$pҲ��������бԾ���ܿ��˵���Ҫ����\n"NOR;
		me->add("neili",-100);
	}
	message_combatd(msg, me, target);
	if(!target->is_fighting(me)) target->fight_ob(me);
	return 1;
}
string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		���˶Է�����
		���ͶԷ�����

	����Ҫ��
		������100��
		��������150��
		����400
HELP
	);
	return 1;
}


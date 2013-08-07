// ju.c �����۶�
// Last Modified by winder on Mar. 10 2000
 
#include <ansi.h>
 
inherit F_SSERVER;
#define PNAME "�������۶���"
int perform(object me,object target)
{
	string msg;
	object weapon,  target_w, *inv;
	int skill, ap, dp, equip;
	int neili_wound, qi_wound ;
	object piece;
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

	if( me->query_temp("htz_ju"))
		return notify_fail(HIR"���Ѿ����ˡ������۶����ˡ�\n"NOR);
		
	if (objectp(weapon = me->query_temp("weapon")))
		return notify_fail("���������˹���\n");

	fskill = "xiantian-qigong";
	bskill = "strike";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 135 )
		return notify_fail("���"+to_chinese(fskill)+"�ȼ�����, ����ʹ��"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 135 )
		return notify_fail("���"+to_chinese(sskill)+"�ȼ�����, ����ʹ��"+PNAME+"��\n");

	if( me->query("neili") < 800 )
		return notify_fail("��������������޷��˹���\n");

	if( me->query("max_neili") < 1000 )
		return notify_fail("���������Ϊ�������޷��˹���\n");

	skill = me->query_skill(bskill,1);
 
	msg = HIC "$N"HIC"�͵�����������һ��"HIB"����"HIC"ֱð����ǰ�����漴���һ
�����������ƣ�һ��������£��������۶�����\n"NOR;

	ap = me->query("combat_exp");
	dp = target->query("combat_exp") / 2;

	if( dp < 1 )
		dp = 1;
	if( random(ap) > dp )
	{
		if(userp(me))
			me->add("neili",-600);
		target_w = target->query_temp("weapon");
		msg += HIC"$N��������ȫ���صø��ǳ��ȣ�\n"NOR;

		if (target->query_temp("weapon") ||
			target->query_temp("secondary_weapon"))
		{
			target_w->unequip();
			target->reset_action();
			msg += HIY"ȴֻ����һ�󶡵����죬������Ƭ����һ�أ�\n"NOR;
      	seteuid(getuid());
      	piece = new("/clone/misc/piece");
      	piece->set("long", "һ�ѱ�������Ƭ��\n");
      	piece->set_name( target_w->query("name") + "����Ƭ", ({target_w->query("id"),"piece"}) );
      	piece->move(environment(target));
     		destruct(target_w);
		}
		me->add_temp("apply/attack", -skill/3);
		me->add_temp("apply/dodge", skill/4);
		me->set_temp("htz_ju", 1);

		me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/3, skill/4 :), skill/3);
//		me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/3, skill/3 :));

		me->start_busy(random(2));
	}
	else
	{
		msg += HIC"$n��$Nв�¿��Ŵ�¶�������������ȵ�$N��æ���ƣ�\n"NOR;
		if(userp(me)) me->add("neili",-600);
		me->start_busy(4);
	}
	message_combatd(msg, me, target);

	if(!target->is_fighting(me)) target->fight_ob(me);

	return 1;
}

void remove_effect(object me, int a_amount, int d_amount)
{
	me->add_temp("apply/attack", a_amount);
	me->add_temp("apply/dodge", -d_amount);
	me->delete_temp("htz_ju");
	tell_object(me, HIY "��������۶�������ϣ��������ջص��\n"NOR);
}

string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		�����Լ��Ĺ������ͷ�����
		�п��ܻٻ��Է�����

	����Ҫ��
		��������135��
		�����135��
		����1000
HELP
	);
	return 1;
}


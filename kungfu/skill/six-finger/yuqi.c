// yuqi.c Ԧ����
// Last Modified by winder on Mar. 10 2000
 
#include <ansi.h>
inherit F_SSERVER;
#define PNAME "��Ԧ������"
int perform(object me,object target)
{
	string msg;
	object weapon, target_w,piece;
	int skill, ap, dp, equip;
	int neili_wound, qi_wound ;
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
		
	if (objectp(weapon = me->query_temp("weapon")))
		return notify_fail("���������˹���\n");

	fskill = "kurong-changong";
	bskill = "finger";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 150 )
		return notify_fail("���"+to_chinese(fskill)+"�ȼ�����, ����ʹ"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 120 )
		return notify_fail("���"+to_chinese(sskill)+"�ȼ�����, ����ʹ"+PNAME+"��\n");

	if( me->query_str() < 30)
		return notify_fail("��ı����������޷��˹���\n");
 
	if( me->query("neili") < 1500 )
		return notify_fail("��������������޷��˹���\n");
 
	skill = me->query_skill(bskill,1);
	msg = HIY "$N��Ȼ��ͷ���ң�ʮָ���죬��Ϣ������ֱ�������޾�����ʱ
�佣���ݺᣬ��������\n"NOR;


	ap = me->query("combat_exp") + skill * 400;
	dp = target->query("combat_exp") / 2;

	if( dp < 1 ) dp = 1;
//	if(userp(me)) me->add("neili", -800);
	if( random(ap) > dp )
	{
		qi_wound = (int)me->query_skill(bskill,1) * 2;
		qi_wound = qi_wound/2 + random(qi_wound);
		if(qi_wound > target->query("qi"))
			qi_wound = target->query("qi");
		target->receive_damage("qi", qi_wound,me);
		target->receive_wound("qi", qi_wound,me);
		target->start_busy(2);
		me->start_busy(random(3));
		me->add("neili", -1000);

		msg += HIR"$n��ʱ�����޴�ȫ���ʹ׶�ģ���Ѫ����ɶ�Զ��\n"NOR;
		if (objectp(target_w = target->query_temp("weapon")))
		{
			target_w->unequip();
			target->reset_action();
      	seteuid(getuid());
      	piece = new("/clone/misc/piece");
      	piece->set("long", "һ���������£����������Ƭ��\n");
      	piece->set_name( target_w->query("name") + "����Ƭ", ({target_w->query("id"),"piece"}) );
      	piece->move(environment(target));
     		destruct(target_w);
			msg += HIY "ͬʱֻ������������һ�����������������$n�پ�����һ�𣬱����������������ײ�����ֶ�����\n" NOR;
		}
	}
	else
	{
		msg += HIG "ֻ��$n���Ų�æ������һ���������$N��������\n"NOR;
		me->start_busy(4);
		me->add("neili", -500);
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
		���˶Է���Ѫ
		��ٶԷ�����

	����Ҫ��
		��������150��
		������120��
		����1500
		��������30
HELP
	);
	return 1;
}


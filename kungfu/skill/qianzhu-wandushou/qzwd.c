// qianzhu-wandushou.c ǧ����
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

inherit F_SSERVER;
#define PNAME "ǧ����"
int perform(object me, object target)
{
	string msg;
	int damage, skill;
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
		
		//���ֱ�������
		
	fskill = "wudu-shengong";
	bskill = "hand";
	pskill = "five-poison";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
		pskill = "shenyuan-gong";
	}

	if( (int)me->query_skill(fskill, 1) < 80 )
		return notify_fail("���"+to_chinese(fskill)+"�Ĺ�������������ʹ��"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail("���"+to_chinese(sskill)+"��Ϊ������������ʹ��"+PNAME+"��\n");

	if( (int)me->query_skill(pskill, 1) < 100 )
		return notify_fail("���"+to_chinese(pskill)+"̫�ͣ�����ʹ��"+PNAME+"��\n");
//	if( !userp(me))
//		return notify_fail("ֻ����Ҳ���������\n");
	if((int)me->query("max_neili") < 700)
		return notify_fail("��������Ϊ����������ʹ��"PNAME"��\n");

	if((int)me->query("neili") < 500)
		return notify_fail("����������������ʹ��"PNAME"��\n");

	if(me->query_temp("qzwd_used"))
		return notify_fail("���ʹ�ù�ǧ���򶾣��޷��ڶ�ʱ������۶�����\n");

	skill = me->query_skill(bskill,1);
	msg = HIR "$N"HIR"һ����Ц�����������һָ��$n"HIR"��ü�ĵ�ȥ��\n";
	message_combatd(msg, me, target);

	if( random(skill) > random((int)target->query_skill("dodge",1)*2/3))
	{
		msg=HIR"ֻ��һ�ƺ�����$N"HIR"��ָ��͸����ֻһ����û��$n"HIR"��ü�ģ�\n"NOR;
		message_combatd(msg, me, target);
		if(target->query_skill("force", 1) > skill * 12 /10 &&
			random(2)==0)
		{
			msg = RED"$N��Ȼ����ָ����һ�����εľ��������ţ�������ֻ��\n$nһ����ȣ�$N��ʱ��һ�����ݰ㱻����Զ����\n" NOR;
			message_combatd(msg, me, target);
			msg = RED"$Pֻ����һ����ɽ�ľ���˳ָ���͹�������ֻ����ȫ������ܡ�\n��Ȼ�ؿ�һʹ�����ɡ��ۡ���һ���³�һ�ں�Ѫ��\n" NOR;
			message_combatd(msg, me);
			damage = skill +(int)me->query_skill("force",1);
			if(damage < 50 ) damage = 50;
			me->receive_wound("qi", damage,target);
			me->add("neili", -100);
			me->start_busy(2);
		}
		else{
			msg = HIR"$n"HIR"����һ���Һ�ˤ���ڵأ�������ʹ���������һ�ţ�\n" NOR;
			message_combatd(msg, me, target);
			damage= skill + (int)me->query_skill("force", 1)/2;
			if(damage > 900 ) damage = 900;
			target->receive_wound( "qi",damage,me);
			if( me->query_skill(pskill, 1) > 100)
			{
				target->apply_condition("snake_poison", (int)target->query_condition("snake_poison") + 50 );
				target->apply_condition("wugong_poison", (int)target->query_condition("wugong_poison") + 50 );
				target->apply_condition("zhizhu_poison", (int)target->query_condition("zhizhu_poison") + 50 );
				target->apply_condition("xiezi_poison", (int)target->query_condition("xiezi_poison") + 50 );
				target->apply_condition("chanchu_poison", (int)target->query_condition("chanchu_poison") + 50 );
			}
			me->add("neili", -300);
			target->start_busy(4);
		}
	}
	else {
		msg = HIG "����$n����׼����һ����¿����������������һ�С�\n" NOR;
		me->start_busy(4);
		message_combatd(msg, me, target);
		me->add("neili", -100);
	}
	if( !target->is_killing(me) ) target->kill_ob(me);
	me->set_temp("qzwd_used",1);
	call_out ("qzwd_used", 6,me);
	return 1;
}
void qzwd_used(object me)
{
	me->delete_temp("qzwd_used");
}
string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		���˶Է���Ѫ
		ʹ���������嶾���ߡ�Ы�ӡ���򼡢��ܡ�֩�룩

	����Ҫ��
		�嶾��80��
		�嶾����100��
		ǧ������100��
		������Ϊ700
		����500
HELP
	);
	return 1;
}


// tianlei.c �����Ʒ� ����������
// Last Modified by winder on Aug. 28 2001

#include <ansi.h>
inherit F_SSERVER;
#define PNAME "����������"
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
   !SCBORN_D->valid_perform(me,sskill,pfname))
   return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"ֻ�ܶ�ս���еĶ���ʹ�á�\n");
		
	if( objectp(me->query_temp("weapon")) )
		return notify_fail("�������ֲ���ʹ����������\n");

	fskill = "guiyuan-tunafa";
	bskill = "strike";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 120 )
		return notify_fail("���"+to_chinese(fskill)+"��δ���ɣ�����ʹ��"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 120 )
		return notify_fail("���"+to_chinese(sskill)+"������죬����ʹ��"+PNAME+"��\n");

	if( (int)me->query("neili", 1) < 600 )
		return notify_fail("�������������㣬����ʹ����������\n");	
	msg = HIY"\n$N��Ȼ������һ������ �� ������˫����糵������������һ�����������ƿ�쭶������Ʋ��ɵ���\n"NOR;

	if( weapon = target->query_temp("weapon") )
	{
		if( random(me->query_str()) > (int)target->query_str()/2 )
		{
			msg +=HIM"\n$pֻ���û���һ�ȣ����ƻ��ھ�ʹ������" + weapon->query("name") + HIM+"���ֶ�����\n" NOR;
			message_combatd(msg, me, target);
			(target->query_temp("weapon"))->move(environment(target));
		}
		else
		{
			msg +=HIY"\n$pΣ����ͻȻ���ط����������ܹ���������һ�������ŵ���ɫ�԰ף�\n" NOR;
			message_combatd(msg, me, target);
		}
		me->start_busy(1);
	}
	else
	{
		if (random(me->query_skill("force")) > target->query_skill("force")/2 )
		{
			me->start_busy(3);
			target->start_busy(random(3));
			damage = (int)me->query_skill("force", 1);
			damage += (int)me->query_skill("strike", 1);
			damage = damage * 2 + random(damage);
			target->receive_damage("qi", damage,me);
			target->receive_wound("qi", damage / 2,me);
			if( damage < 300 ) msg += HIY"\n���$n��ɫһ�±�òҰף��������������˺ü�����\n"NOR;
			else if(damage < 400 ) msg += HIY"\n������صػ��У�$n���ۡ���һ���³�һ����Ѫ��\n"NOR;
				else if(damage < 500 ) msg += RED"\n������䡹��һ����$nȫ����Ѫ������������Ѫ���������\n"NOR;
					else msg += HIR"\n���ֻ���������������죬$nһ���ҽУ���̲�����������ȥ����\n"NOR;
		}
		else 
		{
			me->start_busy(1);
			msg +=HIY"\n$pΣ����ͻȻ���ط����������ܹ���������һ�������ŵ���ɫ�԰ף�\n" NOR;
		}
		message_combatd(msg, me, target);
	}
	me->add("neili", -600);
	return 1;
}

string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		�ٶ�Է����л��˺��Է���Ѫ

	����Ҫ��
		��Ԫ���ɷ�120��
		�����Ʒ�120��
		�Ϲٽ����״�����
		����600
HELP
	);
	return 1;
}


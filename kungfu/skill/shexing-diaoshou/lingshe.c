// lingshe.c ���߷���
// Last Modified by sir on 4/26/2001

#include <ansi.h>

inherit F_SSERVER;
#define PNAME "���߷���"
int perform(object me, object target)
{
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
//	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
        return notify_fail("��Ҫ��˭ʹ�����߷��裡\n");

	if( environment(me)->query("no_fight") )
		return notify_fail("�����ﲻ�ܹ������ˡ�\n");
		
  notify_fail("�㲻�ܹ�������ˡ�\n");
	if (!userp(target) && !target->accept_hit(me)) return 0;
	
	//�������־���

	if((int)me->query_str() < 25)
		return notify_fail("����������������ʹ����һ������\n");
		
	fskill = "hamagong";
	bskill = "hand";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 100 )
		return notify_fail("���"+to_chinese(fskill)+"��Ϊ������Ŀǰ������ʹ��"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail("���"+to_chinese(sskill)+"�Ĺ�����������ʹ��"+PNAME+"��\n");

	if((int)me->query("neili") < 300)
		return notify_fail("���������ڲ���, ����ʹ�����߷���! \n");

	if( target->is_busy() )
		return notify_fail(target->name() +"Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");

	msg = HIY"$Nʹ�����ε��־��������߷��衹��ʮָ��������ǧ��ֻ�������ߣ�����ʵʵ��Ϯ��$n��ȫ��ҪѨ��$n�������У�ƴ�����$N�ַ���ʱ�������ҡ�\n";
	if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/3)
	{
		if (target->query_temp("hmg_dzjm"))
		{
			msg +=HIY"$Pһ�µ���$p�Ĵ�Ѩ��$pֻ��΢΢һ�飬Ѹ���ж��糣��\n"NOR;
			me->start_busy(random(4) + 1);
			me->add("neili", -100);
		} else {
			msg +=  HIG "���$p��$P���м���Ѩ��! \n" NOR;
			target->start_busy( random((int)me->query_skill(bskill,1) / 30) + 2);
			me->add("neili", -100);
		}
	}
	else
	{
		msg += HIM "$p�鼱����������һԾ���˳���Զ��\n" NOR;
		me->start_busy(3);
	        if(!target->is_fighting(me) && target->query("owner") && 
		        me->query("id") == target->query("owner"))
	        target->fight_ob(me);
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
		���ͶԷ�����

	����Ҫ��
		��󡹦100��
		���ε���100��
		��������25
		����300
HELP
	);
	return 1;
}


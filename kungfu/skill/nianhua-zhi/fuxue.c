// fuxue.c �黨ָ ���黨��Ѩ��
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

inherit F_SSERVER;
#define PNAME "�黨��Ѩ"
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
	 return notify_fail("��Ҫ��˭ʹ���黨��Ѩ��\n");

	if( environment(me)->query("no_fight") )
		return notify_fail("�����ﲻ�ܹ������ˡ�\n");

  notify_fail("�㲻�ܹ�������ˡ�\n");
	if (!userp(target) && !target->accept_hit(me)) return 0;
	
	//�������־���
	
	fskill = "hunyuan-yiqi";
	bskill = "finger";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 100 )
		return notify_fail("���"+to_chinese(fskill)+"�Ĺ�����������ʹ��"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail("���"+to_chinese(sskill)+"��Ϊ������Ŀǰ������ʹ��"+PNAME+"��\n");

	if( (int)me->query_skill(bskill, 1) < 100 )
		return notify_fail("���"+to_chinese(sskill)+"��Ϊ������Ŀǰ������ʹ��"+PNAME+"��\n");

	if((int)me->query_str() < 25)
		return notify_fail("����������,����ʹ����һ������\n");

	if((int)me->query("neili") < 300)
		return notify_fail("���������ڲ���������ʹ���黨��Ѩ��\n");

	if( target->is_busy() )
		return notify_fail(target->name()+ "Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");

	msg = HIY"$N"HIY"ʹ���黨ָ�������黨��Ѩ������ס��$n"HIY"��ȫ��ҪѨ, ʹ$n"HIY"�������á�\n";
	if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/4)
	{
		if (target->query_temp("hmg_dzjm"))
		{
			msg += HIY "$Pһָ����$p�Ĵ�Ѩ��$p΢΢һЦ���ж���˿�������谭��$Pһ��֮�£����ڵ�����\n"NOR;
			me->start_busy(4);
			me->add("neili", -100);
		} else {
			msg +=  HIG "���$p��$P���˸��������ã�\n" NOR;
			target->start_busy(random((int)me->query_skill(bskill,1) / 20));
      me->add("neili", -100);
		}
	}
	else
	{
		msg += HIM "����$p������$P����ͼ����û���ϵ���\n" NOR;
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
		��Ԫһ����100��
		����ָ��100��
		�黨ָ100��
		����300
		��������25
HELP
	);
	return 1;
}


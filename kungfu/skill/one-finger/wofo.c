// wofo.c һָ�� ������ҷ�
// Last Modified by winder on Mar. 30 2000

#include <ansi.h>
inherit F_SSERVER;
#define PNAME "����ҷ�"
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
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail("ǣ�ƹ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	//�������־���
	
	fskill = "zhanzhuang-gong";
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
		return notify_fail("���"+to_chinese(fskill)+"�Ļ���ܳ�"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 150 )
		return notify_fail("���"+to_chinese(sskill)+"��򲻹�������ʹ��"+PNAME+"��\n");

	if( (int)me->query_skill(bskill, 1) < 150 )
		return notify_fail("���"+to_chinese(bskill)+"��Ϊ������ʹ����"+PNAME+"��\n");

	if((int)me->query_str() < 30)
		return notify_fail("����������������ʹ����һ������\n");

	if((int)me->query("neili") < 800)
		return notify_fail("���������ڲ���, ����ʹ������ҷ�\n");

	if( target->is_busy() )
		return notify_fail(target->name()+"Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");

	msg = HIY"$N"HIY"ʹ��һָ������������ҷ𡹣���ס��$n"HIY"��ȫ��ҪѨ, ʹ$n"HIY"�������á�\n";
	if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/3)
	{
		if (target->query_temp("hmg_dzjm"))
		{
			msg += HIY "$Pһָ����$p��̴�д�Ѩ��$p΢΢һЦ���ж���˿�������谭��$Pһ��֮�£����ڵ�����\n"NOR;
			me->start_busy(4);
			me->add("neili", -300);
		} else {
			msg += "���$p��$P���˸��������ã�\n" NOR;
			target->start_busy( (int)me->query_skill(bskill,1) / 20);
			me->add("neili", -400);
		}
	} else {
		msg += HIG "����$p������$P����ͼ����û���ϵ���\n" NOR;
		me->start_busy(4);
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
		ʹ���˳�ʱ�䲻���ƶ��򷴻��������ɹ��Ļ��Լ��ͻᱩ¶
		�ڶԷ������ҹ���֮�¡�

	����Ҫ��
		վ׮��100��
		����ָ��150��
		һָ��150��
		����800
		��������30
HELP
	);
	return 1;
}


// lingkong.c ���ָѨ�� �����ָѨ��
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

inherit F_SSERVER;
#define PNAME "�����ָѨ��"
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
		return notify_fail("��Ҫ��˭ʹ�����ָѨ��\n");
         
	if( environment(me)->query("no_fight") )
		return notify_fail("�����ﲻ�ܹ������ˡ�\n");
        
  notify_fail("�㲻�ܹ�������ˡ�\n");
	if (!userp(target) && !target->accept_hit(me)) return 0;
	
	//�������־���
	
	if((int)me->query_str() < 25)
		return notify_fail("���������������ʹ����һ������\n");
		
	fskill = "linji-zhuang";
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
		return notify_fail("���"+to_chinese(fskill)+"�Ļ�򲻹�ʹ��"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail("���"+to_chinese(sskill)+"��򲻹�������ʹ��"+PNAME+"��\n");

	if( (int)me->query_skill(bskill, 1) < 100 )
		return notify_fail("���"+to_chinese(bskill)+"��򲻹�������ʹ��"+PNAME+"��\n");

	if((int)me->query("neili") < 300)
		return notify_fail("���������ڲ���������ʹ�����ָѨ��\n");

	if( target->is_busy() )
		return notify_fail(target->name()+"Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");

	msg = 
HIY "$Nʹ�����ָѨ�����������ָѨ�����ع������������������۾�һ�㣬��
��ʳ�ж�ָ��$n������ȥ��һ����ָ��ȫ�Ƕ���$n��ͷ����ǰ����Ѩ��$n��
�����У�ƴ�����$Nָ������ʱ�������ҡ�\n";
	if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/4)
	{
		if (target->query_temp("hmg_dzjm"))
		{
			msg += HIY "$Pһָ����$p�Ĵ�Ѩ��$pֻ��΢΢һ�飬Ѹ���ж��糣��\n"NOR;
            me->start_busy(4);             
			me->add("neili", -100);
		} else {
			msg +=  HIG "���$p��$Pָ�����м���Ѩ��! \n" NOR;
			target->start_busy( random((int)me->query_skill(bskill, 1) / 20));
			me->add("neili", -100);
		}
	}
	else
	{
		msg += HIM "$p�鼱����������һԾ���˳���Զ��\n" NOR;
		me->start_busy(3);
		if(!target->is_fighting(me) &&
			target->query("owner") &&
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
		�ټ�ʮ��ׯ100��
		����ָ��100��
		���ָѨ��100��
		����300
		��������25
HELP
	);
	return 1;
}


// dian.c �����Ѩ
// Last Modified by winder on Jun. 4 2000

#include <ansi.h>
inherit F_SSERVER;
#define PNAME "�����Ѩ"

int perform(object me, object target)
{
	string msg;
	int damage;
	int flag;
	string fskill,sskill,bskill,pfname;

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
//	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail("��Ҫ��˭ʹ��"PNAME"��\n");
  if( environment(me)->query("no_fight") )
		return notify_fail("�����ﲻ�ܹ������ˡ�\n");

  notify_fail("�㲻�ܹ�������ˡ�\n");
	if (!userp(target) && !target->accept_hit(me)) return 0;
	
	//�������־���
 
	if((int)me->query_str() < 25)
		return notify_fail("���������������ʹ��"PNAME"��\n");
	fskill = "shenyuan-gong";
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
		return notify_fail("���"+to_chinese(fskill)+"��������������ʹ��"+PNAME+"��\n");
	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail("���"+to_chinese(sskill)+"��Ϊ����������"+PNAME+"��\n");
	if( (int)me->query_skill(bskill, 1) < 100 )
		return notify_fail("���"+to_chinese(bskill)+"��Ϊ������������ʹ��"+PNAME+"��\n");

	if((int)me->query("neili") < 300)
		return notify_fail("���������ڲ���������ʹ��"PNAME"��\n");
	if( target->is_busy() )
		return notify_fail(target->name() +"Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");
	msg = HIY"$N"HIY"���ʳָ��������$n"HIY"���˹�ȥ��ָ������絶������ϸ����Х����\n";

	if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/4)
	{
		if (target->query_temp("hmg_dzjm"))
		{
			msg += HIY "$Pָ������$p���ؿڣ�$p΢΢һЦ���ж���˿�������谭��$Pһ��֮�£����ڵ�����\n"NOR;
			me->start_busy(4);
			me->add("neili", -100);
		} else {
			msg +=  HIG "���$p�ؿ�һ�飬�㼴ˤ���ڵ��¡�\n" NOR;
			target->start_busy( random((int)me->query_skill(bskill, 1) / 30)  + 2);
			me->add("neili", -100);
		}
	}
	else
	{
		msg += HIM "$p˫�Ƶ�����ǰ��ǡǡ��ס$P�����ָ����\n" NOR;
 		me->start_busy(4);
  }
  if ((int)me->query("str")>33 && 
    (int)me->query_skill("canhe-finger", 1) > 400 &&
    (int)me->query_skill("finger", 1) > 350 &&
     me->query("family/master_id") == "murong fu")
	{
		me->start_busy(2);
		target->start_busy(random(8));
		damage = (int)me->query_skill("canhe-finger", 1);
		damage = damage + random(damage);
		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage,me);
	        me->add("neili", -200);
	        msg += HIC "һ��������ָ���$p"HIC"�Ƽ����롣\n" NOR; 
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
		��������25
		��Ԫ��100��
		����ָ��100��
		�κ�ָ100��
		����300
HELP
	);
	return 1;
}


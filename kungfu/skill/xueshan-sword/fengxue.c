// Last Modified by winder on Jul. 9 2001
#include <ansi.h>

inherit F_SSERVER;
#define PNAME HIC"����"HIW"ѩ"HIC"�ؽ���"NOR
int perform(object me, object target)
{
	object ob;
	object weapon;
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
		return notify_fail(PNAME"ֻ�ܶ�ս���еĶ���ʹ�á�\n");
		
	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n"); 

	fskill = "bingxue-xinfa";
	bskill = "sword";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 150 )
		return notify_fail("���"+to_chinese(fskill)+"��Ϊ����������������"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 150 )
		return notify_fail("���"+to_chinese(sskill)+"������죬ʹ����"+PNAME+"��\n");

	if((int)me->query("max_neili") < 300)
		return notify_fail("��������Ϊ���ڲ����� \n");

	if((int)me->query("neili") < 200)
		return notify_fail("�����������ڲ����� \n");

	if( target->is_busy() )
		return notify_fail(target->name()+"Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");

	msg = HIC"$N�ؽ����裬���Ʋ��ϼӿ죬������Х��ɢ����ƬƬѩ�����磬ƮȻ������\n�γ�һ��ѩ�������У���$n�������\n";
	if(random(me->query_skill("sword", 1) + me->query_skill("force", 1)) > (target->query_skill("dodge", 1) + (int)target->query_skill("parry", 1))/3)
	{
		msg +=HIG"$n"HIG"ֻ��������ѹ��Խ��Խ�󣬵��������������������������á�\n" NOR;
		target->start_busy( (int)me->query_skill(bskill,1) / 30);
		me->add("neili", -150);
		me->start_busy(1);
	} else
	{
		msg +=HIR"����$n����������ѩ����ʱȫ���ܽ⣬һƬ��ʣ���ѳ���Χ��\n" NOR;
		me->start_busy(2);
		me->add("neili",-50);
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
		���ͶԷ�����

	����Ҫ��
		��ѩ�ķ�150��
		ѩɽ����150��
		������Ϊ300
		����200
HELP
        );
        return 1;
}



// suo.c ������
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

inherit F_SSERVER;
#define PNAME "����������"
int perform(object me)
{
	string msg;
	object weapon, weapon2, target;
	int skill, ap, dp, damage;
	int flag;
	string fskill,sskill,bskill,pfname,pskill;

	sskill = explode(__FILE__,"/")[<2];
	pfname = explode(__FILE__,"/")[<1][0..<3];
  if (userp(me) && !wizardp(me) &&
//   !me->query("perform/"+pfname) &&
   !me->query("can_perform/"+sskill+"/"+pfname) &&
   !me->query_temp("murong/xingyi") &&
   !SCBORN_D->valid_perform(me,sskill,pfname) )
   return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"ֻ�ܶ�ս���еĶ���ʹ�á�\n");
		
	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("id") != "jinshe jian" ||
		weapon->query("ownmake") == 1)
		return notify_fail("��û�ý��߽�������ʹ�þ��У�\n");

	if (!objectp(weapon2 = target->query_temp("weapon")))
		return notify_fail("�Է�û��ʹ�ñ��������ò��ˡ�����������\n");
		
	bskill = "sword";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(sskill, 1) < 150 )
		return notify_fail("���"+to_chinese(sskill)+"�ȼ�����, ����ʹ��"+PNAME+"��\n");

	if( me->query("dex") < 20 || me->query("str") < 20 )
		return notify_fail("�����������������, ����ʹ��"PNAME"��\n");

	if( me->query("neili") < 300 )
		return notify_fail("��������������޷�����"PNAME"��\n");

	skill = me->query_skill(bskill, 1);

	msg = HIC "$N"HIC"����"YEL"���߽�"HIC"����һ����⣬б��һ����������������
"YEL"���߽�"HIC"���⵹�����ù���$n"HIC"��"+weapon2->name()+"�ϡ�\n";
	message_combatd(msg, me, target);

	damage = 10 + random(skill / 2);
	ap = skill;
	dp = target->query_skill("dodge")/2;
	if( dp < 1 ) dp = 1;
	if( random(ap) > random(dp) )
	{
		if(userp(me)) me->add("neili",-50);
		msg = "$n��ʱ������ǰ���һ��������һ������"+weapon2->name()+"���ַɳ���\n" NOR;
		me->start_busy(random(2));
		target->receive_damage("qi", damage,me);
		target->start_busy(2);
		weapon2->move(environment(me));
	}
	else
	{
		if(userp(me)) me->add("neili",-30);
		msg = "$n����������������" + weapon2->name() + "бб˳��һ��һ����˻�����\n"NOR;
		me->start_busy(4);
	}
	message_combatd(msg, me, target);

	return 1;
}
string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}
int sp() {return 1;}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		���˶Է���Ѫ
		���ͶԷ�����
		���öԷ�����

	����Ҫ��
		��������20
		������20
		���߽���150��
		����300
		ʹ�ý��߽�
HELP
	);
	return 1;
}


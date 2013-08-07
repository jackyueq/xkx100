// Last Modified by Winder on Jul. 15 2001
// suiyuan.c

#include <ansi.h>
inherit F_SSERVER;
#define PNAME "����Ե������"
mapping *msg = ({
([	"action":"$Nʹ����Ե�����е�һ�С���ɨ���硹��$w����㶸Ȼ����$n$l",
	"damage": 270,
	"force" : 200,
	"damage_type": "����",
]),
([	"action": "$Nʹ����Ե�����еڶ��С���תǬ������$w�ó�һ���Ϲ����$n$l",
	"damage": 290,
	"force" : 260,
	"damage_type": "����",
]),
([	"action":"$Nʹ����Ե�����е����С��������¡�����Ӱ���Ž����һ�����$n",
	"damage": 330,
	"force" : 300,
	"damage_type": "����",
]),
});

int perform(object me, object target)
{
	object weapon;
	int i, damage, lvl;
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

	fskill = "hanbing-zhenqi";
	bskill = "sword";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 60 )
		return notify_fail("���"+to_chinese(fskill)+"��Ϊ�������ߣ��޷�ʹ��"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 50 )
		return notify_fail("���"+to_chinese(sskill)+"�������ߣ��޷�ʹ��"+PNAME+"��\n");

	if(me->query("max_neili") < 100)
		return notify_fail("���������Ϊ�������޷�ʹ����Ե��������\n");

	if(me->query("neili") < 50)
		return notify_fail("��������������޷�ʹ����Ե��������\n");

	if(target->is_busy())
		return notify_fail(target->name()+"Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");


	lvl = me->query_skill(bskill, 1);
	me->start_busy(1);

	damage = lvl / 2;
	me->add_temp("apply/attack", lvl);
	me->add_temp("apply/damage", damage);
	for(i=0;i<3;i++)
	{
		if (flag == 1) target = offensive_target(me);
		if (!objectp(target)) break;
		me->set_temp("no_reset_action",1);
		me->set("actions", msg[i]);
		COMBAT_D->do_attack(me, target, weapon);
	}
	me->delete_temp("no_reset_action");
	me->reset_action();
	me->receive_damage("qi", damage / 2);
	me->add_temp("apply/attack", -lvl);
	me->add_temp("apply/damage", -damage);

	return 1;
}

string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		������Ե����

	����Ҫ��
		��������60��
		��ɽ����50��
		������Ϊ100
		����50
HELP
	);
	return 1;
}


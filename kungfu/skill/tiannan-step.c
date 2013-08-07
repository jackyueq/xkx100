// tiannan-step.c ���ϲ���
// Last Modified by sir on 10.18.2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "dodge"; }

string *dodge_msg = ({
"ֻ��$nһ��"HIG"�����ذδС�"NOR"���������ϱ�ֱ���������࣬�����$N��һ�С�\n",
"$nһ��"MAG"������鳲��"NOR"������ݳ�����֮Զ���ܿ���$N���������ơ�\n",
"$nʹ��"BLK"������������"NOR"����һ��ƮȻ�ݳ��������ŵء�\n",
"����$n����Ʈ����һ��"BLU"���������С�"NOR"����һ�ݣ����ѱܿ���\n",
"$n������ת��һ��"HIC"���˷��ȥ��"NOR"ٿ����һ��Ų�������ߣ��ܹ�����һ�С�\n",
"����$n����һ�ã�һ��"HIY"���绯������"NOR"$N��һ�����˸��ա�\n",
"ȴ��$n�㲻��أ�һ��"HIW"������ֱ�ϡ�"NOR"���Դܿ����ߣ����˿�ȥ��\n",
"$n����΢�Σ�һ��"HIR"��������졹"NOR"�о����յرܿ���$N��һ�С�\n",
});

int valid_enable(string usage) { return (usage=="dodge") || (usage=="move"); }
int valid_learn(object me) 
{      	
	if( (int)me->query_skill("kurong-changong", 1) < 10 )
	return notify_fail("��Ŀ��������������죬�޷�������ϲ�����\n");
	return 1;
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 20|| (int)me->query("neili") < 4 )
		return notify_fail("�������̫���ˣ����������ϲ�����\n");
	me->receive_damage("qi", 20);
	me->add("neili", -4);	
	return 1;
}
string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int learn_bonus() { return 20; }
int practice_bonus() { return 20; }
int success() { return 20; }
int power_point(object me) { return 1.2; }

int help(object me)
{
	write(HIC"\n���ϲ�����"NOR"\n");
	write(@HELP

    ���ϲ��������ϴ���μұ����Ṧ����

	ѧϰҪ��
	  ��������10��
HELP
	);
	return 1;
}


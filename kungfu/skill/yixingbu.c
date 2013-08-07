// yixingbu.c ���β���
// Last Modified by sir on 10.18.2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "dodge"; }

string *dodge_msg = ({
	BLU"$n�������ĵ���������һ�����պñܹ�$N���������ơ�\n"NOR,
	MAG"����$n����������������һ���������$N��һ�С�\n"NOR,
	MAG"����$n����Ʈ��������һ�ݣ����ѱܿ���\n"NOR,
	MAG"$n������ת��ٿ����һ��Ų�������ߣ��ܹ�����һ�С�\n"NOR,
	BLU"����$n����һ�ã�$N��һ�����˸��ա�\n"NOR,
	BLU"ȴ��$n�㲻��أ����Դܿ����ߣ����˿�ȥ��\n"NOR,
	BLU"$n����΢�Σ��о����յرܿ���$N��һ�С�\n"NOR,
	MAG"$n�������ĵ�����һ������ͷ΢�࣬�����ܹ���$N��һ�С�\n"NOR,
});

int valid_enable(string usage) { return (usage=="dodge") || (usage=="move"); }
int valid_learn(object me) 
{      	
	if( (int)me->query_skill("dulong-dafa", 1) < 10 )
	return notify_fail("��Ķ����󷨲������죬�޷�������β�����\n");
	return 1;
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 40|| (int)me->query("neili") < 8 )
		return notify_fail("�������̫���ˣ����������β�����\n");
	me->receive_damage("qi", 40);
	me->add("neili", -8);	
	return 1;
}
string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int learn_bonus() { return 10; }
int practice_bonus() { return 10; }
int success() { return 10; }
int power_point(object me) { return 1.4; }

int help(object me)
{
	write(HIC"\n���β�����"NOR"\n");
	write(@HELP

    ���β���Ϊ�����������Ṧ����

	ѧϰҪ��
	  ������10��
HELP
	);
	return 1;
}



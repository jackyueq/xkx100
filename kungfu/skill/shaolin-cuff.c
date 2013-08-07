// Last Modified by winder on May. 29 2001
// shaolin-cuff.c - ������ȭ �����ֵ����ſ��ֹ��� �����ֵ��Ȼ���

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

string *msg = ({
 "$Nһʽ����˫���ơ������������һ����˫�Ȱ������˫ȭ��������ǰ��",
 "$Nһʽ�������š�����������˫�ֱ��ƣ���ϥ����ʹ����ѹ",
 "$N�ҽ�����ǰһ��������ƹ��ҽţ�����ת����ͣ��һʽ�������������ȡ�����$n��ȥ",
 "$N������ת���ҽ�������ҿ�һ����һʽ�������ơ�����ȭ���ƣ��ұ��������죬����б��",
});

int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }
int valid_combine(string combo) { return combo=="shaolin-leg"; }

int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��������ȭ������֡�\n");
	if ((int)me->query_skill("zhanzhuang-gong", 1) < 1)
		return notify_fail("���վ׮����򲻹����޷�ѧ������ȭ��\n");
	return 1;
}
int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��ı�����ֲ�����ϰ������ȭ��\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("�������������������ȭ��\n");
	me->receive_damage("qi", 30);
	me->add("neili", -10);
	return 1;
}
mapping query_action(object me, object weapon)
{
	return ([
		"action" : msg[random(sizeof(msg))],
		"dodge"  : 35+random(25),
		"parry"  : -20+random(15),
		"force"  : 70+random(150),
		"damage_type" : random(2)?"����":"����",
	]);
}
int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 20; }
int power_point(object me) { return 1.0; }

int help(object me)
{
	write(HIC"\n������ȭ��"NOR"\n");
	write(@HELP

    ��ȭ������������ȭ������̴����������Ѹ�����͡�ǿ��վ
׮���������ķ�һ���������������ַ����ȷ��;�����������ν
���������ֵ�����Ϊ���ֵ�����

	ѧϰҪ��
		վ׮��
HELP
	);
	return 1;
}


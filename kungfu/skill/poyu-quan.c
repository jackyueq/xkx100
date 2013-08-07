// poyu-quan.c ��ʯ����ȭ
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N�ҽ������������㣬һʽ������ʽ����������һ��һ�ͣ�����$n��$l",
	"lvl" : 0,
	"skill_name" : "����ʽ"
]),
([	"action" : "$N�����̤��ȫ����ת��һ�С�ʯ���쾪������ȭ�͵ػ���$n��$l",
	"lvl" : 10,
	"skill_name" : "ʯ���쾪"
]),
([	"action" : "$N˫�ִ󿪴��أ����߾٣�ʹһ�С����ź��š���˫ȭ��$n��$l��ȥ",
	"lvl" : 20,
	"skill_name" : "���ź���"
]),
([	"action" : "$N����Ȧ���������⵱�أ����ֻ��ڳ��ϣ�һ�С�ǧ��׹�ء�����$n��$l",
	"lvl" : 30,
	"skill_name" : "ǧ��׹��"
]),
([	"action" : "$Nʹһ�С�����������������ǰ̽��˫ȭ���˸���Ȧ������$n��$l",
	"lvl" : 40,
	"skill_name" : "��������"
]),
([	"action" : "$N˫ȭ������һ�ǡ����ֿβ�����Ƴ���磬һ�����е�$n������",
	"lvl" : 50,
	"skill_name" : "���ֿβ"
]),
([	"action" : "$Nʩ��������֡���˫ȭȭ����磬ͬʱ����$nͷ���أ�������Ҫ��",
	"lvl" : 60,
	"skill_name" : "�����"
]),
([	"action" : "$N����ڿۣ�����������һʽ����ʯ���񡹣�˫ȭ���봷��$n���ؿ�",
	"lvl" : 80,
	"skill_name" : "��ʯ����"
])
});

int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }
int valid_combine(string combo) { return combo=="hunyuan-zhang"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("������ʯ����ȭ��������֡�\n");
	if ((int)me->query_skill("zixia-shengong", 1) < 10)
		return notify_fail("��ġ���ϼ�񹦡���򲻹����޷�ѧ����ʯ����ȭ����\n");
	if ((int)me->query("max_neili") < 50)
		return notify_fail("�������̫�����޷�������ʯ����ȭ����\n");
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��ı�����ֲ�����ϰ��\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 40)
		return notify_fail("�����������������ʯ����ȭ����\n");
	me->receive_damage("qi", 35);
	me->add("neili", -25);
	return 1;
}
string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action); i > 0; i--)
		if(level >= action[i-1]["lvl"])
			return action[i-1]["skill_name"];
}
mapping query_action(object me, object weapon)
{
/* d_e=dodge_effect p_e=parry_effect f_e=force_effect m_e=damage_effect */
	int d_e1 = 20;
	int d_e2 = 45;
	int p_e1 = -35;
	int p_e2 = -20;
	int f_e1 = 160;
	int f_e2 = 310;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("poyu-quan", 1);
	for(i = ttl; i > 0; i--)
		if(lvl > action[i-1]["lvl"])
		{
			seq = i; /* �������������� */
			break;
		}
	seq = random(seq);       /* ѡ������������ */
	return ([
		"action"      : action[seq]["action"],
		"dodge"       : d_e1 + (d_e2 - d_e1) * seq / ttl,
		"parry"       : p_e1 + (p_e2 - p_e1) * seq / ttl,
		"force"       : f_e1 + (f_e2 - f_e1) * seq / ttl,
		"damage_type" : "����",
	]);
}
int learn_bonus() { return 15; }
int practice_bonus() { return 15; }
int success() { return 15; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"poyu-quan/" + action;
}
int help(object me)
{
	write(HIC"\n��ʯ����ȭ��"NOR"\n");
	write(@HELP

    ��ʯ����ȭԭΪ��ʯ��������·ȭ����ѧ��Ϊ��ɽ�书��
    �����Ԫ�ƻ�����

	ѧϰҪ��
		��ϼ��10��
		����50
HELP
	);
	return 1;
}


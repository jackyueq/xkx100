// Last Modified by winder on May. 29 2001
// one-finger.c һָ�� ���ɻ��� ȡ�Է�̡������������

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N˫ָ��£��һʽ"MAG"�����а�����"NOR"�����������ϣ�������һǰһ����$n$l",
	"lvl"   : 0,
	"skill_name" : "���а���"
]),
([	"action" : "$N���ƻ��أ���Цһʽ"GRN"��СƷ������"NOR"��������ָǰ���˸��뻡������һ˦������$n$l",
	"lvl"   : 20,
	"skill_name" : "СƷ����"
]),
([	"action" : "$N����������һʽ"HIW"�����ް�����"NOR"��˫��ʳָ�˲������һ����⣬����$n��ȫ��ҪѨ",
	"lvl"   : 40,
	"skill_name" : "���ް���"
]),
([	"action" : "$N��ϥ������һʽ"HIC"���Ź������"NOR"��ȫ������ܲ���������ȭ���⣬����Ĵֱָ����ңң����$nһ��",
	"lvl"   : 60,
	"skill_name" : "�Ź����"
]),
([	"action" : "$N��¶���࣬�������֣�����һ�µ��"GRN"��Ħڭ������"NOR"��ƾ���������ߣ���������$n",
	"lvl"   : 100,
	"skill_name" : "Ħڭ����"
]),
([	"action" : "$N����𾭣���Ϣ���������������͹ģ�������գ�����ָһʽ"HIY"����հ�����"NOR"������$n��ȥ",
	"lvl"   : 150,
	"skill_name" : "��հ���"
])
});

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }
int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��һָ��������֡�\n");
	if ((int)me->query_skill("zhanzhuang-gong", 1) < 100)
		return notify_fail("���վ׮����򲻹����޷�ѧһָ����\n");
	if ((int)me->query("max_neili") < 1200)
		return notify_fail("�������̫�����޷���ϰһָ����\n");
	if ((me->query_skill("nianhua-finger", 1) < 50) ||
		(me->query_skill("boruo-strike", 1) < 50) )
		return notify_fail("����黨ָ�Ͱ����ƻ�򲻹����޷�ѧһָ����\n");
	return 1;
}
int practice_skill(object me)
{
	if ((int)me->query("qi") < 60)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 30)
		return notify_fail("�������������һָ����\n");
	me->receive_damage("qi", 55);
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
	int d_e1 = 25;
	int d_e2 = 45;
	int p_e1 = -35;
	int p_e2 = -15;
	int f_e1 = 330;
	int f_e2 = 430;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("one-finger", 1);
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
		"damage_type" : random(2) ? "����" : "����",
	]);
}
int learn_bonus() { return 5; }
int practice_bonus() { return 5; }
int success() { return 10; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"one-finger/" + action;
}

int help(object me)
{
	write(HIC"\nһָ����"NOR"\n");
	write(@HELP

    һָ���������ָ߼�ָ�������Է�̡������������

	ѧϰҪ��
		վ׮��100��
		�黨ָ50��
		������50��
		������Ϊ1200
HELP
	);
	return 1;
}


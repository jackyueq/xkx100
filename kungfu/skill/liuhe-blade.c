// liuhe-blade.c �������ϵ�

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$Nһ����Х������$wһ�һʽ�����ǽ�$n���ڵ���֮��",
	"lvl"    : 0,
	"skill_name" : "������",
]),
([	"action" : "$Nһ��"HIR"��Ǭ����ת��"NOR"������$w�ڿ����������£�ͻȻ�»�����$n��$l",
	"lvl"    : 20,
	"skill_name" : "Ǭ����ת",
]),
([	"action" : "$N���¼�����̤���ķ����棬����$w����һ����â�����·��衣��һ����������",
	"lvl"    : 40,
	"skill_name" : "��������",
]),
([	"action" : "$N��ɫ��ɱ��һ���������е�����˸������һƬ�̹ǵĵ��罫$n����Χס��"HIC"���������ϡ�"NOR"!",
	"lvl"    : 60,
	"skill_name" : "��������",
]),
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }
int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 50)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("huntian-qigong", 1) < 30)
		return notify_fail("��Ļ����������̫ǳ��\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "blade")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("��������������������ϵ�����\n");
	me->receive_damage("qi", 25);
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
	int d_e1 = 55;
	int d_e2 = 35;
	int p_e1 = 5;
	int p_e2 = -15;
	int f_e1 = 100;
	int f_e2 = 150;
	int m_e1 = 50;
	int m_e2 = 160;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int)me->query_skill("liuhe-blade", 1);
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
		"damage"      : m_e1 + (m_e2 - m_e1) * seq / ttl,
		"damage_type" : "����",
	]);
}
int learn_bonus() { return 20; }
int practice_bonus() { return 25; }
int success() { return 15; }
int power_point(object me) { return 1; }

string perform_action_file(string action)
{
	return __DIR__"liuhe-blade/" + action;
}

int help(object me)
{
	write(HIC"\n�������ϵ���"NOR"\n");
	write(@HELP

    �������ϵ�Ϊؤ��ĵ�����

	ѧϰҪ��
		��������30��
		����50
HELP
	);
	return 1;
}


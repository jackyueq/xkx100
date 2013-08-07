// hamaquan.c
// Last Modified by winder on May. 15 2001
#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$Nһʽ"HIB"����������"NOR"�����ƻ�צ����Ϯ$n����������·Ҫ��",
	"lvl" : 0,
	"skill_name" : "��������"
]),
([	"action" : "$N������Σ�������ǰ���󣬷���$n�ļ羮��Ѩ",
	"lvl" : 8,
	"skill_name" : "���ֵ�Ѩ"
]),
([	"action" : "$Nʹһʽ"HIY"��ǰհ������"NOR"�����Ƹ��״����׶�������������$n",
	"lvl" : 30,
	"skill_name" : "ǰհ����"
]),
([	"action" : "$Nʹһʽ"HIW"��������Ӱ��"NOR"������˷�����������Ӱ��һȭ����$n���ؿ�",
	"lvl" : 70,
	"skill_name" : "������Ӱ"
]),
([	"action" : "$N���ֳ�צ��ȫ�������죬һʽ"HIR"���޵и�󡡹"NOR"������$n��$l",
	"lvl" : 98,
	"skill_name" : "�޵и��"
])
});

int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�����ȭ������֡�\n");
	if ((int)me->query_skill("hamagong", 1) < 20)
		return notify_fail("��ĸ�󡹦��򲻹����޷�ѧ���ȭ��\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷������ȭ�֡�\n");
	return 1;
}
int practice_skill(object me)
{
	if ((int)me->query("qi") < 40)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 40)
		return notify_fail("����������������ȭ��\n");
	me->receive_damage("qi", 35);
	me->add("neili", -20);
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
	int f_e1 = 150;
	int f_e2 = 300;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("hamaquan", 1);
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
int learn_bonus() { return 15; }
int practice_bonus() { return 15; }
int success() { return 15; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"hamaquan/" + action;
}

int help(object me)
{
	write(HIC"\n���ȭ��"NOR"\n");
	write(@HELP

    ŷ���洴���İ���ɽ�ɱ���ȭ����

	ѧϰҪ��
		��󡹦20��
		������Ϊ100
HELP
	);
	return 1;
}


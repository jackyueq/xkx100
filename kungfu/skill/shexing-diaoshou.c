// shexing-diaoshou.c ���ε���
// Last Modified by sir 10.23.2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$Nһʽ"HIB"�����߳�����"NOR"��������Σ���������ͻȻ����$n�ı����Ѩ",
	"lvl" : 0,
	"skill_name" : "���߳���"
]),
([	"action" : "$N����һ�Σ�һʽ"HIY"����ͷ��β��"NOR"����������$n�ļ�ͷ����ȭ����$n���ؿ�",
	"lvl" : 10,
	"skill_name" : "��ͷ��β"
]),
([	"action" : "$Nһʽ"MAG"���������㡹"NOR"�����ֻ�£��צ��һ���־����$n���ʺ�Ҫ��",
	"lvl" : 20,
	"skill_name" : "��������"
]),
([	"action" : "$N�������У�����ֱ����һʽ"GRN"��������Ӱ��"NOR"����Ʈ��������$n������",
	"lvl" : 30,
	"skill_name" : "������Ӱ"
]),
([	"action" : "$Nʹһʽ"HIB"��������ܡ�"NOR"����ȭ�ϸ�����̽��ͻ����ץ��$n���ɲ�",
	"lvl" : 38,
	"skill_name" : "�������"
]),
([	"action" : "$Nһʽ"CYN"����������"NOR"��ʮָ����������ʵʵ��Ϯ��$n��ȫ��ҪѨ",
	"lvl" : 51,
	"skill_name" : "��������"
]),
([	"action" : "$N˫�ֱ�ȭ��һʽ"GRN"��������ӿ��"NOR"����Ӱ���ɣ�ͬʱ��$nʩ���žŰ�ʮһ��",
	"lvl" : 56,
	"skill_name" : "������ӿ"
]),
([	"action" : "$Nһʽ"RED"���������š�"NOR"��ȭ���������֣��������ޣ�����������$n�ĵ���",
	"lvl" : 60,
	"skill_name" : "��������"
]),
});

int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }
int valid_combine(string combo) { return combo=="hamagong"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�����ε��ֱ�����֡�\n");
	if ((int)me->query_skill("hamagong", 1) < 20)
		return notify_fail("��ĸ�󡹦��򲻹����޷�ѧ���ε��֡�\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷������ε��֡�\n");
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��ı�����ֲ�����ϰ��\n");
	if ((int)me->query("qi") < 35)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 25)
		return notify_fail("����������������ε��֡�\n");
	me->receive_damage("qi", 30);
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
	int d_e1 = -45;
	int d_e2 = -10;
	int p_e1 = 20;
	int p_e2 = 45;
	int f_e1 = 130;
	int f_e2 = 230;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("shexing-diaoshou", 1);
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
int learn_bonus() { return 20; }
int practice_bonus() { return 20; }
int success() { return 15; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"shexing-diaoshou/" + action;
}

int help(object me)
{
	write(HIC"\n���ε��֣�"NOR"\n");
	write(@HELP

    ���ε����ǰ���ɽ���书�����϶���ŷ������ߵ��䶯�����
�������书��

	ѧϰҪ��
		��󡹦20��
		����100
HELP
	);
	return 1;
}


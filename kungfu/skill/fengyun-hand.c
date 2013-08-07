// Last Modified by winder on May. 29 2001
// fengyun-hand.c ������ ���޺�ȭ����

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$Nһʽ"CYN"���������ա�"NOR"��˫�����ƻ�צ����ָ�繳��Ю�ŷ���ֱ��$n������ҪѨ",
	"limb" : "����Ѩ",
	"lvl" : 0,
	"skill_name" : "��������"
]),
([	"action" : "$Nһʽ"RED"���һ����ơ�"NOR"���������»Ӷ�����������������һ̽������$n�ļ羮��Ѩ",
	"lvl" : 8,
	"limb" : "�羮Ѩ",
	"skill_name" : "�һ�����"
]),
([	"action" : "$Nʹһʽ"GRN"����������"NOR"����ָ������ó�������Ӱ�����������ְ���$n����ǰҪ��",
	"lvl" : 16,
	"skill_name" : "��������"
]),
([	"action" : "$N���ֳ��ƣ�������ȭ��һʽ"BLU"����Ŀ�ѻԡ�"NOR"��������ȭӰ��Ӱ����������һ�㣬����$n",
	"lvl" : 24,
	"skill_name" : "��Ŀ�ѻ�"
]),
([	"action" : "$Nʹһʽ"YEL"�������ķ���"NOR"��˫�ֻӶ�������˷�����������Ӱ������һצͻ����ץ��$n$l",
	"lvl" : 40,
	"skill_name" : "�����ķ�"
]),
([	"action" : "$N���ֻ��ۣ�˫�������ư�ζ���һʽ"CYN"��ˮ�����ɡ�"NOR"���ڽڽ��ƣ���$n��������",
	"lvl" : 48,
	"skill_name" : "ˮ������"
]),
([	"action" : "$Nһʽ"GRN"��ɽ�����ܡ�"NOR"��һ���ĳ�����ɳʯ��Ȼ��ʮָ���죬������հ������$n��ȫ��ҪѨ",
	"lvl" : 54,
	"skill_name" : "ɽ������"
]),
([	"action" : "$N�������ţ�һʽ"YEL"��������ġ�"NOR"����һ���׷������У�˫��ͬʱ����$n���ߵ���Ѩ",
	"lvl" : 100,
	"skill_name" : "�������"
])
});

int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }
int valid_combine(string combo){ return combo=="luohan-cuff"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�������ֱ�����֡�\n");
	if ((int)me->query_skill("zhanzhuang-gong", 1) < 10)
		return notify_fail("���վ׮����򲻹����޷�ѧ�����֡�\n");
	if ((int)me->query("max_neili") < 10)
		return notify_fail("�������̫�����޷��������֡�\n");
	if (me->query_skill("shaolin-cuff", 1) < 10 )
		return notify_fail("�㻹δ����������ȭ���޷�ѧϰ�����֡�\n");

	return 1;
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 40)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("������������������֡�\n");
	me->receive_damage("qi", 20);
	me->add("neili", -10);
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
	int d_e1 = -30;
	int d_e2 = 0;
	int p_e1 = 30;
	int p_e2 = 60;
	int f_e1 = 60;
	int f_e2 = 160;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("fengyun-hand", 1);
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
int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 20; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	 return __DIR__"fengyun-hand/" + action;
}

int help(object me)
{
	write(HIC"\n�����֣�"NOR"\n");
	write(@HELP

    �������������������ַ������޺�ȭ������

	ѧϰҪ��
		վ׮��10��
		������ȭ10��
		������Ϊ10
HELP
	);
	return 1;
}


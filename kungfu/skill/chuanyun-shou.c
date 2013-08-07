// chuanyun-shou.c ������
// Last Modified by Sir on 5/19/2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$Nһʽ"HIC"������ʽ��"NOR"��������Σ���������ͻȻ����$n�ı����Ѩ",
	"lvl" : 0,
	"skill_name" : "����ʽ"
]),
([	"action" : "$N����һ�Σ�һʽ"HIW"������ʽ��"NOR"����������$n�ļ�ͷ����ȭ����$n���ؿ�",
	"lvl" : 10,
	"skill_name" : "����ʽ"
]),
([	"action" : "$Nһʽ"BLU"���ὣʽ��"NOR"�����ֻ�£��צ��һ���־����$n���ʺ�Ҫ��",
	"lvl" : 20,
	"skill_name" : "�ὣʽ"
]),
([	"action" : "$N�������У�����ֱ����һʽ"GRN"������ʽ��"NOR"����Ʈ��������$n������",
	"lvl" : 30,
	"skill_name" : "����ʽ"
]),
([	"action" : "$Nʹһʽ"CYN"����ˮʽ��"NOR"����ȭ�ϸ�����̽��ͻ����ץ��$n���ɲ�",
	"lvl" : 38,
	"skill_name" : "��ˮʽ"
]),
([	"action" : "$Nһʽ"HIM"������ʽ��"NOR"��ʮָ����������ʵʵ��Ϯ��$n��ȫ��ҪѨ",
	"lvl" : 51,
	"skill_name" : "����ʽ"
]),
([	"action" : "$N˫�ֱ�ȭ��һʽ"HIY"��ժ��ʽ��"NOR"����Ӱ���ɣ�ͬʱ��$nʩ���žŰ�ʮһ��",
	"lvl" : 56,
	"skill_name" : "ժ��ʽ"
]),
([	"action" : "$Nһʽ"HIR"��׷��ʽ��"NOR"��ȭ���������֣��������ޣ�����������$n�ĵ���",
	"lvl" : 60,
	"skill_name" : "׷��ʽ"
])
});

int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }
int valid_combine(string combo) { return combo=="tianchang-zhang"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�������ֱ�����֡�\n");
	if ((int)me->query_skill("baiyun-xinfa", 1) < 20)
		return notify_fail("��İ����ķ���򲻹����޷�ѧ�����֡�\n");
	return 1;
}

int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��ı�����ֲ�����ϰ��\n");
	if ((int)me->query("qi") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("������������������֡�\n");
	me->receive_damage("qi", 25);
	me->add("neili", -15);
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
	int d_e1 = -35;
	int d_e2 = -5;
	int p_e1 = 25;
	int p_e2 = 55;
	int f_e1 = 90;
	int f_e2 = 190;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("chuanyun-shou", 1);
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
int learn_bonus() { return 25; }
int practice_bonus() { return 25; }
int success() { return 15; }
int power_point(object me) { return 1.0; }
string perform_action_file(string action)
{
	return __DIR__"chuanyun-shou/" + action;
}

int help(object me)
{
	write(HIC"\n�����֣�"NOR"\n");
	write(@HELP

    ������Ϊ��ɽ���书��
    �����쳤�ƻ�����

	ѧϰҪ��
		�����ķ�20��
HELP
	);
	return 1;
}


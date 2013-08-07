// tanzhi.c ��ָ��ͨ
// Last Modified by sir 10.22.2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N��ָ���˸���Ȧ��һʽ"CYN"�������ѵء�"NOR"���϶��»���$n��ȫ��",
	"lvl" : 0,
	"skill_name" : "�����ѵ�"
]),
([	"action" : "$N���ƻ��أ�һ��"BLU"���������ơ�"NOR"����ָ��������ָ��$n�Ķ�ͷ",
	"lvl" : 10,
	"skill_name" : "��������"
]),
([	"action" : "$N˫�������һʽ"YEL"��ǧ����ָ��"NOR"����ָ��$n��$l",
	"lvl" : 20,
	"skill_name" : "ǧ����ָ"
]),
([	"action" : "$N����һ̾��һ��"RED"����ָ������"NOR"��˫�ֻó�����ָӰ������$n��$l",
	"lvl" : 30,
	"skill_name" : "��ָ����"
]),
([	"action" : "$Nһʽ"GRN"��Цָ���ϡ�"NOR"��������ʽ����ָ����һ��ָ�����$n��$l",
	"lvl" : 40,
	"skill_name" : "Цָ����"
]),
([	"action" : "$N�ó�"HIY"������һָ��"NOR"���ȫ��������һָ����$n��$l",
	"lvl" : 50,
	"skill_name" : "����һָ"
]),

});

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }
int valid_combine(string combo) { return combo=="lanhua-shou"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("����ָ��ͨ������֡�\n");
	if ((int)me->query_skill("bibo-shengong", 1) < 20)
		return notify_fail("��ı̲��񹦻�򲻹����޷�ѧ��ָ��ͨ��\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷�����ָ��ͨ��\n");
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��ı�����ֲ�����ϰ��\n");
	if ((int)me->query("qi") < 40)
		return notify_fail("���������������Ϣһ�������ɡ�\n");
	if ((int)me->query("neili") < 30)
		return notify_fail("���������������ָ��ͨ��\n");
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
	int d_e1 = 30;
	int d_e2 = 50;
	int p_e1 = -30;
	int p_e2 = -10;
	int f_e1 = 300;
	int f_e2 = 400;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("tanzhi-shentong", 1);
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
int learn_bonus() { return 10; }
int practice_bonus() { return 10; }
int success() { return 15; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"tanzhi-shentong/" + action;
}
int help(object me)
{
	write(HIC"\n��ָ��ͨ��"NOR"\n");
	write(@HELP

    �����һ�������ҩʦ�ĳ���������
    ����������Ѩ�ֻ�����

	ѧϰҪ��
		�̲���20��
		����100
HELP
	);
	return 1;
}


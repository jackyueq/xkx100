// tianshan-zhang.c ��ɽ�ȷ�
// Last Modified by sir 10.22.2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action": "$Nʹ��һ��"HIW"�����ӿ�����"NOR"������$w�󿪴���ɨ��$n��$l",
	"lvl" : 1,
	"skill_name" : "���ӿ���"
]),
([	"action": "$N����$w������죬һ��"HIC"��ɽ��������"NOR"��$n��$l��ȥ",
	"lvl" : 13,
	"skill_name" :"ɽ������"
]),
([	"action": "$N����$w���Ӹ�����ʹһ��"HIW"����ɽѩ����"NOR"����$n��$l",
	"lvl" : 30,
	"skill_name" : "��ɽѩ��"
]),
([	"action": "$Nһ��"HIR"��������ѩ��"NOR"������Ʈ�����ߣ�����$w����$n��$l",
	"lvl" : 45,
	"skill_name" : "������ѩ"
]),
([	"action": "$Nʹһ��"HIB"���ع�õ硹"NOR"������$w��һ���������$n��$l",
	"lvl" : 60,
	"skill_name" : "�ع�õ�"
]),
([	"action": "$Nʹ����"HIC"����˪��Ӱ��"NOR"��$w������Ӱ��������$n��$l",
	"lvl" : 75,
	"skill_name" : "��˪��Ӱ"
]),
([	"action": "$N��$wƾ��һָ��һ��"BLU"����ʯ���̡�"NOR"����$n��$l",
	"lvl" : 90,
	"skill_name" : "��ʯ����"
]),
([	"action": "$N����һԾ������$wһ��"MAG"������������"NOR"��׼$n��$lɨȥ",
	"lvl" : 105,
	"skill_name" : "��������"
]),
([	"action": "$N����$w�й�ֱ����һʽ"CYN"�����ȳ��硹"NOR"��׼$n��$l��ȥ",
	"lvl" : 120,
	"skill_name" : "���ȳ���"
]),
([	"action": "$Nһ��"GRN"�����·ת��"NOR"��$w�����ػ���$n��$l��ȥ",
	"lvl" : 145,
	"skill_name" : "���·ת"
]),
});

int valid_enable(string usage) { return usage == "staff" || usage == "parry"; }
int valid_learn(object me)
{
	if (me->query_skill("huagong-dafa",1) < 20)
		return notify_fail("��Ļ����󷨹���������\n");
	if ((int)me->query("max_neili") < 80)
		return notify_fail("�������������\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "staff")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("qi") < 50 || (int)me->query("neili") < 30 )
		return notify_fail("�������������������ɽ�ȷ���\n");
	me->receive_damage("qi", 40);
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
string perform_action_file(string action)
{
	return __DIR__"tianshan-zhang/" + action;
}
mapping query_action(object me, object weapon)
{
/* d_e=dodge_effect p_e=parry_effect f_e=force_effect m_e=damage_effect */
	int d_e1 = -40;
	int d_e2 = -10;
	int p_e1 = 15;
	int p_e2 = 50;
	int f_e1 = 250;
	int f_e2 = 300;
	int m_e1 = 180;
	int m_e2 = 280;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("tianshan-zhang", 1);
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
int learn_bonus() { return 10; }
int practice_bonus() { return 10; }
int success() { return 10; }
int power_point(object me) { return 1.0; }

int help(object me)
{
	write(HIC"\n��ɽ�ȷ�\n");
	write(@HELP

    ��ɽ�ȷ�����������е����

	ѧϰҪ��
		������20��
		����80
HELP
	);
	return 1;
}


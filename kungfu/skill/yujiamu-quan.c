// yujiamu-quan.c ������ĸȭ
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N����˫ȭ��ʹ��һ��"HIC"���ඥ��"NOR"����ͷ����$n��$l",
	"skill_name" : "�ඥ",
	"lvl" : 0
]),
([	"action" : "$Nʹ��һ��"HIC"����ࡹ"NOR"������һ�ͣ����ֻ���������һȭ����$n���ɲ�",
	"skill_name" : "���",
	"lvl" : 8
]),
([	"action" : "$Nʹ��һ��"HIC"���ü��"NOR"����ȭ���$n��ǰ�أ�һ������ȭ��ɨ$n��̫��Ѩ",
	"skill_name" : "�ü",
	"lvl" : 16
]),
([	"action" : "$N���ι��죬ʹһ��"HIC"������"NOR"��˫ȭ���»���$n��$l",
	"skill_name" : "���",
	"lvl" : 24
]),
([	"action" : "$Nʹ��һ��"HIC"�����š�"NOR"��˫ȭ������������������ֱָ$n��$l",
	"skill_name" : "����",
	"lvl" : 32
]),
([	"action" : "$N΢΢һЦ��ʹ��һʽ"HIC"��������"NOR"��˫ȭǰ�������ֱȡ$n������",
	"skill_name" : "����",
	"lvl" : 40
]),
([	"action" : "$Nʹ��һ��"HIC"�����ġ�"NOR"��ȫ��ת��˫ȭ��ɨ$n��$l",
	"skill_name" : "����",
	"lvl" : 48
]),
([	"action" : "$N����һԾ��ʹ��һ��"HIC"����ʤ��"NOR"��һȭ�ͻ�$n�ʺ�",
	"skill_name" : "��ʤ",
	"lvl" : 56
]),
});

int valid_enable(string usage) { return usage == "unarmed" || usage == "parry"; }
int valid_combine(string combo) { return combo=="dashou-yin"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��������ĸȭ������֡�\n");
	else if ((int)me->query("max_neili") < 50)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("longxiang", 1) >= 20 ||
		(int)me->query_skill("xiaowuxiang", 1) >= 20)
		return 1;
	else if ((int)me->query_skill("longxiang", 1) < 20)
		return notify_fail("���������������̫ǳ��\n");
	else if ((int)me->query_skill("xiaowuxiang", 1) < 20)
		return notify_fail("���С���๦���̫ǳ��\n");
}
int practice_skill(object me)
{
	object weapon;

	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��������ĸȭ������֡�\n");
	if ((int)me->query("qi") < 40)
		return notify_fail("������������������˽�����ĸȭ��\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("�������������������ĸȭ��\n");
	me->receive_damage("qi", 30);
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
	int d_e1 = 30;
	int d_e2 = 55;
	int p_e1 = -25;
	int p_e2 = -10;
	int f_e1 = 100;
	int f_e2 = 250;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("yujiamu-quan", 1);
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
int learn_bonus() { return 30; }
int practice_bonus() { return 25; }
int success() { return 20; }
int power_point(object me) { return 1.0; }

int help(object me)
{
	write(HIC"\n������ĸȭ��"NOR"\n");
	write(@HELP

    ������ĸȭ������ѩɽ���书��
    �������ڴ���ӡ������

	ѧϰҪ��
		�����������С���๦20��
		����50
HELP
	);
	return 1;
}


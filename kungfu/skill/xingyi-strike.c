// xingyi-strike.c ������
// Last Modified by sega on Mar. 10 2000

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N����һ�ϣ�Ȼ�������ĳ������θ�����һʽ"CYN"�����α�Ӱ��"NOR"�������ջأ����Ʊ�����£��͵�����$n��$l",
	"lvl" : 0,
	"skill_name" : "���α�Ӱ"
]),
([	"action" : "$N���˫�֣�ʮָ���ţ�һʽ"RED"�����ǵ�㡹"NOR"����ָ����Ʈ����ʮָֻ�⼲��$n��$l",
	"lvl" : 20,
	"skill_name" : "���ǵ��"
]),
([	"action" : "$Nʹһʽ"HIC"�������Ƕ���"NOR"��һ������Ծ����������������է��է�ϣ���۵糸����$n��$l��������",
	"lvl" : 40,
	"skill_name" : "�����Ƕ�"
]),
([	"action" : "$Nһ����Х��һʽ"HIW"���������ǡ�"NOR"��˫�ƻó������Ƕ�������ǵذ���$n��ȥ",
	"lvl" : 60,
	"skill_name" : "��������"
])
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }	
int valid_combine(string combo) { return combo=="canhe-finger"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�������Ʊ�����֡�\n");
	if ((int)me->query_skill("shenyuan-gong", 1) < 15)
		return notify_fail("�����Ԫ����򲻹����޷�ѧ�����ơ�\n");
	if ((int)me->query("max_neili") < 50)
		return notify_fail("�������̫�����޷��������ơ�\n");
	return 1;
}

int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��ı�����ֲ�����ϰ��\n");
	if ((int)me->query("qi") < 40)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 40)
		return notify_fail("������������������ơ�\n");
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
	int d_e1 = -35;
	int d_e2 = -5;
	int p_e1 = 5;
	int p_e2 = 35;
	int f_e1 = 180;
	int f_e2 = 280;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("xingyi-strike", 1);
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

int help(object me)
{
	write(HIC"\n�����ƣ�"NOR"\n");
	write(@HELP

    ����Ľ�ݼ������ֵľ���������һ�Ž�������֮������������
ת���ơ��������Ʊ��������ݻ���Ľ�ݼҴ��Ʒ���
    ����κ�ָ������

	ѧϰҪ��
		��Ԫ��15��
		����50
HELP
	);
	return 1;
}


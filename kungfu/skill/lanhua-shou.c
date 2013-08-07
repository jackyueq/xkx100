// lanhua-shou.c -������Ѩ��
// Last Modified by sir 10.23.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N������ָ�ֿ���΢΢һ�����ٲ�£����һ����һʽ" MAG"�������Ƶ���"NOR"������$n������ҪѨ",
	"lvl" : 0,
	"skill_name" : "�����Ƶ�"
]),
([	"action" : "$N��������$n��һʽ"CYN"�����Ʊ��¡�"NOR"��������ָ������������$n����ǰ��Ѩ",
	"lvl" : 10,
	"skill_name" : "���Ʊ���"
]),
([	"action" : "$Nʹһʽ"HIW"������������"NOR"�������鹥�����ֲ�ָбǰ����������$n�ļ羮Ѩ",
	"lvl" : 20,
	"skill_name" : "��������"
]),
([	"action" : "$N���ƻ��أ�΢΢�������ƹ��ϣ�һʽ"BLU"������ŪӰ��"NOR"����������$n����ͻѨ",
	"lvl" : 30,
	"skill_name" : "����ŪӰ"
]),
([	"action" : "$Nʹһʽ"GRN"���������塹"NOR"����Ӱ����������$n����͵�����$n�Ĵ�׵Ѩ",
	"lvl" : 42,
	"skill_name" : "��������"
]),
([	"action" : "$N���������������ϵ�����ǰ������ָ�η��ϣ�΢��һ������һʽ"HIG"�������뷼��"NOR"��˫���������һ��������������������$n�Ļ��ǡ���ᡢ�Ϲ�������Ѩ",
	"lvl" : 54,
	"skill_name" : "�����뷼"
]),
([	"action" : "$N����ƮƮ������Ծ��һʽ"RED"����Ӱ���㡹"NOR"���Ӹ����£�����һ����������$n�İٻ��Ѩ",
	"lvl" : 66,
	"skill_name" : "��Ӱ����"
]),
([	"action" : "$N����ʩչ��"HIR"��������Բ��"NOR"��˫�ּ�����һ�����ľ�������$n�������¸���ҪѨ",
	"lvl" : 80,
	"skill_name" : "������Բ"
])
});

int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }
int valid_combine(string combo) { return combo=="tanzhi-shentong"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail(HIC"��������Ѩ�ֱ�����֡�\n"NOR);
	if ((int)me->query_skill("bibo-shengong", 1) < 20)
		return notify_fail("��ı̲��񹦻�򲻹����޷�ѧ������Ѩ�֡�\n");
	if ((int)me->query("max_neili") < 200)
		return notify_fail("�������̫�����޷���������Ѩ�֡�\n");
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��ı�����ֲ�����ϰ��\n");
	if ((int)me->query("qi") < 40)
		return notify_fail("�������̫���ˣ��޷���������Ѩ�֡�\n");
	if ((int)me->query("neili") < 40)
		return notify_fail("�������������������Ѩ�֡�\n");
	me->receive_damage("qi", 35);
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
	int d_e1 = -50;
	int d_e2 = -20;
	int p_e1 = 10;
	int p_e2 = 40;
	int f_e1 = 170;
	int f_e2 = 270;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("lanhua-shou", 1);
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
	return __DIR__"lanhua-shou/" + action;
}

int help(object me)
{
	write(HIC"\n������Ѩ�֣�"NOR"\n");
	write(@HELP

    ������Ѩ���Ƕ����һ����书��������ָ״��������
    ���뵯ָ��ͨ������

	ѧϰҪ��
		�̲���20��
		����200
HELP
	);
	return 1;
}


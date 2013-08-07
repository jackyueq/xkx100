// huhe-quan.c ����˫��ȭ
// Last Modified by Winder on Mar. 10 2000
// ��Ҫ����û���ɵ�npc����

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N���ֺ�ʮ��һʽ�������ơ���˫ȭ���ƶ���������$n��$l",
	"lvl" : 0,
	"skill_name" : "������"
]),
([	"action" : "$Nһʽ�����Ρ���˫�������»���ȭ�����棬��ž����",
	"lvl" : 10,
	"skill_name" : "����"
]),
([	"action" : "$N�ڿշ���һʽ�����Ρ���˫��˫���������$n�޿ɶ��",
	"lvl" : 20,
	"skill_name" : "����"
]),
([	"action" : "$N˫���麬����Ե�³���һʽ���ڻ����ġ���������$n�Ƴ�",
	"lvl" : 30,
	"skill_name" : "�ڻ�����"
]),
([	"action" : "$Nһ��ǰ�죬һ�ۺ�ָ��һʽ���׶Ⱦ��졹������$n����ǰ���",
	"lvl" : 40,
	"skill_name" : "�׶Ⱦ���"
]),
([	"action" : "$Nһʽ���׺׵�ˮ��������ʮָ���$n��ȫ����ʮ����ҪѨ",
	"lvl" : 48,
	"skill_name" : "�׺׵�ˮ"
]),
([	"action" : "$N��Ŀ���ӣ�˫��������һʽ����Х������������˷������������ǵ�
����",
	"lvl" : 54,
	"skill_name" : "��Х����"
]),
([	"action" : "$N��Ц��Ц��˫ȭ�����޶���һʽ���ͻ���ɽ������Ȼ����$n��ǰ��",
	"lvl" : 60,
	"skill_name" : "�ͻ���ɽ"
])
});

int valid_enable(string usage) { return	usage=="cuff" || usage=="parry"; }
int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("������˫��ȭ������֡�\n");
	if ((int)me->query_skill("haoran-zhengqi", 1) < 10)
		return notify_fail("��ĺ�Ȼ������򲻹����޷�ѧ����˫��ȭ��\n");
	if ((int)me->query("max_neili") < 50)
		return notify_fail("�������̫�����޷�������˫��ȭ��\n");
	return 1;
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("�����������������˫��ȭ��\n");
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
	int d_e1 = 40;
	int d_e2 = 60;
	int p_e1 = -20;
	int p_e2 = 0;
	int f_e1 = 60;
	int f_e2 = 210;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("huhe-quan", 1);
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
int practice_bonus() { return 30; }
int success() { return 20; }
int power_point(object me) { return 1.0; }

int help(object me)
{
	write(HIC"\n����˫��ȭ��"NOR"\n");
	write(@HELP

    ����˫��ȭ�����к׵ĳ���������

	ѧϰҪ��
		��
HELP
	);
	return 1;
}


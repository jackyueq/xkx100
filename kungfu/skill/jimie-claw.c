// Last Modified by Winder on May. 29 2001
// jimie-claw.c ����צ �Ͳ������ֻ��� �������������˿ࡣ

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$Nȫ��εض���һʽ"HIG"������"NOR"�־���˫צ��ۣ�Ѹ�͵�ץ��$n��ȴ�ֲ����κΰ���",
	"lvl"    : 0,
	"skills_name" : "��",
]),
([	"action" : "$Nһʽ"HIY"���ϡ�"NOR"�־���˫צ�й�ֱ����ȴ�����У���������֮�ʣ�$n�ѱ��޿ɱ�",
	"lvl"    : 10,
	"skills_name" : "��",
]),
([	"action" : "$N�Ų����ǣ�����"MAG"������"NOR"̬��������ץ����һ�ӣ���Ȼ�ܴ�����������ֱϮ$n$l",
	"lvl"    : 20,
	"skills_name" : "��",
]),
([	"action" : "$N˫צ����һʽ"HIB"������"NOR"�־�������ץ����׷��$n��Ӱ���ǣ���Ҫ��ɱ$pȥצ��",
	"lvl"    : 30,
	"skills_name" : "��",
]),
([	"action" : "$Nһʽ"GRN"���󲻵á�"NOR"����צͻ������צ������������ץ�ֳ���˫צ�����ץ��$n���ؿ�",
	"lvl"    : 40,
	"skills_name" : "�󲻵�",
]),
([	"action" : "$Nԭ�ز�����һʽ"RED"�������롹"NOR"��ֻ��$nϮ����˫����Ȼ��צ������ֱ��$n��������Ѩ",
	"lvl"    : 60,
	"skills_name" : "������",
]),
([	"action" : "$N����һ�ӣ�˫צ�����������ƿն�����һʽ"HIM"��Թ���᡹"NOR"��Ѹ���ޱȵطɴ���$n",
	"lvl"    : 80,
	"skills_name" : "Թ����",
]),
([	"action" : "$N�ڿո߷����ɣ����һʽ"HIR"��������ʢ��"NOR"��һʱ����г�������$N����Ӱ�����ץӰ����$n",
	"lvl"    : 100,
	"skills_name" : "������ʢ",
])
});

int valid_enable(string usage) { return usage=="claw" || usage=="parry"; }
int valid_combine(string combo){ return combo=="boluomi-hand"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("������צ������֡�\n");
	if ((int)me->query_skill("zhanzhuang-gong", 1) < 40)
		return notify_fail("���վ׮����򲻹����޷�ѧ����צ��\n");
	if ((int)me->query("max_neili") < 400)
		return notify_fail("�������̫�����޷���ϰ����צ��\n");
	if (me->query_skill("sanhua-strike", 1) < 40)
		return notify_fail("���ɢ���ƻ�򲻹����޷�ѧ����צ��\n");
	return 1;
}
int practice_skill(object me)
{
	if ((int)me->query("qi") < 40)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("�����������������צ��\n");
	me->receive_damage("qi", 40);
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
	int d_e1 = 60;
	int d_e2 = 30;
	int p_e1 = -5;
	int p_e2 = -20;
	int f_e1 = 100;
	int f_e2 = 250;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int)me->query_skill("jimie-claw", 1);
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
		"damage_type" : random(2) ? "����" : "ץ��",
	]);
}
int learn_bonus() { return 30; }
int practice_bonus() { return 25; }
int success() { return 20; }
int power_point(object me) { return 1; }

string perform_action_file(string action)
{
	 return __DIR__"jimie-claw/" + action;
}

int help(object me)
{
	write(HIC"\n����צ��"NOR"\n");
	write(@HELP

    ����צ������������צ�����Ͳ������ֻ��������Է��������˿ࡣ

	ѧϰҪ��
		վ׮��40��
		ɢ����40��
		������Ϊ400��
HELP
	);
	return 1;
}


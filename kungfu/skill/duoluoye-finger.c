// Last Modified by Winder on May. 29 2001
// duoluoye-finger.c ����Ҷָ �ʹ������ƻ��� ���Է���֮���������족��

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }
 
mapping *action = ({
([	"action" : "$Nһʽ"HIY"���������졹"NOR"��������ָ�������������������һ�����ز���$n$l",
	"lvl"   : 0,
	"skill_name" : "��������"
]),
([	"action" : "$N���Ц��ʹ��"HIC"�������졹"NOR"������΢�࣬��ָ����״�����Юһ�ɼ����ľ�������$n",
	"lvl"   : 20,
	"skill_name" : "������"
]),
([	"action" : "$Nһʽ"HIB"��ҹĦ�졹"NOR"���������д󿪴��أ�����Ʈ���鶯����Ȼһָ���������$n$l��",
	"lvl"   : 40,
	"skill_name" : "ҹĦ��"
]),
([	"action" : "$Nʹ��һ��"CYN"�������졹"NOR"������������������ס$n�����ӣ�����һ�ӣ�һָ����$n$l",
	"lvl"   : 60,
	"skill_name" : "������"
]),
([	"action" : "$N˫�ֱ�Բ���������У�"YEL"�������졹"NOR"������һ��ָ���Ϯ$n������������ʵ���޼᲻��",
	"lvl"   : 80,
	"skill_name" : "������"
]),
([	"action" : "$N��$n������ָ�����������������Х֮��������"MAG"�����������졹"NOR"����ʵʵ������ʤ��",
	"lvl"   : 100,
	"skill_name" : "����������"
]),
});

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }
int valid_combine(string combo) { return combo=="jingang-strike"; }
 
int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		 return notify_fail("������Ҷָ������֡�\n");
	if ((int)me->query_skill("zhanzhuang-gong", 1) < 50)
		 return notify_fail("���վ׮����򲻹����޷�ѧ����Ҷָ��\n");
	if ((int)me->query("max_neili") < 500)
		return notify_fail("�������̫�����޷�������Ҷָ��\n");
	if ((me->query_skill("boluomi-hand", 1) < 50) ||
		(me->query_skill("mohe-finger", 1) < 50))
		return notify_fail("��Ĳ������ֺ�Ħڭָ��򲻹����޷�ѧ����Ҷָ��\n");
	return 1;
}
int practice_skill(object me)
{
	if ((int)me->query("qi") < 50)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("�����������������Ҷָ��\n");
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
	int d_e1 = 40;
	int d_e2 = 60;
	int p_e1 = -20;
	int p_e2 = 0;
	int f_e1 = 150;
	int f_e2 = 250;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("duoluoye-finger", 1);
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
	return __DIR__"duoluoye-finger/" + action;
}

int help(object me)
{
	write(HIC"\n����Ҷָ��"NOR"\n");
	write(@HELP

    ����Ҷָ�������ֵ�ָ�����ʹ������ƻ��������Է���֮���������족��

	ѧϰҪ��
		վ׮��50��
		��������50��
		Ħڭָ50��
		������Ϊ500
HELP
	);
	return 1;
}


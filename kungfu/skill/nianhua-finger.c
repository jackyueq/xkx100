// Last Modified by Winder on May. 29 2001
// nianhua-finger.c �黨ָ ��ӥצ������ ȡ������ʮ���������

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N����̧�ۣ���ָ���˸���Ȧ��һʽ"HIB"��������ʽ��"NOR"����һ��������$n��$l",
	"lvl"    : 0,
	"skill_name" : "������ʽ"
]),
([	"action" : "$N����������ǰ��һ��"HIY"��������ʽ��"NOR"����ָ��Ҹ��������������������$n��$l",
	"lvl"    : 10,
	"skill_name" : "������ʽ"
]),
([	"action" : "$N���΢Ц������б�У�����פ����ǽ������һʽ"HIM"������ʽ��"NOR"����$n$l���",
	"lvl"    : 20,
	"skill_name" : "����ʽ"
]),
([	"action" : "$N˫Ŀ΢������¶��Ц��һʽ"HIG"����Ҷʽ��"NOR"���û���ǧ�ٸ�ָӰ������$n$l",
	"lvl"    : 30,
	"skill_name" : "��Ҷʽ"
]),
([	"action" : "$Nһʽ"MAG"�������ʽ��"NOR"�����ƻ�ס�������бָ�������ƣ����ŲŻ�������$n$l",
	"lvl"    : 40,
	"skill_name" : "�����ʽ"
]),
([	"action" : "$N΢Ц֮����˫��ƽ����ǰ��ʮָ�濪��һʽ"CYN"���ȳ���ʽ��"NOR"��ָ��$n�������Ѩ",
	"lvl"    : 60,
	"skill_name" : "�ȳ���ʽ"
]),
([	"action" : "$N˫�Ʒ��ɣ�һʽ"RED"����������ʽ��"NOR"��΢Ц����ָ�˱ų������ᾢ������$n",
	"lvl"    : 80,
	"skill_name" : "��������ʽ"
]),
([	"action" : "$Nһ��"HIC"��Ħڭ����ʽ��"NOR"����ָ����������һ����ϸ���������������$n��$l��ȥ",
	"lvl"    : 110,
	"skill_name" : "Ħڭ����ʽ"
]),
([	"action" : "$Nһ��"HIM"��ʮ��٤Ҷʽ��"NOR"����Цһ����˫��ʳָ���棬ָ������һ����������ḧ��$n$l",
	"lvl"    : 130,
	"skill_name" : "ʮ��٤Ҷʽ"
]),
([	"action" : "$N����������ǰ��һʽ"HIR"��Ħ�о���ʽ��"NOR"��΢Ц������ʳָ��סĴָ���������$nһ��",
	"lvl"    : 150,
	"skill_name" : "Ħ�о���ʽ"
])
});

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }
int valid_combine(string combo){ return combo=="eagleg-claw"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("���黨ָ������֡�\n");
	if ((int)me->query_skill("zhanzhuang-gong", 1) < 60)
		return notify_fail("���վ׮����򲻹����޷�ѧ�黨ָ��\n");
	if ((int)me->query("max_neili") < 600)
		return notify_fail("�������̫�����޷����黨ָ��\n");
	if ((me->query_skill("duoluoye-finger", 1) < 50) ||
		(me->query_skill("jingang-strike", 1) < 50))
		return notify_fail("��Ĵ������ƺͶ���Ҷָ��򲻹����޷�ѧ�黨ָ��\n");
	return 1;
}
int practice_skill(object me)
{
	if ((int)me->query("qi") < 55)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 30)
		return notify_fail("��������������黨ָ��\n");
	me->receive_damage("qi", 35);
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
	int d_e1 = 35;
	int d_e2 = 60;
	int p_e1 = -20;
	int p_e2 = -5;
	int f_e1 = 200;
	int f_e2 = 300;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("nianhua-finger", 1);
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
	return __DIR__"nianhua-finger/" + action;
}

int help(object me)
{
	write(HIC"\n�黨ָ��"NOR"\n");
	write(@HELP

    �黨ָ��������ָ������ӥצ��������ȡ������ʮ���������

	ѧϰҪ��
		վ׮��60��
		��������50��
		����Ҷָ50��
		������Ϊ600
HELP
	);
	return 1;
}


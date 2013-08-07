// lieyan-dao.c ���浶
// Last Modified by winder on Sep. 27 2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$Nһ�С�����������$w����һ��������$n���������Σ�����������仯����",
	"lvl" : 0,
	"skill_name" : "��������",
]),
([	"action" : "$Nһ�С���ˮǧɽ����������һǰһ��$w����������$n��$lնȥ",
	"lvl" : 8,
	"skill_name" : "��ˮǧɽ",
]),
([	"action" : "$N����Ծ�䣬һ�С���ɨǧ���$w���ż������һ������$n��ɨ��ȥ",
	"lvl" : 16,
	"skill_name" : "��ɨǧ��",
]),
([	"action" : "$Nһ�С����ҿ�������$w�󿪴��أ����Ҳ�������һ������һ����$n�����翳��",
	"lvl" : 24,
	"skill_name" : "���ҿ���",
]),
([	"action" : "$N����$w���϶��£�һ�С����ɷ��١���������к����һƬѩ���ٲ�����$n��ͷ��",
	"lvl" : 33,
	"skill_name" : "���ɷ���",
]),
([	"action" : "$N����$w��ʹ��һ�С�ֱ���������������ã����ҿ�����ǧ�����������$n",
	"lvl" : 42,
	"skill_name" : "ֱ������",
]),
([	"action" : "$N���õ��羢����һ�С���è������һ����ת������������$n��$l����ȥ",
	"lvl" : 51,
	"skill_name" : "��è����",
]),
([	"action" : "$N��ǰһ��������һ�С��ϲ���ɽ����$wֱֱ��������һƬ�����ĵ�Ӱ��$n��ȫ����ȥ",
	"lvl" : 60,
	"skill_name" : "�ϲ���ɽ",
]),
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }
int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 10)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("jiuyang-shengong", 1) < 20)
		return notify_fail("��ľ����񹦻��̫ǳ��\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "blade")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("����������������浶����\n");
	me->receive_damage("qi", 30);
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
	int d_e1 = 50;
	int d_e2 = 30;
	int p_e1 = 0;
	int p_e2 = -20;
	int f_e1 = 100;
	int f_e2 = 150;
	int m_e1 = 70;
	int m_e2 = 180;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int)me->query_skill("lieyan-dao", 1);
	for(i = ttl; i > 0; i--)
		if(lvl > action[i-1]["lvl"])
		{
			seq = i; /* �������������� */
			break;
		}
	seq = random(seq);	 /* ѡ������������ */
	return ([
		"action"	: action[seq]["action"],
		"dodge"	 : d_e1 + (d_e2 - d_e1) * seq / ttl,
		"parry"	 : p_e1 + (p_e2 - p_e1) * seq / ttl,
		"force"	 : f_e1 + (f_e2 - f_e1) * seq / ttl,
		"damage"	: m_e1 + (m_e2 - m_e1) * seq / ttl,
		"damage_type" : "����",
	]);
}
int learn_bonus() { return 20; }
int practice_bonus() { return 15; }
int success() { return 15; }
int power_point(object me) { return 1; }
string perform_action_file(string action)
{
//	return __DIR__"lieyan-dao/" + action;
}
int help(object me)
{
	write(HIC"\n���浶����"NOR"\n");
	write(@HELP

    ���浶�������̵ĵ�����

	ѧϰҪ��
		������20��
		������Ϊ10
HELP
	);
	return 1;
}


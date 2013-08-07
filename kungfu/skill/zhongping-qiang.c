//zhongping-qiang.c ��ƽǹ��
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action": "$N˫��һ�𣬾���ǰ�죬ʹ��һ��"HIW"����ƽ�޵С�"NOR"������$wƽƽֱ��������$n��$l",
	"lvl" : 0,
	"skill_name" : "��ƽ�޵�"
]),
([	"action": "$N����$w������ת���������������¶ף�����һ��"HIB"��ҹ��̽����"NOR"������$n��$l��ȥ",
	"lvl" : 10,
	"skill_name" : "ҹ��̽��"
]),
([	"action": "$N����$w������һ��ǹ����һ��"HIB"�����߳�����"NOR"��$n������ȥ",
	"lvl" : 20,
	"skill_name" : "���߳���"
]),
([	"action": "$Nһ��"HIM"��������ǹ��"NOR"������$w����СȦ��ȥ$n�ĺ��У�����$w΢̧��ָ��$n��$l",
	"lvl" : 30,
	"skill_name" : "������ǹ"
]),
});

int valid_enable(string usage) { return usage=="spear" || usage=="parry"; }
int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 70)
		return notify_fail("�������������\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "spear")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("qi") < 50 || (int)me->query("neili") < 50 )
		return notify_fail("�������������������ƽǹ����\n");
	me->receive_damage("qi", 20);
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
	int d_e1 = -30;
	int d_e2 = -10;
	int p_e1 = 0;
	int p_e2 = 20;
	int f_e1 = 200;
	int f_e2 = 300;
	int m_e1 = 200;
	int m_e2 = 350;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("zhongping-qiang", 1);
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
int learn_bonus() { return 15; }
int practice_bonus() { return 15; }
int success() { return 10; }
int power_point(object me) { return 1.0; }

int help(object me)
{
	write(HIC"\n��ƽǹ����"NOR"\n");
	write(@HELP

    ��ƽǹ���ǻ����ɵĳ����书��

	ѧϰҪ��
		����70
HELP
	);
	return 1;
}


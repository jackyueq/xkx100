// duanjia-sword.c �μҽ�
// Last Modified by sir 10.22.2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N��ǰ����һ����һ��"HIB"���ƺ����롹"NOR"������$w����������$n��$l������ȥ",
	"lvl" : 0,
	"skill_name" : "�ƺ�����"
]),
([	"action" : "$N����Ծ�����ֽ���������һ����$w�����������٣�һʽ" GRN"������ֱ�¡�"NOR"ֱ��$n��$l",
	"lvl" : 9,
	"skill_name" : "����ֱ��"
]),
([	"action" : "$Nһ��"BLU"��ѩӵ���ء�"NOR"��$w�����������⣬���¶��Ϸ���$n��$l",
	"lvl" : 19,
	"skill_name" : "ѩӵ����"
]),
([	"action" : "$Nһ��"RED"�����ͻ��"NOR"������$w���ƺ�ɨʵ��б��������$n��$l",
	"lvl" : 29,
	"skill_name" : "���ͻ��"
]),
([	"action" : "$Nʹ��"HIB"��ҹ��̽����"NOR"��$w����������������಻�ϻ���$n��$l",
	"lvl" : 39,
	"skill_name" : "ҹ��̽��"
]),
([	"action" : "$Nһ��"HIG"��̩ɽѹ����"NOR"������һ�󽣾�������$w���϶������������ֱ��$n��$l������ȥ",
	"lvl" : 49,
	"skill_name" : "̩ɽѹ��"
]),
([	"action" : "$Nһ��"MAG"������滨��"NOR"�����ڰ�գ�$w�س飬���ֹ���$n��$l",
	"lvl" : 69,
	"skill_name" : "����滨"
]),
([	"action" : "$N��Ӱһ��, �Ƶ�$n����һ��"HIW"����¹��ԭ��"NOR"��������$n��$l����",
	"lvl" : 89,
	"skill_name" : "��¹��ԭ"
]),
});

int valid_enable(string usage)
{
	return (usage == "sword") || (usage == "staff") || (usage == "parry");
}

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		 return notify_fail("�������������\n");
	if ((int)me->query_skill("kurong-changong", 1) < 20)
		 return notify_fail("��Ŀ����������̫ǳ��\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		 || (string)weapon->query("skill_type") != "sword")
		 return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("qi") < 50 || (int)me->query("neili") < 30 )
		 return notify_fail("����Ъ���������ɡ�\n");
	me->receive_damage("qi", 45);
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
	int d_e2 = -15;
	int p_e1 = 10;
	int p_e2 = 40;
	int f_e1 = 300;
	int f_e2 = 400;
	int m_e1 = 200;
	int m_e2 = 300;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("duanjia-sword", 1);
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
		"damage_type" : random(2) ? "����" : "����",
	]);
}
int learn_bonus() { return 5; }
int practice_bonus() { return 5; }
int success() { return 10; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"duanjia-sword/" + action;
}
int help(object me)
{
	write(HIC"\n�μҽ���"NOR"\n");
	write(@HELP

    �μҽ������ϴ���μҽ�����

	ѧϰҪ��
		��������20��
		����100
HELP
	);
	return 1;
}


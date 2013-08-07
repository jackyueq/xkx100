// ruyi-hook.c ���⹳��
// Last Modifyed by Winder on Aug. 21 2002

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "ֻ��$N$w����һ�㣬һ�С����츲�ء�ͬʱ����$n��ͷ�������Ⱥ����ɨ��$n�Ȳ���",
	"lvl" : 0,
	"skill_name" : "���츲��"
]),
([	"action" : "ֻ��$N���ֽ�ָ�鹥$n������$wȴ��Ѹ�ײ����ڶ�֮����$n��������ȥ����һ�С��������ϡ���",
	"lvl" : 3,
	"skill_name" : "��������"
]),
([	"action" : "ֻ��$Nһ�С�ѩ����������$w�����ͬѩ���׷ɣ���$n��ȫ��������$w��â֮�¡�",
	"lvl" : 6,
	"skill_name" : "ѩ������"
]),
([	"action" : "ֻ��$Nʹ����������������һ������һ����һ������һ����һ���ǳɣ�ֱ��$n�������Ѩ��",
	"lvl" : 9,
	"skill_name" : "��������"
]),
([	"action" : "$Nһ�С������пա���$w���϶��»���һ���󻡣�ƽƽ����$n��$l��ȥ",
	"lvl" : 12,
	"skill_name" : "�����п�"
]),
([	"action" : "$Nһ�С�������β�����ҽ����ϣ����ֻ��գ�$w���½���$n��$l",
	"lvl" : 15,
	"skill_name" : "������β"
]),
([	"action" : "$Nһ�С����Ķ��ǡ���$w������ң�һ���ǳɺ�ɨ$n��$l",
	"lvl" : 18,
	"skill_name" : "���Ķ���"
]),
([	"action" : "$N�ҽ���ǰһ������ϥ����һ�С�������������$w��ǰ�Ϸ�����$n��$l",
	"lvl" : 21,
	"skill_name" : "��������"
]),
([	"action" : "$Nʹһ�С�������թ�����ҽ����س���$w�������Һ󳷣�ͻȻ����ǰ������$n��$l",
	"lvl" : 24,
	"skill_name" : "������թ"
]),
([	"action" : "$Nʹ���������ص�����$w��������Բ�������಻�ϻ���$n��$l",
	"lvl" : 27,
	"skill_name" : "�����ص�"
]),
([	"action" : "$Nһת��$w���б����һ�С��ɺ�λ���������$n��$l",
	"lvl" : 30,
	"skill_name" : "�ɺ�λ�"
]),
([	"action" : "$N˫������$w��΢һ��ͷ��һ�С�����˼������ͻȻ���Ժ���$n��ȥ",
	"lvl" : 35,
	"skill_name" : "����˼��"
]),
([	"action" : "$N˫��ִ��$w����ͷ���ڣ�һ�С����ܹ��ݡ�����ת���壬����$n",
	"lvl" : 40,
	"skill_name" : "���ܹ���"
]),
([	"action" : "$Nһ�С���ţ���١���$w��$nһ��֮��ͻȻ����$n��$l",
	"lvl" : 50,
	"skill_name" : "��ţ����"
]),
([	"action" : "$N˫�Ų�������������һ�С���Ҷ���ҡ���$w��ǰƽ��$n���ɲ�",
	"lvl" : 60,
	"skill_name" : "��Ҷ����"
]),
([	"action" : "$Nһ�С�Ⱥħ���衹��$w�趯��סȫ����$nײȥ",
	"lvl" : 70,
	"skill_name" : "Ⱥħ����"
]),
([	"action" : "$Nһ����ʹһ�С��������ơ���$w����һ�е�����$n��$l",
	"lvl" : 80,
	"skill_name" : "��������"
]),
([	"action" : "$N����$w��󳷣�����ǰƽƽ����һ�С�����������$n��$l",
	"lvl" : 90,
	"skill_name" : "�������"
]),
([	"action" : "$N������������һ�С����ͬ�١���ͷ�½��ϣ�$w��$n��ͷ����ȥ",
	"lvl" : 100,
	"skill_name" : "���ͬ��"
]),
});


int valid_enable(string usage) { return (usage == "hook") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("dulong-dafa", 1) < 20)
		return notify_fail("��Ķ����󷨻��̫ǳ��\n");
	if ((int)me->query_skill("hook", 1) < 20)
		return notify_fail("��Ĺ���������������ʵ��\n");
	return 1;
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "hook")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("qi") < 40)
		return notify_fail("�����Ѫ���������⹳����\n");
	me->receive_damage("qi", 30);
	return 1;
}

string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action)-1; i >= 0; i--)
		if(level >= action[i]["lvl"])
			return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
/* d_e=dodge_effect p_e=parry_effect f_e=force_effect m_e=damage_effect */
	int d_e1 = -50;
	int d_e2 = -20;
	int p_e1 = 20;
	int p_e2 = 50;
	int f_e1 = 100;
	int f_e2 = 200;
	int m_e1 = 200;
	int m_e2 = 400;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("ruyi-hook",1);
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
int success() { return 5; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"ruyi-hook/" + action;
}

int help(object me)
{
	write(HIC"\n���⹳��"NOR"\n");
	write(@HELP

    ���⹳����������������

	ѧϰҪ��
		������20��
		��������20��
		������Ϊ100
HELP
	);
	return 1;
}


// luohua-jian.c �仨ʮ����
// Last Modified by winder on Sep. 12 2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N��շ�������һ��������һ��"GRN"��ˮ���ؾ��仨��"NOR"�������������ͬǧ��㺮�ǣ���$n��ͷ����",
	"lvl"    : 0,
	"skill_name"  : "ˮ���ؾ��仨"
]),
([	"action" : "$N�����ǰһ�������ֵ��ƻ��أ���������һ����$w���Ϸ��ã�һʽ"HIY"������������ƻ���"NOR"����$n��$l",
	"lvl"    : 20,
	"skill_name"  : "����������ƻ�"
]),
([	"action" : "$N������߳һ��������$w����һ�㣬�������ϰ������࣬һ��"BLU"����������̤�仨��"NOR"$w�Ӹ���������������$n��$l",
	"lvl"    : 30,
	"skill_name"  : "��������̤�仨"
]),
([	"action" : "$N˫�Ų������ˣ���������̩ɽ������΢����ɽ���������$w�����һʽ"MAG"������������÷����"NOR"��ֻ����������׷׵������$n��$l",
	"lvl"    : 70,
	"skill_name"  : "����������÷��"
]),
([	"action" : "$N����һ��������һ��"RED"�������ҡ��ҹ����"NOR"������$wҡҷ�������������޵ش���$n",
	"lvl"    : 80,
	"skill_name"  : "�����ҡ��ҹ��"
]),
([	"action" : "$N˫Ŀֱ��$n�����ּ��죬������ͬʱ��ס$w�������⶯��һ��"HIC"����Ϊ�������仨��"NOR"��$w�󿪴��أ���$n��$lֱ����ȥ",
	"lvl"    : 90,
	"skill_name"  : "��Ϊ�������仨"
]),
([	"action" : "ֻ��$N���Ҳ壬������˸������һ��"HIM"�����ֺ����Ͳл���"NOR"��$w����ػ���һ����Ȧ������..��..�����죬����$n��$l",
	"lvl"    : 100,
	"skill_name"  : "���ֺ����Ͳл�"
]),
([	"action" : "$N�����Դ죬һ��"HIG"�������޴����ɻ���"NOR"���ֻ�����ֻ�����͡���һ����һ���������$n��$l",
	"lvl"    : 110,
	"skill_name"  : "�����޴����ɻ�"
]),
([	"action" : "$Nһ����߳�����Ⱪ����һ��"HIW"����ҡ����ѣ������"NOR"������ͻ��������$w���糤����ӣ��������ϣ�ӿ��$n��$l",
	"lvl"    : 130,
	"skill_name"  : "��ҡ����ѣ����"
]),
([	"action" : "$Nһ����Х���ұ�һ��һ��"HIR"�������ٳؿ��仨��"NOR"������$w������֮�����ֶ�����$nֻ��һ�������Ľ����������",
	"lvl"    : 150,
	"skill_name"  : "�����ٳؿ��仨"
]),
([	"action" : "$N����һת��һ��"HIW"��������ѩӳ÷����"NOR"���������£�$w��ͻ���ǳ����೤�Ľ�â��������,����$n��$l",
	"lvl"    : 160,
	"skill_name"  : "������ѩӳ÷��"
]), 
([      "action" : "$N˫üһ�����ɱ����ʢ��һ��"HIM"�����������������"NOR"����Žż��أ��ҽ�Ѹ����ǰ̤��һ����ֻ��$N������$w�϶�Ϊһ��ֱ��$n��ȥ",     
	"lvl"    : 170,
	"skill_name"  : "�������������"
]),
([	"action" : "$N��Ԫ��һ�������ڱۣ�һ��"HIR"���˼䴦���к컨��"NOR"��ֻ�����������������｣���ݺᣬ$n����Ҫ͸��������",
	"lvl"    : 180,
	"skill_name"  : "�˼䴦���к컨"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }
int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("honghua-shengong", 1) < 20)
		return notify_fail("��ĺ컨�񹦻��̫ǳ��\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("qi") < 50 || (int)me->query("neili") < 35 )
		return notify_fail("������������������仨ʮ������\n");
	me->receive_damage("qi", 45);
	me->add("neili", -30);	
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
	int d_e1 = -5;
	int d_e2 = 15;
	int p_e1 = -35;
	int p_e2 = -15;
	int f_e1 = 150;
	int f_e2 = 200;
	int m_e1 = 140;
	int m_e2 = 240;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("luohua-jian", 1);
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
int learn_bonus() { return 10; }
int practice_bonus() { return 10; }
int success() { return 10; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"luohua-jian/" + action;
}
int help(object me)
{
	write(HIM"\n�仨ʮ������"NOR"\n");
	write(@HELP

    �仨ʮ�����ֳƺ컨ʮ�������Ǻ컨�᱾�Ž�����

	ѧϰҪ��
		�컨��20��
		������Ϊ100
HELP
	);
	return 1;
}

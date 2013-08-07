// Last Modified by winder on Sep. 12 2001
// zhuhun-jian.c ׷�������

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$Nʹһʽ"HIB"���޳�������"NOR"������$w����΢�񣬻ó�һ���׹����$n��$l",
	"lvl"    : 0,
	"skill_name" : "�޳�����"
]),
([	"action" : "$N����ǰ��ʹ��"BLU"��ɷ�񵱵���"NOR"��������磬$w������ƥ����$n��$l��ȥ",
	"lvl"    : 20,
	"skill_name" : "ɷ�񵱵�"
]),
([	"action" : "$Nһ��б��һʽ"MAG"������عˡ�"NOR"��������ͷ����ת���⣬����$w������$n��$l",
	"lvl"    : 40,
	"skill_name" : "����ع�"
]),
([	"action" : "$N����$wһ����һʽ"HIB"�����Ź�����"NOR"��������Ϣ������$n�ĺ�ͷ",
	"lvl"    : 60,
	"skill_name" : "���Ź���"
]),
([	"action" :"$N�������Ʈ�䣬һʽ"BLU"��Թ����㡹"NOR"���������ˣ�����$w��ָ������$n������·",
	"lvl"    : 80,
	"skill_name" : "Թ�����"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }
int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 300)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("sword", 1) < 50)
		return notify_fail("��ĺ컨�񹦻��̫ǳ��\n");
	if ((int)me->query_skill("honghua-shengong", 1) < 50)
		return notify_fail("��ĺ컨�񹦻��̫ǳ��\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("qi") < 40 || (int)me->query("neili") < 30 )
		return notify_fail("�����������������׷�����������\n");
	me->receive_damage("qi", 35);
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
	int d_e1 = 15;
	int d_e2 = 35;
	int p_e1 = -15;
	int p_e2 = -5;
	int f_e1 = 100;
	int f_e2 = 150;
	int m_e1 = 90;
	int m_e2 = 190;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("zhuihun-jian", 1);
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
int learn_bonus() { return 20; }
int practice_bonus() { return 20; }
int success() { return 15; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"zhuihun-jian/" + action;
}
int help(object me)
{
	write(HIM"\n׷���������"NOR"\n");
	write(@HELP

    ��ʮ��·׷�������������˫���Ǻ컨��������޳������ĵ����书��

	ѧϰҪ��
		�컨��50��
		��������50��
		������Ϊ300
HELP
	);
	return 1;
}

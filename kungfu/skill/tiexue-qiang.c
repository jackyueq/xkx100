// tiexue-qiang.c ��Ѫǹ��
// Last Modified by winder on Aug. 25 2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action":"$N����һ�����������ѣ�����$w��Ұ�ӳ�������һʽ"RED"��Ѫսǧ�"NOR"",
	"lvl"   : 0,
	"skill_name" : "Ѫսǧ��"
]),
([	"action":"$N�������µ���̤������ʹ��"CYN"��ŭ�ӱ�����"NOR"������$w��ɨ$n��$l",
	"lvl"   : 10,
	"skill_name" : "ŭ�ӱ���"
]),
([	"action":"$N˫��΢�ף�ʹ��һʽ"YEL"���ɸ���졹"NOR"������$wңҡָ��$n��ͷ��",
	"lvl"   : 20,
	"skill_name" : "�ɸ����"
]),
([	"action":"$N����Ծ��һʽ"HIR"��ʬ���Ұ��"NOR"������$w����һ��Х������$n",
	"lvl"   : 30,
	"skill_name" : "ʬ���Ұ"
]),
([	"action":"$N����$w�й�ֱ����һʽ"HIY"��ֱ��������"NOR"����׼$n���ؿڴ̳�",
	"lvl"   : 50,
	"skill_name" : "ֱ������"
]),
([	"action":"$N����$wһʽ"HIB"����ɽ�ٶ���"NOR"����׼$n��$l���¶���������",
	"lvl"   : 80,
	"skill_name" : "��ɽ�ٶ�"
]),
([	"action":"$N����$w����һ�Ű�â��һʽ"HIC"���Ƹ����ۡ�"NOR"�����ַɴ�$n�ؿ�",
	"lvl"   : 100,
	"skill_name" : "�Ƹ�����"
]),
([	"action":"$Nһʽ"GRN"����ʯ��١�"NOR"����Ծ��$n�������$w�缲������Լ��ؿ�",
	"lvl"   : 120,
	"skill_name" : "��ʯ���"
]),
});

int valid_enable(string usage) { return usage=="spear" || usage=="parry"; }
int valid_learn(object me)
{
	object weapon;
	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "spear")
		return notify_fail("����Ѫǹ������ִǹ��\n");
	if ((int)me->query_skill("guiyuan-tunafa", 1) < 20)
		return notify_fail("���Ԫ���ɷ���򲻹����޷�ѧ��Ѫǹ����\n");
	if ((int)me->query("max_neili") < 20)
		return notify_fail("�������̫�����޷�����Ѫǹ����\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "spear")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("qi") < 50 || (int)me->query("neili") < 50 )
		return notify_fail("�������������������Ѫǹ����\n");
	me->receive_damage("qi", 30);
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
	int d_e1 = -60;
	int d_e2 = -30;
	int p_e1 = -10;
	int p_e2 = 10;
	int f_e1 = 300;
	int f_e2 = 400;
	int m_e1 = 300;
	int m_e2 = 500;  //������ţ�� -_-b --qingyun
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("tiexue-qiang", 1);
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
int learn_bonus() { return 5; }
int practice_bonus() { return 5; }
int success() { return 0; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"tiexue-qiang/" + action;
}

int help(object me)
{
	write(HIC"\n��Ѫǹ����"NOR"\n");
	write(@HELP

    ��Ѫǹ�������ư����Ϲٽ�����������ǹ����������ǹ��������
�Ϲٰ���һ�Ŀ���ͼ����ԭ��ǹ����ʽ�������ء�

	ѧϰҪ��
		��Ԫ���ɷ�20��
		������Ϊ40
HELP
	);
	return 1;
}


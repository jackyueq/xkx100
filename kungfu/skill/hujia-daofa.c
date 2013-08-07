// hujia-daofa.c ���ҵ���
// Last Modified by sega on Mar. 10 2000
//������С,������

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N����$w���ƣ�һ��"HIM"���Ʋ�������"NOR"������������$nl��ȥ",
	"lvl"    : 0,
	"skill_name" : "�Ʋ�����",
]),
([	"action" : "$Nһ��"HIC"��ɳŸ�Ӳ���"NOR"���������¶��ϻ��˸��뻡��$wһ��һ�գ�ƽ��
����$n�ľ���",
	"lvl"    : 8,
	"skill_name" : "ɳŸ�Ӳ�",
]),
([	"action" : "$Nʹ��һ��"HIB"������������"NOR"����$w��������һ��ѹ��$n ",
	"lvl"    : 16,
	"skill_name" : "��������",
]),
([	"action" : "$Nһ��"HIG"���������ȡ�"NOR"��$w������б����$n��ȥ ",
	"lvl"    : 24,
	"skill_name" : "��������",
]),
([	"action" : "$N����$w��ת��Ծ��һ��"RED"����´��ʡ�"NOR"��һ���׹�����$n���ؿ�",
	"lvl"    : 32,
	"skill_name" : "��´���",
]),
([	"action" : "$N����$w��ʹ��һ��"HIW"���׺���᡹"NOR"���������ã����ҿ�����������$n",
	"lvl"    : 40,
	"skill_name" : "�׺����",
]),
([	"action" : "$Nһ��"GRN"��������ů��"NOR"�����Ծ����أ�$w˳����ǰ��Ю��������$n��$l",
	"lvl"    : 48,
	"skill_name" : "������ů",
]),
([	"action" : "$Nļ��ʹһ��"HIM"���˷��ص���"NOR"����ʱ�����������䵶��������˷�ӿ��
$nȫ��",
	"lvl"    : 56,
	"skill_name" : "�˷��ص�",
]),
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }
int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 50)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("force", 1) < 20)
		return notify_fail("��Ļ����ڹ����̫ǳ��\n");
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "blade")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("������������������˺��ҵ�����\n");
	me->receive_damage("qi", 50-(int)(me->query_str()/5));
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

	lvl = (int)me->query_skill("hujia-daofa",1);
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
int learn_bonus() { return 20; }
int practice_bonus() { return 15; }
int success() { return 15; }
int power_point(object me) { return 1; }

int help(object me)
{
	write(HIC"\n���ҵ�����"NOR"\n");
	write(@HELP

    ���ҵ���Ϊ����ʼ����������������쳾ݼҴ��������ɺ���
��������˷����ҽ��������¡�

	ѧϰҪ��
		�����ڹ�20��
		����50
HELP
	);
	return 1;
}


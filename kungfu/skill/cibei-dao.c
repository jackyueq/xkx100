// cibei-dao.c �ȱ���
// Last Modified by sega Mar. 10 2000

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N����$wбָ��һ��"GRN"��ͣ����·��"NOR"������һ�٣�һ����$n��$l��ȥ",
	"lvl"    : 0,
	"skill_name" : "ͣ����·",
]),
([	"action" : "$Nһ��"MAG"��ͯ�ӹһ���"NOR"����������㣬$wһ��һ�գ�ƽ�л���$n�ľ���",
	"lvl"    : 8,
	"skill_name" : "ͯ�ӹһ�",
]),
([	"action" : "$Nչ���鲽������Ծ�䣬һ��"HIW"���ƴ����¡�"NOR"������һ������ն��$n",
	"lvl"    : 16,
	"skill_name" : "�ƴ�����",
]),
([	"action" : "$Nһ��"YEL"�����ż�ɽ��"NOR"��$w�󿪴��أ����϶��»���һ���󻡣���ֱ��
��$n",
	"lvl"    : 24,
	"skill_name" : "���ż�ɽ",
]),
([	"action" : "$N����$wһ����һ��"BLU"����Ϫ���㡹"NOR"��˫�ֳ����������У�����$n����
��",
	"lvl"    : 33,
	"skill_name" : "��Ϫ����",
]),
([	"action" : "$N����$w��ʹ��һ��"HIC"���Ź����ġ�"NOR"���������ã����ҿ�����������
$n",
	"lvl"    : 42,
	"skill_name" : "�Ź�����",
]),
([	"action" : "$Nһ��"HIC"���������ۡ�"NOR"�����Ծ����أ�$w˳����ǰ��Ю��������$n��
$l",
	"lvl"    : 51,
	"skill_name" : "��������",
]),
([	"action" : "$N����פ�أ�һ��"HIB"��������Ϣ��"NOR"���ӳ�һƬ�����ĵ�Ӱ����$n��ȫ
��ӿȥ",
	"lvl"    : 60,
	"skill_name" : "������Ϣ",
]),
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; } 
//int valid_combine(string combo) { return combo=="fumo-jian"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 50)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("hunyuan-yiqi", 1) < 10)
		return notify_fail("��Ļ�Ԫһ�������̫ǳ��\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "blade")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("��������������ȱ�����\n");
	me->receive_damage("qi", 25);
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
	int d_e1 = 60;
	int d_e2 = 40;
	int p_e1 = 10;
	int p_e2 = -10;
	int f_e1 = 50;
	int f_e2 = 100;
	int m_e1 = 10;
	int m_e2 = 120;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int)me->query_skill("cibei-dao", 1);
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
int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 20; }
int power_point(object me) { return 1; }
int help(object me)
{
	write(HIC"\n�ȱ�����"NOR"\n");
	write(@HELP

    �ȱ���Ϊ������ʮ������֮һ��

	ѧϰҪ��
		��Ԫһ����10��
		����50
HELP
	);
	return 1;
}


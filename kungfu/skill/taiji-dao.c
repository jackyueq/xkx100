// taiji-dao.c ̫������
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N����$wбָ��һ��"HIM"��ͣ����·��"NOR"������һ�٣�һ����$n��$l��ȥ",
	"lvl"    : 0,
	"skill_name" : "ͣ����·",
]),
([	"action" : "$Nһ��"MAG"��ͯ�ӹһ���"NOR"����������㣬$wһ��һ�գ�ƽ�л���$n�ľ���",
	"lvl"    : 10,
	"skill_name" : "ͯ�ӹһ�",
]),
([	"action" : "$Nչ���鲽������Ծ�䣬һ��"CYN"���ƴ����¡�"NOR"������һ������ն��$n",
	"lvl"    : 20,
	"skill_name" : "�ƴ�����",
]),
([	"action" : "$Nһ��"HIB"�����ż�ɽ��"NOR"��$w�󿪴��أ����϶��»���һ���󻡣���ֱ����$n",
	"lvl"    : 30,
	"skill_name" : "���ż�ɽ",
]),
([	"action" : "$N����$wһ����һ��"RED"����Ϫ���㡹"NOR"��˫�ֳ����������У�����$n���ؿ�",
	"lvl"    : 40,
	"skill_name" : "��Ϫ����",
]),
([	"action" : "$N����$w��ʹ��һ��"HIY"���Ź����ġ�"NOR"���������ã����ҿ�����������$n",
	"lvl"    : 50,
	"skill_name" : "�Ź�����",
]),
([	"action" : "$Nһ��"HIG"���������ۡ�"NOR"�����Ծ����أ�$w˳����ǰ��Ю��������$n��$l",
	"lvl"    : 60,
	"skill_name" : "��������",
]),
([	"action" : "$N����פ�أ�һ��"HIM"��������Ϣ��"NOR"���ӳ�һƬ�����ĵ�Ӱ����$n��ȫ��ӿȥ",
	"lvl"    : 70,
	"skill_name" : "������Ϣ",
]),
});

int valid_enable(string usage) { return (usage=="blade") || (usage=="parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("taiji-shengong", 1) < 20)
		return notify_fail("���̫���񹦻��̫ǳ��\n");
	if ((int)me->query_skill("taiji-quan", 1) < 20)
		return notify_fail("���̫��ȭ���̫ǳ��\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("�������������̫��������\n");
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
	int d_e1 = 45;
	int d_e2 = 20;
	int p_e1 = -10;
	int p_e2 = -25;
	int f_e1 = 100;
	int f_e2 = 150;
	int m_e1 = 110;
	int m_e2 = 220;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int)me->query_skill("taiji-dao", 1);
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
int practice_bonus() { return 5; }
int success() { return 10; }
int power_point(object me) { return 1; }

int help(object me)
{
	write(HIC"\n̫��������"NOR"\n");
	write(@HELP

    ��̫��ȭ��ѧԭ����ͬ��Ϊ�䵱�ɵ�����

	ѧϰҪ��
		̫��ȭ20��
		̫����20��
		����100
HELP
	);
	return 1;
}


// yanxing-dao.c ���е���
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"skill_name" : "���־�",
	"action" : "$Nʹ��"MAG"�����־���"NOR"�������������е�бб������һ���׹�����$n��$l",
	"lvl"    : 0
]),
([	"skill_name" : "���־�",
	"action" : "$Nʹ��"BLU"�����־���"NOR"�����ֻ��������һ�������ֵ���ͷֱ��������һ����âֱ��$n��$l����",
	"lvl"    : 10
]),
([	"skill_name" : "���־�",
	"action" : "$Nʹ��"HIY"�����־���"NOR"�����ֺ󳷣���б���мܣ�˳���¶磬������Ҹ�´�������ס�Է����󣬵��ⲻָͣ��$n��$l",
	"lvl"    : 20
]),
([	"skill_name" : "���־�",
	"action" : "$Nʹ��"HIC"�����־���"NOR"��������ϣ�����ͻ�������ִ����Է�$n���У����ֵ��͵ص�������$n���ڵ�����",
	"lvl"    : 30
]),
([	"skill_name" : "���־�",
	"action" : "$Nʹ��"HIG"�����־���"NOR"���������էȻһ�������ּ��ٲ�ס$n���֣����е�һ�������磬������ס$n��$l",
	"lvl"    : 40
]),
([	"skill_name" : "���־�",
	"action" : "$Nʹ��"HIM"�����־���"NOR"�������䣬����Ʈ����׽����͸����$n�ۻ�����֮�ʣ����ֵ��ⷴ����$n��$l",
	"lvl"    : 50
]),
([	"skill_name" : "̽�־�",
	"action" : "$Nʹ��"HIR"��̽�־���"NOR"����ӯ��һ����ת�����ų��������ֵ�������ǰ��ֱ��$n��$l",
	"lvl"    : 60
]),
([	"skill_name" : "���־�",
	"action" : "$N����ʹ��"HIB"�����־���"NOR"��������ת�������Ķ�������$n��ת�����е���������$n��ȫ���������Լ����µĵ����У��޴�����",
	"lvl"    : 70
]),
([	"skill_name" : "���־�",
	"action" : "$N����ʹ��"GRN"�����־���"NOR"������ص�������$nǰ����һ�������ⶸ�֣�����ǧ���������ڶ���",
	"lvl"    : 80
]),
([	"skill_name" : "���־�",
	"action" : "$N����ʹ��"RED"�����־���"NOR"��˫�ֽ��棬������߫��$nʵ�ڿ����嵶�������˺����ܣ�ֻ��һ����ֱ�ƹ���",
	"lvl"    : 90
]),
});

int valid_enable(string usage) { return usage=="blade" || usage=="parry"; }
int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 50)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("linji-zhuang", 1) < 20)
		return notify_fail("����ټ�ʮ��ׯ���̫ǳ��\n");
	if ((int)me->query_skill("blade", 1) +100 < (int)me->query_skill("yanxing-dao", 1) )
		return notify_fail("��Ļ����������̫ǳ��\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("����������������е���\n");
	me->receive_damage("qi", 10);
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
	int d_e1 = 35;
	int d_e2 = 15;
	int p_e1 = -15;
	int p_e2 = -35;
	int f_e1 = 150;
	int f_e2 = 200;
	int m_e1 = 170;
	int m_e2 = 280;
/*	int d_e1 = -50;
	int d_e2 = -35;
	int p_e1 = -25;
	int p_e2 = -0;
	int f_e1 = 200;
	int f_e2 = 250;
	int m_e1 = 200;
	int m_e2 = 300;*/
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int)me->query_skill("yanxing-dao", 1);
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
int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 5; }
int power_point(object me) { return 1; }

string perform_action_file(string action)
{
	return __DIR__"yanxing-dao/" + action;
}
int help(object me)
{
	write(HIC"\n���е�����"NOR"\n");
	write(@HELP

    ���е���Ϊ�����ɵ�����

	ѧϰҪ��
		���������ȼ����ܵ������е����ȼ�
		�ټ�ʮ��ׯ20��
		����50
HELP
	);
	return 1;
}


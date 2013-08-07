// canhe-finger.c �κ�ָ
// Modified by sir 10.23.2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$Nһʽ"MAG"��Ŀ��ʶ����"NOR"��������ָ���籡������������ָ���������������$n��$l",
	"lvl" : 0,
	"skill_name" : "Ŀ��ʶ��"
]),
([	"action" : "$N����һת��һʽ"HIR"�������㾦��"NOR"���������¶���ʳָ�촦��һ��������ض�����ֱ��$n���۾���ȥ",
	"lvl" : 20,
	"skill_name" : "�����㾦"
]),
([	"action" : "$N����ʳָһ̧����$n��ȥ������ʳָ�����ŵ���$n��$l��һʽ"GRN"����˷���롹"NOR"��˫��������ʵ��$n�پ���֪����ζԸ�",
	"lvl" : 40,
	"skill_name" : "��˷����"
]),
([	"action" : "$N��Ȼ���־���֮ɫ���������ߣ�ֻһ˲�䣬���β��˷�����һʽ
"BLU"���ܳ�������"NOR"������ʳָ���¶��ϣ����Ƶ���$n��$l",
	"lvl" : 60,
	"skill_name" : "�ܳ�����"
]),
([	"action" : "$N����Ľ��������Ȼ�ķ���������һ��һ�ţ�һʽ"YEL"�����ϲ�����"NOR"��˫��ʳָ��ָ����$n��$l��ȥ",
	"lvl" : 70,
	"skill_name" : "���ϲ���"
]),
([	"action" : "$N����˫���鲽���ƣ��۽�Ƴ��$n������ͻȻ�����ֱ���Ϊָ���͵�һ���죬һʽ"CYN"���˱����᡹"NOR"���ص�$n��$l",
	"lvl" : 90,
	"skill_name" : "�˱�����"
]),
([	"action" : "$Nһ������$n������ϥһ������������һָ��һʽ"RED"����н������"NOR"��ָ��$n�ĺ���",
	"lvl" : 100,
	"skill_name" : "��н����"
]),
([	"action" : "$N�������̤��һ�����ֿ���������أ��Ҳ���ǰһ�󲽣���ʱ�۽�$n��"GRN"�����μ���"NOR"��ʳָ����$n��$l",
	"lvl" : 130,
	"skill_name" : "���μ�"
]),
});
int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }
int valid_combine(string combo) { return combo=="xingyi-strike"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("���κ�ָ������֡�\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷����κ�ָ��\n");
	if ((int)me->query_skill("shenyuan-gong", 1) < 15)
		return notify_fail("�����Ԫ��򲻹����޷�ѧ�κ�ָ��\n");
	return 1;
}

int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��ı�����ֲ�����ϰ��\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 25)
		return notify_fail("���������������\n");
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
	int d_e1 = 30;
	int d_e2 = 50;
	int p_e1 = -30;
	int p_e2 = -10;
	int f_e1 = 280;
	int f_e2 = 380;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("canhe-finger", 1);
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
		"damage_type" : random(2) ? "����" : "����",
	]);
}
int learn_bonus() { return 15; }
int practice_bonus() { return 15; }
int success() { return 15; }
int power_point() { return 1.0; }
string perform_action_file(string action)
{
	return __DIR__"canhe-finger/" + action;
}

int help(object me)
{
	write(HIC"\n�κ�ָ��"NOR"\n");
	write(@HELP

    �κ�ָΪ����Ľ�ݼ�ָ��������Ľ���ϼ�ѧԨԴ���κ�ָ����
�಻ѷ�������ɴ������ָ��
    ���������ƻ�����

	ѧϰҪ��
		��Ԫ��15��
		����100
HELP
	);
	return 1;
}


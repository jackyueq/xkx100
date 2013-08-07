// wuluo-zhang.c ����������
// Last Modified by sir 10.22.2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N��Ϣ����������һ��"HIB"������������"NOR"���������������$n",
	"lvl"    : 0,
	"skill_name" : "��������"
]),
([	"action" : "$N����ǳЦ���Ƶ�$n�����������������ӵ$n���䡣$n��ü���㣬$N����һ��"BLU"���������ơ�"NOR"��������Ϣ��$n��$l�ĵ�",
	"lvl"    : 20,
	"skill_name" : "��������"
]),
([	"action" : "$Nһ��"MAG"���̺����Ρ�"NOR"��˫�ƻû���һƬ��Ӱ����һ�����̣���$nϸϸ���ܵ���������",
	"lvl"    : 40,
	"skill_name" : "�̺�����"
]),
([	"action" : "$N����Խ��Ȧ�⣬����һ��"HIC"���������졹"NOR"��ԶԶ����$n��$l�����ĳ����ƣ��Ʒ�ε�����Ȼ��ʢֱ��$n����������",
	"lvl"    : 60,
	"skill_name" : "��������"
]),
([	"action" : "$N���ƴ�������Χ��������ƮƮ����$n��ȥ������$n�����мܣ�����ȴ���ؿڼ���Ȧ����һ��"HIW"������������"NOR"���ϳ����ƣ�����$n��$l",
	"lvl"    : 80,
	"skill_name" : "��������"
]),
([	"action" : "$N˫�����ƣ�����һ�󾢷磬һ��"HIW"��������ɢ��"NOR"��һ�ɿ������$n",
	"lvl"    : 100,
	"skill_name" : "������ɢ"
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }
int valid_combine(string combo) { return combo=="jinyu-quan"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�����������Ʊ�����֡�\n");
	if ((int)me->query_skill("kurong-changong",1) < 20)
		return notify_fail("��Ŀ�������̫�����޷������������ơ�\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷������������ơ�\n");
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��ı�����ֲ�����ϰ��\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("����������������������ơ�\n");
	me->receive_damage("qi", 25);
	me->add("neili", -10);
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
	int d_e1 = -20;
	int d_e2 = 0;
	int p_e1 = 20;
	int p_e2 = 50;
	int f_e1 = 130;
	int f_e2 = 230;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("wuluo-zhang", 1);
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
int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 20; }
int power_point(object me) { return 1.0; }

int help(object me)
{
	write(HIC"\n���������ƣ�"NOR"\n");
	write(@HELP

    ���������������ϴ���μҵ��书��
    �������ȭ������

	ѧϰҪ��
		��������20��
		����100
HELP
	);
	return 1;
}



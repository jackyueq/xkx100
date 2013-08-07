//yingzhua-gong.c ӥצ��
// Last Modified by sega on Mar. 10 2000

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$Nȫ��εض��𣬰����һ�����һʽ"HIY"����ӥϮ�á�"NOR"��Ѹ�͵�ץ��$n��$l",
	"lvl"    : 0,
	"skills_name" : "��ӥϮ��",
]),
([	"action" : "$N����ֱ����˫��ƽ�죬һʽ"HIW"����ӥչ�᡹"NOR"��˫צһǰһ��£��$n��$l",
	"lvl"    : 10,
	"skills_name" : "��ӥչ��",
]),
([	"action" : "$Nһʽ"HIB"���γ��ɡ�"NOR"��ȫ����б��ƽ�ɣ�����һ����˫צ����$n�ļ�ͷ",
	"lvl"    : 20,
	"skills_name" : "�γ���",
]),
([	"action" : "$N˫צ�����Ͼ٣�ʹһʽ"HIM"��ӭ������"NOR"��һ�����ֱ�Ϯ��$n����Ҹ����",
	"lvl"    : 30,
	"skills_name" : "ӭ������",
]),
([	"action" : "$Nȫ�������ǰ��һʽ"HIR"��������צ��"NOR"����צͻ�������Ȱ�ץ��$n���ؿ�",
	"lvl"    : 40,
	"skills_name" : "������צ",
]),
([	"action" : "$N���ػ��У�һʽ"CYN"������հ�ա�"NOR"������Ϯ�����д�Ѩ�����ַ�ץ$n���ɲ�",
	"lvl"    : 50,
	"skills_name" : "����հ��",
]),
([	"action" : "$N��������צ���棬һʽ"YEL"���������ա�"NOR"�������������ƿն�����Ѹ���ޱȵػ���$n",
	"lvl"    : 55,
	"skills_name" : "��ӥϮ��",
]),
([	"action" : "$N�ڿո߷����ɣ�һʽ"HIW"��ӥ�����"NOR"������ж�ʱ�Գ�һ������צӰ����������$n",
	"lvl"    : 60,
	"skills_name" : "��ӥϮ��",
])
});

int valid_enable(string usage) { return usage=="claw" || usage=="parry"; }
int valid_combine(string combo) { return combo=="fengyun-shou"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��ӥצ��������֡�\n");
	if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
		return notify_fail("��Ļ�Ԫһ������򲻹����޷�ѧӥצ����\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷���ӥצ����\n");
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��ı�����ֲ�����ϰ��\n");
	if ((int)me->query("qi") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("�������������ӥצ����\n");
	me->receive_damage("qi", 30);
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
	int d_e1 = 50;
	int d_e2 = 30;
	int p_e1 = -5;
	int p_e2 = -30;
	int f_e1 = 200;
	int f_e2 = 350;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int)me->query_skill("yingzhua-gong", 1);
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
		"damage_type" : random(2) ? "ץ��" : "����",
	]);
}
int learn_bonus() { return 20; }
int practice_bonus() { return 20; }
int success() { return 15; }
int power_point(object me) { return 1; }

int help(object me)
{
	write(HIC"\nӥצ����"NOR"\n");
	write(@HELP

    ӥצ��Ϊ������ʮ������֮һ��
    ��������ֻ�����

	ѧϰҪ��
		��Ԫһ����20��
		����100
HELP
	);
	return 1;
}


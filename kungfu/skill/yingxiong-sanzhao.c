// yingxiong-sanzhao.c Ӣ������
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$nץס$N�ĺ󾱣�һ������$N����������ת����$n��Ҹ��ɦ��һ�ѣ�\n$n��������������$N������ס$nҸ�£�����������ת��ץס$n��ڣ�����\n����$n�����ӣ������Լ�ͷ��������ˤ��",
	"lvl" : 0,
	"skill_name" : "����ٶ�",
]),
([	"action" : "$N�������ϣ�$n������̤ס$N�ĺ�����$N˫��һ����������ݣ�\n�ұ�ȴ�������Ӷ�����ͻȻ��һ�������$n�Ŀ�����ȥ��ֻһ����\n������ץס$n�ҽ����ף�������$nС����ȥ",
	"lvl" : 10,
	"skill_name" : "³�����",
]),
([	"action" : "$N˫�۷��ڱ���ͻȻ˫��ʮָ���𣬸��ɰ���֮�Σ��������һײ\nʮָ��ץ��$n���ز���$n���һ����$NͻȻһ�������������Ծ��\n˫��һ�֣��ѿ���$n��ͷ��ͬʱ˫�ְ�ָѹס$n̫��Ѩ��ʳָ��ü����ָ����",
	"lvl" : 20,
	"skill_name" : "���ཱུ��",
])
});

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }
int valid_combine(string combo) { return combo=="shenlong-bashi"; }
int valid_learn(object me)
{
	if (me->query_int() < 35)
		return notify_fail("������Բ������޷�ѧӢ�����С�\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷�ѧӢ�����С�\n");
	if ((int)me->query_skill("dulong-dafa", 1) < 60)
		return notify_fail("��Ķ����󷨻�򲻹����޷�ѧӢ�����С�\n");
	return 1;
}
string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action)-1; i >= 0; i--)
		if(level >= action[i]["lvl"])
			return action[i]["skill_name"];
}
int practice_skill(object me)
{
	if ((int)me->query("qi") < 55)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("�������������Ӣ�����С�\n");
	me->receive_damage("qi", 30);
	me->add("neili", -10);
	return 1;
}
mapping query_action(object me, object weapon)
{
/* d_e=dodge_effect p_e=parry_effect f_e=force_effect m_e=damage_effect */
	int d_e1 = 25;
	int d_e2 = 45;
	int p_e1 = -35;
	int p_e2 = -15;
	int f_e1 = 490;
	int f_e2 = 590;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("yingxiong-sanzhao",1);
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
int learn_bonus() { return 5; }
int practice_bonus() { return 5; }
int success() { return 10; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"yingxiong-sanzhao/" + action;
}

int help(object me)
{
	write(HIC"\nӢ������"NOR"\n");
	write(@HELP

    Ӣ��������������ָ����ȡ������Ӣ����������������ʽ������

	ѧϰҪ��
		������60��
		������Ϊ100
		��������35
HELP
	);
	return 1;
}


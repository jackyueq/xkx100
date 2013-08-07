// Last Modified by winder on May. 29 2001
// shaolin-leg.c ���ֵ��� ��������ȭ����

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$Nһʽ"BLU"������ʽ��"NOR"������֧�أ����Ȼ�����ֱ��$n��ͷ��",
	"lvl"    : 0,
	"skill_name" : "����ʽ"
]),
([	"action" : "$N����һ�����Ѵ�$n����ӹ������㷴�ߣ�����һ��"HIW"����ƽʽ��"NOR"������$n�ı���",
	"lvl"    : 20,
	"skill_name" : "��ƽʽ"
]),
([	"action" : "$N�����ף����㻭������Բ��ʹ��"HIC"��׷��ʽ��"NOR"��ɨ��$n��ϥ��",
	"lvl"    : 40,
	"skill_name" : "׷��ʽ"
]),
([	"action" : "$N����΢�࣬����ٿ�ص���������$n��ͷ�����ɲ�������һʽ"GRN"������ʽ��"NOR"",
	"lvl"    : 60,
	"skill_name" : "����ʽ"
]),
([	"action" : "$N������������������η�ת��ɨ�������������������ɨ��ǰ��һ��"HIG"��ɨҶʽ��"NOR"������$n��$l",
	"lvl"    : 80,
	"skill_name" : "ɨҶʽ"
]),
([	"action" : "$NԾ���ڰ�գ�˫�����裬�����������磬"HIY"������ʽ��"NOR"��Ѹ�����׵ؾ���$n",
	"lvl"    : 100,
	"skill_name" : "����ʽ"
]),
});

int valid_enable(string usage) { return usage=="leg" || usage=="parry"; }
int valid_combine(string combo) { return combo=="shaolin-cuff"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("ѧ���ֵ���ʱ���ﲻ����������\n");
	if ((int)me->query_skill("zhanzhuang-gong", 1) < 1)
		return notify_fail("���վ׮����򲻹����޷�ѧ���ֵ��ȡ�\n");
	return 1;
}
int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("����������������ֵ��ȡ�\n");
	me->receive_damage("qi", 20);
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
	int d_e1 = -30;
	int d_e2 = 0;
	int p_e1 = 0;
	int p_e2 = 30;
	int f_e1 = 100;
	int f_e2 = 200;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("shaolin-leg", 1);
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
	write(HIC"\n���ֵ��ȣ�"NOR"\n");
	write(@HELP

    �����������������ȷ���ע���ȷ���ϰ��

	ѧϰҪ��
		վ׮��
HELP
	);
	return 1;
}


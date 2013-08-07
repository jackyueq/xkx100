// Last Modified by Winder on May. 29 2001
// sanhua-strike.c ɢ���� ��Ħڭָ�������ļ�ʫ�����ǰ�ˡ�

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N���Ʊ��������һʽ��"HIG"����ݾ�"NOR"��������������£��������縧�壬����Ʈ��$n",
	"lvl"   : 0,
	"skill_name" : "����ݾ�"
]),
([	"action" : "$N��ָ������һʽ��"GRN"���ж���ܰ"NOR"��������˫�ƴ��巭�ɣ������Ľ���������$n���ɶ�ȥ",
	"lvl"   : 30,
	"skill_name" : "���ж���ܰ"
]),
([	"action" : "$Nһʽ��"HIY"�ﺨ��˪��"NOR"�����������У�����է��է�ϣ����ڷ���ҡ�ڣ����ḧ��$n$l",
	"lvl"   : 60,
	"skill_name" : "�ﺨ��˪��"
]),
([	"action" : "$N˫��ѩ�ף�һʽ��"HIW"������÷��"NOR"�����������Ƽ�ó�����÷����䣬������$nƮȥ",
	"lvl"   : 100,
	"skill_name" : "������÷��"
])
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }
int valid_combine(string combo){ return combo=="mohe-finger"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��ɢ���Ʊ�����֡�\n");
	if ((int)me->query_skill("zhanzhuang-gong", 1) < 30)
		return notify_fail("���վ׮����򲻹����޷�ѧɢ���ơ�\n");
	if ((int)me->query("max_neili") < 200)
		return notify_fail("�������̫�����޷���ɢ���ơ�\n");
	if (me->query_skill("weituo-strike", 1) < 30)
		return notify_fail("���Τ���ƻ�򲻹����޷�ѧɢ���ơ�\n");
	return 1;
}
int practice_skill(object me)
{
	if ((int)me->query("qi") < 40)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("�������������ɢ���ơ�\n");
	me->receive_damage("qi", 30);
	me->add("neili", -15);
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
	int d_e1 = -25;
	int d_e2 = 0;
	int p_e1 = 20;
	int p_e2 = 45;
	int f_e1 = 140;
	int f_e2 = 240;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("sanhua-strike", 1);
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
int learn_bonus() { return 25; }
int practice_bonus() { return 25; }
int success() { return 15; }
int power_point() { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"sanhua-strike/" + action;
}

int help(object me)
{
	write(HIC"\nɢ���ƣ�"NOR"\n");
	write(@HELP

    ɢ�������������Ʒ�����Ħڭָ������

	ѧϰҪ��
		վ׮��30��
		Τ����30��
		������Ϊ200
HELP
	);
	return 1;
}


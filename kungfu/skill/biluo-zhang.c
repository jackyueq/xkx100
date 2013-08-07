// biluo-zhang.c ������
// Last Modified by sir 10.23.2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$Nһʽ������ʽ�������ִ��磬��������$n��$l",
	"lvl" : 0,
	"skill_name" : "����ʽ"
]),
([  "action" : "$N����΢̨��ֱ����ǰ��һʽ������ʽ��������$n��$l��ȥ",
	"lvl" : 10,
	"skill_name" : "����ʽ"
]),
([	"action" : "$Nʹһʽ�����ʽ��������΢��������˳�ƶ������͵ز���$n��$l",
        "lvl" : 30,
	"skill_name" : "���ʽ"
]),
([	"action" : "$N˫����������������һʽ������ʽ�����Ʒ缤����������$n��ȥ",
        "lvl" : 40,
	"skill_name" : "����ʽ"
]),
([	"action" : "$N˫�Ʋ��Ϸ�ת��ʹ��һʽ��Ǳ��ʽ����˫�Ʋ�£����ֱ����$n��$lϮȥ",
        "lvl" : 50,
	"skill_name" : "Ǳ��ʽ"
]),

([	"action" : "$N����һ�䣬ʹһʽ������ʽ����˫�ƴ�����ɲ�ľ������͵ػ���$n��$l",
        "lvl" : 60,
	"skill_name" : "����ʽ"
]),
([	"action" : "$Nʹһʽ������ʽ����˫�������ƻã�ͬʱ��$n��$l��ȥ",
        "lvl" : 70,
	"skill_name" : "����ʽ"
]),

([	"action" : "$Nһʽ������ʽ���������䣬������Ʈ���������ѻ���$n��$l��",
        "lvl" : 80,
	"skill_name" : "����ʽ"
]),
([	"action" : "$Nͻ��һ�С�����ʽ����˫��Ю��һ�����֮�ƣ��͵�����$n��$l",
        "lvl" : 100,
	"skill_name" : "����ʽ"
])
});

int valid_enable(string usage) { return usage=="parry" || usage=="strike"; }
int valid_combine(string combo) { return combo=="luoyan-hand"; }

int valid_learn(object me)
{
	if(((int)me->query_skill("huiyan-xinfa", 1) < 15 ) )
		return notify_fail("��ı����ڹ���������졣\n");
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�������Ʊ�����֡�\n");
	if ((int)me->query("max_neili") < 50)
		return notify_fail("�������̫�����޷��������ơ�\n");
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��ı�����ֲ�����ϰ��\n");
	if ((int)me->query("qi") < 60)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 60)
		return notify_fail("������������������ơ�\n");
	me->receive_damage("qi", 40);
	me->add("neili", -30);
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
	int d_e1 = 15;
	int d_e2 = 50;
	int p_e1 = 20;
	int p_e2 = 50;
	int f_e1 = 30;
	int f_e2 = 160;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("biluo-zhang", 1);
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
int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 5; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"biluo-zhang/" + action;
}
int help(object me)
{
	write(HIC"\n�����ƣ�"NOR"\n");
	write(@HELP

    �������Ǻ�ɽ�ɵ��Ʒ���
    ����������ֻ�����

	ѧϰҪ��
		�����ķ�15��
		����50
HELP
	);
	return 1;
}


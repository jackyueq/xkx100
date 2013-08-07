// hunyuan-zhang.c ��Ԫ��
// Last Modified by sir 10.22.2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$Nһʽ"HIW"�����Ƴ�ᶡ�"NOR"��˫�Ƽ�����һ�ŵ����İ�����������$n��$l",
	"lvl" : 0,
	"skill_name" : "���Ƴ��"
]),
([	"action" : "$N��ָ�罣��һʽ"HIW"���׺���ա�"NOR"������$n��$l��ȥ",
	"lvl" : 10,
	"skill_name" : "�׺����"
]),
([	"action" : "$Nʹһʽ"HIB"���ƶ����롹"NOR"������΢��������է��է�ϣ��͵ز���$n��$l",
	"lvl" : 20,
	"skill_name" : "�ƶ�����"
]),
([	"action" : "$N˫����������������һʽ"GRN"�����ɴ�䡹"NOR"���ó�������̵����룬������$n��ȥ",
	"lvl" : 30,
	"skill_name" : "���ɴ��"
]),
([	"action" : "$N��������һ�ݣ�ʹ��һʽ"HIC"����������"NOR"��˫�Ʋ�£����ֱ����$n��$l��ȥ",
	"lvl" : 40,
	"skill_name" : "������"
]),
([	"action" : "$N����һ�䣬ʹһʽ"MAG"���ޱ���ľ��"NOR"��˫�ƴ�����ɲ�ľ������͵ػ���$n��$l",
	"lvl" : 50,
	"skill_name" : "�ޱ���ľ"
]),
([	"action" : "$Nʹһʽ"HIG"����ɽ��ˮ��"NOR"���������أ�������ӯ��ͬʱ��$n��$l��ȥ",
	"lvl" : 60,
	"skill_name" : "��ɽ��ˮ"
]),
([	"action" : "$Nͻ��һ��"RED"���������á�"NOR"��˫��Ю��һ�����֮�ƣ��͵�����$n��$l",
	"lvl" : 70,
	"skill_name" : "��������"
]),
([	"action" : "$Nһʽ"HIM"��������ơ�"NOR"��˫�������һ����裬�����ѻ���$n��$l��",
	"lvl" : 80,
	"skill_name" : "�������"
]),
([	"action" : "$Nһʽ"BLU"������Ʈ�졹"NOR"����������������˫��һ��һ�ͣ����Ƽ򵥣�ȴ��$n�޷�����",
	"lvl" : 90,
	"skill_name" : "����Ʈ��"
])
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }
int valid_combine(string combo) { return combo=="poyu-quan"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("����Ԫ�Ʊ�����֡�\n");
	if ((int)me->query_skill("zixia-shengong", 1) < 20)
		return notify_fail("�����ϼ�񹦻�򲻹����޷�ѧ��Ԫ�ơ�\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷�����Ԫ�ơ�\n");
	return 1;
}
int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��ı�����ֲ�����ϰ��\n");
	if ((int)me->query("neili") < 40)
		return notify_fail("���������������Ԫ�ơ�\n");
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
	int d_e2 = -5;
	int p_e1 = 15;
	int p_e2 = 45;
	int f_e1 = 150;
	int f_e2 = 250;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("hunyuan-zhang", 1);
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
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"hunyuan-zhang/" + action;
}
int help(object me)
{
	write(HIC"\n��Ԫ�ƣ�"NOR"\n");
	write(@HELP

    ��Ԫ��Ϊ��ɽ�书����Ԫ��Ե�Խ��������������ƶ��뽣����
����
    ������ʯ����ȭ������

	ѧϰҪ��
		��ϼ��20��
		����100
HELP
	);
	return 1;
}


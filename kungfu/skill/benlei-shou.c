// Last Modified by winder on Sep. 12 2001
// benlei-shou.c ������

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$Nһʽ"CYN"��������ˮ��"NOR"��˫��һ����һ�ɾ�����������$n��$l",
	"lvl"   : 0,
	"skill_name" : "������ˮ"
]),
([	"action" : "$Nһʽ"BLU"�����ƴ��¡�"NOR"������һ��������$n��$l��ȥ",
	"lvl"   : 10,
	"skill_name" : "���ƴ���"
]),
([	"action" : "$Nʹһʽ"MAG"�����Ƹ��꡹"NOR"������΢��������է��է�ϣ��͵ز���$n��$l",
	"lvl"   : 20,
	"skill_name" : "���Ƹ���"
]),
([	"action" : "$N�����������죬һʽ"YEL"����ɽ������"NOR"�������纣ˮ����$n��ȥ",
	"lvl"   : 30,
	"skill_name" : "��ɽ����"
]),
([	"action" : "$N��������һ�ݣ�ʹ��һʽ"HIB"�����Ʊ��ա�"NOR"��˫��һ̯����ֱ����$n��$l��ȥ",
	"lvl"   : 40,
	"skill_name" : "���Ʊ���"
]),
([	"action" : "$N����һ�䣬ʹһʽ"HIB"������������"NOR"��˫�ƴ�����ɲ�ľ������͵ػ���$n��$l",
	"lvl"   : 50,
	"skill_name" : "��������"
]),
([	"action" : "$Nʹһʽ"HIW"��˺�����ơ�"NOR"���������أ�������ӯ��ͬʱ��$n��$l��ȥ",
	"lvl"   : 60,
	"skill_name" : "˺������"
]),
([	"action" : "$Nͻ��һ��"HIM"���ƺ����Ρ�"NOR"��˫��Ю��һ�����֮�ƣ��͵�����$n��$l",
	"lvl"   : 70,
	"skill_name" : "�ƺ�����"
]),
([	"action" : "$Nһʽ"HIY"�������޶���"NOR"��˫�������һ����裬�����ѻ���$n��$l��",
	"lvl"   : 80,
	"skill_name" : "�����޶�"
]),
([	"action" : "$Nһʽ"HIR"�������콵��"NOR"���������ϴ������࣬˫��һ��һ�ͣ����Ƽ򵥣�ȴ��$n�޷�����",
	"lvl"   : 90,
	"skill_name" : "�����콵"
]),
([	"action" : "$Nһʽ"HIW"�������ɾ���"NOR"�������������������Ƽ��������ϼ�⣬��$n������ס",
	"lvl"   : 100,
	"skill_name" : "�����ɾ�"
])
});
int valid_enable(string usage) { return usage=="hand" || usage=="parry" ; }
int valid_combine(string combo) { return combo=="baihua-cuoquan"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�������ֱ�����֡�\n");
	if ((int)me->query_skill("honghua-shengong", 1) < 20)
		return notify_fail("��ĺ컨�񹦻�򲻹����޷�ѧ�����֡�\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷��������֡�\n");
	return 1;
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 40)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 40)
		return notify_fail("������������������֡�\n");
	me->receive_damage("qi", 35);
	me->add("neili", -25);
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
	int d_e1 = -50;
	int d_e2 = -20;
	int p_e1 = 10;
	int p_e2 = 40;
	int f_e1 = 180;
	int f_e2 = 280;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("benlei-shou", 1);
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
	return __DIR__"benlei-shou/" + action;
}

int help(object me)
{
	write(HIM"\n�����֣�"NOR"\n");
	write(@HELP

    �컨���ĵ�����̩���Ŀ����书��

	ѧϰҪ��
		�컨��20��
		������Ϊ100
HELP
	);
	return 1;
}

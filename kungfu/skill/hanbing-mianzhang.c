// hannbing-mianzhang.c ��������
// Last Modified by sir 10.22.2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$Nһʽ"HIB"���󽭶�ȥ��"NOR"��˫�ƴ󿪴�ϣ�ֱ��$n��$l��ȥ",
	"lvl" : 0,
	"skill_name" : "�󽭶�ȥ"
]),
([	"action" : "$N����һ�䣬һʽ"YEL"���ƺӾ�����"NOR"��˫��������ֱ������$n��$l",
	"lvl" : 10,
	"skill_name" : "�ƺӾ���"
]),
([	"action" : "$Nʹһʽ"GRN"������ɽɫ��"NOR"��������΢����棬������ϸ�����ֱȡ$n��$l",
	"lvl" : 20,
	"skill_name" : "����ɽɫ"
]),
([	"action" : "$N����һ�֣�һʽ"MAG"�������׺���"NOR"������������������$n�����ȥ",
	"lvl" : 30,
	"skill_name" : "�����׺�"
]),
([	"action" : "$N����һת��ʹ��һʽ"HIM"��ˮ�����١�"NOR"��ֻ��������Ӱ��ס��$n��ȫ��",
	"lvl" : 40,
	"skill_name" : "ˮ������"
]),
([	"action" : "$NͻȻ����һ����ʹ��һʽ"HIG"��С����硹"NOR"���������أ�������ӯ������$n��$l",
	"lvl" : 50,
	"skill_name" : "С�����"
]),
([	"action" : "$Nʹһʽ"HIW"����ѩ��ɽ��"NOR"��˫��Ю��籩ѩ֮�ƣ��͵�����$n��$l",
	"lvl" : 60,
	"skill_name" : "��ѩ��ɽ"
]),
([	"action" : "$Nһ��"HIW"��˪�����ء�"NOR"��˫�ƴ�����ɪ������������$n��$l",
	"lvl" : 70,
	"skill_name" : "˪������"
]),
([	"action" : "$N����Ȼһ�䣬ʹ��һʽ"HIW"�����������"NOR"����Ӱǧ����ã���$n�޷�����",
	"lvl" : 80,
	"skill_name" : "�������"
]),
([	"action" : "$N��Хһ����һʽ"HIW"����˪ѩ�꡹"NOR"��˫�ƻ��裬��ͬѩ������ת������$n��$l",
	"lvl" : 90,
	"skill_name" : "��˪ѩ��"
])
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry" ; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("���������Ʊ�����֡�\n");
	if (me->query_skill("jiuyang-shengong", 1) < 40)
		return notify_fail("��ľ����񹦲�������޷�ѧ�������ơ�\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷����������ơ�\n");
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��ı�����ֲ�����ϰ��\n");
	if ((int)me->query("qi") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 40)
		return notify_fail("��������������������ơ�\n");
	me->receive_damage("qi", 25);
	me->add("neili", -10);
	return 1;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	if( random(me->query_skill("hanbing-mianzhang",1)) > 10 )
		victim->apply_condition("ice_poison", random(me->query_skill("hanbing-mianzhang",1)/10) + 1 + victim->query_condition("ice_poison"));
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
	int d_e1 = -15;
	int d_e2 = 5;
	int p_e1 = 25;
	int p_e2 = 55;
	int f_e1 = 110;
	int f_e2 = 220;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("hanbing-mianzhang", 1);
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

string perform_action_file(string action)
{
	return __DIR__"hanbing-mianzhang/" + action;
}
int help(object me)
{
	write(HIC"\n�������ƣ�"NOR"\n");
	write(@HELP

    ����������������������ΤһЦ�Ķ����书�����ƺ�ͻẮ��
��������ʱ�������亦�ޱȡ�

	ѧϰҪ��
		������40��
		����100
HELP
	);
	return 1;
}


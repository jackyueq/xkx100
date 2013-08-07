// meiren-sanzhao.c ��������
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

inherit SKILL;

mapping *action = ({
([      "action" : "$N����΢����������Ť�����㷴�ߣ���$n��С����ȥ��$n������ܣ�\n$N˳�Ʒ�������������§ס$nͷ����������$w��׼$n���ģ�һ����ȥ",
	"lvl" : 0,
	"skill_name" : "��������",
]),
([      "action" : "$N�����Ե���$n�������̤ס$N�ĺ�����$N���Դ��������Լ����ؿ����䣬\n˳���ڵ���һ�������$n�Ŀ��������������$w����$n�ĺ���",
	"lvl" : 10,
	"skill_name" : "С�����",
]),
([      "action" : "$N������ǰ���ߣ�˳��һ�������ϵ�$w����$n���ʺ��ȥ",
	"lvl" : 20,
	"skill_name" : "�������",
])
});

int valid_enable(string usage) { return usage=="sword" || usage=="parry"; }
int valid_learn(object me)
{
	if (me->query_int() < 35)
		return notify_fail("������Բ������޷�ѧ�������С�\n");
        if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷�ѧ�������С�\n");
	if ((int)me->query_skill("dulong-dafa", 1) < 60)
		return notify_fail("��Ķ����󷨻�򲻹����޷�ѧ�������С�\n");
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
        int level;
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
        if( (int)me->query("qi") < 30 || (int)me->query("jing") < 30 )
                return notify_fail("��ľ�������Ѫ̫���ˡ�\n");
        level = (int)me->query_skill("meiren-sanzhao", 1);
        if( level < 30 )
                return notify_fail("����������е����ջ�������\n");
        if( level > 15 * (int)me->query("int") )
                return notify_fail("�������������Ҳ������ȥ�ˡ�\n");

        me->receive_damage("qi", 30);
        me->receive_damage("jing", 30);
        return 1;
}

mapping query_action(object me, object weapon)
{
/* d_e=dodge_effect p_e=parry_effect f_e=force_effect m_e=damage_effect */
	int d_e1 = -15;
	int d_e2 = 5;
	int p_e1 = -45;
	int p_e2 = 25;
	int f_e1 = 150;
	int f_e2 = 200;
	int m_e1 = 180;
	int m_e2 = 270;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("meiren-sanzhao",1);
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
		"damage"      : m_e1 + (m_e2 - m_e1) * seq / ttl,
		"damage_type" : random(2) ? "����" : "����",
	]);
}
int learn_bonus() { return 5; }
int practice_bonus() { return 5; }
int success() { return 5; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"meiren-sanzhao/" + action;
}

int help(object me)
{
	write(HIC"\n��������"NOR"\n");
	write(@HELP

    ����������������������ȡ��������������

	ѧϰҪ��
		������60��
		������Ϊ100
		��������35
HELP
	);
	return 1;
}


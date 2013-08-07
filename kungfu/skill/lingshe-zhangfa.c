//lingshe_zhangfa.c �����ȷ�
// Last Modified by sir 10.22.2001

#include "ansi.h"
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$Nʹ��һ��"HIB"�����߳�����"NOR"������$w�󿪴���ɨ��$n��$l",
	"lvl"    : 0,
	"skill_name" : "���߳���"
]),
([	"action" : "$N����$w������죬һ��"BLU"��ҡͷ��β��"NOR"��$n��$l��ȥ",
	"lvl"    : 20,
	"skill_name" : "ҡͷ��β"
]),
([	"action" : "$N����$w���Ӹ�����ʹһ��"MAG"�������½���"NOR"����$n��$l",
	"lvl"    : 30,
	"skill_name" : "�����½�"
]),
([	"action" : "$Nһ��"HIM"������ͦ��"NOR"������$w����ɨ��$n��$l",
	"lvl"    : 40,
	"skill_name" : "����ͦ��"
]),
([	"action" : "$Nʹ��һ��"YEL"���������ߡ�"NOR"��$w�����ػ���$n��$lɨȥ",
	"lvl"    : 50,
	"skill_name" : "��������"
]),
([	"action" : "$N����$wһ�ӣ�ʹ��һ��"MAG"���߲����ҡ�"NOR"���������ɨ��$n��$l",
	"lvl"    : 60,
	"skill_name" : "�߲�����"
]),
([	"action" : "$Nʹ��һ��"RED"��������ɽ��"NOR"���߾�����$w����ͷ����$n��$l",
	"lvl"    : 80,
	"skill_name" : "������ɽ"
]),
([	"action" : "$Nʹ��һ��"HIR"�����߳�����"NOR"������$w��һ̽��ֱɨ$n��$l",
	"lvl"    : 100,
	"skill_name" : "���߳���"
]),
});

int valid_enable(string usage) { return usage == "staff" || usage == "parry"; }
int valid_learn(object me)
{
	if ((int)me->query_skill("hamagong", 1) < 20)
		return notify_fail("��ĸ�󡹦����������\n");
	if ((int)me->query("max_neili") < 70)
		return notify_fail("�������������\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "staff")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("qi") < 60 || (int)me->query("neili") < 50 )
		 return notify_fail("����Ъ���������ɡ�\n");
	me->receive_damage("qi", 55);
	me->add("neili", -30);
	return 1;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	object weapon;

	if (objectp(weapon = me->query_temp("weapon")) &&
       ((string)weapon->query("id") == "she zhang" ||
        (string)weapon->query("id") == "lingshe zhang")&&
		random(me->query_skill("hamagong",1)) > 10 ) 
	{
		victim->apply_condition("snake_poison", random(me->query_skill("hamagong",1)/10) + 1 + victim->query_condition("snake_poison"));
		tell_object(victim, HIG"����ñ����еĵط�һ����ľ��\n" NOR );
		tell_object(victim, HIG"ԭ���Ǳ���ͷ�ܳ��Ķ���ҧ��һ�ڣ�\n"NOR);
	}
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
	int p_e1 = 5;
	int p_e2 = 40;
	int f_e1 = 300;
	int f_e2 = 400;
	int m_e1 = 210;
	int m_e2 = 300;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("lingshe-zhangfa", 1);
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
		"damage_type" : "����",
	]);
}
int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 5; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"lingshe-zhangfa/" + action;
}
int help(object me)
{
	write(HIC"\n�����ȷ���"NOR"\n");
	write(@HELP

    �����ȷ�������ŷ����Ĵ����书���ȷ��׺ݣ�������ͷ����
��϶���ˣ�����������

	ѧϰҪ��
		��󡹦20��
		������Ϊ70
HELP
	);
	return 1;
}


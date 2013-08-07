// dagou-bang.c �򹷰���
// Last Modified by sir 10.22.2001
// write by Xiang

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action": "$Nʹ��һ��"HIG"������˫Ȯ��"NOR"������$w���������������$n��$l",
	"lvl"        : 10,
	"skill_name" : "����˫Ȯ"
]),
([	"action": "$N����$w���һζ���һ��"HIG"������Ѱ�ߡ�"NOR"��$n��$l��ȥ",
	"lvl"        : 20,
	"skill_name" : "����Ѱ��"
]),
([	"action": "$N����$w���Ӹ�����ʹһ��"HIG"����ݾ��ߡ�"NOR"����$n��$l",
	"lvl"        : 30,
	"skill_name" : "��ݾ���"
]),
([	"action": "$Nʩ��"HIG"���������졹"NOR"��$w����������$n��ȥ",
	"lvl"        : 40,
	"skill_name" : "��������"
]),
([	"action":"$N�������һ����â�����������ʹ��"HIR"�������޹���"NOR"������ǵ�����",
	"lvl"        : 50,
	"skill_name" : "�����޹�"
]),
});

int valid_enable(string usage) { return (usage=="stick") || (usage=="parry"); }

int valid_learn(object me)
{
	if ((int)me->query_skill("huntian-qigong", 1) < 50)
		return notify_fail("��Ļ��������Ļ�򻹲�����\n");
	if ((int)me->query("max_neili") < 200)
		return notify_fail("�������������\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "stick")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("qi") < 50 || (int)me->query("neili") < 50 )
		return notify_fail("������������������򹷰�����\n");
	me->receive_damage("qi", 40);
	me->add("neili", -40);
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
	int d_e1 = -60;
	int d_e2 = -30;
	int p_e1 = -10;
	int p_e2 = 10;
	int f_e1 = 300;
	int f_e2 = 400;
	int m_e1 = 100;
	int m_e2 = 300;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("dagou-bang", 1);
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
int learn_bonus() { return 10; }
int practice_bonus() { return 10; }
int success() { return 5; }
int power_point() { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"dagou-bang/" + action;
}

int help(object me)
{
	write(HIC"\n�򹷰�����"NOR"\n");
	write(@HELP

    ��ʮ��·�򹷰�����ؤ�￪����ʦү������������ǰ�ΰ�����
���ΰ��������������ڶ����ˡ�ؤ������ΰ������书��ʤ������
ʦ��������·�����и�������������仯������������ؤ��굽Σ
�ѹ�ͷ���������Գ�������������򹷰�������ɱ�У�����Ⱥа��
    �򹷰���������Ȼª�ף����仯��΢���������ʵ�ǹ�����
����ѧ�е�һ������Ĺ���׿Ȼ�Գ�һ�ң�������ɵĹ������
ǣ�档��ѧ���������ǲ����������������������������⡢ת��
���ֿھ�������һ�����á�ÿ��ھ�������ÿ���������䣬������
ٱ��Ϊؤ����������ഫ�����֮����

	ѧϰҪ��
		��������50��
		����200
HELP
	);
	return 1;
}


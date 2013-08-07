// wudang-quan.c �䵱��ȭ
// Last Modified by Winder on Feb. 18 2001
#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N�����ұۣ�һ��"RED"�������֡�"NOR"��һȭֱ������$n��$l",
	"lvl" : 0,
	"skill_name" : "������"
]),
([	"action" : "$N����ǰ̽������籼$n��࣬һ��"HIB"�����֡�"NOR"����$n��$l��ȥ",
	"lvl" : 10,
	"skill_name" : "����"
]),
([	"action" : "$N˫��΢�������лζ���һ��"HIM"��һ���ޡ�"NOR"���д�������$n��$l",
	"lvl" : 20,
	"skill_name" : "һ����"
]),
([	"action" : "$N�����ȣ�������Σ�������ȭһʽ"GRN"��ֱ����"NOR"Ѹ�ʹ���$n���ؿ�",
	"lvl" : 40,
	"skill_name" : "ֱ��"
]),
([	"action" : "$Nʩ��"HIC"�����ͷ��"NOR"������Ծ����У�˫��ͬʱ����$n��$l",
	"lvl" : 50,
	"skill_name" : "���ͷ"
]),
([	"action" : "$N˫�ۻػ�������΢΢������һ��"HIW"��������"NOR"������$n��˫��",
	"lvl" : 60,
	"skill_name" : "����"
])
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }
int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("���䵱��ȭ������֡�\n");
	if ((int)me->query_skill("taiji-shengong", 1) < 1)
		return notify_fail("���̫���񹦻�򲻹����޷�ѧ�䵱��ȭ��\n");
	return 1;
}
int practice_skill(object me)
{
	int lvl = me->query_skill("wudang-quan", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ((int)me->query("qi") < 30)
		return notify_fail("�������̫���ˡ�\n");
	me->receive_damage("qi", 20);
	return 1;
}
string query_skill_name(int level)
{
	int i = sizeof(action);

	while (i--)
		if(level > action[i]["lvl"])
			return action[i]["skill_name"];
}
mapping query_action(object me, object weapon)
{
/* d_e=dodge_effect p_e=parry_effect f_e=force_effect m_e=damage_effect */
	int d_e1 = 35;
	int d_e2 = 55;
	int p_e1 = -25;
	int p_e2 = -5;
	int f_e1 = 120;
	int f_e2 = 220;	
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("wudang-quan", 1);
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
	write(HIC"\n�䵱��ȭ��"NOR"\n");
	write(@HELP

    �䵱��ȭΪ�䵱������ȭ����

	ѧϰҪ��
		̫����1��
HELP
	);
	return 1;
}


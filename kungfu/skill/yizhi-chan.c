// yizhi-chan.c һָ��
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N˫ָ��£��һʽ"HIY"�����������"NOR"��������ϣ�������һǰһ�����$n���ظ���",
	"lvl" : 0,
	"skill_name" : "�������"
]),
([	"action" : "$N���ƻ��أ�һʽ"HIY"��������ա�"NOR"��������ָǰ���˸��뻡���͵�һ˦������$n��$l",
	"lvl" : 20,
	"skill_name" : "�������"
]),
([	"action" : "$N����������һʽ"HIY"�����Ź�ɡ�"NOR"��˫��ʳָ�˲������һ������������$n��ȫ��ҪѨ",
	"lvl" : 40,
	"skill_name" : "���Ź��"
]),
([	"action" : "$N��ϥ������һʽ"HIY"�����ޱߡ�"NOR"��������ȭ���⣬����Ĵֱָ����ңң����$nһ��",
	"lvl" : 60,
	"skill_name" : "���ޱ�"
])
});

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }	
int valid_combine(string combo) { return combo=="banruo-zhang"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��һָ��������֡�\n");
	if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
		return notify_fail("��Ļ�Ԫһ������򲻹����޷�ѧһָ����\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷���һָ����\n");
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��ı�����ֲ�����ϰ��\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 50)
		return notify_fail("�������������һָ����\n");
	me->receive_damage("qi", 40);
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
	int d_e1 = 25;
	int d_e2 = 50;
	int p_e1 = -30;
	int p_e2 = -15;
	int f_e1 = 360;
	int f_e2 = 460;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("yizhi-chan", 1);
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
	return __DIR__"yizhi-chan/" + action;
}

int help(object me)
{
	write(HIC"\nһָ����"NOR"\n");
	write(@HELP

    һָ��Ϊ������ʮ������֮һ��
    ��������ƻ�����

	ѧϰҪ��
		��Ԫһ����20��
		����100
HELP
	);
	return 1;
}


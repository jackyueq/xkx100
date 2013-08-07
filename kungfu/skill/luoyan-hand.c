// luoyan-hand.c ��������
// Last Modified by sir 10.23.2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$Nһʽ"HIC"������б�㡹"NOR"�����ƻ�צ����ָ�繳��ֱ��$n������ҪѨ",
	"lvl" : 0,
	"skill_name" : "����б��"
]),
([	"action" : "$N������Σ�һʽ"CYN"������޺ۡ�"NOR"����������ֱ��������$n�ļ羮��Ѩ
",
	"lvl" : 10,
	"skill_name" : "����޺�"
]),
([	"action" : "$Nʹһʽ"BLU"������˪�᡹"NOR"����ָ��������ò�ʩ������$n����·Ҫ��",
	"lvl" : 20,
	"skill_name" : "����˪��"
]),
([	"action" : "$N����ӥץ�������߾٣�һʽ"MAG"�����������"NOR"����$n���нڴ���",	
	"lvl" : 30,
	"skill_name" : "�������"
]),
([	"action" : "$Nʹһʽ"YEL"��������衹"NOR"������˷�����������Ӱ��һצͻ����ץ��$n
���ؿ�",
	"lvl" : 50,
	"skill_name" : "�������"
]),
([	"action" : "$N���ֻ��ۣ�ȫ��ؽ�žž���죬һʽ"HIM"�����ֻ�ʱ��"NOR"������$n��$l",
	"lvl" : 80,
	"skill_name" : "���ֻ�ʱ"
]),
([	"action" : "$Nһʽ"HIB"���Ϻ����㡹"NOR"��ʮָ���죬������հ������$n��ȫ��ҪѨ",
	"lvl" : 100,
	"skill_name" : "�Ϻ�����"
]),
([	"action" : "$N�������ţ�һʽ"HIG"��������ۡ�"NOR"����һ�������У�˫��ͬʱ����$n
���ߵ���Ѩ",
	"lvl" : 150,
	"skill_name" : "�������"
])
});

int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }
int valid_combine(string combo) { return combo=="biluo-zhang"; }
int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("���������ֱ�����֡�\n");
	if ((int)me->query_skill("huiyan-xinfa", 1) < 20)
		return notify_fail("��Ļ����ķ���򲻹����޷�ѧ�������֡�\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷����������֡�\n");
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��ı�����ֲ�����ϰ��\n");
	if ((int)me->query("qi") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("��������������������֡�\n");
	me->receive_damage("qi", 25);
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
	int d_e1 = -40;
	int d_e2 = -10;
	int p_e1 = 20;
	int p_e2 = 50;
	int f_e1 = 110;
	int f_e2 = 210;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("luoyan-hand", 1);
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
	return __DIR__"luoyan-hand/" + action;
}

int help(object me)
{
	write(HIC"\n�������֣�"NOR"\n");
	write(@HELP

    ��������Ϊ��ɽ�ɾ���֮һ��
    ��������ƻ�����
    
	ѧϰҪ��
		�����ķ�20��
HELP
	);
	return 1;
}


// Last Modified by winder on May. 29 2001
// zui-club.c �������

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action":""HIB"�����ɺͣ�����Ȱ�������ʡ�"NOR"��$N����$w���ᣬ��������$n��$l",	
	"lvl" : 0,
	"skill_name" : "���ɺͣ�����Ȱ��������"
]),
([	"action":""MAG"�����ɹã������������ɲ���"NOR"��$N���ƻ��أ��ұ�Ю���͵�ɨ��$n������",
	"lvl" : 20,
	"skill_name" : "���ɹã������������ɲ�"
]),
([	"action":""HIY"���ܹ��ˣ�ǧ���������ѡ�"NOR"��$N����$w��ָ���أ���$n��$l��ȥ",
	"lvl" : 30,
	"skill_name" : "�ܹ��ˣ�ǧ����������"
]),
([	"action":""HIC"�������ӣ����������������"NOR"��$N����$w�����˻��˸���Ȧ������$n��$l",
	"lvl" : 40,
	"skill_name" : "�����ӣ��������������"
]),
([	"action":""HIR"�������룬����������������"NOR"��$N���й������ţ�����������$n",
	"lvl" : 50,
	"skill_name" : "�����룬��������������"
]),
([	"action":""HIW"��������ߵ���ɽ����ء�"NOR"��$N����֧�أ�һ��һ���������$n��$l",
	"lvl" : 55,
	"skill_name" : "������ߵ���ɽ�����"
]),
([	"action":""YEL"���Ź��ϣ�����ױ�����¿��"NOR"��$NŤ������$w�ӿ�����������$n���ؿ�",
	"lvl" : 60,
	"skill_name" : "�Ź��ϣ�����ױ�����¿"
]),
([	"action":""CYN"�������������������ǧ����"NOR"��$N�ڿն�����ɽ��Ӱ������ѹ��$n",
	"lvl" : 64,
	"skill_name" : "�����������������ǧ��"
]),
});

int valid_enable(string usage) { return (usage=="club") || (usage=="parry"); }
int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 500)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("zhanzhuang-gong", 1) < 50)
		return notify_fail("���վ׮�����̫ǳ��\n");
	if ((int)me->query_skill("weituo-club", 1) < 20)
		return notify_fail("���Τ�ӹ����̫ǳ��\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "club")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("qi") < 50 || (int)me->query("neili") < 50 )
		return notify_fail("��������������������������\n");
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
	int d_e1 = -45;
	int d_e2 = -35;
	int p_e1 = 10;
	int p_e2 = 25;
	int f_e1 = 250;
	int f_e2 = 300;
	int m_e1 = 100;
	int m_e2 = 200;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("zui-club", 1);
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
int success() { return 10; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"zui-club/" + action;
}

int help(object me)
{
	write(HIC"\n���������"NOR"\n");
	write(@HELP

    ��������������ָ߼�������

	ѧϰҪ��
		վ׮��50��
		Τ�ӹ�20��
		������Ϊ500
HELP
	);
	return 1;
}


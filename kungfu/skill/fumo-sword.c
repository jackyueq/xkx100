// Last Modified by winder on May. 29 2001
// fumo-sword.c ��ħ��

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$Nһʽ"MAG"�������ơ�"NOR"������ƽָ��������磬һ���ǳɺ�ɨ$n������",
	"lvl" : 0,
	"skill_name" : "������"
]),
([	"action" : "$N��ǰԾ��һ�������ֽ���������$wʹ��һʽ"HIC"�������ơ�"NOR"ֱ��$n��$l",
	"lvl" : 10,
	"skill_name" : "������"
]),
([	"action" : "$N�β�ͦ����һʽ"HIB"����ɽ�ơ�"NOR"������$w�����ޱȣ������ӽ�ײ��$n��$l",
	"lvl" : 20,
	"skill_name" : "��ɽ��"
]),
([	"action" : "$Nһʽ"HIG"�������ơ�"NOR"��$w������һ���һ���󻡣�ƽƽ����$n��$l��ȥ",
	"lvl" : 30,
	"skill_name" : "������"
]),
([	"action" : "$N����š���������鱧��Բ��һʽ"GRN"�������ơ�"NOR"��$w�й�ֱ��������$n���ؿ�",
	"lvl" : 40,
	"skill_name" : "������"
]),
([	"action" : "$Nһʽ"YEL"�������ơ�"NOR"��$w������������������ֱ����Ю����֮����Ȼն��$n��$l",
	"lvl" : 49,
	"skill_name" : "������"
]),
([	"action" : "$N����ʩ��"HIM"�������ơ�"NOR"��$w����Ƴ�һ����â��������ƿ�����$n��$l",
	"lvl" : 57,
	"skill_name" : "������"
]),
([	"action" : "$N˫�Ȱ�����ף�һʽ"BLU"�������ơ�"NOR"�����⻮������ԲȦ����������������",
	"lvl" : 64,
	"skill_name" : "������"
]),
});

int valid_enable(string usage) { return (usage=="sword") || (usage=="parry") ; }
//int valid_combine(string combo) { return combo=="cibei-dao"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 500)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("zhanzhuang-gong", 1) < 50)
		return notify_fail("���վ׮�����̫ǳ��\n");
	if ((int)me->query_skill("damo-sword", 1) < 20)
		return notify_fail("��Ĵ�Ħ�����̫ǳ��\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("qi") < 50 || (int)me->query("neili") < 30 )
		return notify_fail("�������������������ħ����\n");
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
	int d_e1 = -5;
	int d_e2 = 20;
	int p_e1 = -30;
	int p_e2 = -15;
	int f_e1 = 150;
	int f_e2 = 200;
	int m_e1 = 140;
	int m_e2 = 230;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("fumo-sword", 1);
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
int learn_bonus() { return 15; }
int practice_bonus() { return 15; }
int success() { return 10; }
int power_point(object me) { return 1.0; }

int help(object me)
{
	write(HIC"\n��ħ����"NOR"\n");
	write(@HELP

    ��ħ���������ָ߼�������

	ѧϰҪ��
		վ׮��50��
		��Ħ��20��
		������Ϊ500
HELP
	);
	return 1;
}


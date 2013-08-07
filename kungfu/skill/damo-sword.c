// Last Modified by winder on May. 29 2001
// damo-sword.c ��Ħ��

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action":"$Nʹһʽ"HIB"��������Ե����"NOR"������$w����΢�񣬻ó�һ���������$n��$l",
	"lvl"   : 0,
	"skill_name" : "������Ե��"
]),
([	"action":"$N����ǰ��ʹ��"MAG"����ȥ�����С�"NOR"�������������ޣ�$w��������$n��$l��ȥ",
	"lvl"   : 9,
	"skill_name" : "��ȥ������"
]),
([	"action":"$Nһʽ"HIC"��������ɣԶ��"NOR"������Ʈ�����ߣ��˷�����������$wңҡָ��$n��$l",
	"lvl"   : 18,
	"skill_name" : "������ɣԶ"
]),
([	"action":"$N��������Ծ��һʽ"HIY"���ֻط����᡹"NOR"���������ּ�ת������ն��$n��$l",
	"lvl"   : 27,
	"skill_name" : "�ֻط�����"
]),
([	"action":"$N����$w�й�ֱ����һʽ"GRN"��ˮ��ͨ���š�"NOR"��������Ϣ�ض�׼$n��$l�̳�һ��",
	"lvl" : 36,
	"skill_name" : "ˮ��ͨ����"
]),
([	"action":"$N����$wбָ���죬��â���£�һʽ"HIB"��������������"NOR"����׼$n��$lбб����",
	"lvl"   : 44,
	"skill_name" : "����������"
]),
([	"action":"$N��ָ�����㣬����$w�Ƴ�����ѩ����â��һʽ" MAG"��ǧ��һέȥ��"NOR"����$n��$l",
	"lvl"   : 52,
	"skill_name" : "ǧ��һέȥ"
]),
([	"action":"$N���Ƶ�����һʽ"GRN"�����Ķ�������"NOR"��$w�Ի���Ծ�����缲�������$n���ؿ�",
	"lvl"   : 60,
	"skill_name" : "���Ķ�����"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("zhanzhuang-gong", 1) < 20)
		return notify_fail("���վ׮�����̫ǳ��\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("qi") < 30
	|| (int)me->query("neili") < 15 )
		return notify_fail("�������������������Ħ����\n");
	me->receive_damage("qi", 30);
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
	int d_e1 = 25;
	int d_e2 = 50;
	int p_e1 = 0;
	int p_e2 = 15;
	int f_e1 = 100;
	int f_e2 = 150;
	int m_e1 = 50;
	int m_e2 = 140;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("damo-sword", 1);
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
int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 20; }
int power_point() { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"damo-sword/" + action;
}

int help(object me)
{
	write(HIC"\n��Ħ����"NOR"\n");
	write(@HELP

    ��Ħ�������������Ž�����

	ѧϰҪ��
		վ׮��20��
		������Ϊ100
HELP
	);
	return 1;
}


// damo-jian.c ��Ħ��
// Last Modified by sir 10.22.2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action":"$Nʹһʽ"MAG"��������Ե����"NOR"������$w����΢�񣬻ó�һ���������$n��$l",
	"lvl" : 0,
	"skill_name" : "������Ե��"
]),
([	"action":"$N����ǰ��ʹ��"HIC"����ȥ�����С�"NOR"�������������ޣ�$w��������$n��$l��ȥ",
	"lvl" : 10,
	"skill_name" : "��ȥ������"
]),
([	"action":"$Nһʽ"YEL"��������ɣԶ��"NOR"������Ʈ�����ߣ��˷�����������$wңҡָ��$n��$l",
	"lvl" : 20,
	"skill_name" : "������ɣԶ"
]),
([	"action":"$N��������Ծ��һʽ"BLU"���ֻط����᡹"NOR"���������ּ�ת������ն��$n��$l",
	"lvl" : 30,
	"skill_name" : "�ֻط�����"
]),
([	"action":"$N����$w�й�ֱ����һʽ"HIW"��ˮ��ͨ���š�"NOR"��������Ϣ�ض�׼$n��$l�̳�һ��",
	"lvl" : 40,
	"skill_name" : "ˮ��ͨ����"
]),
([	"action":"$N����$wбָ���죬��â���£�һʽ"HIM"��������������"NOR"����׼$n��$lбб����",
	"lvl" : 50,
	"skill_name" : "����������"
]),
([	"action":"$N��ָ�����㣬����$w�Ƴ�����ѩ����â��һʽ"GRN "��ǧ��һέȥ��"NOR"����$n��$l",
	"lvl" : 60,
	"skill_name" : "ǧ��һέȥ"
]),
([	"action":"$N���Ƶ�����һʽ"HIG"�����Ķ�������"NOR"��$w�Ի���Ծ�����缲�������$n���ؿ�",
	"lvl" : 70,
	"skill_name" : "���Ķ�����"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
		return notify_fail("��Ļ�Ԫһ�������̫ǳ��\n");
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
	int d_e1 = 30;
	int d_e2 = 50;
	int p_e1 = 0;
	int p_e2 = 20;
	int f_e1 = 100;
	int f_e2 = 150;
	int m_e1 = 40;
	int m_e2 = 140;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("damo-jian", 1);
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
	return __DIR__"damo-jian/" + action;
}

int help(object me)
{
	write(HIC"\n��Ħ����"NOR"\n");
	write(@HELP

    ��Ħ��Ϊ������ʮ������֮һ��

	ѧϰҪ��
		��Ԫһ����20��
		����100
HELP
	);
	return 1;
}


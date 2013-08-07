// murong-sword.c Ľ�ݽ���
// Last Modified by sir 10.22.2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N�鲽����������΢΢ǰ�㣬һʽ"MAG"��ϴ��������"NOR"������$w���������һ������$n��$l",
	"lvl"   : 0,
	"skill_name" : "ϴ������"
]),
([	"action" : "$N��ǰ����һ�������ֽ���������$wʹ��һʽ"GRN"�����������"NOR"ֱ��$n��$l",
	"lvl"   : 20,
	"skill_name" : "�������"
]),
([	"action" : "$N��������һ�죬���ֽ���������$wȦת���֣�ʹ��һʽ"BLU "���������"NOR"����ѩƬƮ�����$n��ȥ",
	"lvl"   : 40,
	"skill_name" : "��������"
]),
([	"action" : "$Nת����������˫ϥ�͵��³�������$wƥ����ش̣�����ɷȻ����
���ۻ��Ѽ�������һʽ"YEL"������Ī����"NOR"",
	"lvl"   : 60,
	"skill_name" : "����Ī��"
]),
([	"action" : "$Nһ��"HIB"���ﻢ���¡�"NOR"������Ծ�����ȷ���ƽ�ţ�$w���϶��»���һ���󻡣�ƽƽ����$n��$l��ȥ",
	"lvl"   : 80,
	"skill_name" : "�ﻢ����"
]),
([	"action" : "$N���������һš��һ��"HIC"����ש����"NOR"������$w������$n��$lбб��ȥ",
	"lvl"   : 100,
	"skill_name" : "��ש����"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }
int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("shenyuan-gong", 1) < 20)
		return notify_fail("�����Ԫ�����̫ǳ��\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("qi") < 50 || (int)me->query("neili") < 30 )
		return notify_fail("�����������������Ľ�ݽ�����\n");
	if ((int)me->query_skill("parry", 1) < 10)
		return notify_fail("����мܼ���̫�ͣ�û����Ľ�ݽ�����\n");
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
	int d_e1 = 0;
	int d_e2 = 20;
	int p_e1 = -30;
	int p_e2 = -10;
	int f_e1 = 100;
	int f_e2 = 150;
	int m_e1 = 130;
	int m_e2 = 220;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("murong-sword", 1);
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

string perform_action_file(string action)
{
	return __DIR__"murong-sword/" + action;
}

int help(object me)
{
	write(HIC"\nĽ�ݽ�����"NOR"\n");
	write(@HELP

    Ľ�ݽ���Ϊ���Ϲ���Ľ���洫������

	ѧϰҪ��
		��Ԫ��20��
		����100
HELP
	);
	return 1;
}


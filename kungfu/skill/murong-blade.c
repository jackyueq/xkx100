// murong-blade.c Ľ�ݵ���
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N���Ծ��˫������$w���߾ٹ�ͷ��һ��"HIM"������ǵ���׳־��"NOR"����
�籼��׹�أ���������糾��һ����$n��$l��������",
	"lvl"    : 0,
	"skill_name" : "����ǵ���׳־",
]),
([	"action" : "$N����б��һ������������$w�����ǰ�أ��͵ز�����ת��������
�ۣ��Աۿ�����һ��"HIR"���䵶��ת��Ǭ����"NOR"��ƽ�л���$n��$l",
	"lvl"    : 20,
	"skill_name" : "�䵶��ת��Ǭ��",
]),
([	"action" : "$N����$w��չ�����Σ�ʹ��"HIW"��ң����ǧ��ѩ��"NOR"��ͻȻ֮�䣬������
�׹�����������Ȧ��֮�ڣ�ȫ�ǵ�Ӱ",
	"lvl"    : 40,
	"skill_name" : "ң����ǧ��ѩ",
]),
([	"action" : "$Nһ��"HIG"��׳־������������"NOR"��$w���ƴ�䣬����һ�������µĽ�ħ��
��������һ��������ɽ�����Ϻ��Ĳ�ʮ��·����ת����һ������ʷ�ҵ�
�ط����������������$n����",
	"lvl"    : 60,
	"skill_name" : "׳־����������",
]),
});

int valid_enable(string usage) { return (usage=="blade") || (usage=="parry"); }
int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 50)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("shenyuan-gong", 1) < 10)
		return notify_fail("�����Ԫ�����̫ǳ��\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("�������������Ľ�ݵ�����\n");
	me->receive_damage("qi", 30);
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
	int d_e1 = 50;
	int d_e2 = 25;
	int p_e1 = -5;
	int p_e2 = -20;
	int f_e1 = 100;
	int f_e2 = 150;
	int m_e1 = 90;
	int m_e2 = 200;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int)me->query_skill("murong-blade", 1);
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
int learn_bonus() { return 15; }
int practice_bonus() { return 10; }
int success() { return 15; }
int power_point(object me) { return 1; }

string perform_action_file(string action)
{
	return __DIR__"murong-blade/" + action;
}

int help(object me)
{
	write(HIC"\nĽ�ݵ�����"NOR"\n");
	write(@HELP

    Ľ�ݵ���Ϊ���Ϲ���Ľ���洫���������ۻ��������������
�ơ�

	ѧϰҪ��
		��Ԫ��10��
		����50
HELP
	);
	return 1;
}


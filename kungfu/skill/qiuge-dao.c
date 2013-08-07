// Last Modified by winder on Sep. 12 2001
// qiuge-dao.c ����ߵ�

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$Nʹһ��"GRN"��һҶ��Ƽ��󺣡�"NOR"������$wһ�ڣ����μ�����ɣ����˺�һ������$n��$l��",
	"lvl"    : 0,
	"skill_name" : "һҶ��Ƽ���",
]),
([	"action" : "$N$w�����������⣬һ��"HIB"�������δ�����꡹"NOR"����������$n��$l��",
	"lvl"    : 15,
	"skill_name" : "�����δ������",
]),
([	"action" : "$N����$w����������ˮ��һ��"HIY"��˥��б�������֡�"NOR"��бб����$n��$l",
	"lvl"    : 30,
	"skill_name" : "˥��б��������",
]),
([	"action" : "$N����$w���⼤����һ��"YEL"������Ӱ�հ����̡�"NOR"��ն��$n��",
	"lvl"    : 45,
	"skill_name" : "����Ӱ�հ�����",
]),
([	"action" : "$N����$w���裬�������Ŵشأ�һ��"HIR"�����ܻ���֪��ɫ��"NOR"��ƮƮ������$n��ȥ",
	"lvl"    : 60,
	"skill_name" : "���ܻ���֪��ɫ",
]),
([	"action" : "$N����$w����ɭȻ��һ��"CYN"����Ƽ��Զ��������"NOR"ֱ��$n��$l",
	"lvl"    : 75,
	"skill_name" : "��Ƽ��Զ������",
]),
([	"action" : "$Nʹһ��"RED"���ͷ������仨�졹"NOR"������$w�ڶ����������ն��$n��$l",
	"lvl"    : 90,
	"skill_name" : "�ͷ������仨��",
]),
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }
int valid_learn(object me)
{ 
	if ((int)me->query("max_neili") < 150)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("honghua-shengong", 1) < 20)
		return notify_fail("��ĺ컨�񹦻��̫ǳ��\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "blade")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("���������������赶����\n");
	me->receive_damage("qi", 25);
	return 1;
}
string *parry_msg = ({
	"$nʹ��һ�С���ҡɽ�������������е�$Wɢ��˿˿��������$P��$w��\n",
	"$n����$W���������һ�С����������б��������Ӱ��ͻȻ����һ�ƹ�â�Ӳ��滮��$P֮�ؾȡ�\n",
	"$n����΢�٣����е�$W����һ�����⣬һ�С����������һ�С�������$P��$w��\n",
});
string *unarmed_parry_msg = ({
	"$nʹ��һ�С�˪���Ҷ����������е�$W����������$N�Ĺ����沨��ɢ��\n",
	"$n���μ��ˣ�����$W���·��裬һ�С������������󡹣���ס$N����ʽ��\n",
	"$n���е�$W�����䵶����һ�С�������Ӱ���������������ࡣ\n",
});
string query_parry_msg(object weapon)
{
	if( weapon ) return parry_msg[random(sizeof(parry_msg))];
	else return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
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
	int d_e1 = 45;
	int d_e2 = 25;
	int p_e1 = -5;
	int p_e2 = -25;
	int f_e1 = 100;
	int f_e2 = 150;
	int m_e1 = 90;
	int m_e2 = 200;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int)me->query_skill("qiuge-dao", 1);
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
int practice_bonus() { return 10; }
int success() { return 15; }
int power_point(object me) { return 1; }

string perform_action_file(string action)
{
	return __DIR__"qiuge-dao/" + action;
}
int help(object me)
{
	write(HIM"\n����ߵ���"NOR"\n");
	write(@HELP

    �컨�᱾�ŵ�����

	ѧϰҪ��
		�컨��20��
		������Ϊ100
HELP
	);
	return 1;
}

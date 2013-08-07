// xunlei-sword.c
// Last Modified by sir 10.22.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N�������ң�����һ�ܣ�һʽ"HIC"������ָ·��"NOR"��$wͻȻ��$n��$l��ȥ��",
	"lvl" : 0,
	"skill_name"  : "����ָ·"
]),
([	"action" : "$Nʹ��һʽ"BLU"�����ӷ���"NOR"��������ղ෭��һ�������´̳�",
	"lvl" : 5,
	"skill_name"  : "���ӷ���"
]),
([	"action" : "$N���ֽ�ָѪָ������$wʹ��һ��"MAG"������Ѱ�롹"NOR"��������������$n��$l����",
	"lvl" : 10,
	"skill_name"  : "����Ѱ��"
]),
([	"action" : "$N��������$w�����ڱ��£�һ��"GRN"����Գ̽����"NOR"��������������$n��$l",
	"lvl" : 15,
	"skill_name"  :"��Գ̽��"
]),
([	"action" : "$N̤����ǰ��һʽ"HIG"������Ѱ�ߡ�"NOR"�����г����ڶ����������$n��$l",
	"lvl" : 20,
	"skill_name"  : "����Ѱ��"
]),
([	"action" : "$Nһ��"HIY"��б����֦��"NOR"�����屳ת������$w���Ҽ��Ϸ��������´̳�",
	"lvl" : 25,
	"skill_name"  : "б����֦"
]),
([	"action" : "$Nһʽ"HIC"�������׶���"NOR"�������з棬�������ϣ���$n���������ؽ���֮��",
	"lvl" : 30,
	"skill_name"  : "�����׶�"
]),
([	"action" : "$N��ǰ����һ��"RED"������Ҿ�֡�"NOR"��$w��Ȼ�����´̳���������������",
	"lvl" : 35,
	"skill_name"  : "����Ҿ��"
]),
([	"action" : "$N����$w�����һζ���һ��"HIW"�����������"NOR"������ֱ��$n������Ҫ��",
	"lvl" : 45,
	"skill_name"  : "�������"
]),
([	"action" : "$N˫�ֳֽ�����$w������ʹ��һ��"HIR"���ٻ����졹"NOR"���������$n��ǰ�Ϸ���ȥ",
	"lvl" : 55,
	"skill_name"  : "�ٻ�����"
]),
([	"action" : "$N������$n��ʹ��һ��"HIB"������ն�㡹"NOR"���Ӷ�����$w��ֱ��$n������·",
	"lvl" : 65,
	"skill_name"  : "����ն��"
]),
([	"action" : "$N����$w��������һ��"HIC"����Ů���롹"NOR"��$wͻȻ���ִ���$n��$l",
	"lvl" : 75,
	"skill_name"  : "��Ů����"
]),
([	"action" : "$N������ǰ��������ָ��һ��"HIG"����Գ��֦��"NOR"��$w����$n��ͷ��Ҫ��",
	"lvl" : 85,
	"skill_name"  : "��Գ��֦"
]),
([	"action" : "$Nһ��"BLU"������ӱޡ�"NOR"��$w�����ߣ�����һ����������$nȫ����������",
	"lvl" : 95,
	"skill_name"  : "����ӱ�"
]),
([	"action" : "$N�������£�һ��"RED"�����ƿ�����"NOR"��$w��Ȼ��תֱ�ϣ�������$n������Ҫ������Χס",
	"lvl" : 100,
	"skill_name"  : "���ƿ���"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }
int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("xuantian-wuji", 1) < 10)
		return notify_fail("��������޼������̫ǳ��\n");
	if ((int)me->query_skill("sword", 1) < 10)
		return notify_fail("��Ļ����������̫ǳ��\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("qi") < 50 || (int)me->query("neili") < 35 )
		return notify_fail("�����������������Ѹ��ʮ������\n");
	me->receive_damage("qi", 45);
	me->add("neili", -30);
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
	int d_e1 = -10;
	int d_e2 = 10;
	int p_e1 = -40;
	int p_e2 = -20;
	int f_e1 = 150;
	int f_e2 = 200;
	int m_e1 = 160;
	int m_e2 = 250;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("xunlei-sword", 1);
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
int learn_bonus() { return 10; }
int practice_bonus() { return 10; }
int success() { return 5; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"xunlei-sword/" + action;
}

int help(object me)
{
	write(HIC"\nѸ��ʮ������"NOR"\n");
	write(@HELP

    Ѹ��ʮ�����������ɵĽ�����

	ѧϰҪ��
		�����޼���10��
		��������10��
		����100
HELP
	);
	return 1;
}


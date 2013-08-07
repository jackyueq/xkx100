// yunu-sword.c ��Ů����ʮ����
// Last Modified by sir 10.22.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"skill_name" : "��������",
	"action":  "$Nʹһ��"HIM"���������ߡ�"NOR"����̤�й�������$wֱָ$n$l",
	"lvl" : 0
]),
([	"skill_name" : "�����޷�",
	"action":  "$N������ת��һ��"HIB"�������޷졹"NOR"������һƬ��Ӱ������$n��$l",
	"lvl" : 10
]),
([	"skill_name" : "ҹ��ԧ��",
	"action":  "$N�趯$w��ʹ��һ��"HIG"��ҹ��ԧ�졹"NOR"���������ң���˸������ֱ��$n��$l",
	"lvl" : 20
]),
([	"skill_name" : "֯Ů����",
	"action":  "$Nһ�����ȣ�����"HIW"��֯Ů����"NOR"������$w��Ϊһ�����⣬����$n��$l",
	"lvl" : 30
]),
([	"skill_name" :  "С������",
	"action":  "$N��Ȼ����ֱ�ϣ�һ��"HIR"��С�����ˡ�"NOR"������$w�������ϴ���$n��$l",
	"lvl" : 40
]),
});

int valid_enable(string usage) { return usage=="sword" || usage=="parry"; }
int valid_learn(object me)
{
	object ob;
	if( (string)me->query("gender") != "Ů��" )
		return notify_fail("��Ů����ʮ������ֻ��Ů�Ӳ��������书��\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("�������������û�а취����Ů����ʮ������\n") ;
	if( (string)me->query_skill_mapped("force")!= "zixia-shengong")
		return notify_fail("��Ů����ʮ�������������ϼ�񹦲�������\n");
	if( !(ob = me->query_temp("weapon"))
		|| (string)ob->query("skill_type") != "sword" )
		return notify_fail("���������һ�ѽ�������������\n");

	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("qi") < 35 || (int)me->query("neili") < 15 )
		return notify_fail("�����������������û�а취��ϰ��Ů����ʮ������\n");
	me->receive_damage("qi", 30);
	me->add("neili", -15);
//	write("�㰴����ѧ����һ����Ů����ʮ������\n");
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
	int d_e1 = 15;
	int d_e2 = 40;
	int p_e1 = -10;
	int p_e2 = 5;
	int f_e1 = 100;
	int f_e2 = 150;
	int m_e1 = 80;
	int m_e2 = 170;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("yunu-sword", 1);
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
int learn_bonus() { return 25; }
int practice_bonus() { return 25; }
int success() { return 15; }
int power_point(object me) { return 1.0; }

int valid_effect(object me, object weapon, string name, int skill)
{
}

string perform_action_file(string action)
{
	return __DIR__"yunu-sword/" + action;
}
int help(object me)
{
	write(HIC"\n��Ů����ʮ������"NOR"\n");
	write(@HELP

    ��Ů����ʮ�����������������򴫸�Ů���ӵĻ�ɽ�ɽ�����

	ѧϰҪ��
		Ů��
		��ϼ��
		����50
HELP
	);
	return 1;
}


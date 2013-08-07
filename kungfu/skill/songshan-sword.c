// songshan-sword.c ��ɽ����
// Last Modified by winder on Mar. 10 2000
// Modified by Java Sep.1998

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"skill_name" : "��������",
	"action" : "$N����$wһ�����ٽ���������������ʹһ��"HIY"���������ڡ�"NOR"����\n��ϵ���ڵ���ɽ����",
	"lvl" : 0
]),
([	"skill_name" : "���ż�ɽ",
	"action" : "$N��������һ�֣�����$w�����ӳ���ʹ������ɽ�ɽ���"HIG"�����ż�\nɽ��"NOR"",
	"lvl" : 10
]),
([	"skill_name" : "������ɽ",
	"action" : "$N����$w���϶��µ���$nֱ����ȥ��һ��"HIB"��������ɽ��"NOR"������ʯ\n���쾪�����ƣ�����ɽ����֮�������ӵ����쾡��",
	"lvl" : 20
]),
([	"skill_name" :"ǧ������",
	"action" : "$N����$wͻȻ�佣��һ�£�����һ���׺磬������ΰ������Ʈ�ݣ�\n������ɽ�����ľ�Ҫ���ڣ�һ��"RED"��ǧ��������"NOR"��$n$lֱ�̹���",
	"lvl" : 30
]),
([	"skill_name" :"���両��",
	"action" : "$N����$wͻȻ�佣��һ�£�һ��"GRN"�����両�ࡹ"NOR"����һ����⣬��\n׳�ۻ룬��$n$lֱ�̹���",
	"lvl" : 40
]),
([	"skill_name" : "�����",
	"action" : "$N����$w����һ�£�һ��"HIW"������ء�"NOR"�������࣬������ΰ����\n$n$lֱ�̹���",
	"lvl" : 50
]),
([	"skill_name" : "��������",
	"action" : "$N����$wˢ��һ��������Ҽ�����ȥ������һ����ɽ�����ڽ���\n"HIC"������������"NOR"�����ڽ�ز�������ۻ롣����$w�԰���к��������������\nֱ����������һ������һ��",
	"lvl" : 60
]),
});

int valid_enable(string usage) { return usage=="sword" || usage=="parry"; }
int valid_learn(object me)
{
	object ob;
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("�������������û�а취����ɽ������\n");
	if( (string)me->query_skill_mapped("force")!= "hanbing-zhenqi")
		return notify_fail("��ɽ����������Ϻ���������������\n");
	if( !(ob = me->query_temp("weapon")) ||
		(string)ob->query("skill_type") != "sword" )
		return notify_fail("���������һ�ѽ�������������\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("qi") < 40 || (int)me->query("neili") < 30 )
		return notify_fail("�����������������û����ϰ��ɽ������\n");
	me->receive_damage("qi", 35);
	me->add("neili", -20);
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
	int d_e1 = 5;
	int d_e2 = 25;
	int p_e1 = -25;
	int p_e2 = -5;
	int f_e1 = 100;
	int f_e2 = 150;
	int m_e1 = 120;
	int m_e2 = 210;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("songshan-sword", 1);
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
int learn_bonus() { return 20; }
int practice_bonus() { return 20; }
int success() { return 10; }
int power_point(object me) { return 1.0; }

int valid_effect(object me, object weapon, string name, int skill)
{
}

string perform_action_file(string action)
{
	return __DIR__"songshan-sword/" + action;
}
int help(object me)
{
	write(HIC"\n��ɽ������"NOR"\n");
	write(@HELP

    ��ɽ������������������ɽ���������������ɽ��ף������
�ɣ������嶨�Ľ�����

	ѧϰҪ��
		��������
		����50
HELP
	);
	return 1;
}


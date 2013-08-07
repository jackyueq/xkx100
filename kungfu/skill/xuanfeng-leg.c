// xuanfeng-leg.c ����ɨҶ��
// Last Modified by sir 10.21.2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N˫����Σ�����͵ط���һʽ"HIC"��������ӿ��"NOR"���ż�ζ�������$n��ƨ��",
	"lvl" : 0,
	"skill_name" : "������ӿ"
]),
([	"action" : "$N��Ŷٵأ���ת�����������ߣ�ֻһɲ�Ǽ�һ�����ҽ�һʽ"HIB"���չ�������"NOR"������$n��$l",
	"lvl" : 0,
	"skill_name" : "�չ�����"
]),
([	"action" : "$N����һ��������Ť��ס$n�����֣��ҽ�ͬʱ�߳���������׼��һʽ"GRN"����Ԩ���ԡ�"NOR"�����е�$n���ؿ�",
	"lvl" : 10,
	"skill_name" : "��Ԩ����"
]),
([	"action" : "$NͻȻԾ��˫������Ȧת��һʽ"HIY"�������Ҷ��"NOR"������糾������$n��ȫ��",
	"lvl" : 10,
	"skill_name" : "�����Ҷ"
]),
([	"action" : "$N���ֻ��أ�˫�Ž�������һʽ"HIW"����ɨ���ơ�"NOR"���ŽŲ���$n����������",
	"lvl" : 20,
	"skill_name" : "��ɨ����"
]),
([	"action" : "$NͻȻ����ȴ�����ˣ�һ��ǰ�շ����ҽ����϶���һʽ"HIM "������׹�ء�"NOR"����$n������ֱ������",
	"lvl" : 30,
	"skill_name" : "����׹��"
]),
([	"action" : "$Nʹһʽ"HIW"��˷�紵ѩ��"NOR"��ȫ��ͻȻ������ת��˫���ǰ����Ѹ���޼�����$n���ؿ�",
	"lvl" : 40,
	"skill_name" : "˷�紵ѩ"
]),
([	"action" : "$N����Ծ�𣬿������������һ�����ˣ�һʽ"MAG"���׶����졹"NOR"��˫�������������$n��$l",
	"lvl" : 30,
	"skill_name" : "�׶�����"
]),
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; } 
int valid_combine(string combo) { return combo=="luoying-zhang"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("����ɨҶ�ȱ�����֡�\n");
	if ((int)me->query_skill("bibo-shengong", 1) < 15)
		return notify_fail("��ı̲��񹦻�򲻹����޷�ѧ����ɨҶ�ȡ�\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷�������ɨҶ�ȡ�\n");
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��ı�����ֲ�����ϰ��\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 50)
		return notify_fail("�����������������ɨҶ�ȡ�\n");
	me->receive_damage("qi", 50);
	me->add("neili", -50);
	return 1;
}
string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action)-1; i >= 0; i--)
		if(level >= action[i]["lvl"])
			return action[i]["skill_name"];
}
mapping query_action(object me, object weapon)
{
/* d_e=dodge_effect p_e=parry_effect f_e=force_effect m_e=damage_effect */
	int d_e1 = 5;
	int d_e2 = 25;
	int p_e1 = -45;
	int p_e2 = 30;
	int f_e1 = 350;
	int f_e2 = 450;	
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("xuanfeng-leg", 1);
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
		"damage_type" : random(2) ? "����" : "����",
	]);
}

int learn_bonus() { return 10; }
int practice_bonus() { return 10; }
int success() { return 10; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"xuanfeng-leg/" + action;
}

int help(object me)
{
	write(HIC"\n����ɨҶ�ȣ�"NOR"\n");
	write(@HELP

    ����ɨҶ���Ƕ����һ�������ҩʦ�����书��
    ������Ӣ���ƻ�����

	ѧϰҪ��
		�̲���15��
		����100
HELP
	);
	return 1;
}


// xuantian-zhi.c ��������ָ
// Last Modified by sir 10.22.2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N��ָ�ӳ���һʽ"BLU"����Ȼ���꡹"NOR"������$n����Ե",
	"lvl" : 0,
	"skill_name" : "��Ȼ����"
]),
([	"action" : "$Nȫ��֮������һָ��һʽ"HIC"���������项"NOR"��ָ��$n����ǰ",
	"lvl" : 15,
	"skill_name" : "��������"
]),
([	"action" : "$N�����������Ѩ������һʽ"MAG"��������֡�"NOR"����$n��$l����",
	"lvl" : 25,
	"skill_name" : "�������"
]),
([	"action" : "$N˫Ŀŭ�ӣ�һʽ"CYN"���������ġ�"NOR"��˫ָ����$n�Ķ�����硢�ۡ���
����",
	"lvl" : 45,
	"skill_name" : "��������"
]),
([	"action" : "$Nһʽ"HIR"���������ˡ�"NOR"�������������⣬��ָ���Ƶ���$n��$l",
	"lvl" : 60,
	"skill_name" : "��������"
]),
([	"action" : "$N���������ʮָ�濪��һʽ"HIW"�����߱��项"NOR"��Сָ����$n��̫ԨѨ",
	"lvl" : 70,
	"skill_name" : "���߱���"
]),
([	"action" : "$N˫�ų�������������һʽ"HIG"���������ࡹ"NOR"����$n��ȫ��",
	"lvl" : 80,
	"skill_name" : "��������"
]),
});

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }
int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("����������ָ������֡�\n");
	if ((int)me->query_skill("kuihua-xinfa", 1) < 80)
		return notify_fail("��Ŀ����ķ���򲻹����޷�ѧ��������ָ��\n");
	if ((int)me->query("max_neili") < 150)
		return notify_fail("�������̫�����޷�����������ָ��\n");
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��ı�����ֲ�����ϰ��\n");
	if ((int)me->query("jing") < 40)
		return notify_fail("��ľ�̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("���������������������ָ��\n");
	me->receive_damage("jing", 35);
	me->add("neili", -15);
	return 1;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	if( random(me->query_skill("xuantian-zhi")) > 60 &&
		(victim->query_condition("cold_poison") < 50))
		victim->apply_condition("cold_poison", random(me->query_skill("xuantian-zhi")/20) + 1 + victim->query_condition("cold_poison"));
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
	int d_e1 = 35;
	int d_e2 = 55;
	int p_e1 = -25;
	int p_e2 = -5;
	int f_e1 = 240;
	int f_e2 = 340;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("xuantian-zhi", 1);
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
int learn_bonus() { return 20; }
int practice_bonus() { return 20; }
int success() { return 15; }
int power_point(object me) { return 1.0; }

int help(object me)
{
	write(HIC"\n��������ָ��"NOR"\n");
	write(@HELP

    ������̺�ľ���书��÷ׯ��ׯ���ڰ��ӵ�����ָ����������
���������ھ���������������֮�С�

	ѧϰҪ��
		�����ķ�80��
		����150
HELP
	);
	return 1;
}



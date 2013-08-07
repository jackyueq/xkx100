// heisha-zhang.c ��ɰ��
// Last Modified by winder on Aug. 25 2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$Nһʽ"HIB"���޳�������"NOR"��˫�ֶ���һ�ӣ��ѵ�$n��$l����",
	"lvl"    : 0,
	"skill_name"  : "�޳�����"
]),
([	"action" : "$N����һת��һʽ"BLU"��С�������"NOR"������б�࣬�������У�����$n������",
	"lvl"    : 20,
	"skill_name"  : "С�����"
]),
([	"action" : "$Nʹһʽ"HIB"��ҹ�����ˡ�"NOR"������ǰ�壬˫����ǰ���ŷ����������ĳ���ֱȡ$n��$l",
	"lvl"    : 40,
	"skill_name"  : "ҹ������"
]),
([	"action" : "$Nһʽ"BLU"��ۺ����ɳ��"NOR"������������$n���������ģ���ʵ����",
	"lvl"    : 60,
	"skill_name"  : "ۺ����ɳ"
]),
([	"action" : "$N�������Ʋ��������˳�����£�һʽ"BLU"���ʹ��ඥ��"NOR"������$n��ͷ��",
	"lvl"    : 80,
	"skill_name"  : "�ʹ��ඥ"
]),
([	"action" : "$NͻȻ����һ�٣���Ϊ���ȣ�������ۣ�����"HIB"���ж�������"NOR"",
	"lvl"    : 100,
	"skill_name"  : "�ж�����"
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry" ; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("����ɰ�Ʊ�����֡�\n");
	if ((int)me->query_skill("honghua-shengong", 1) < 10)
		return notify_fail("��ĺ컨�񹦻�򲻹����޷�ѧ��ɰ�ơ�\n");
	if ((int)me->query("max_neili") < 20)
		return notify_fail("�������̫�����޷�����ɰ�ơ�\n");
	return 1;
}
int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 40)
		return notify_fail("���������������ɰ�ơ�\n");
	me->receive_damage("qi", 25);
	me->add("neili", -10);
	return 1;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	if( random(me->query_skill("heisha-zhang")) > 60 &&
		(victim->query_condition("black_poison") < 50))
		victim->apply_condition("black_poison", random(me->query_skill("heisha-zhang")/20) + 1 + victim->query_condition("black_poison"));
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
	int d_e1 = -15;
	int d_e2 = 10;
	int p_e1 = 30;
	int p_e2 = 55;
	int f_e1 = 110;
	int f_e2 = 210;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("heisha-zhang", 1);
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
int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 20; }
int power_point(object me) { return 1.0; }

int help(object me)
{
	write(HIC"\n��ɰ�ƣ�"NOR"\n");
	write(@HELP

    ��ɰ���Ǵ����ڰ��޳����϶��ܵĶ����Ʒ��������̶����޳�������

	ѧϰҪ��
		�컨��10��
		������Ϊ20
HELP
	);
	return 1;
}


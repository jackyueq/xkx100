// wudu-zhang.c �嶾��
// Last Modified by sir 10.22.2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N˫��һ�������ƴ��ŵ��������⣬ֱ��$n��ȥ",
	"lvl" : 0,
	"skill_name" : "�嶾��"
]),
([	"action" : "$N������Σ�����ֱ�������綾��һ��ֱ��$n����ǰ",
	"lvl" : 10,
	"skill_name" : "�嶾��"
]),
([	"action" : "$N˫�Ʒ��ɣ�������ã��һ�ɰ���������������$n��ȫ��",
	"lvl" : 20,
	"skill_name" : "�嶾��"
]),
([	"action" : "$N����һ�֣�������Ы���������ߣ�ͬʱ��$n����ȥ",
	"lvl" : 30,
	"skill_name" : "�嶾��"
]),
([	"action" : "$NĬ��������˫�ƺ�Ȼ��ڣ�����һ������ֻ��$n��ȫ��",
	"lvl" : 40,
	"skill_name" : "�嶾��"
])
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry" ; }
int valid_combine(string combo) { return combo=="qianzhu-wandushou"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("���嶾�Ʊ�����֡�\n");
	if ((int)me->query_skill("wudu-shengong", 1) < 20)
		return notify_fail("����嶾�񹦻�򲻹����޷�ѧ�嶾�ơ�\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷����嶾�ơ�\n");
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��ı�����ֲ�����ϰ��\n");
	if ((int)me->query("qi") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("��������������嶾�ơ�\n");
	me->receive_damage("qi", 25);
	me->add("neili", -10);
	return 1;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	if( random(me->query_skill("qianzhu-wandushou",1)) > 30 )
		victim->receive_wound("qi", damage_bonus/3);
	if ( victim->query("family/family_name")!= "�嶾��" &&
		me->query_skill("wudu-shengong",1)>40)
	{
		switch( random(5) )
		{
			case 0:
				victim->apply_condition("snake_poison", (me->query_skill("wudu-shengong"))/10 + victim->query_condition("snake_poison"));
				break;
			case 1:
				victim->apply_condition("zhizhu_poison", (me->query_skill("wudu-shengong"))/10 + victim->query_condition("zhizhu_poison"));
				break;
			case 2:
				victim->apply_condition("wugong_poison", (me->query_skill("wudu-shengong"))/10 + victim->query_condition("wugong_poison"));
				break;
			case 3:
				victim->apply_condition("xiezi_poison", (me->query_skill("wudu-shengong"))/10 + victim->query_condition("xiezi_poison"));
				break;
			case 4:
				victim->apply_condition("chanchu_poison", (me->query_skill("wudu-shengong"))/10 + victim->query_condition("chanchu_poison"));
				break;
		}
		return HIR"$nֻ�����˴�һ���飬�ƺ��ж��ˡ�\n" NOR;
	}
}
void skill_improved(object me)
{
	if(random(15) < 1 && me->query("per") > 5)
	{
		tell_object(me, HIR"���Ȼ�������ڶ�����ܣ����϶�ʱ����һ�������\n" NOR );
		me->add("per", -1);
	}
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
	int d_e1 = -20;
	int d_e2 = 5;
	int p_e1 = 25;
	int p_e2 = 50;
	int f_e1 = 120;
	int f_e2 = 230;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("wudu-zhang", 1);
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
	write(HIC"\n�嶾�ƣ�"NOR"\n");
	write(@HELP

    �嶾�����嶾�̵Ķ��Ź��򣬿���ǧ�����ֻ�����

	ѧϰҪ��
		�嶾��20��
		����100
HELP
	);
	return 1;
}


// shenghuo-ling.c ʥ���
// Last Modified by sega on Mar. 10 2000

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N̤��һ���������ڵ���һ�����ѱ�ס��$nС�ȡ�ʮָ��ס��$nС���ϵ�
���ж�������������Ѩ��$nֻ���°��������Ѷ������һ��",
         "lvl" : 0
]),
([	"action" : "ͻȻ֮�䣬$N���λζ���ͬʱ�۽�������$w��$n���ϻ�ȥ�����²�֪���
�ƶ���������䡣����ͬʱץס$n���죬һ��֮�£���$n����ԶԶ���˳�ȥ",
	"lvl" : 10
]),
([	"action" : "$N����ֱ�������ֳ�$w��$n����������䡣������һ˲֮�䣬$n��������
��Ȼһȭ����$n���ϡ�$nһ�����ģ�$N���$w����$n����",
	"lvl" : 20
]),
([	"action" : "$N���ط��֣������Ǳ�$wβ�����ϵ����ĵ�һ�죬���ô���$n����",
	"lvl" : 30
]),
([	"action" : "$N��Ȼ��ͷ��һ��ͷ����$nײ����$n������ɫ����������һ�ã�ͻ���ؿ�
һʹ���ѱ�$N����ײ��",
	"lvl" : 40
]),
([	"action" : "$N����$w���Ӻ�ɨ��ͻȻ�����������Ľ��$n��֪�Է��Ǻ����⣬���뻹�Ǳ�֮
Ϊ�������̤��һ������ǰ�׹⼱����$N��$w�ѵ��Ҽ�",
	"lvl" : 50
]),
([	"action" : "$N��Ȼ��ͷ��һ��ͷ����$nײ����$n������ɫ����������һ�ã�ͻ���ؿ�
һʹ���ѱ�$N����ײ��",
	"lvl" : 60
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }
int valid_learn(object me)
{
	int lvl = (int)me->query_skill("shenghuo-ling", 1);

	if ( me->query("gender") == "����" && lvl > 49)
		return notify_fail("�����첻�㣬��ѧ��ȥ�����߻���ħ��\n");
	if ((int)me->query("max_neili") < 50)
		return notify_fail("����ô����������ѧʥ�����\n");
	if ((int)me->query_skill("jiuyang-shengong", 1) < 20)
		return notify_fail("��ľ����񹦻�򲻹���ѧ����ʥ�����\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("qi") < 35 || (int)me->query("neili") < 15 )
		return notify_fail("�����������������ʥ�����\n");
	me->receive_damage("qi", 30);
        me->add("neili", -15);
	return 1;
}
mapping query_action(object me, object weapon)
{
/* d_e=dodge_effect p_e=parry_effect f_e=force_effect m_e=damage_effect */
	int d_e1 = 20;
	int d_e2 = 40;
	int p_e1 = -10;
	int p_e2 = 10;
	int f_e1 = 100;
	int f_e2 = 150;
	int m_e1 = 70;
	int m_e2 = 160;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("shenghuo-ling", 1);
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
int power_point(object me)
{
	if( me->query_skill("qiankun-danuoyi", 1) < 100) return 1.0;
	if( me->query_skill("qiankun-danuoyi", 1) > 250) return 2.0;
	return (me->query_skill("qiankun-danuoyi", 1)-100)/150+1;
}

string perform_action_file(string action)
{
	return __DIR__"shenghuo-ling/" + action;
}

int help(object me)
{
	write(HIR"\nʥ�����"NOR"\n");
	write(@HELP

    ʥ���������ʥ��ʥ�����ϵ��书��������ʽ�����ޱȶ���
��֮���ֲ���������ʥ����֮�����ԣ����������ޱȡ�

	ѧϰҪ��
		������20��
		����50
		̫���޷���ϰ50�����ϵ�ʥ���
HELP
	);
	return 1;
}


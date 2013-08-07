// duanyun-fu.c ���Ƹ�
// Last Modified by sega on Mar. 10 2000

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N����ڿ�Ծ��˫�ֽ���$w����׼$n��ͷ�������϶��µؿ�����ȥ��\nֻ�ڰ��������һ�ž޴�ĺ�Ӱ",
	"lvl" : 0,
	"skill_name" : "����ٵ�"
]),
([	"action" : "$NͻȻ��һ��������ǰ����������$w���¶��Ϸ���$n����·��$n����һ\n������ɫ����Ӱ�����Լ�����֪�����æ�м�",
	"lvl" : 20,
	"skill_name" : "��������"
]),
([	"action" : "$N��Ȼ����һ��������б����ǰ�����һ��������΢�Σ�����$w�ڿ���\n����һ����Ӱ�����ٺ�ɨ$n���Ҽ磬��������",
	"lvl" : 40,
	"skill_name" : "��ɨǧ��"
]),
([	"action" : "$NͻȻ�������ҹ������漴���𣬾��������һ˲�䣬�ѵ�������$w��\n��$n�����ߣ����ּȿ��Һ�",
	"lvl" : 60,
	"skill_name" : "����Ϊ��"
]),
([	"action" : "$N˫�ֺ��$w��ƽɨ$nǰ�أ���ʽδʹ�Ͼ��Ѵ�ס�Ȼ���У�����ֱײ\n$n��С����",
	"lvl" : 80,
	"skill_name" : "��ײ��"
]),
([	"action" : "$N����������ת��΢�ף�$n��$N¶����������æ������ȴͻȻ����$N��\n������ת����������$w��Ѹ�͵�ɨ���Լ�������",
	"lvl" : 100,
	"skill_name" : "�ط�ת��"
]),
([	"action" : "$N����΢��������ͬһʱ�������������ҿ����師��$n�����$w�Ӳ�ͬ\n�ķ�λ�����Լ���һʱ�侹��֪������м�",
	"lvl" : 120,
	"skill_name" : "�師����"
]),
([	"action" : "$Nǰ���͵�������һ�٣����Ҳ΢΢һ�𣬽��ž���ͷ��ͷ����ת
��\nȦ��$w����������֮��ƽֱ�����ȵ�Ϯ��$n��$n������δ����㣬�ܿ���������\n�Լ�����һ�ߣ����ɴ�ʧɫ",
	"lvl" : 150,
	"skill_name" : "һ������"
])
});

int valid_enable(string usage) { return usage=="axe" ||	usage=="parry"; }

int valid_learn(object me)
{
	if ((int)me->query_skill("kurong-changong", 1) < 20)
		return notify_fail("��Ŀ���������򲻹����޷�ѧ���Ƹ���\n");
	if ((int)me->query("max_neili") < 150)
		return notify_fail("�������̫�����޷������Ƹ���\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;
	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "axe")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("����������������Ƹ���\n");
	me->receive_damage("qi", 35);
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
	int d_e1 = 60;
	int d_e2 = 30;
	int p_e1 = -30;
	int p_e2 = -60;
	int f_e1 = 200;
	int f_e2 = 400;
	int m_e1 = 300;
	int m_e2 = 500;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int)me->query_skill("duanyun-fu", 1);
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
int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 5; }
int power_point(object me)
{
	return 1;
}
string perform_action_file(string action)
{
	return __DIR__"duanyun-fu/" + action;
}

int help(object me)
{
	write(HIC"\n���Ƹ���"NOR"\n");
	write(@HELP

    ���Ƹ�Ϊ���ϴ���μҵ��书��

	ѧϰҪ��
		��������20��
		����150
HELP
	);
	return 1;
}


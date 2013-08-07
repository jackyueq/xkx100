// lianhua-zhang.c ������
// Last Modified by qingyun 2005.1.9

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$Nʹ�������������ơ�С�������������ƻ��أ����ƻ�������$n��$l",
	"lvl" : 0,
	"skill_name" : "С������"
]),
([	"action" : "$N����һ�������ֻ��أ�����һ�ǡ�ǧҶ����������һ���Ʒ磬ֱ��$n��$l",
	"lvl" : 20,
	"skill_name" : "ǧҶ����"
]),
([	"action" : "$Nһʽ���������������Ծ��ֱ��$n��˫�ƻû�����ʮ����Ӱ������������$n",
	"lvl" : 40,
	"skill_name" : "�������"
]),
([	"action" : "$N��¶΢Ц��һ�С�Ҷ����ɡ�����һ�ڣ����ƻ���һ������Ļ��ߣ�ֱ��$n��$l",
	"lvl" : 80,
	"skill_name" : "Ҷ�����"
]),
([	"action" : "$Nʹ����˫�����ޡ���˫�Ʒɿ��趯����$nȦ���Ʒ�֮�ڣ����ۻ����Ҽ���Ȼ�ĳ�",
	"lvl" : 100,
	"skill_name" : "˫������"
]),
([	"action" : "$N˫��΢�Ż���ǰ̽��˫����ֱ��ͻȻ�仯Ϊ�ƣ�һʽ�����ط��ۡ�����$n��$l",
	"lvl" : 120,
	"skill_name" : "���ط���"
]),
([	"action" : "$N����$n�������ߣ�ʹ������Ұ���㡹�����紩�����������·��裬����$n��$l",
	"lvl" : 140,
	"skill_name" : "��Ұ����"
]),
([	"action" : "ɲ�Ǽ�$N�������ͻȻʹ��һ�С��������������һ�Ʊ���$n��$l��ȥ",
	"lvl" : 160,
	"skill_name" : "�������"
]),
([	"action" : "$N���ƻ��أ���������ǰһ�Σ�ͻ�ش�Ҹ�´�����һʽ����ź������ֱ��$n$l",
	"lvl" : 180,
	"skill_name" : "��ź����"
]),
([	"action" : "ֻ��$Nʹһ�С�ź��˿���������ƻζ���ƽ�٣�����ҡ�ڲ����л���ԲȦ����$n",
	"lvl" : 200,
	"skill_name" : "ź��˿��"
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }	
int valid_combine(string combo) { return combo=="suohou-hand"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�������Ʊ�����֡�\n");
	if ((int)me->query_skill("huntian-qigong", 1) < 20)
		return notify_fail("��Ļ���������򲻹����޷�ѧ�����ơ�\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷��������ơ�\n");
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��ı�����ֲ�����ϰ��\n");
	if ((int)me->query("qi") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("������������������ơ�\n");
	me->receive_damage("qi", 30);
	me->add("neili", -15);
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
	int d_e1 = -25;
	int d_e2 = -5;
	int p_e1 = 15;
	int p_e2 = 45;
	int f_e1 = 210;
	int f_e2 = 310;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("lianhua-zhang", 1);
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
int learn_bonus() { return 25; }
int practice_bonus() { return 25; }
int success() { return 15; }
int power_point() { return 1.0; }

int help(object me)
{
	write(HIC"\n�����ƣ�"NOR"\n");
	write(@HELP

    ������Ϊ���߹�����֮һ��
    �������������ֻ�����

	ѧϰҪ��
		��������20��
		����100
HELP
	);
	return 1;
}


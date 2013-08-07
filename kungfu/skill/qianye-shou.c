// qianye-shou.c ����ǧҶ��
// Last Modified by sir 10.22.2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$Nһʽ"HIB"���Ϻ����"NOR"��������Σ���������ͻȻ����$n�ı����Ѩ",
	"lvl" : 0,
	"skill_name" : "�Ϻ����"
]),
([	"action" : "$N����һ�Σ�һʽ"HIY"������������"NOR"����������$n�ļ�ͷ����ȭ����$n���ؿ�",
	"lvl" : 10,
	"skill_name" : "��������"
]),
([	"action" : "$Nһʽ"HIG"������������"NOR"�����ֻ�£��צ��һ���־����$n���ʺ�Ҫ��",
	"lvl" : 20,
	"skill_name" : "��������"
]),
([	"action" : "$N�������У�����ֱ����һʽ"HIW"�������Ӱ��"NOR"����Ʈ��������$n������",
	"lvl" : 30,
	"skill_name" : "�����Ӱ"
]),
([	"action" : "$Nʹһʽ"CYN"��ˮ��׽�¡�"NOR"����ȭ�ϸ�����̽��ͻ����ץ��$n���ɲ�",
	"lvl" : 38,
	"skill_name" : "ˮ��׽��"
]),
([	"action" : "$N˫ȭ���裬һʽ"HIC"������ȥ����"NOR"�����ֻ��ۣ�£��Ȧ״���ͻ�$n�����",
	"lvl" : 45,
	"skill_name" : "����ȥ��"
]),
([	"action" : "$Nһʽ"HIM"��ˮ�ݳ�û��"NOR"��ʮָ����������ʵʵ��Ϯ��$n��ȫ��ҪѨ",
	"lvl" : 51,
	"skill_name" : "ˮ�ݳ�û"
]),
([	"action" : "$N˫�ֱ�ȭ��һʽ"RED"������������"NOR"����Ӱ���ɣ�ͬʱ��$nʩ���žŰ�ʮһ��",
	"lvl" : 56,
	"skill_name" : "��������"
]),
([	"action" : "$Nһʽ"HIR"������տա�"NOR"��ȭ���������֣��������ޣ�����������$n�ĵ���",
	"lvl" : 60,
	"skill_name" : "����տ�"
]),
});

int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }	
int valid_combine(string combo) { return combo=="longzhua-gong"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("������ǧҶ�ֱ�����֡�\n");
	if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
		return notify_fail("��Ļ�Ԫһ������򲻹����޷�ѧ����ǧҶ�֡�\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷�������ǧҶ�֡�\n");
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��ı�����ֲ�����ϰ��\n");
	if ((int)me->query("qi") < 40)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 40)
		return notify_fail("�����������������ǧҶ�֡�\n");
	me->receive_damage("qi", 35);
	me->add("neili", -25);
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
	int d_e1 = -50;
	int d_e2 = -15;
	int p_e1 = 15;
	int p_e2 = 40;
	int f_e1 = 160;
	int f_e2 = 260;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("qianye-shou", 1);
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
int learn_bonus() { return 15; }
int practice_bonus() { return 15; }
int success() { return 10; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"qianye-shou/" + action;
}

int help(object me)
{
	write(HIC"\n����ǧҶ�֣�"NOR"\n");
	write(@HELP

    ����ǧҶ��Ϊ������ʮ������֮һ��
    ������צ��������

	ѧϰҪ��
		��Ԫһ����20��
		����100
HELP
	);
	return 1;
}


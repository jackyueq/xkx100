// kuaihuo-strike.c ���ʮ����
// Last Modified by sir 10.22.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N����һȭֱ���������翪�Ʊգ���ס�Է����֣����°��������ȣ�����"GRN"��ʹ�����졹"NOR"",
	"lvl"    : 0,
	"skill_name" : "ʹ������"
]),
([	"action" : "$N����һ�Ʒ���$n���ţ����ư��������Ƿ�ס$n���ߣ�����ֱȭ����$n�ؿڣ�����һ��"HIG"���������ܡ�"NOR"",
	"lvl"    : 20,
	"skill_name" : "��������"
]),
([	"action" : "$N������ֱ�濪������$n���ţ����ֻӶ�������$n����������Ѩ������"HIB"�����»��ȡ�"NOR"",
	"lvl"    : 40,
	"skill_name" : "���»���"
]),
([	"action": "$Nʹ��"HIR"������Χ¯��"NOR"��˫����$n���屧ȥ�����г��ȼ���$n$l",
	"lvl"    : 60,
	"skill_name" : "����Χ¯"
]),
([	"action" : "$Nʹ��"MAG"��������÷��"NOR"�����������£�бб��$n�������£�������ָ��������÷֦б����ָ��$n",
	"lvl"    : 80,
	"skill_name" : "������÷"
]),
([	"action" : "$N����ʹ�������Ź���˫�ֳ�������״��Ƭ�̼���ָ��$n��ǣ�����һ��"HIW"�������þơ�"NOR"",
	"lvl"    : 100,
	"skill_name" : "�����þ�"
]),
([	"action" : "$N������ֱָ��������$n������Ѩ�����ֳɺ��λ���������"HIM"��Ū�����١�"NOR"",
	"lvl"    : 120,
	"skill_name" : "Ū������"
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }
int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�����ʮ���Ʊ�����֡�\n");
	if ((int)me->query_skill("panshi-shengong", 1) < 20)
		return notify_fail("����ʯ�񹦻�򲻹����޷�ѧ���ʮ���ơ�\n");
	if ((int)me->query("max_neili") < 50)
		return notify_fail("�������̫�����޷������ʮ���ơ�\n");
	return 1;
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 40)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 40)
		return notify_fail("����������������ʮ���ơ�\n");
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
	int d_e1 = -30;
	int d_e2 = -5;
	int p_e1 = 15;
	int p_e2 = 40;
	int f_e1 = 150;
	int f_e2 = 260;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("kuaihuo-strike", 1);
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
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"kuaihuo-strike/" + action;
}

int help(object me)
{
	write(HIC"\n���ʮ���ƣ�"NOR"\n");
	write(@HELP

    ���ʮ������̩ɽ�ɵ��书��

	ѧϰҪ��
		��ʯ��20��
		����50
HELP
	);
	return 1;
}


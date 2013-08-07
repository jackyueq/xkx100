// chuanyun-leg.c �����ȷ�
// Last Modified by winder on Sep. 27 2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N���Ӽ�ת���ҽ����������һʽ"BLU"������Ϊ�Ρ�"NOR"����ɨ$n������",
	"lvl" : 0,
	"skill_name" : "����Ϊ��"
]),
([	"action" : "$N�����߳��������������£��ҽŽ���������߳���һʽ"GRN"��׷����硹"NOR"��˫���Ⱥ�����$n��$l",
	"lvl" : 15,
	"skill_name" : "׷�����"
]),
([	"action" : "$Nһʽ"MAG"�����Ҵ�����"NOR"����ź��ߣ��漴����ǰ���䲽���ҽ�Ѹ�ٷ�������$n��$l",
	"lvl" : 30,
	"skill_name" : "���Ҵ���"
]),
([	"action" : "$NͻȻһ���󷭣�һʽ"HIW"�����߱�����"NOR"��˫�Ȼζ�����$n��$l��ȥ",
	"lvl" : 45,
	"skill_name" : "���߱���"
]),
([	"action" : "$Nʹһʽ"HIC"�����Ʋ��¡�"NOR"���εض���˫�������߳�������$n���ؿ�",
	"lvl" : 60,
	"skill_name" : "���Ʋ���"
]),
([	"action" : "$N������������һʽ"HIY"����ɨ���ݡ�"NOR"�����Ⱥ�ɨ$n��$l",
	"lvl" : 75,
	"skill_name" : "��ɨ����"
]),
([	"action" : "$N����һ�ƣ������$n��ͷ����һʽ"HIB"����Ӱ���١�"NOR"������ͻȻ����$n��$l",
	"lvl" : 90,
	"skill_name" : "��Ӱ����"
]),
([	"action" : "$Nʹһʽ"HIR"���������¡�"NOR"��������ն���˫��������ֻ��������Ӱ������$n",
	"lvl" : 100,
	"skill_name" : "��������"
]),
});

int valid_enable(string usage) { return usage=="leg" || usage=="parry"; }
int valid_combine(string combo) { return combo=="zhentian-cuff"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�������ȱ�����֡�\n");
	if ((int)me->query_skill("xuantian-wuji", 1) < 20)
		return notify_fail("��������޼�����򲻹����޷�ѧ�����ȡ�\n");
	if ((int)me->query("max_neili") < 50)
		return notify_fail("�������̫�����޷��������ȡ�\n");
	return 1;
}
int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 15)
		return notify_fail("������������������ȡ�\n");
	me->receive_damage("qi", 25);
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
	int d_e1 = -40;
	int d_e2 = -10;
	int p_e1 = -5;
	int p_e2 = 25;
	int f_e1 = 200;
	int f_e2 = 300;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("chuanyun-leg", 1);
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
int success() { return 10; }
int power_point(object me) { 
	if (me->query("gender")=="Ů��")
	  return 1.2;
	else 
	  return 0.8;
}

string perform_action_file(string action)
{
	return __DIR__"chuanyun-leg/" + action;
}

int help(object me)
{
	write(HIC"\n�����ȣ�"NOR"\n");
	write(@HELP

    �������������ɲ���Ů���ӵ��书��

	ѧϰҪ��
		�����޼���20��
		����50
HELP
	);
	return 1;
}


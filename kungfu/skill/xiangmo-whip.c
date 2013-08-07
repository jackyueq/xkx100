// Last Modified by winder on May. 29 2001
// xiangmo-whip ��ħ��

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action": "$NԾ�����ɣ����ڰ�գ���ʽ���䣬$w�羪�κ��ˣ���$n�������",
	"lvl" : 0,
	"skill_name" : "�����İ�",
]),
([	"action": "$N��ʽһ�䣬���е�$w����һ�����������·��ڵ�Ϯ��$n��$l",
	"lvl" : 20,
	"skill_name" : "��������",
]),
([	"action": "$N����$wǰ���趯��һ�С�����չ�᡹���ޱ޽Դ���$n��$l��",
	"lvl" : 60,
	"skill_name" : "����չ��",
]),
([	"action": "$N����$w�ն����޷���ӿ��ȥʽ�����������ɨֱ����������������̼��ѽ�$nȫ���ס",
	"lvl" : 90,
	"skill_name" : "�����ѩ",
]),
([	"action": "$N����$wȦȦ��㣬��ʽ���࣬����ʹ��һ�С���ħʽ����$w�Ϸ��������������Ӱ������˷���$n����Ҫ������",
	"lvl" : 120,
	"skill_name" : "��ħʽ",
]),
});

int valid_enable(string usage) { return (usage=="whip") || (usage=="parry"); }
int valid_learn(object me)
{
	object weapon;

	if ((int)me->query("max_neili") < 500)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("zhanzhuang-gong", 1) < 50)
		return notify_fail("���վ׮�����̫ǳ��\n");
	if ((int)me->query_skill("jiujie-whip",1) < 20)
		return notify_fail("��ľŽڱ���Ϊ���㣬û�а취����ħ�ޡ�\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;
	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "whip")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("qi") < 30 || (int)me->query("neili") < 30 )
		return notify_fail("��������������Žڱ޷���\n");
	me->receive_damage("qi", 25);
	me->add("neili", -25);
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
	int d_e1 = -50;
	int d_e2 = -40;
	int p_e1 = 0;
	int p_e2 = 10;
	int f_e1 = 100;
	int f_e2 = 150;
	int m_e1 = 250;
	int m_e2 = 400;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("xiangmo-whip", 1);
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

int learn_bonus() { return 10; }
int practice_bonus() { return 10; }
int success() { return 10; }
int power_point() { return 1.0; }
 
int help(object me)
{
	write(HIC"\n��ħ�ޣ�"NOR"\n");
	write(@HELP

    ��ħ���������ָ߼��޷���

	ѧϰҪ��
		վ׮��50��
		�Žڱ�20��
		������Ϊ500
HELP
	);
	return 1;
}


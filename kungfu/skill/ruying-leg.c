// Last Modified by winder on May. 29 2001
// ruying-leg.c ��Ӱ������ ���ܻ��� ȡ�Է��С����;�����

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N������ǰ����Ȼ���������ȣ�һʽ"HIC"������ͬ�⡹"NOR"�������ɰֱ��$n��$l",
	"lvl"   : 0,
	"skill_name" : "����ͬ��"
]),
([	"action" : "$N����һ����˫��һ��Ծ����У�һʽ"HIM"�����ͬ�ޡ�"NOR"���ڰ�������߽ţ�ֱ��$n$l",
	"lvl"   : 10,
	"skill_name" : "���ͬ��"
]),
([	"action" : "$N����ǰ�㣬��Ż�Բ����ն�������˳��ʹ��һʽ"HIW"�����ͬס��"NOR"����ɨ$n$l",
	"lvl"   : 30,
	"skill_name" : "���ͬס"
]),
([	"action" : "$Nһ�Բ���������ٿ�ص������������ȣ�����$n��ͷ���أ���������һʽ"HIB"���ں��޾���"NOR"",
	"lvl"   : 60,
	"skill_name" : "�ں��޾�"
]),
([	"action" : "$N���������������ת�����������η�ת��ɨ��һ��"HIR"�����ͬ�á�"NOR"�����𾢷�ɨ��$n$l",
	"lvl"   : 100,
	"skill_name" : "���ͬ��"
]),												
([	"action" : "$NԾ���ڰ�գ�˫������������磬һʽ"HIW"������ͬ����"NOR"��ȫ����ת���£�Ѹ�����׵غ���$n",
	"lvl"   : 150,
	"skill_name" : "����ͬ��"
]),
});

int valid_enable(string usage) { return usage=="leg" || usage=="parry"; }
int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("ѧ��Ӱ������ʱ���ﲻ����������\n");
	if ((int)me->query_skill("zhanzhuang-gong", 1) < 120)
		return notify_fail("���վ׮����򲻹����޷�ѧ��Ӱ�����ȡ�\n");
	if ((int)me->query("max_neili") < 1500)
		return notify_fail("�������̫�����޷�����Ӱ�����ȡ�\n");
	if ((me->query_skill("shaolin-leg", 1) < 50) ||
		(me->query_skill("boruo-strike", 1) < 50))
		return notify_fail("������ֵ��ȺͰ����ƻ�򲻹����޷�ѧ��Ӱ�����ȡ�\n");
	return 1;
}
int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("��ľ���̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("���������������Ӱ�����ȡ�\n");
	me->receive_damage("qi", 50);
	me->add("neili", -20);
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
	int d_e2 = -20;
	int p_e1 = -10;
	int p_e2 = 20;
	int f_e1 = 300;
	int f_e2 = 400;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("ruying-leg", 1);
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
int learn_bonus() { return 10; }
int practice_bonus() { return 10; }
int success() { return 5; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	 return __DIR__"ruying-leg/" + action;
}

int help(object me)
{
	write(HIC"\n��Ӱ�����ȣ�"NOR"\n");
	write(@HELP

   ��Ӱ�������������ָ߼��ȷ������ܻ��������Է��С����;�����

	ѧϰҪ��
		վ׮��120��
		���ֵ���50��
		������50��
		������Ϊ1500
HELP
	);
	return 1;
}


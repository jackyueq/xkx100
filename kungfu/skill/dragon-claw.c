// Last Modified by Winder on May. 29 2001
// dragon-claw.c ��צ�� �Ͱ����ƻ��� ȡ�ԡ����������ǡ���

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "�ں��������У�$Nʹһ��"CYN"������ʽ��"NOR"��˫���繳��ꫣ�����$n������$p��$l",
	"lvl"    : 0,
	"skill_name" : "����ʽ" ,		
]),
([	"action" : "$N�͵���ǰԾ����һ��"BLU"��׽Ӱʽ��"NOR"������$n���ߣ�����˫����ץ�����в���$n������",
	"lvl"    : 10,
	"skill_name" : "׽Ӱʽ" ,		
]),
([	"action" : "$N˫��ƽ�죬ʮָ΢΢���¶���������$n��$l������һ�л�����"GRN"������ʽ��"NOR"",
	"lvl"    : 20,
	"skill_name" : "����ʽ" ,		
]),
([	"action" : "$N���������������ڻӿ�ץ��������ȭ��һ��"YEL"������ʽ��"NOR"����$n�ؿڣ�ȴ�������ޱ�",
	"lvl"    : 30,
	"skill_name" : "����ʽ" ,		
]),
([	"action" : "$N�������գ�����������ɽ��һ��"MAG"������ʽ��"NOR"��ͻȻ���У������ҳ����͵ػ���$n��$l",
	"lvl"    : 40,
	"skill_name" : "����ʽ" ,		
]),
([	"action" : "$N�ڲ���ǰ�����ֻ��أ�����̽������һ��"HIW"������ʽ��"NOR"ץ��$n��$l��ʹ��ʹ������",
	"lvl"    : 50,
	"skill_name" : "����ʽ" ,		
]),
([	"action" : "$N˫��ƽ����ǰ�����ֻ�ס���ţ�һ��"HIB"������ʽ��"NOR"������һת������$n���ԣ���������$p��$l",
	"lvl"    : 60,
	"skill_name" : "����ʽ" ,		
]),
([	"action" : "$N������ǰ������Ҹ�º��գ�һצ��������ָ�繳��һ��"HIM"����ȱʽ��"NOR"����$n�Ķ���",
	"lvl"    : 70,
	"skill_name" : "��ȱʽ" ,		
]),
([	"action" : "$N����б��$n����֮�䣬һ��"HIR"������ʽ��"NOR"������ȡĿ�յУ����ַ���$n��$l",
	"lvl"    : 80,
	"skill_name" : "����ʽ" ,		
]),
([	"action" : "$Nһ����ָ$n�Ľ�����һ��"CYN"���ὣʽ��"NOR"��һ������ץ��$n��ץ���пգ��·����г���",
	"lvl"    : 100,
	"skill_name" : "�ὣʽ" ,		
]),
([	"action" : "$N����ץ��$n��ǰ�������Ѩ������б��̫��Ѩ��һ��"HIW"������ʽ��"NOR"ʹ��$n��������",
	"lvl"    : 120,
	"skill_name" : "����ʽ" ,		
]),
([	"action" : "$Nǰ���ŵأ�һ�ֶ����צ��һ��ָ�أ�һ��"RED"��׷��ʽ��"NOR"�����������������$n��ȫ��",
	"lvl"    : 150,
	"skill_name" : "׷��ʽ" ,		
])
});

int valid_enable(string usage) { return usage=="claw" || usage=="parry"; }
int valid_combine(string combo){ return combo=="boruo-strike"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("����צ��������֡�\n");
	if ((int)me->query_skill("zhanzhuang-gong", 1) < 80)
		return notify_fail("���վ׮����򲻹����޷�ѧ��צ����\n");
	if ((int)me->query("max_neili") < 800)
		return notify_fail("�������̫�����޷�����צ����\n");
	if ((me->query_skill("nianhua-finger", 1) < 50) ||
		(me->query_skill("eagleg-claw", 1) < 50))
		return notify_fail("����黨ָ��ӥצ����򲻹����޷�ѧ��צ����\n");
	return 1;
}
int practice_skill(object me)
{
	if ((int)me->query("qi") < 55)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 30)
		return notify_fail("���������������צ����\n");
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
	int d_e1 = 30;
	int d_e2 = 5;
	int p_e1 = -20;
	int p_e2 = -50;
	int f_e1 = 300;
	int f_e2 = 450;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int)me->query_skill("dragon-claw", 1);
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
		"damage_type" : random(2) ? "����" : "ץ��",
	]);
}
int learn_bonus() { return 10; }
int practice_bonus() { return 5; }
int success() { return 10; }
int power_point(object me) { return 1; }

string perform_action_file(string action)
{
	return __DIR__"dragon-claw/" + action;
}

int help(object me)
{
	write(HIC"\n��צ����"NOR"\n");
	write(@HELP

    ��צ����������צ�����Ͱ����ƻ�����

	ѧϰҪ��
		վ׮��80��
		�黨ָ50��
		ӥצ��50��
		������Ϊ800
HELP
	);
	return 1;
}


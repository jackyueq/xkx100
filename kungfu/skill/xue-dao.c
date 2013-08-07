// xue-dao.c Ѫ��
// Last Modified by sega on Mar. 10 2000

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N�߾�����$w,ʹ��һ��"RED"��ĥ��˱Ѫ��"NOR"��һ��б��$n��$l",
	"skill_name" : "ĥ��˱Ѫ",
	"lvl" : 0,
]),
([	"action" : "$N�͵�һ����ʹһ��"HIR"����Ѫ���ء�"NOR"������$w����$n�Ĵ���",
	"skill_name" : "��Ѫ����",
	"lvl" : 8,
]),
([	"action" : "$N���һ�㣬ʹ��"RED"��Ѫ��ãã��"NOR"���������϶���ֱ��$n��$l",
	"skill_name" : "Ѫ��ãã",
	"lvl" : 16,
]),
([	"action" : "$Nʹ��һ��"HIR"��Ż����Ѫ��"NOR"����$w��������һ��ѹ��$n",
	"skill_name" : "Ż����Ѫ",
	"lvl" : 24,
]),
([	"action" : "$N�ͺ�һ����ʹ��"RED"��Ѫ�����ˡ�"NOR"����$wֱ��$n��$l",
	"skill_name" : "Ѫ������",
	"lvl" : 32,
]),
([	"action" : "$Nʹ��"HIR"��Ѫ���߰ߡ�"NOR"������б�̣���Ȼ����һ����ն$n������",
	"skill_name" : "Ѫ���߰�",
	"lvl" : 40,
]),
([	"action" : "$Nʹһʽ"RED"����Ѫ��Ѫ��"NOR"���ӵ�ֱָ$n���ؿ�",
	"skill_name" : "��Ѫ��Ѫ",
	"lvl" : 48,
]),
([	"action" : "$N������㣬ʹ��һ��"HIR"��Ѫ�����桹"NOR"��ת���$w����$n������",
	"skill_name" : "Ѫ������",
	"lvl" : 56,
]),
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }
int valid_combine(string combo) { return combo=="mingwang-jian"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 50)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("longxiang", 1) >= 20 ||
		(int)me->query_skill("xiaowuxiang", 1) >= 20)
		return 1;
	else return notify_fail("��ı����ڹ����̫ǳ��\n");
}
int practice_skill(object me)
{
	object weapon;

	if(!me->query_skill("longxiang",1) && !me->query_skill("xiaowuxiang",1))
		return notify_fail("��Ѫ������Ҫ��ѩɽ�ɵ��ڹ���Ϊ������\n");
	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("��ʹ�õ��������ԡ�\n"); 
	if ((int)me->query("qi") < 50)
		return notify_fail("������������������ˡ�Ѫ������\n");

	me->receive_damage("qi", 30);
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
	int d_e1 = 35;
	int d_e2 = 15;
	int p_e1 = -15;
	int p_e2 = -35;
	int f_e1 = 100;
	int f_e2 = 200;
	int m_e1 = 150;
	int m_e2 = 260;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int)me->query_skill("xue-dao", 1);
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
int power_point(object me) { return 1; }

string perform_action_file(string action)
{
	return __DIR__"xue-dao/" + action;
}
int help(object me)
{
	write(HIR"\nѪ����"NOR"\n");
	write(@HELP

    Ѫ���ǲر�Ѫ����Ѫ��������������Ϊѩɽ�����Ź���

	ѧϰҪ��
		�����������С���๦20��
		����50
HELP
	);
	return 1;
}


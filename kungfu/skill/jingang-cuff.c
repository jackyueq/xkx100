// Last Modified by winder on May. 29 2001
// jingang-cuff.c ����ȭ ���ܻ��� ���Է���֮������������

#include <ansi.h>;
inherit "/inherit/skill/cuff.c";
string type() { return "martial"; }
string martialtype() { return "skill"; }
 
mapping *action = ({
([	"action" : "$N˫��һ�ӣ���һʽ"HIY"��������"NOR"�������ͨ��֮�ƣ�ȭ��������������ֱ��$n��ȥ",
	"lvl"   : 0,
	"skill_name" : "����"
]),
([	"action" : "$N�������������һ�գ�����һ����ǽ������������ȭ������$n��һ��"HIY"����˼��"NOR"��ǽ����",
	"lvl" : 10,
	"skill_name" : "��˼"
]),
([	"action" : "$Nһ����ʽ"HIY"����ҵ��"NOR"��˫ȭ���������������ಢ����׼$n$lһʽ�ӳ��������쳣",
	"lvl" : 20,
	"skill_name" : "��ҵ"
]),
([	"action" : "$Nʹ��һ��"HIY"�����"NOR"��˫�������Ӷ���ȭ����ſ��е�ʨ�Ӻ���������ɽ��Ϯ��$n",
	"lvl" : 40,
	"skill_name" : "����"
]),
([	"action" : "$N��������һʽ"HIY"��������"NOR"�������������һȭ���棬������ǰ�ˣ����������ϻ�$n",
	"lvl" : 60,
	"skill_name" : "����"
]),
([	"action" : "$N�ӳ���ȭ������$n�����⻨ȭ֮��ʱ��һ�ɾ��籬��������$p�ؿڣ�������ʵ��"HIY"�����ڡ�"NOR"",
	"lvl" : 70,
	"skill_name" : "����"
]),
([	"action" : "$N���̷𾭣����һ��"HIY"�����"NOR"��ֱ��$nǰ�أ�ȭ�������������������������˿������",
 	"lvl" : 80,
	"skill_name" : "����"
]),
([	"action" : "ֻ��$N��ʮ����������"HIY"��������"NOR"һ��Ϊ��������Ϊȭ����������ȫ������ѹ��$n",
	"lvl" : 100,
	"skill_name" : "����"
]),
});

int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }
int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		 return notify_fail("������ȭ������֡�\n");
	if ((int)me->query_skill("zhanzhuang-gong", 1) < 140)
		 return notify_fail("���վ׮����򲻹����޷�ѧ����ȭ��\n");
	if ((int)me->query("max_neili") < 2000)
		return notify_fail("�������̫�����޷�������ȭ��\n");
	if ((me->query_skill("shaolin-cuff", 1) < 50) ||
		(me->query_skill("one-finger", 1) < 50))
		return notify_fail("���������ȭ��һָ����򲻹����޷�ѧ����ȭ��\n");
	return 1;
}
int practice_skill(object me)
{
	if ((int)me->query("qi") < 50)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("�����������������ȭ��\n");
	me->receive_damage("qi", 45);
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
	int d_e1 = 20;
	int d_e2 = 40;
	int p_e1 = -40;
	int p_e2 = -20;
	int f_e1 = 210;
	int f_e2 = 410;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("jingang-cuff", 1);
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
		"damage_type" : "����",
	]);
}
int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 5; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"jingang-cuff/" + action;
}

int help(object me)
{
	write(HIC"\n����ȭ��"NOR"\n");
	write(@HELP

    ����ȭ�������ָ߼�ȭ�������Է���֮������������

	ѧϰҪ��
		վ׮��140��
		������ȭ50��
		һָ��50��
		������Ϊ2000

HELP
	);
	return 1;
}


// yunlong-jian.c ������
// Last Modified by sir 10.22.2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action":"\n$Nʹһʽ"GRN"����һ�С�"NOR"������$w����΢�񣬻ó�һ���׹����$n��$l",
	"lvl" : 0,
		"dodge"       : -100000,
		"parry"       : -100000,
		"force"       : 1,
		"damage"      : 1,
	"skill_name" : "����˳��Ȼ"
]),
([	"action" : "$Nļ��ʹһ��"HIR"���ڶ��С�"NOR"����ʱ�����м���Ѫ������$nȫ��",
		"dodge"       : 100000,
		"parry"       : 100000,
		"force"       : 1,
		"damage"      : 1,
	"lvl" : 0,
	"skill_name" : "��Ҷ����ɽ"
]),
([	"action" : "$Nļ��ʹһ��"HIR"�������С�"NOR"����ʱ�����м���Ѫ������$nȫ��",
		"dodge"       : -100000,
		"parry"       : 100000,
		"force"       : 1,
		"damage"      : 1,
	"lvl" : 0,
	"skill_name" : "��Ҷ����ɽ"
]),
([	"action" : "$Nļ��ʹһ��"HIR"�������С�"NOR"����ʱ�����м���Ѫ������$nȫ��",
		"dodge"       : 100000,
		"parry"       : -100000,
		"force"       : 1,
		"damage"      : 1,
	"lvl" : 0,
	"skill_name" : "��Ҷ����ɽ"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }
int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 200)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("yunlong-shengong", 1) < 20)
		return notify_fail("��������񹦻��̫ǳ��\n");
	if ((int)me->query_skill("yunlong-xinfa", 1) < 20)
		return notify_fail("��������ķ����̫ǳ��\n");
	if ((int)me->query_skill("force", 1) < 40)
		return notify_fail("��Ļ����ڹ����̫ǳ��\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query_skill("yunlong-shengong", 1) < 20)
		return notify_fail("��������񹦻��̫ǳ��\n");
	if( (int)me->query("qi") < 55 || (int)me->query("neili") < 40 )
		return notify_fail("���������������������������\n");
	me->receive_damage("qi", 50);
	me->add("neili", -35);
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
	return action[random(sizeof(action))];
}
int learn_bonus() { return 5; }
int practice_bonus() { return 5; }
int success() { return 5; }
int power_point() { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"yunlong-jian/" + action;
}
int help(object me)
{
	write(HIC"\n����������"NOR"\n");
	write(@HELP

    ��ػῴ�ұ��죬�����⹥����������󣬿�������һ����

	ѧϰҪ��
		�����ڹ�40��
		������20��
		�����ķ�20��
		����200
HELP
	);
	return 1;
}


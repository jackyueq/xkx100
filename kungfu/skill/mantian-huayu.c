// mantian-huayu.c ���컨��

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

string	*msg = ({
"$N������࣬һʽ������̤����������$w�������·�ͻȻ˦����ֱ����$n��$l",
"$w�ƿշɳ���һʽ�����羭�졹������һ�����ߣ��������ң�����$n��$l��",
"$N˫�����һʽ�����Ƽ��ա�������$w��$n����������$n��ȫ������",
"$N�����һ����ȴ��$nһ�С�������Ҷ����ʮ��ö$w�ɿ��л�������",
"$N���μ�����ǰ������һʽ��ѩ��׷�١�����ö$w��$n��в����ȥ",
"$Nһʽ�����ײ�ɣ��������һת������������ö$w������$n�ı���",
"$N���һ�ݣ�һ�С����Ƽ�����Ӹ����£�����$w���䣬ֱ��$n��$l",
"$Nһ�С����ǵ���������ָ������ö$w��һ��ڹ�����$n��ͷ��",
});

int valid_enable(string usage) { return usage=="throwing" || usage=="parry"; }
mapping query_action(object me, object weapon)
{
	return ([
		"action":msg[random(sizeof(msg))],
		"damage":(random(2)+2)*(me->query_skill("mantian-huayu",1))/4,
		"damage_type":"����",
		"dodge":random(20)+20,
		"force":random(50)+me->query_skill("mantian-huayu",1),
		"post_action": (: call_other, WEAPON_D, "throw_weapon" :)
	]);
}
int practice_skill(object me)
{
	object weapon;
	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "throwing")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("����������������컨�ꡣ\n");
	me->receive_damage("qi", 30);
	return 1;
}
int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("xuantian-wuji", 1) < 30)
		return notify_fail("��������޼������̫ǳ��\n");
	return 1;
}
int learn_bonus() { return 15; }
int practice_bonus() { return 10; }
int success() { return 10; }
int power_point(object me) { return 1; }

string perform_action_file(string action)
{
	return __DIR__"mantian-huayu/" + action;
}

int help(object me)
{
	write(HIC"\n���컨�꣺"NOR"\n");
	write(@HELP

    ���컨���������ɵİ���������

	ѧϰҪ��
		�����޼���30��
		����100
HELP
	);
	return 1;
}


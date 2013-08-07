// iron-sword.c ��������
// Last Modified by winder on Feb. 28 2001
 
#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

string *msg = ({
BLU "$N����ƽƽ�̳�һ����ʵ���Ǻ����κα仯����ȴ�к��֮����$n"BLU"ֻ��\nһ�ɴ�����$w"BLU"ֱ������",
BLU "$N���Ծ�����潣�𣬽�������֮����������һ������$n"BLU"�������ڽ���֮��",
BLU "$N��̾һ�������ֺ���һ��������ָ��$n"BLU"��������˿���仯��ȴ���ý�\n�����裬����ƽ�����̺����б仯������ʤ����",
BLU "$NѸ������һ��������������磬�������磬�޿ɵ��棡�˽�֮�죬������\n˼��$n"BLU"�޷��ֱ����·ȥ��",
BLU "$N���׳�Х������Ʊ�ã������������һ��ƽָ������������$n"BLU"��\n�������$n"BLU"ֻ�������κ���֮�У������и���$N�������纣��һ�㣬һ��\nһ������ӿ�������Ӳ�����������ǿ",
BLU "$N����$w"BLU"��������ɽ���������ǰ���ͺ�һ�������ǽ�������ġ�����\nʽ�����������ǽ�Ӱ������ǧ��������ֻ��$n"BLU"����ζ�",
BLU "$N$w"BLU"����ʮ�ལ��һʱѸ�������ǻ��գ�һʱ���سٻ��������޼���Ѱ��\nƽ�������ַ�˼������˳�̣�������������������޲��ǽ��������ţ����淵��\n���棬ȴ�Ѳ��ٴ��κ�����",
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }
int valid_learn(object me)
{
	object weapon;
	if ((int)me->query("max_neili") < 1500)
		return notify_fail("�������̫�����޷�������������\n");
	if ((int)me->query_skill("yunv-xinfa", 1) < 150)
		return notify_fail("�����Ů�ķ����������޷�������������\n");
	if (!(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "sword" )
		return notify_fail("���������һ�ѽ�������������\n");
	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("id") != "iron sword")
		return notify_fail("û�����������֣����޷��������������׾Ԧ�ɵĽ��⡣\n");
	return 1;
}
int practice_skill(object me)
{
	int cost;
	cost = 40;
	if ((int)me->query("qi") < 140)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 50)
		return notify_fail("�����������������������\n");
	if ((int)me->query_skill("anran-zhang", 1)>150)
	        cost=80;
	if ((int)me->query_skill("anran-zhang", 1)>250)
	        cost=160;   
	me->receive_damage("qi", cost);
	me->add("neili", -50);
	return 1;
}
mapping query_action(object me, object weapon)
{
	return ([
		"action":msg[random(sizeof(msg))]+NOR,
		"damage":240+random(100),
		"damage_type":random(2)?"����":"����",
		"dodge":-25+random(20),
		"parry":-55+random(20),
		"force":150+random(80)
	]);
}
int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 5; }
int power_point(object me)
{
	object weapon;
  if (!objectp(weapon = me->query_temp("weapon")) ||
                (string)weapon->query("id") != "iron sword")  
		return 0.8;
  else return 1.2;
}

string perform_action_file(string action)
{
	return __DIR__"iron-sword/" + action;
}
int help(object me)
{
	write(HIC"\n����������"NOR"\n");
	write(@HELP

    ����Ժ�С��Ů�ھ���ȶϳ���ǰ���֣����ñ�����������
����֮������������֮�󣬽�������֮�������ɴ˽�����

	ѧϰҪ��
		��Ů�ķ�150��
		����1500
		������ִ������
HELP
	);
	return 1;
}


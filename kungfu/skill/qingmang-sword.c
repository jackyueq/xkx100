// qingmang-sword.c ��������

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

string *msg = ({
	"$Nˢˢˢ�������У�ʹ�����������š�������$w������������������һ�㣬��֪Ҫ����δ�",
	"$N�������ˣ�����һ�У�$wֱ��$n���ţ��Ƶ�$n��æ��ͷ����",
	"$N�������$nС����һɨ���뽫$n�赹������$wһ������ָס$n�ʺ�",
	"$Nһ����Ц������$wӭ�濳�£�ֱ��$n$l",
	"$Nһ�³嵽$n��ǰ��ͻȻ֮��γ�$w������$nͷ�Ͽ�����ȥ",
	"$NͻȻһ�°�$w�ӻ�������ͻ���������ж����ǿ켫��$nȫ�����ܵ���ԣ",
	"$N$wͦ����һ�С����߳���������$n������ȥ���Ƶ����Ǿ���",
	"$N���������ã���$wȦת������$n$l",
	"$Nһ�С��������š���$w�����ޱȵ���$n��$l"
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("wudu-shengong", 1) < 20)
		return notify_fail("����嶾�񹦻��̫ǳ��\n");
	if ((int)me->query_skill("force", 1) < 20)
		return notify_fail("��Ļ����ڹ����̫ǳ��\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("qi") < 30
	|| (int)me->query("neili") < 15 )
		return notify_fail("���������������������������\n");
	me->receive_damage("qi", 30);
	me->add("neili", -10);
	return 1;
}
mapping query_action(object me, object weapon)
{
	return ([
		"action" : msg[random(sizeof(msg))],
		"damage" : 30+random(100),
		"dodge"  : 30+random(25),
		"parry"  : 5+random(15),
		"force"  : 50+random(50),
		"damage_type" : random(2)?"����":"����",
	]);
}
int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 20; }
int power_point(object me) { return 1.0; }

int help(object me)
{
	write(HIC"\n����������"NOR"\n");
	write(@HELP

    �����������嶾������һ�֡�

	ѧϰҪ��
		�����ڹ�20��
		�嶾��20��
		����100
HELP
	);
	return 1;
}


// juemen-gun.c ���Ź�
// Last Modified by sega on Mar. 10 2000
//û���ļ�,û�ð�?
//����ׯ�����ʺͿ�������Ÿ���

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

string *dodge_msg = ({
	"$n�ҽ�����һ��Ծ�������$N�Ĺ�����\n",
	"$n���Ա��˳���˳��һ��������һ�ߡ�\n",
	"$nб���ǰһ���������죬$N��һ���䵽�մ���\n",
	"$n��Ȼֱ������գ��ܾ�Ҳ������Ӱ�������������$N�ı���\n",
	"$nͻȻһ����ת��$N����һ�л�����һ�ߡ�\n",
});

mapping *action = ({
([	"action" : "$Nб���ǰһ���������죬����$w��ɨ$n��$l",
	"damage": 450,
	"dodge" : 50,
	"damage_type" : "����"
]),
([	"action" : "$N��Ȼֱ������գ��ܾ�Ҳ������Ӱ��$n����Ѱ�䣬$N��
�������£�$w����$n��$l",
	"damage": 500,
	"dodge" : 45,
	"damage_type" : "����"
]),
([	"action" : "$Nԭ��һ���������ȴ����ص�һɲ�ǣ�������$nƽ�ɹ�
ȥ������$wָ��$n��$l",
	"damage": 550,
	"dodge" : 60,
	"damage_type" : "����"
]),
([	"action" : "$NͻȻһ����ת��$w��ɨһȦ��Ю�����ҵľ�������$n��$l",
	"damage": 600,
	"dodge" : 75,
	"damage_type" : "����"
]),
([	"action" : "$N��ǰ�˳���˳��һ�������ŷ�����������$wб���ϻ�
��$n��$l",
	"damage": 750,
	"dodge" : 65,
	"damage_type" : "����"
]),
([	"action" : "$N����$w���·��ɣ������һ���Ȼ������Ȼ���$n������
Ȧ��ָ��$n��$l",
	"damage": 800,
	"dodge" : 65,
	"damage_type" : "����"
])
});

int valid_enable(string usage){return usage=="club" || usage=="parry"|| usage=="dodge"; }

int valid_learn(object me)
{
	if ((int)me->query_skill("hunyuan-yiqi") < 20)
		return notify_fail("��Ļ�Ԫһ����������޷������Ź���\n");
	if ((int)me->query("max_neili") < 400)
		return notify_fail("�������̫�����޷������Ź���\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "club")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("qi") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 50)
		return notify_fail("����������������Ź���\n");
	me->receive_damage("qi", 20);
	return 1;
}
int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 5; }
int power_point() { return 1.0; }
int valid_effect(object me, object weapon, string name, int skill)
{
}
string perform_action_file(string action)
{
	return __DIR__"juemen-gun/" + action;
}

int help(object me)
{
	write(HIC"\n���Ź���"NOR"\n");
	write(@HELP

    ���Ź�Ϊ������ʮ������֮һ��

	ѧϰҪ��
		��Ԫһ����20��
		����400
HELP
	);
	return 1;
}


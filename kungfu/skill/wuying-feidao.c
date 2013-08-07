// Last Modified by winder on Sep. 12 2001
// wuying-feidao.c ��Ӱ�ɵ�

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([      "action": "$N˫��һ�Σ����е�$w��һ�����߰����$n��$l",
        "force" : 20,
        "dodge" : -20,
        "damage": 90,
        "damage_type": "����",
        "post_action": (: call_other, WEAPON_D, "throw_weapon" :),
]),
([      "action": "$N����һ����$w�����̶����ƿ���ֱ��$n��$l",
        "force" : 120,
        "dodge" : -30,
        "damage": 190,
        "damage_type": "����",
        "post_action": (: call_other, WEAPON_D, "throw_weapon" :),
]),
([      "action": "$N��ָ΢����$wбб�ķ���$n��$l",
        "force" : 220,
        "dodge" : -20,
        "damage": 290,
        "damage_type": "����",
        "post_action": (: call_other, WEAPON_D, "throw_weapon" :),
]),
([      "action": "$N�������⣬����һ˦�����е�$w����һ����������$n��$l",
        "force" : 320,
        "dodge" : -40,
        "damage": 390,
        "damage_type": "����",
        "post_action": (: call_other, WEAPON_D, "throw_weapon" :),
]),
});

int valid_enable(string usage) { return usage=="throwing" ; }
int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_neili") < 500 )
                return notify_fail("�������������û�а취����Ӱ�ɵ���\n");
        if( !(ob = me->query_temp("weapon")) || 
		(string)ob->query("skill_type") != "throwing" )
                return notify_fail("���������һЩ������������Ӱ�ɵ���\n");
	if ((int)me->query_skill("honghua-shengong", 1) < 50)
		return notify_fail("��ĺ컨�񹦻�򲻹����޷�ѧ��Ӱ�ɵ���\n");

        return 1;
}
int practice_skill(object me)
{
        if( (int)me->query("qi") < 30 || (int)me->query("neili") < 50 )
                return notify_fail("�����������������û�취��ϰ��Ӱ�ɵ���\n");
        me->receive_damage("qi", 30);
        me->add("neili", -30);
  //      write("�㰴����ѧ����һ����Ӱ�ɵ���\n");
        return 1;
}
mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}
int learn_bonus() { return 20; }
int practice_bonus() { return 20; }
int success() { return 15; }
int power_point(object me) { return 1; }

string perform_action_file(string action)
{
        return  __DIR__"wuying-feidao/" + action;
}
 
int help(object me)
{
	write(HIM"\n��Ӱ�ɵ���"NOR"\n");
	write(@HELP

    ��Ӱ�ɵ�Ϊ����Ԫͨ�ļҴ�������Ԫ֮ͨŮ�������
�컨����������̡�

	ѧϰҪ��
		�컨��50��
		������Ϊ500
HELP
	);
	return 1;
}

// shenkong-xing.c �����
// Last Modified by sir on 10.18.2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "dodge"; }

string *dodge_msg = ({
	"$nʹ��һ��"HIC"���Ŀա�"NOR"����������Ʈȥ \n",
	"$nʹ��һ��"HIW"�����Կա�"NOR"��˫��һ�㣬Ծ������֮�� \n",
	"$nʹ��һ��"HIM"�����ա�"NOR"������һ�䣬����$N��� \n",
	"$n���һ����ʹ��һ��"HIG"���󰲿ա�"NOR"����$Nͷ��Խ�� \n",
	"$nʹ��һ��"HIY"����ա�"NOR"��������Ʈȥ��˲��������$N��ǰ \n",
	"$nʹ��һ��"HIR"����տա�"NOR"����ʱ$N��Χ����$n����Ӱ \n",
});

int valid_enable(string usage) { return usage == "dodge" || usage == "move"; }
int valid_learn(object me)
{      	
	if( (int)me->query_skill("xiaowuxiang", 1) < 10 )
	return notify_fail("���С���๦�������죬�޷��������С�\n");
	return 1;
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 10|| (int)me->query("neili") < 2 )
		return notify_fail("�������̫���ˣ�����������С�\n");
	me->receive_damage("qi", 10);
	me->add("neili", -4);	
	return 1;
}
string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int learn_bonus() { return 25; }
int practice_bonus() { return 25; }
int success() { return 20; }
int power_point(object me) { return 1.1; }

int help(object me)
{
	write(HIC"\n����У�"NOR"\n");
	write(@HELP

    �������ѩɽ�µ��ӱ����Ṧ����

	ѧϰҪ��
	  С���๦10��
HELP
	);
	return 1;
}


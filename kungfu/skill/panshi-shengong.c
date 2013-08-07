// panshi-shengong.c ��ʯ��
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>;
inherit FORCE;
#include "force.h"
string type() { return "martial"; }
string martialtype() { return "force"; }

int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 10; }
int power_point(object me) { return 1; }

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{

	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("��Ļ����ڹ���򻹲�����������ѧϰ��ʯ�񹦡�\n");

	return valid_public(me);
}

int practice_skill(object me)
{
	return notify_fail("��ʯ��ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
	return __DIR__"panshi-shengong/" + func;
}
int help(object me)
{
	write(HIM"\n��ʯ�񹦣�"NOR"\n");
	write(@HELP

    ̩ɽ���ڹ��������Ƽ��˹�֮�á�

	ѧϰҪ��
		�����ڹ�10��
HELP
	);
	return 1;
}


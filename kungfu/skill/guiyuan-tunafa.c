// guiyuan-tunafa.c ���ư� ��Ԫ���ɷ�
// Last Modified by winder on Nov. 15 2000

#include <ansi.h>;
#include "force.h"
inherit FORCE;
string type() { return "martial"; }
string martialtype() { return "force"; }

int valid_enable(string usage) { return usage == "force"; }
int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 10; }
int power_point(object me) { return 1; }

int valid_learn(object me)
{
	int nf;
	
	nf = (int)me->query_skill("force", 1);
	if ( nf < 10)
		return notify_fail("��Ļ����ڹ���򻹲������޷�����Ԫ���ŷ���\n");

	return valid_public(me);
}

int practice_skill(object me)
{
	return notify_fail("��Ԫ���ŷ�ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
	return __DIR__"guiyuan-tunafa/" + func;
}
int help(object me)
{
	write(HIM"\n��Ԫ���ɷ���"NOR"\n");
	write(@HELP

    ���ư���ڹ��������ơ����Ƽ��˹�֮�á�

	ѧϰҪ��
		�����ڹ�10��
HELP
	);
	return 1;
}


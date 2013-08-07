// shenyuan-gong.c ��Ԫ��
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>;
#include "force.h";
inherit FORCE;
string type() { return "martial"; }
string martialtype() { return "force"; }

int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 10; }
int power_point(object me) { return 1; }

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
	int nf;
	nf = (int)me->query_skill("force", 1);

	if ( nf < 10)
		return notify_fail("��Ļ����ڹ���򲻹����޷������Ԫ����\n");

	return valid_public(me);
}

int practice_skill(object me)
{
	return notify_fail("��Ԫ��ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
	return __DIR__"shenyuan-gong/" + func;
}
int help(object me)
{
	write(HIC"\n��Ԫ����"NOR"\n");
	write(@HELP

    ��Ԫ���ǽ��Ϲ���Ľ�����ҵı����ڹ���

	ѧϰҪ��
		�����ڹ�10��
HELP
	);
	return 1;
}


// xuantian-wuji �����޼���

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
	int nl, ng, nf, nx;
	nf = (int)me->query_skill("force", 1);
	ng = (int)me->query_skill("goplaying", 1);
	nl = (int)me->query_skill("luteplaying", 1);
	nx = (int)me->query_skill("xuantian-wuji", 1);

	if ( nf < 20)
		return notify_fail("��Ļ����ڹ���򻹲������޷���������޼�����\n");

	return valid_public(me);
}

int practice_skill(object me)
{
	return notify_fail("�����޼���ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
	return __DIR__"xuantian-wuji/" + func;
}
int help(object me)
{
	write(HIC"\n�����޼�����"NOR"\n");
	write(@HELP

    �����޼����������ɵı����ڹ���

	ѧϰҪ��
		�����ڹ�10��
		�൱�����弼�յ�����
HELP
	);
	return 1;
}


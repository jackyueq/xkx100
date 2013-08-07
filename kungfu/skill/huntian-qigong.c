// huntian-qigong.c ��������
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
	int i = (int)me->query_skill("huntian-qigong", 1);
	int t = 1, j;

	for (j = 1; j < i / 10; j++) t*= 2;

	if (i > 10 && ((int)me->query("shen") > t * 100 || (int)me->query("shen") < t * (-100)))
		return notify_fail("ѧ����������Ҫ������а��������а��������ò���ѽ��\n");

	return valid_public(me);
}

int practice_skill(object me)
{
	return notify_fail("��������ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
	return __DIR__"huntian-qigong/" + func;
}
int help(object me)
{
	write(HIC"\n����������"NOR"\n"); 
	write(@HELP

    ��������Ϊؤ�ﱾ���ڹ��� 

	ѧϰҪ��
		ѧ����������Ҫ������а��������а
HELP
	);
	return 1;
}


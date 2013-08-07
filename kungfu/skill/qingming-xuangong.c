// qingming-xuangong.c ��ڤ����
// Last Modified by winder on Aug. 10 2000

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
	if (me->query_skill("force",1) < 10)
		return notify_fail("�����ڹ��������������ѧ��ڤ��������\n");

	return valid_public(me);
}

int practice_skill(object me)
{
	return notify_fail("��ڤ����ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
	return __DIR__"qingming-xuangong/" + func;
}
int help(object me)
{
	write(HIC"\n��ڤ������"NOR"\n");
	write(@HELP

    ��ڤ����������ɱ����ڹ���

	ѧϰҪ��
		�����ڹ�10��
HELP
	);
	return 1;
}


// kurong-changong.c ��������
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
	if ( me->query_skill("force", 1) < 10)
		return notify_fail("��Ļ����ڹ������������������������\n");
	if ( me->query("gender") == "����")
		return notify_fail("���޸����ԣ���������������������Ŀ���������\n");

	return valid_public(me);
}

int practice_skill(object me)
{
	return notify_fail("��������ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
	return __DIR__"kurong-changong/" + func;
}


int help(object me)
{
	write(HIC"\n����������"NOR"\n");
	write(@HELP

    �г��޳���˫�����٣��ϱ��������Ǽٷǿգ�
    �����湦�������¿��ٳ��Ͼ��ô˼����ഫ����Ĳ�������˫
��֮�����𣬴����˷ǿݷ��١��Ǽٷǿյ���߾��磬�������ӱ�
�Դ�Ϊ����֮�������ο�������Ϊ��������֮���ɡ�
    Ϊ���ϴ���μҵı����ڹ���

	ѧϰҪ��
		�����ڹ�10��
		������̫��
HELP
	);
	return 1;
}


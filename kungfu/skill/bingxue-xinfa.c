// bingxue-xinfa.c ��ѩ�ķ�
// Last Modified by winder on Jul. 15 2001

#include <ansi.h>;
#include "force.h";
inherit FORCE;
string type() { return "martial"; }
string martialtype() { return "force"; }

int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 10; }
int power_point(object me) { return 1; }

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me)
{
	int lvl = (int)me->query_skill("bingxue-xinfa", 1);

	if ( me->query_skill("force", 1) < 10)
		return notify_fail("��Ļ����ڹ����������\n");
	if ( me->query("gender") == "����" && lvl > 49)
		return notify_fail("���޸����ԣ���������������������ı�ѩ�ķ���\n");

	return valid_public(me);
}

int practice_skill(object me)
{
	return notify_fail("��ѩ�ķ�ֻ����ѧ�ģ����Ǵ�����(exert)�����������ȡ�\n");
}

string exert_function_file(string func)
{
        return __DIR__"bingxue-xinfa/" + func;
}
int help(object me)
{
	write(HIC"\n��ѩ�ķ���"NOR"\n");
	write(@HELP

    ��ѩ�ķ���ѩɽ�����ǵ��ڹ��ķ�����ѩɽ�ɵ��ӱ����ڹ���

	ѧϰҪ��
		�����ڹ�10��
		̫���޷�����50�����ϵı�ѩ�ķ�
HELP
	);
	return 1;
}


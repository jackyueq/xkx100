// force.c �����ڹ�
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "force"; }

int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 30; }
int power_point(object me) { return 1; }
int valid_learn(object me) {return 1;}

string exert_function_file(string func)
{
	return __DIR__"force/" + func;
}

void skill_improved(object me)
{}
int help(object me)
{
	write(HIC"\n�����ڹ���"NOR"\n");
	write(@HELP

    �����ڹ��������书�Ļ��������ܸ��������ĸ��ǡ�
    ��help neigong��

	ѧϰҪ��
		��
HELP
	);
	return 1;
}


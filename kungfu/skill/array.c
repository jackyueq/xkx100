// array.c
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>;
inherit SKILL;

string type() { return "knowledge"; }
int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 30; }
int power_point(object me) { return 1; }

int help(object me)
{
	write(HIC"\n�����󷨣�"NOR"\n");
	write(@HELP

    �һ������Ӳ������û������ܡ�

	ѧϰҪ��
		��
HELP
	);
	return 1;
}


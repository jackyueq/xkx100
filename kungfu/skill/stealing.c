// stealing.c ���ֿտ�
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
	write(HIC"\n���ֿտգ�"NOR"\n");
	write(@HELP

    ���ֿտ���ؤ��ı��������
    ��help steal��

	ѧϰҪ��
		��
HELP
	);
	return 1;
}


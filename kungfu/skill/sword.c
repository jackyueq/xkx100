// sword.c ��������
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>;
inherit SKILL;

string type() { return "martial"; }
string martialtype() { return "skill"; }
int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 30; }
int power_point(object me) { return 1; }

int help(object me)
{
	write(HIC"\n����������"NOR"\n");
	write(@HELP

    �����似�Ļ�������
    �����ųơ��ٱ�֮�����������ƣ��������������߽�Ҫƽ�ƣ�
��Ҫ�潣�У����۹˽��⣬���������ȣ�������Ȼ����������࣬
������ͣ�磬�����绨����������ֶ�����

	ѧϰҪ��
		��
HELP
	);
	return 1;
}


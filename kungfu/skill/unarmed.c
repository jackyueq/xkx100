// unarmed.c ����ȭ��
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>;
inherit SKILL;

string type() { return "martial"; }
string martialtype() { return "skill"; }
int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 30; }
int power_point(object me) { return 1; }

void skill_improved(object me)
{}

int help(object me)
{
	write(HIC"\n����ȭ�ţ�"NOR"\n");
	write(@HELP

    ȭ�����似�Ļ����������ܸ���������������

	ѧϰҪ��
		��
HELP
	);
	return 1;
}


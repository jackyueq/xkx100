// literate.c ����д��
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>;
inherit SKILL;

string type() { return "knowledge"; }
int learn_bonus() { return 20; }
int practice_bonus() { return 20; }
int success() { return 20; }
int power_point(object me) { return 1; }

void skill_improved(object me)
{}

int valid_learn(object me)
{
//	if ( me->query("class") != "bonze" )
//		return notify_fail("�����ڲ���ѧϰ����д�֡�\n");
	return 1;
}

int help(object me)
{
	write(HIC"\n����д�֣�"NOR"\n");
	write(@HELP

    ����д������ѧ�伮�Ļ��������ܸ������������ԡ�

	ѧϰҪ��
		��
HELP
	);
	return 1;
}


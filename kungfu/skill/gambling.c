// gambling.c �����ļ�
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>;
inherit SKILL;

string type() { return "knowledge"; }
int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 30; }
int power_point(object me) { return 1; }

void skill_improved(object me)
{}

int valid_learn(object me)
{
	if ( me->query("age") <= 20 )
		return notify_fail("�����ڻ�̫С������ѧϰ�����ļ���\n");
	return 1;
}

int help(object me)
{
	write(HIC"\n�����ļ���"NOR"\n");
	write(@HELP

    �����ļ���һ�ֽ������ա�ͨ���ڶĳ��жĲ��������ý�����
������ע��������档

	ѧϰҪ��
		�Ĳ�
HELP
	);
	return 1;
}


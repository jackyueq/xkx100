// cookery.c �������
// Last Modified by winder on Jun. 10 2000

#include <ansi.h>;
inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }
int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 30; }
int power_point(object me) { return 1; }

int valid_learn(object me)
{
	return 1;
}
int practice_skill(object me)
{
	return notify_fail("�������ֻ�ܿ�ѧϰ����ߡ�\n");
}
int help(object me)
{
	write(HIC"\n������գ�"NOR"\n");
	write(@HELP

    �����������������ҵı�Ǯ����help cookery��

	ѧϰҪ��
		�ޡ����츳���������˶Ը�������Ŭ��
HELP
	);
	return 1;
}


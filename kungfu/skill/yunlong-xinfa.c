// yunlong-xinfa.c �����ķ�
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>;
inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }
int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 30; }
int power_point(object me) { return 1; }

int practice_skill(object me)
{	
	return notify_fail("�����ķ�ֻ�ܿ�ѧ(learn)����ߡ�\n");
}
int help(object me)
{
	write(HIC"\n�����ķ���"NOR"\n");
	write(@HELP

    �����ķ��������ŵľ���֧�������Լ�����ػ��ڷ��帴����

	ѧϰҪ��
		��
HELP
	);
	return 1;
}


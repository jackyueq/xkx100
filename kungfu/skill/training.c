// training.c Ԧ����
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>;
inherit SKILL;
string type() { return "knowledge"; }

int learn_bonus() { return 15; }
int practice_bonus() { return 10; }
int success() { return 10; }
int power_point(object me) { return 1; }

int help(object me)
{
	write(HIC"\nԦ������"NOR"\n"); 
	write(@HELP

    Ԧ��������ʹ����ļ��ܡ�Ψؤ����ӺͰ���ɽ������ѧ����
    ��help train��help transport��

	ѧϰҪ��
		��
HELP
	);
	return 1;
}


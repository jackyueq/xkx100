// digging.c ���֮��
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
	int lvl;

	lvl = (int)me->query_skill("construction", 1);

	if (lvl > 29 && me->query("kar") != 27) 
		return notify_fail("�������ʣ���ֻ����ϰ����̶��ˡ�\n");
	else return 1;
}

int practice_skill(object me)
{
	return notify_fail("���֮��ֻ�ܿ�ѧϰ����ߡ�\n");
}
int help(object me)
{
	write(HIC"\n���֮����"NOR"\n");
	write(@HELP

    ���֮�������������ž�����

	ѧϰҪ��
		�ޡ�
HELP
	);
	return 1;
}


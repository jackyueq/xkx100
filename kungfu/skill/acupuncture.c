// acupuncture.c ���֮��
// Last modified by winder 2003.9.2

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
        if ((int)me->query_skill("medicine", 1) < 50)
                return notify_fail("��ļ���֮������̫ǳ���޷�������֮����\n");
        if ((int)me->query_skill("medicine", 1) <
		(int)me->query_skill("acupuncture", 1))
                return notify_fail("��ļ���֮�����ޣ��޷����ո���µ����֮����\n");
        return 1;
}
int practice_skill(object me)
{
	return notify_fail("���֮��ֻ�ܿ�ѧϰ����ߡ�\n");
}
int help(object me)
{
	write(HIC"\n���֮����"NOR"\n");
	write(@HELP

    ��ͨ���֮���������������£��β����ˡ�

	ѧϰҪ��
		���֮�������˶Ը�������Ŭ��
HELP
	);
	return 1;
}


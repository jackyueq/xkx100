// chengzi18po.c ����ʮ����
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>;
inherit SKILL;

string type() { return "knowledge"; }
int learn_bonus() { return 10; }
int practice_bonus() { return 10; }
int success() { return 10; }
int power_point() { return 1; }

void skill_improved(object me) {}

int valid_learn(object me)
{
	if(me->query_skill("qingming-xuangong", 1) + random(5) <
		me->query_skill("chengzi18po", 1))
		return notify_fail("��ı����ڹ�δ������޷�������ϰ����ʮ���ơ�\n");
	return 1;
}

int help(object me)
{
	write(HIC"\n����ʮ���ƣ�"NOR"\n");
	write(@HELP

    ������ʮ���ơ��롰���־Ŵ򡱲���Ϊ�����ɽ�书�����ױ�
�����׹��䡣

	ѧϰҪ��
		��Ӧ�������ڤ����
HELP
	);
	return 1;
}


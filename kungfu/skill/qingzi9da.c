// qingzi9da.c ���־Ŵ�
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>;
inherit SKILL;

string type() { return "knowledge"; }
int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 10; }
int power_point(object me) { return 1; }

void skill_improved(object me) {}

int valid_learn(object me)
{
	if(me->query_skill("qingming-xuangong", 1)  <
		me->query_skill("qingzi9da", 1))
		return notify_fail("��ı����ڹ�δ������޷�������ϰ���־Ŵ�\n");
	return 1;
}

int help(object me)
{
	write(HIC"\n���־Ŵ�"NOR"\n");
	write(@HELP

    �����־Ŵ��롰����ʮ���ơ�����Ϊ�����ɽ�书�����ױ�
������䶤��

	ѧϰҪ��
		��Ӧ�������ڤ����
HELP
	);
	return 1;
}


// necromancy.c ������
// Last Modified by winder on Mar. 10 2000
// by Java

#include <ansi.h>;
inherit SKILL;
string type() { return "knowledge"; }

int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 5; }
int power_point(object me) { return 1; }

int valid_learn(object me)
{
	if( (int)me->query_skill("longxiang",1) <
		(int)me->query_skill("necromancy",1) )
		return notify_fail("������������̫���ˣ��޷�����������Ľ�������\n");
	return 1;
}
int practice_skill(object me)
{
	return notify_fail("������ֻ�ܿ�ѧ(learn)����ߡ�\n");
}

int help(object me)
{
	write(HIC"\n��������"NOR"\n");
	write(@HELP

    ������Ϊ�����ܼ�����Ϊ���ڵ��ӣ������൱�Ľ�������Ϊ��
�������������ջ�ĳ���������ϵĶ�������, ���������뿪������
�����㡣�Է�����ڹ���񣬶���ѧ�ղ�������ȻҲ������������
����
    ��help shexin��

	ѧϰҪ��
		����������ȼ����ܵ��ڽ������ȼ�
HELP
	);
	return 1;
}


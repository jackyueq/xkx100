// qimen-wuxing ��������
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
	return notify_fail("���������ܿ�ѧ(learn)����ߡ�\n");
}
int valid_learn(object me) 
{
	if( me->query_skill("hubo",1))
    return notify_fail("�������̫�࣬һʱ�޷�����������У�\n");
  return 1;
}
int help(object me)
{
	write(HIC"\n�������У�"NOR"\n");
	write(@HELP


    �Ƕ����һ����Ķ��Ź����ഫ�һ�����Ȼ�ش����⣬�˼���
����������ȴ�ǼҴ�Ԩ���������������о��ú���������Ź���
�������һ����Ĳ�����Ϳ��԰ڳ����������󣬰ѵ����������ڡ�

    array somebody  �ڲ����������£����Զ�ĳ�˲���ʹ��
�������ڡ�

    �����Ķ����׾���ϵ���鼮��ߡ�


	ѧϰҪ��
		����ͬʱ��ϰ���һ���֮��
HELP
	);
	return 1;
}


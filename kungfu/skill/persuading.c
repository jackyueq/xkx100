// persuading.c ��������
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
	return notify_fail("��������Ҫ��ʵ������ߡ�\n");
}
int help(object me)
{
	write(HIC"\n�������ˣ�"NOR"\n");
	write(@HELP

    ���ҵ��ӳ��Ŵ�˷�̣��������ˣ��������˶ɼ�����������
ֻ���Լ����У����Զ������˵Ĺ�ҵ���Ƕ����ɿ������˵��ӵ���
Ҫ��׼�����ҵ��ӿ�������persuadeȰ��ս���е���һ��ߣΣУ�
�ն�����ʵ����������Ϊ����ȡ��ʵս�����Ǳ�ܡ�
    ��help persuade��

	ѧϰҪ��
		ʵ���л��
HELP
	);
	return 1;
}


// qufeng.c ����֮��
// Last Modified by winder on Mar. 10 2000

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
	if ((int)me->query_skill("yunv-xinfa", 1) < 10)
		return notify_fail("�����Ů�ķ���򲻹����޷�ѧ����֮����\n");
	if ((int)me->query("max_neili") < 30)
		return notify_fail("�������̫�����޷�ѧϰ����֮����\n");
	return 1;
}
int practice_skill(object me)
{
	return notify_fail("����֮��ֻ�ܿ�ѧϰ����ߡ�\n");
}
int help(object me)
{
	write(HIC"\n����֮����"NOR"\n");
	write(@HELP

    ��Ĺ������������������ʹ�÷佬ƿ��������˵С�
    ��help qufeng��

	ѧϰҪ��
		��Ů�ķ�10��
		����30
HELP
	);
	return 1;
}


// lamaism.c �����ķ�
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
	if ((me->query_skill("buddhism",1) > 1) ||
		(me->query_skill("mahayana",1) > 1))
		return notify_fail("������"+RANK_D->query_respect(me)+ "�������ţ���ôȴ��ѧ�����ķ���\n");
	if( (int)me->query_skill("taoism",1) > 1 )
		return notify_fail("��ѧ��ţ���ӵ��ķ����޷����������ķ���\n");
	if ((me->query_skill("ziyunyin",1) > 1) ||
		(me->query_skill("zhengqijue",1) > 1))
		return notify_fail("������"+RANK_D->query_respect(me)+ "�Ѿ�ѧ��α���ӵ��ķ�����ôȴ��ѧ�����ķ���\n");
	if ((me->query_skill("poison",1) > 1))
		return notify_fail("������"+RANK_D->query_respect(me)+ "�Ѿ�ѧ��аħ����Ķ�������ôȴ��ѧ�����ķ���\n");
	if (me->query_skill("lamaism", 1) >= 150)
		return notify_fail("�������ʣ���������ķ������Ҳ�͵���Ϊֹ�ˡ�\n");
	return 1;
}

int practice_skill(object me)
{
	return notify_fail("�����ķ�ֻ�ܿ�ѧ(learn)����ߡ�\n");
}

int help(object me)
{
	write(HIC"\n�����ķ���"NOR"\n");
	write(@HELP

    �����ķ���ѩ�������ķ������Գ������顣

	ѧϰҪ��
		����ѧ���ڡ����Һͻ�ɽ���ķ��Լ����޶���
HELP
	);
	return 1;
}


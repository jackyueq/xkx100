// mahayana.c ������͹�
//Last Modified by winder on Mar. 10 2000

#include <ansi.h>;
inherit SKILL;

string type() { return "knowledge"; }
int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 30; }
int power_point(object me) { return 1; }

int valid_learn(object me)
{
	mapping myfam;
	myfam = (mapping)me->query("family");
/*
	if (!myfam || (myfam["family_name"] != "������"))
		return notify_fail("�㲻�Ƕ��ҵ��ӣ���������������͹���\n");
	if (me->query_skill("linji-zhuang",1) < me->query_skill("mahayana",1))
		return notify_fail("��ı����ڹ���Ϊ̫�٣�����������͹�Ҳû�á�\n");
*/
	if ((int)me->query("shen") < 0 )
		return notify_fail("���а��̫�أ��޷�����������͹���\n");
//	if (me->query_skill("persuading",1) <= me->query_skill("mahayana",1))
//		return notify_fail("�������̫�٣�����������͹�Ҳû�á�\n");
	if( (int)me->query_skill("taoism",1) > 1 )
		return notify_fail("��ѧ��ţ���ӵ��ķ����޷�����������͹���\n");
	if ((me->query_skill("lamaism",1) > 1))
		return notify_fail("���Ĵ����ڣ��޷�����������͹���\n");
	if (me->query_skill("mahayana", 1) >= 200)
		return notify_fail("�������ʣ���Դ�����͹������Ҳ�͵���Ϊֹ�ˡ�\n");

	return 1;
}

int practice_skill(object me)
{
	return notify_fail("������͹�ֻ�ܿ�ѧϰ����ߡ�\n");
}
int help(object me)
{
	write(HIC"\n������͹���"NOR"\n");
	write(@HELP

    �������ز�ϲ�����������������˳���������������������Ǳ
�ܣ�����Ч�̶���ȡ���ڷ���Ϊ����������͹��ĵȼ���������
���޿��ڶ�������ʹ������jingzuo����help jingzuo��

	ѧϰҪ��
		��Ӧ���ټ�ʮ��ׯ
		����ѧ�����ķ���������ڽ��ķ�
HELP
	);
	return 1;
}


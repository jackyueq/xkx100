// horticulture.c ԰��ݪ��
// Last Modified by winder on Jun. 10 2000

#include <ansi.h>;
inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }
int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 30; }
int power_point() { return 1; }

int valid_learn(object me)
{
	int lvl;

	lvl = (int)me->query_skill("horticulture", 1);

	if (lvl > 29 && me->query("kar") != 26) 
		return notify_fail("�������ʣ���ֻ����ϰ����̶��ˡ�\n");
	else return 1;
}

int practice_skill(object me)
{
	return notify_fail("԰��ݪ��ֻ�ܿ�ѧϰ����ߡ�\n");
}
int help(object me)
{
	write(HIC"\n԰��ݪ����"NOR"\n");
	write(@HELP

    ��ң����ʦ��ң��ѧ�����ˣ�������ѧ������������������
�ž��գ��������� (luteplaying)��������̸ (goplaying)����ī
����(painting)������֮��(medicine)����ľ����(construction)��
԰��ݪ��(horticulture)����԰����(dramaturgy)��

	ѧϰҪ��
		�ޡ����츳���������˶Ը�������Ŭ��
HELP
	);
	return 1;
}


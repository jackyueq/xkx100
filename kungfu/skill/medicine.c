// medicine.c ����֮��
// Last Modified by winder on Jun. 10 2000

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
	int lvl;

	lvl = (int)me->query_skill("medicine", 1);

	if( (int)me->query("age") < 16 )
		return notify_fail("������̫�ᣬ�޷���ϰ����֮����\n");

	if (!me->query("medicine"))
	{
		if (random(6) == 1)
		{
			me->set("medicine",2);
		}
		else
		{
			me->set("medicine",1);
		}
	}
	if (lvl > 29 && me->query("medicine") == 1) 
		return notify_fail("�������ʣ���ֻ����ϰ����̶��ˡ������Ŭ������������ร�ɡ�\n");
	else return 1;
}

int practice_skill(object me)
{
	return notify_fail("����֮��ֻ�ܿ�ѧϰ����ߡ�\n");
}
int help(object me)
{
	write(HIC"\n����֮����"NOR"\n");
	write(@HELP

    ��ң����ʦ��ң��ѧ�����ˣ�������ѧ������������������
�ž��գ��������� (luteplaying)��������̸ (goplaying)����ī
����(painting)������֮��(medicine)����ľ����(construction)��
԰��ݪ��(horticulture)����԰����(dramaturgy)��
    ��ͨ����֮�������Բ�ҩ�����������β�����help medical��

	ѧϰҪ��
		�ޡ����츳���������˶Ը�������Ŭ��
HELP
	);
	return 1;
}


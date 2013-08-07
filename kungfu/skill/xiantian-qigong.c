// xiantian-qigong.c ��������
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>;
#include "force.h";
inherit FORCE;
string type() { return "martial"; }
string martialtype() { return "force"; }

int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 10; }
int power_point() { return 1; }

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
	int lvl = (int)me->query_skill("xiantian-qigong", 1);
	int t = 1, j;
	if (lvl<=100) for (j = 1; j < lvl / 10; j++) t*=2;

	if ( me->query("gender") == "����")
		return notify_fail("���޸����ԣ��������������������������ڵ�����������\n");

	if ( me->query("class") == "bonze" )
		return notify_fail(RANK_D->query_respect(me)+"�����ҵ�����������������ȥ���˷��ţ�\n");

	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("��Ļ����ڹ���򻹲�����\n");

	if(lvl<=100)
	{
		if (lvl > 10 && (int)me->query("shen") < t * 100)
			return notify_fail("�����������̫���ˡ�\n");
	}
	else
	{
		if ((int)me->query("shen") < (51200 + (lvl - 100) * 1000))
			return notify_fail("�����������̫���ˡ�\n");
	}

	return valid_public(me);
}

int practice_skill(object me)
{
	return notify_fail("��������ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
	return __DIR__"xiantian-qigong/" + func;
}

int help(object me)
{
	write(HIC"\n����������"NOR"\n");
	write(@HELP

    ���칦�������ڹ����ڣ���ȫ��������书�Ļ��������칦��
��������ʵ���������Ž��������������棬��Ȼ�ӿ졣���칦����
���蹲�־Žڣ������������������붥����Һ��������������
�����ţ�̫�����Σ�����ȼã�����ϵ����������ɣ�������ʥ��

	ѧϰҪ��
		�����ڹ�10��
		������̫������
		��Ӧ������
HELP
	);
	return 1;
}


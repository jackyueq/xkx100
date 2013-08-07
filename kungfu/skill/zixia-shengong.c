// zixia-shengong.c ��ϼ��
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>;
inherit FORCE;
#include "force.h"
string type() { return "martial"; }
string martialtype() { return "force"; }

int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 10; }
int power_point() { return 1; }

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
	int i = (int)me->query_skill("zixia-shengong", 1);
	int t = 1, j;

	if(i <= 100) for (j = 1; j < i / 10; j++) t *= 2;

	if ( me->query("gender") == "����" && i > 49)
		return notify_fail("���޸����ԣ������������������������ϼ�񹦡�\n");

	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("��Ļ����ڹ���򻹲�����������ѧϰ��ϼ�񹦡�\n");

	if(i<=100)
	{
		if (i > 10 && (int)me->query("shen") < t * 100) 
			return notify_fail("�����������̫���ˣ��޷������������ϼ�񹦡�\n");
	}
	else
	{
		if ((int)me->query("shen") < (51200 + (i - 100) * 1000)) 
			return notify_fail("�����������̫���ˣ��޷������������ϼ�񹦡�\n");
	}


	return valid_public(me,"huashan-neigong");
}

int practice_skill(object me)
{
	return notify_fail("��ϼ��ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
	return __DIR__"zixia-shengong/" + func;
}
int help(object me)
{
	write(HIM"\n��ϼ�񹦣�"NOR"\n");
	write(@HELP

    ��ɽ�����ڹ��������Ƽ��˹�֮�ã��������Ӿ�������������
�Ӻ����������������Ϊ�������������������������������Ϊ��

	ѧϰҪ��
		�����ڹ�10��
		��Ӧ������
		̫���޷�ѧ��50�����ϵ���ϼ��
HELP
	);
	return 1;
}


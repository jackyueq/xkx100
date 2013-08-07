// huiyan-xinfa.c �����ķ�
// Last Modified by ahda on Aug.30 2001

#include <ansi.h>;
#include "force.h";
inherit FORCE;

string type() { return "martial"; }
string martialtype() { return "force"; }
int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 10; }
int power_point(object me) { return 1; }

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
	int lvl = (int)me->query_skill("huiyan-xinfa", 1);
	int t = 1, j;
	if (lvl<=100)
		for (j = 1; j < lvl / 10; j++)
			t*=2;

	if ( me->query("gender") == "����" && lvl > 49)
		return notify_fail("���޸����ԣ���������������������Ļ����ķ���\n");

	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("��Ļ����ڹ���򻹲�����\n");

	if(lvl<=100)
	{
		if (lvl > 10 && (int)me->query("shen") < t * 100) 
			return notify_fail("�����������̫���ˣ��޷���������Ļ����ķ���\n");
	}
	else
	{
		if ((int)me->query("shen") < (51200 + (lvl - 100) * 1000)) 
			return notify_fail("�����������̫���ˣ��޷���������Ļ����ķ���\n");
	}

	return valid_public(me);
}

int practice_skill(object me)
{
	return notify_fail("�����ķ�ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
	return __DIR__"huiyan-xinfa/" + func;
}

int help(object me)
{
	write(HIC"\n�����ķ���"NOR"\n");
	write(@HELP

    �����ķ��˺�ɽ����ɽ��ѧ��Ϊ��ɽ��ǰ��������������
    ��ϰ��ɽ�ɸ��ָ����书�ĸ���������������֮��Ч��

	ѧϰҪ��
		�����ڹ�10��
		��Ӧ������
		̫���޷�����50�����ϵĻ����ķ�
HELP
	);
	return 1;
}


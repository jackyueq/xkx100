// taiji-shengong.c ̫����
// Last Modified by winder on Mar. 10 2000

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
	int lvl = (int)me->query_skill("taiji-shengong", 1);
	int t = 1, j;
	if (lvl<=100)
		for (j = 1; j < lvl / 10; j++)
			t*=2;

	if ( me->query("gender") == "����" && lvl > 49)
		return notify_fail("���޸����ԣ����������������������̫���񹦡�\n");

	if ( me->query("class") == "bonze" )
		return notify_fail("̫���񹦽����������ϣ���Υ��������徻֮�⣬"+RANK_D->query_respect(me)+"���޴˹������������\n");

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
	return notify_fail("̫����ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
	return __DIR__"taiji-shengong/" + func;
}

int help(object me)
{
	write(HIC"\n̫���񹦣�"NOR"\n");
	write(@HELP

    ̫�������䵱����֮�أ��������塹�����项����Բ������
ͨ��������ϰ�䵱�ɸ��ָ����书�ĸ������䵱�������̫����
�͵�ѧ�ķ�������������������������֮��Ч��

	ѧϰҪ��
		���в���ѧ
		̫���޷�����50�����ϵ�̫����
		�����ڹ�10��
		��Ӧ������
HELP
	);
	return 1;
}


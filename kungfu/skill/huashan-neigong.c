// huashan-neigong.c ��ɽ�ڹ�
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>;
inherit FORCE;
#include "force.h"

string type() { return "martial"; }
string martialtype() { return "force"; }
int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 10; }
int power_point(object me) { return 1; }

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
// need more limit here
{
	if ((int)me->query_skill("zixia-shengong", 1) < 10)
		return notify_fail("�����ϼ�񹦻�򻹲�����\n");
	return valid_public(me,"zixia-shengong");
}

int practice_skill(object me)
{
	return notify_fail("��ɽ����ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
	return SKILL_D(__DIR__"huashan-neigong/") + func;
}

int help(object me)
{
	write(HIC"\n��ɽ�ڹ���"NOR"\n");
	write(@HELP

    ��ɽ�ڹ�Ϊ��ɽ���ڱ����ڹ��ķ���

	ѧϰҪ��
		��ϼ��10��
HELP
	);
	return 1;
}


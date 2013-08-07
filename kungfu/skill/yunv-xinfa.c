// yunv-xinfa.c ��Ů�ķ�
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

	if ( me->query("gender") == "����")
		return notify_fail("���޸����ԣ������ѵ���������ϰ��Ů�ķ���\n");

	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("��Ļ����ڹ���򻹲�����\n");

	return valid_public(me);
}

int practice_skill(object me)
{
	return notify_fail("��Ů�ķ�ֻ����ѧ(learn)�����������ȡ�\n");
}

string exert_function_file(string func)
{
	return __DIR__"yunv-xinfa/" + func;
}

int help(object me)
{
	write(HIC"\n��Ů�ķ���"NOR"\n");
	write(@HELP

    ��Ĺ�ڹ�����һ���������֣�Ψ��ƽ�ľ�������������֮�Ų�
����ϰ�ϳ��书����Ů�ľ������ѶȺܴ�ѧϰ��Ҫ�������꣬ѭ
�򽥽����гɹ�֮��������Ѱ�ٱ����ؼ�����Ů�ľ������²��ж���

	ѧϰҪ��
		�����ڹ�10��
		������̫��
HELP
	);
	return 1;
}


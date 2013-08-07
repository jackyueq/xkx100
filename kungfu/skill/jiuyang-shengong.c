// jiuyang-shengong.c ������
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
	int lvl = (int)me->query_skill("jiuyang-shengong", 1);

	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("��Ļ����ڹ���򻹲�����������ѧϰ�����񹦡�\n");

	return valid_public(me);
}

int practice_skill(object me)
{
	return notify_fail("������ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
	return __DIR__"jiuyang-shengong/" + func;
}

int help(object me)
{
	write(HIC"\n�����񹦣�"NOR"\n");
	write(@HELP

    ���������ԡ������澭����
    ���������е�һ������٤�����еļз�֮�У���Ħ��ʦ������
д��һ�����飬��Ϊ�������澭�����������澭���м������ǿ��
���塢�׽�ϴ��ķ��ţ���Զ��ʦ������ϰ���������Ӻ���������
�ô��飬Ϊ�ӱ�׷�ɣ�����Գ����ֱ������֮�󣬷������޼�����
���ɾ��İ�Գ����żȻȡ�ã������񹦲��ؼ����ա�

    �����⹦Ч��

	ѧϰҪ��
		�����ڹ�10��
HELP
	);
	return 1;
}


// bibo-shengong.c �̲���
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

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me)
{
	int lvl = (int)me->query_skill("bibo-shengong", 1);

	if ( me->query_skill("force", 1) < 10)
		return notify_fail("��Ļ����ڹ����������\n");
	if ( me->query("gender") == "����" && lvl > 49)
		return notify_fail("���޸����ԣ���������������������ı̲��񹦡�\n");

	return valid_public(me);
}

int practice_skill(object me)
{
	return notify_fail("�̲���ֻ����ѧ�ģ����Ǵ�����(exert)�����������ȡ�\n");
}

string exert_function_file(string func)
{
	return __DIR__"bibo-shengong/" + func;
}
int help(object me)
{
	write(HIC"\n�̲��񹦣�"NOR"\n");
	write(@HELP

    ���Ƕ����һ�����ҩʦ������һ���ڹ��ķ�����˵������ҩʦ��
�����ϣ������̺��������̲���ӿ�����ƾ��ˣ�������˲���֮�࣬
��Ȼ���򣬴���һ�������������ϵ��ڹ�����ν�̲��񹦡�

	ѧϰҪ��
		�����ڹ�10��
		̫���޷�����50�����ϵı̲���
HELP
	);
	return 1;
}


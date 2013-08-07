// bahuang-gong.c �˻�����Ψ�Ҷ���
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>;
#include "force.h";
inherit FORCE;

string type() { return "martial"; }
string martialtype() { return "force"; }
int valid_enable(string usage) { return usage == "force"; }
int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 10; }
int power_point(object me) { return 1; }

int valid_learn(object me)
{
	if ((string)me->query("family/master_id")!="ju jian"
	&& (string)me->query("family/master_id")!="mei jian"
	&& (string)me->query("family/master_id")!="tong lao"
	&& (string)me->query("family/master_id")!="xu zhu")
	return notify_fail("ֻ�����չ����µ��Ӳ���ѧϰ�˻�����Ψ�Ҷ��𹦡�\n");
	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("��Ļ����ڹ���򻹲�����\n");
	return valid_public(me,"beiming-shengong");
}
int practice_skill(object me)
{
	return notify_fail("�˻�����Ψ�Ҷ���ֻ����ѧ(learn)������ߡ�\n");
}
string exert_function_file(string func)
{
	return __DIR__"bahuang-gong/" + func;
}
int help(object me)
{
	write(HIC"\n�˻�����Ψ�Ҷ��𹦣�"NOR"\n");
	write(@HELP

    �˻�����Ψ�Ҷ��������չ��������ϵ��ڹ����������ϳ���
��Ϊ�������⹦���������ȴ��һ�����Ĳ���֮����ÿ��ʮ�꣬
��Ҫ���ϻ�ͯһ�Ρ�

	ѧϰҪ��
		���չ�����
		�����ڹ�10��
HELP
	);
	return 1;
}


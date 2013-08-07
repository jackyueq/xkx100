// dulong-dafa.c �ߵ�  ������
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
	mapping skills;
	string *sname;

	int lvl = (int)me->query_skill("dulong-dafa", 1);
	int t = 1, i, j;
	int other_force = 0;

	for (j = 1; j < lvl / 10; j++) t *= 2;
/*
	if (!me->query("yijin_wan"))
		return notify_fail("��δ����ʳ�����ı�̥�׾��裬û�и������޷�ѧϰ�����󷨡�\n");

	if (me->query("yijin_wan") < me->query("age") - 13 )
		return notify_fail("��δ��ÿ�갴�ڷ�ʳ�����ı�̥�׾��裬�޷�����ѧϰ�����󷨡�\n");

*/
	if ( (int)me->query_skill("force", 1) < 10 ||
		(int)me->query_skill("force", 1)/2 < lvl/3 )
		return notify_fail("��Ļ����ڹ���򻹲������޷���ᶾ���󷨡�\n");
	if (lvl > 10 && (int)me->query("shen") > t * 100 &&
		(me->query_skill("taoism", 1) ||
		me->query_skill("buddhism", 1)) )
		return notify_fail("���в�����ѧϰ�����󷨡�\n");
	return valid_public(me);
}

int practice_skill(object me)
{
	return notify_fail("������ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
	return __DIR__"dulong-dafa/" + func;
}

int help(object me)
{
	write(HIC"\n�����󷨣�"NOR"\n");
	write(@HELP

    ������Ϊ�����̱����ڹ���

	ѧϰҪ��
		�����ڹ�10��
		������ϰ���ڻ�����ķ�
HELP
	);
/*		���ڷ�ʳ��̥�׾��� */
	return 1;
}


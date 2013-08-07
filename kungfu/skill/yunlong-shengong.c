// yunlong-shengong.c ������
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
	int i, nb, nf, nh, ns, ts;
	nb = (int)me->query_skill("yunlong-xinfa", 1);
	nf = (int)me->query_skill("force", 1);
	nh = (int)me->query_skill("yunlong-shengong", 1);

	if ( me->query("gender") == "����" && nh > 49)
		return notify_fail("���޸����ԣ���������������������������񹦡�\n");

  if ( nb < 100 && nb <= nh )
		return notify_fail("��������ķ���Ϊ�������޷���������������񹦡�\n");

	if ( nf < 10)
		return notify_fail("��Ļ����ڹ���򻹲������޷���������񹦡�\n");

	return valid_public(me);
}

int practice_skill(object me)
{
	return notify_fail("�����ڹ�ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
	return __DIR__"yunlong-shengong/" + func;
}
int help(object me)
{
	write(HIC"\n�����񹦣�"NOR"\n");
	write(@HELP

    ��ػ᱾���ڹ����������Ƽ��˹�֮������;��


	ѧϰҪ��
		��Ӧ�������ķ�
		�����ڹ�10��
		̫���޷�ѧ���ߵȼ���������
HELP
	);
	return 1;
}


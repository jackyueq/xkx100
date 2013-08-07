// zhanzhuang-gong.c ������ ��ƽ����վ׮��
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
{
	int i, nb, nf, nh, ns, ts;

	nb = (int)me->query_skill("buddhism", 1);
	nf = (int)me->query_skill("force", 1);
	nh = (int)me->query_skill("zhanzhuang-gong", 1);
	ns = (int)me->query("guilty");

	if ( me->query("couple/have_couple") )
		return notify_fail("�㳾Եδ�ˣ��޷�ѧϰ��ƽ����վ׮����\n");
	if ( me->query("sex/number") )
		return notify_fail("���Ѿ�����ɫ�䣬�޷���ѧϰ��ƽ����վ׮����\n");
	if ( nb < 100 && nb <= nh )
		return notify_fail("��������ķ���Ϊ�������޷������������ƽ����վ׮����\n");
	if ( nf < 10)
		return notify_fail("��Ļ����ڹ���򻹲������޷������ƽ����վ׮����\n");
	if ( ns > 0 ) 
		return notify_fail("���ŷ�ɮ�����䣬�޷������������ƽ����վ׮����\n");

  return valid_public(me,"yijinjing");
}

int practice_skill(object me)
{
	return notify_fail("��ƽ����վ׮��ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
	return __DIR__"zhanzhuang-gong/" + func;
}
int help(object me)
{
	write(HIC"\nվ׮����"NOR"\n");
	write(@HELP

    վ׮��ȫ����ƽ����վ׮����Ϊ�������ɱ����ڹ���
    ��������ע�ظ�����Ҫ�������վ�ȣ����ն�����ϰ����ƽָ����
����׮ʱ��ͷƽ����ƽ����ƽ��ϥƽ����ϰʱ��������ˮ������Щ��λ��
��ϰ�����У�������ˮ�����

	ѧϰҪ��
		�����ڹ�10��
		�����ķ���Ϊ��������ƽ����վ׮��
		������������
HELP
	);
	return 1;
}


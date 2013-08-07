// yijinjing.c ���� �׽��
// Last Modified by sega on Mar. 10 2000
// Feb.21 1998 by Java

#include <ansi.h>
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
	mapping skl = me->query_skills();
	string *sk;
	string skl_name = explode(__FILE__, "/")[<1][0..<3];
	int i, nb, nf, oh, oh1, nh, ns, ts;
	nb = (int)me->query_skill("buddhism", 1);
	nf = (int)me->query_skill("force", 1);
	oh = (int)me->query_skill("hunyuan-yiqi", 1);
	oh1 = (int)me->query_skill("zhanzhuang-gong", 1);
	nh = (int)me->query_skill("yijinjing", 1);
	ns = (int)me->query("guilty");

	if ( oh + oh1 < 100 )
		return notify_fail("��������ڹ�̫�ͣ��޷�ѧϰ�׽�񹦣�\n");
	if ( me->query("couple/have_couple") )
		return notify_fail("�㳾Եδ�ˣ��޷���ѧϰ�׽�񹦣�\n");
	if ( me->query("sex/number") )
		return notify_fail("���Ѿ�����ɫ�䣬�޷���ѧϰ�׽�񹦣�\n");
	if ( me->query("gender") != "����" )
		return notify_fail("���ͯ��֮�壬������ϰ�׽�񹦡�\n");

	if ( nb < 100 && nb <= nh )
		return notify_fail("��������ķ���Ϊ�������޷�����������׽�񹦡�\n");

	if ( nf < 10)
		return notify_fail("��Ļ����ڹ���򻹲������޷�����׽�񹦡�\n");

	if ( ns > 0 ) 
		return notify_fail("���ŷ�ɮ�����䣬�޷�����������׽�񹦡�\n");

	return valid_public(me,({"zhanzhuang-gong","hunyuan-yiqi"}));
}

int practice_skill(object me)
{
	return notify_fail("�׽��ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
	return __DIR__"yijinjing/" + func;
}

//add by sega
mixed be_hit_ob(object me,object victim,int damage_bonus,int factor)

//factor= ���� damage_bonus=���� .
{
	int ap,dp;
//�ڹ����̫��(����2������),�����˺�ȫ������,�����ϲ�����
	ap=me->query_skill("force");
	dp=victim->query_skill("force");
	if ((int)random(ap/2)>dp && me->query("neili")>2000)
	{

		if (random(10)==1) tell_object(victim, "��ֻ������ͬ���ڽ����ϣ�ͷ��������һ����ͷ�������֣�\n");
		else tell_object(victim,HIY"��ֻ���þ�����ͬ���ڽ����֣������޷������ֺ���\n"NOR);
		tell_object(me, HIY"��ֻ���þ���Ϯ�壬��æ����������񹦣�һ����������ȫ��\n"NOR);
		me->add("neili",-2*damage_bonus);
		return -damage_bonus;
	}
	else if ((random(ap*2)>dp) && me->query("neili")>1500)
	{
		if (random(10)==1) tell_object(victim,HIY"��ֻ������ͬ���ڽ����ϣ�ͷ��������һ����ͷ���������֡���\n"NOR);
		else tell_object(victim,HIY"��ֻ���þ�����ͬ���ڽ����ϣ�����������ʹ��\n"NOR);
		tell_object(me, HIY"��ֻ���þ���Ϯ�壬������������֣�һ����������ȫ��\n"NOR);
		me->add("neili",-damage_bonus);
		return -random(damage_bonus);
	}
	return 0;
}

int help(object me)
{
	write(HIC"\n�׽�񹦣�"NOR"\n");
	write(@HELP

    ���׽����ϴ�衷������Ϊ��������֮�����ഫΪ��Ħ��ʦ
���������в������ø�ɮ���٤��������������ϰ�����ѣ���ÿ�
�ơ����࣬���ࡱ�����в�����ϰ�书֮����������Ӻ�������
�ߡ�
    ��ϴ�衷�������������书�ľ�Ҫ�����׽����һ�ż����
����ڹ��ķ��鼮��

	ѧϰҪ��
		δ��ɫ���ͯ��֮��
		δ����
		��Ԫһ����100��
		��Ӧ����������ķ�
HELP
	);
	return 1;
}


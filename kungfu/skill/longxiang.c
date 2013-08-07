// longxiang.c ���������
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
	int i = (int)me->query_skill("longxiang", 1);
     //   int t = 1, j;
     //	for (j = 1; j < i / 10; j++) t*= 2;

	if (((string)me->query("class") != "lama") && i > 29)
		return notify_fail("�㲻��ɮ�ˣ�ѧ���˸���������������\n");

	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("��Ļ����ڹ�����㣬����ѧ�����������\n");

	if ( me->query("gender") == "����" && i > 49)
		return notify_fail("���޸����ԣ���������������������������������\n");

	if (i > 10 && (int)me->query("shen") >  - i * 1000)
		return notify_fail("Ҫѧ�������������ı��ֻ������ɣ� \n");
  return valid_public(me,"xiaowuxiang");
}

int practice_skill(object me)
{
	return notify_fail("���������ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
	return __DIR__"longxiang/" + func;
}
int help(object me)
{
	write(HIC"\n�����������"NOR"\n");
	write(@HELP

    ��������������������������������ϵĻ����񹦡�Ϊѩɽ��
�����ڹ�����������������Ե�������ʮ�����ϣ�ÿ��һ�У�����
ʮ��ʮ��Ĵ������������������������

    �����������������ʮ���㣬��һ�㹦��ʮ��ǳ�ף���������
֮�ˣ�ֻҪ�õ����ڣ�һ�����м������ɡ��ڶ���ȵ�һ�����һ
������ʱ�����ꡣ�������ֱȵڶ������һ������ʱ�߰��ꡣ���
�ɱ�������Խ������Խ�ѽ�չ������������Ժ���������һ�㣬
����������ʮ�����Ͽ๦������һ�ţ���ɮ��ʿ��������������һ
ʮ���㡰�����������ȴ��δ��һ������ʮ�����ϡ��⹦��ѭ��
�����������޲�������֮�������˵���ǧ����䣬���ձ����ʮ
���㾳�磬ֻ���������ޣ������еĸ�ɮ��ʿ������������֮ǰ��
�����߲㡢�ڰ˲㣬��ǵ�������ɣ���һ�����������������ٲ�
��Ĵ�Σ����������䣬�ر�����һλ��ɮ�����˵ھŲ㣬������
�;�������������ʮ��ʱ����ħ�����޷����ƣ����ڿ���������
ҹ�����վ���������

	ѧϰҪ��
		�����ڹ�10��
		��Ӧ������
		�ǳ������ﲻ��ѧ��30�����ϵ����������
		̫�಻��ѧ��50�����ϵ����������
HELP
	);
	return 1;
}


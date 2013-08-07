// xiaowuxiang.c С���๦
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>;
inherit FORCE;
#include "force.h"
string type() { return "martial"; }
string martialtype() { return "force"; }

int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 10; }
int power_point() { return 1; }

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
	int i = (int)me->query_skill("xiaowuxiang", 1);

	if (((string)me->query("class") != "lama") && i > 29)
		return notify_fail("�㲻��ɮ�ˣ�ѧ���˸����С���๦��\n");

	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("��Ļ����ڹ�����㣬����ѧС���๦��\n");

	if ( me->query("gender") == "����" && i > 49)
		return notify_fail("���޸����ԣ����������������������С���๦��\n");

//       if (i > 10 && (int)me->query("shen") < t * 100)
  //      	return notify_fail("ҪѧС���๦����ı��ֻ������ɣ� \n");


	return valid_public(me,"longxiang");
}

int practice_skill(object me)
{
	return notify_fail("С���๦ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
	return __DIR__"xiaowuxiang/" + func;
}
int help(object me)
{
	write(HIC"\nС���๦��"NOR"\n");
	write(@HELP

    С���๦�˱��������ң�ɵ��ڹ�֮һ����ң�ڹ���Ϊ��ڤ��
�����˻�����Ψ�Ҷ��𹦼�С���๦���֣���ң��������ң�Ӿ�ͨ
��ڤ�񹦣���ɽͯ��ר�ð˻�����Ψ�Ҷ��𹦣���ʦ������̫����
��ˮ�����С���๦��Ϊ�����������Ϊ��ެ��ʦ�Ħ�����ã���
Ϊѩɽ���ڹ���С���๦��΢�����֮�߶�ѩɽ����֮���浶��
�����������־���֮�¡�

	ѧϰҪ��
		�ǳ���Ϊ����ѧ����30�����ϵ�С���๦
		̫��ѧ����50�����ϵ�С���๦
		�����ڹ�10
		��Ӧ������
HELP
	);
	return 1;
}


// xidu-poison.c ��������
// Last Modified by winder on Mar. 10 2000
// Modified by Java Mar.1998

#include <ansi.h>;
inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }
int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 30; }
int power_point(object me) { return 1; }

int valid_learn(object me)
{
	mapping myfam;
	myfam = (mapping)me->query("family");
	if (!myfam || (myfam["family_name"] != "����ɽ��"))
		return notify_fail("�㲻�ǰ���ɽ���ӣ�������������������\n");
	if (me->query("shen")<=0) 
	  return notify_fail("������������Ҫ�ĺ�����������������ı��ֻ�������\n");
	return 1;
}

int practice_skill(object me)
{
	return notify_fail("��������ֻ�ܿ�ѧϰ����ߡ�\n");
}
int help(object me)
{
	write(HIC"\n����������"NOR"\n");
	write(@HELP

    ���������¶��ؾ��书���¶���Ч�������������ĸߵ��кܴ�
�Ĺ�ϵ��

	ѧϰҪ��
		�������ɵ��ķ�����ѧ
		�ǰ���ɽ�ɵ��Ӳ���ѧ
HELP
	);
	return 1;
}


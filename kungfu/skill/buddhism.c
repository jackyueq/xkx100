// buddhism.c �����ķ�
// Last Modified by winder on Mar. 10 2000

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
	if( (int)me->query("guilty") > 0 )
		return notify_fail("���ŷ�ɮ�����䣬����֮��̫�أ��޷����������ķ���\n");
	if ( me->query_skill("taoism",1) > 1)
		return notify_fail("����ѧ�˵�ѧ�ķ�����ô�����������ķ���\n");
	if ((me->query_skill("ziyunyin",1) > 1) ||
		(me->query_skill("zhengqijue",1) > 1))
		return notify_fail("����ѧ�˻�ɽ�ķ����������������ķ���\n");
	if (me->query("class") != "bonze")
		return notify_fail("�㷲���أ������ң���ô�����������ķ���\n");
	if (me->query_skill("buddhism", 1) >= 150)
		return notify_fail("�������ʣ���������ķ������Ҳ�͵���Ϊֹ�ˡ�\n");
	return 1;
}
int practice_skill(object me)
{
	return notify_fail("�����ķ�ֻ�ܿ�ѧ(learn)����ߡ�\n");
}

int help(object me)
{
	write(HIC"\n�����ķ���"NOR"\n");
	write(@HELP

    ���ֵ��ӵı��޿Ρ������ɴ�����ʦ��Ħ�����������ڴ�ʦ��
���Ƕ������ڵ�һ�棬���ֵ�����Ӧ����ϰ���ڣ����з�Ϊ�Ρ�
��ϻ�Ԫһ�������Գ����������ӵĳ̶�ȡ���ڻ�Ԫһ����������
�ķ��ȼ��ĸߵ͡�

	ѧϰҪ��
		�����ǳ������޷�����
                ������ķ�����������ܼ�ѧ
HELP
	);
	return 1;
}


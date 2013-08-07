// poison.c ��������
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
	if (!myfam || (myfam["family_name"] != "������"))
		return notify_fail("�㲻�����޵��ӣ���������������\n");
	if((myfam["master_id"]!="ding chunqiu")&&
		(me->query_skill("poison",1) > 120))
		return notify_fail("��ֻ���򶡴���ѧϰ������Ķ�����\n");	
	if((me->query_skill("taoism",1) > 1 ) ||
		(me->query_skill("buddhism",1) > 1) ||
		(me->query_skill("ziyunyin",1) > 1) ||
		(me->query_skill("zhengqijue",1) > 1))
		return notify_fail("������"+ RANK_D->query_respect(me)+"�Ѿ�ѧ���������ɵ��ķ�����ôȴ��ѧ���ǲ��ܵĶ�����\n");
	if (me->query_skill("poison", 1) >= 150)
		return notify_fail("�������ʣ���Ի������������Ҳ�͵���Ϊֹ�ˡ�\n");
	return 1;
}

void skill_improved(object me)
{
	if ((me->query_skill("poison",1) == 50) ||
		(me->query_skill("poison",1) == 60) ||
		(me->query_skill("poison",1) == 70) ||
		(me->query_skill("poison",1) == 80) ||
		(me->query_skill("poison",1) == 90) ||
		(me->query_skill("poison",1) >= 100))
	{
		tell_object(me, "�����ڵĶ��ʿ�ʼ���������ˣ�������ɢ���ˡ�\n");
		me->apply_condition("poison_sandu",1000);
	}
}

int practice_skill(object me)
{
	return notify_fail("��������ֻ�ܿ�ѧϰ����ߡ�\n");
}
int help(object me)
{
	write(HIC"\n����������"NOR"\n");
	write(@HELP

    ���޵����¶��ؾ��书���¶���Ч���ͻ��������ĸߵ��кܴ�
�Ĺ�ϵ�������ڶ��ط�������ʱ��������ɢ����

	ѧϰҪ��
		�������ɵ��ķ�����ѧ
		�������ɵ��Ӳ���ѧ
HELP
	);
	return 1;
}


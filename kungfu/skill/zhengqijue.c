// zhengqijue.c ������
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }
int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 30; }
int power_point(object me) { return 1; }

int valid_learn(object me)
{
	if (me->query_skill("zixia-shengong",1) < 30)
		return notify_fail(RANK_D->query_respect(me)+"����ɽ�Ź�����ϼ��һ����ѧ�˶��٣�\n");
	if (me->query_skill("buddhism",1) > 1)
		return notify_fail(RANK_D->query_respect(me)+"�Ȳη𷨣����������һ�ɽ����������ĵ���\n");
	if( (int)me->query_skill("taoism",1) > 1 )
		return notify_fail("��ѧ��̫�ϵ���֮�ķ������������һ�ɽ����������ĵ���\n");
	if ((me->query_skill("poison",1) > 1))
		return notify_fail("������"+ RANK_D->query_respect(me)+"�Ѿ�ѧ��аħ����Ķ�������ô���������������\n");
	if ((me->query_skill("lamaism",1) > 1))
		return notify_fail("������"+ RANK_D->query_respect(me)+"�Ѿ�ѧ�������ķ����������������ˣ�\n");
	if (me->query_skill("zhengqijue", 1) >= 100)
		return notify_fail("�������ʣ���������������Ҳ�͵���Ϊֹ�ˡ�\n");
	return 1;
}

int practice_skill(object me)
{
	return notify_fail("������ֻ�ܿ�ѧ(learn)����ߡ�\n");
}
void skill_improved(object me)
{
	tell_object(me, HIR "������ĵ���һ������֮����\n" NOR );
//	me->add("shen", 200);
}

int help(object me)
{
	write(HIC"\n��������"NOR"\n");
	write(@HELP

    ������Ϊ��ɽ�ķ��������ϼ������������
    ��Ѱ���������Ķ���

	ѧϰҪ��
		��ϼ��30��
		����ѧϰ���Ż����ķ�����������
HELP
	);
	return 1;
}


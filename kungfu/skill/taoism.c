// taoism.c ��ѧ�ķ�
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
	int lvl;

	lvl = (int)me->query_skill("taoism", 1);

	if( (int)me->query("shen") < 0 )
		return notify_fail("�������̫�أ��޷�������ѧ�ķ���\n");
	if(me->query("gender") == "����" && lvl > 39)
		return notify_fail("�����һ�������������Ժ���ԭ����û������֮
�����޷��������������仯֮����\n");
	if ((me->query_skill("buddhism",1) > 1) ||
		(me->query_skill("mahayana",1) > 1))
		return notify_fail( "������"+RANK_D->query_respect(me)+"������ţ���ôȴ��ѧ��ѧ�ķ���\n");
	if ((int)(me->query_skill("lamaism",1) > 1))
		return notify_fail( "������"+RANK_D->query_respect(me)+"�Ѿ�ѧ�������ķ�����ôȴ��ѧ��ѧ�ķ���\n");
	if ((me->query_skill("ziyunyin",1) > 1) ||
		(me->query_skill("zhengqijue",1) > 1))
		return notify_fail( "������"+RANK_D->query_respect(me)+"�Ѿ�ѧ�˻�ɽ�ɵ��ķ�����ôȴ��ѧ��ѧ�ķ���\n");
	if ((int)(me->query_skill("poison",1) > 1))
		return notify_fail( "������"+RANK_D->query_respect(me)+"�Ѿ�ѧ��аħ����Ķ�������ôȴ��ѧ��ѧ�ķ���\n");
	if (me->query_skill("taoism", 1) >= 150)
		return notify_fail("�������ʣ���Ե�ѧ�ķ������Ҳ�͵���Ϊֹ�ˡ�\n");

	return 1;
}

int practice_skill(object me)
{
	return notify_fail("��ѧ�ķ�ֻ�ܿ�ѧϰ����ߡ�\n");
}

int help(object me)
{
        write(HIC"\n��ѧ�ķ���"NOR"\n");
        write(@HELP

    ̫�ϵ��洫�µĵ���������ǧ�����̺��Ĳ�������ķ���
    ��Ѱ�ҵ��¾��Ķ���

        ѧϰҪ��
                �������ķ��������ķ�����������������ͻ����������ܼ�ѧ
HELP
        );
        return 1;
}


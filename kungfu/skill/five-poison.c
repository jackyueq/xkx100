// five-poison.c �嶾����
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>;
inherit SKILL;

string type() { return "knowledge"; }
int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 30; }
int power_point(object me) { return 1; }

void skill_improved(object me)
{}

int valid_learn(object me)
{
        mapping myfam;
        myfam = (mapping)me->query("family");
        if (!myfam || (myfam["family_name"] != "�嶾��"))
                return notify_fail("�㲻���嶾�̵��ӣ����������嶾������\n");
        return 1;

}

int help(object me)
{
	write(HIC"\n�嶾������"NOR"\n");
	write(@HELP

    �嶾����Ϊ�����嶾�̶��Ŷ�����Ҳ�����ö��ļ��ɣ����嶾
�̵��ӱ��޵Ĺ��򣬹�ϵ��Ͷ���ĳɰܺͰ������˺�����

	ѧϰҪ��
		��
HELP
	);
	return 1;
}


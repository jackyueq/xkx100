// dodge.c �����Ṧ
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>;
inherit SKILL;

string type() { return "martial"; }
string martialtype() { return "dodge"; }
int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 30; }
int power_point(object me) { return 1; }

string *dodge_msg = ({
	"���Ǻ�$p$lƫ�˼��硣\n",
	"���Ǳ�$p����ض㿪�ˡ�\n",
	"����$n����һ�࣬���˿�ȥ��\n",
	"���Ǳ�$p��ʱ�ܿ���\n",
	"����$n����׼�������Ų�æ�Ķ㿪��\n",
});

string query_dodge_msg()
{
	return dodge_msg[random(sizeof(dodge_msg))];
}
int help(object me)
{
	write(HIC"\n�����Ṧ��"NOR"\n");
	write(@HELP

    �Ṧ���似�Ļ����������ܸ�������������
    �Ṧ�ߵ�һ���̶ȿ������׶ɺ�(cross)����ϰһЩ�ر���Ṧ
����Ϊ���״ﵽ����������

	ѧϰҪ��
		��
HELP
	);
	return 1;
}


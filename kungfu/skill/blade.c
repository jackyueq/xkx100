// blade.c ��������
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 30; }
int power_point(object me) { return 1; }

int help(object me)
{
	write(HIC"\n����������"NOR"\n");
	write(@HELP

    �����似�Ļ�������
    ����������Ҫ����֮һ�����д󵶱���Ϊ���ٱ�֮˧��������
���ͻ���ǹ��������������������һ��һʽ��Ҫ�����䡢���ҵ���
��������ʹ���ص��ǲ�ͷ���ԡ���ת��ɨ���ù��ƴ̡��м�Ĩ���ȣ�
���е������֡�˫�����ߡ��󵶿����֣������á�ն�������ͻ�֮
˵�� 

	ѧϰҪ��
		��
HELP
	);
	return 1;
}


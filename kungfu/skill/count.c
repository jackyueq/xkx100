// count.c ��������
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>;
inherit SKILL;

string type() { return "knowledge"; }
int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 10; }
int power_point(object me) { return 1; }

void skill_improved(object me) {}

int valid_learn(object me)
{
	object ob;

	mapping myfam;
	myfam = (mapping)me->query("family");
	if(!myfam || myfam["family_name"] != "�һ���"|| myfam["master_id"] != "huang yaoshi")
		return notify_fail("ֻ�л�ҩʦ�ĵ��Ӳ���ѧ�������ԡ�\n");
	if( (int)me->query_skill("literate",1) < 50 )
		return notify_fail("��Ķ���д��̫�ͣ�û�а취ѧ�������ԡ�\n");

	return 1;
}

int practice_skill(object me)
{
	return notify_fail("��������ֻ����ѧ(learn)�������������ȡ�\n");
}
int help(object me)
{
	write(HIC"\n�������ԣ�"NOR"\n");
	write(@HELP

    �һ������ӿ���ƾ�˼��ܲ�֪���Ŀǰ���ڵ�λ�á�����ͨ��
�Ķ�����ͼ���������顷��ߡ�
    ��help location��

	ѧϰҪ��
		����д��50��
		��Ϊ��ҩʦ�մ�����
HELP
	);
	return 1;
}


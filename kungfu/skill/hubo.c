// hubo.c ���һ���
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>;
inherit SKILL;

string type() { return "knowledge"; }
int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 30; }
int power_point(object me) { return 1; }

int valid_learn(object me) 
{
	if( (int)me->query("int") > 24 )
		return notify_fail("������Բ��ʺ�ѧϰ���һ���֮����\n" ) ;
	if( (int)me->query("cps") < 20 )
		return notify_fail("������Բ��ʺ�ѧϰ���һ���֮����\n" ) ;
	if( !me->query("double_attack") )
		return notify_fail("���һ���֮��Ҫ���ܲ�ͨ�ֽ̣�\n" ) ;
	if( me->query_skill("qimen-wuxing"))
    return notify_fail("�����ѧ̫�࣬һʱ�޷�������һ�����\n");
	return 1;
}
int help(object me)
{
	write(HIC"\n���һ�����"NOR"\n");
	write(@HELP

    ���һ������ܲ�ͨ���һ�������ʮ���꣬����û�˲��У�ֻ��
���ֺ����ִ����������á���Ҫּ�ǡ��ķֶ��ã����ֻ�������
�ֻ�Բ�������һ����ɳƵ����������ص��书����˫�ַ�ʹ��ͬ��
����ͬʱ�������ˡ�ȻΨ�д�������֮�ˣ���һ�����ڣ�һ�����⣬
��������Ů�ľ����������������������ϰ֮��

	ѧϰҪ��
		�������Բ�����24��
		�����츳����
HELP
	);
	return 1;
}


// linji-zhuang.c �ټ�ʮ��ׯ
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#include "force.h";
inherit FORCE;
string type() { return "martial"; }
string martialtype() { return "force"; }

int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 10; }
int power_point(object me) { return 1; }

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
	int i, np, nf, nh, ns, ts;
	nf = (int)me->query_skill("force", 1);
	nh = (int)me->query_skill("linji-zhuang", 1);
	np = (int)me->query_skill("mahayana", 1);
	ns = (int)me->query("guilty");

	if ( me->query("couple/have_couple") )
		return notify_fail("�㳾Եδ�ˣ��޷���ѧϰ�ټ�ʮ��ׯ��\n");

	if ( me->query("sex/number") )
		return notify_fail("���Ѿ�����ɫ�䣬�޷���ѧϰ�ټ�ʮ��ׯ��\n");

	if ( me->query("gender") != "Ů��" )
		return notify_fail("��Ǵ�Ů֮�壬������ϰ�ټ�ʮ��ׯ��\n");


	if (((string)me->query("class") != "bonze") && i > 29)
		return notify_fail("�㲻����ã�ѧ���˸�����ټ�ʮ��ׯ��\n");

	if ( np <= nh && nh <= 150)
		return notify_fail("��Ĵ�����͹���Ϊ�������޷�����������ټ�ʮ��ׯ��\n");

	if ( nf < 10)
		return notify_fail("��Ļ����ڹ���򻹲������޷�����ټ�ʮ��ׯ��\n");

	if ( ns > 0 ) 
		return notify_fail("���ŷ�ɮ�����䣬�޷�����������ټ�ʮ��ׯ��\n");

	return valid_public(me);
}

int practice_skill(object me)
{
	return notify_fail("�ټ�ʮ��ׯֻ����ѧ(learn)�������������ȡ�\n");
}

void skill_improved(object me)
{
	switch (me->query_skill("linji-zhuang",1))
	{
		case 30:
			tell_object(me, HIG "�����ׯ������! \n" NOR );
			break;
		case 60:
			tell_object(me, HIG "��֮��ׯ������! \n" NOR );
			break;
		case 90:
			tell_object(me, HIG "������ׯ������! \n" NOR );
			break;
		case 120:
			tell_object(me, HIG "�����ׯ������! \n" NOR );
			break;
		case 150:
			tell_object(me, HIG "���Сׯ������! \n" NOR );
			break;
		case 180:
			tell_object(me, HIG "����ڤׯ������! \n" NOR );
			break;
	}
	return;
}
string exert_function_file(string func)
{
	return __DIR__"linji-zhuang/" + func;
}

int help(object me)
{
	write(HIC"\n�ټ�ʮ��ׯ��"NOR"\n");
	write(@HELP

    �ټ�ʮ��ׯ����������������������˳���ǣ����֮�ġ�����
���ơ���С��ڤ������������;����ʼ�ڵ��Ҷ����ڷ�ҵ�������
�����硣ʮ��ׯ�ֱ���ʮ�����ֱ������ֿɷֱ��Ϊ����ׯ������
ׯ��֮��ׯ������ׯ������ׯ������ׯ������ׯ��Ʈ��ׯ������ׯ��
С��ׯ������ׯ��ڤ��ׯ��ÿ����һׯ���ж�������Ī��ô�����
���ǵ���ʮ��ׯ��Ϊ�����ڻ��ͨʱ����ָ��ء�֮�ġ���С����
�ס����ơ���ڤ������������Ϊ�������棬�������ӿ���ʹ�õ���
�����칦�ܡ����ܹ�ͨ��ڤ��ׯ���������������ɵ���������ʿ��
��������������ᡢˮ��ȼõľ��硢����ͨ�����鵤֮���
    �ټ�ʮ��ׯ������Ϊ�������ˣ���Ч�̶ȱ������ڹ��ߣ�����
���������ơ�

	ѧϰҪ��
		��Ů����֮��
		�����˲�����ϰ30�����ϵ��ټ�ʮ��ׯ
		��Ӧ����Ĵ�����͹�
		�����ڹ�10��
		������
HELP
	);
	return 1;
}


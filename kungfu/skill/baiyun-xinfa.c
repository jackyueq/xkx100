// baiyun-xinfa.c �����ķ�
// Last Modify by sir 5/17/2001

#include <ansi.h>;
#include "force.h";
inherit FORCE;

string type() { return "martial"; }
string martialtype() { return "force"; }
int valid_enable(string usage) { return usage == "force"; }
int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 10; }
int power_point() { return 1; }

int valid_learn(object me)
{
	int i,nb,ny,ns;
	
	nb = (int)me->query_skill("buddhism", 1);
	ny = (int)me->query_skill("baiyun-xinfa", 1);
	ns = (int)me->query("guilty");

	if ( me->query("couple/have_couple") )
		return notify_fail("�㳾Եδ�ˣ��޷���ѧϰ�����ķ���\n");	
	if ( me->query("gender") != "Ů��" )
		return notify_fail("�����ķ�ֻ�ʺ�Ů��������\n");
	if ( me->query("sex/number") )
		return notify_fail("��Ǵ�Ů֮���޷���ϰ�����ķ���\n");	
	if (((string)me->query("class") != "bonze") && i > 29)
		return notify_fail("�㲻����ã�ѧ���˸���İ����ķ���\n");
	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("��Ļ����ڹ���򻹲�����\n");

	if ( nb < 100 && nb <= ny )
		return notify_fail("��������ķ���Ϊ�������޷���������İ����ķ���\n");
	if ( ns > 0 ) 
		return notify_fail("���ŷ�ɮ�����䣬�޷���������İ����ķ���\n");
	return valid_public(me);
	
}

int practice_skill(object me)
{
	return notify_fail("�����ķ�ֻ����ѧ(learn)�������������ȡ�\n");
}
string exert_function_file(string func)
{
	return __DIR__"baiyun-xinfa/" + func;
}

int help(object me)
{
	write(HIC"\n�����ķ���"NOR"\n");
	write(@HELP

  ��ɽ���ڹ�

	ѧϰҪ��
		�����ڹ�10��
		��Ů����֮��		
HELP
	);
        return 1;
}


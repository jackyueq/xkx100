// piaoyibu.c Ʈ�ݲ���
// Last Modified by sir on 10.18.2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype(object me) { return "dodge"; }

string *dodge_msg = ({
	"$nһ��"HIC"�����ضɺ���"NOR"��Ծ�����ߣ������$N��һ�С�\n",
	"$n�������һ�ݣ�ʹ��һ��"HIY"�������䳾��"NOR"���ܹ���$N�Ĺ�����\n",
	"$nʹ��"HIY"������ɳ��"NOR"��ǡ�ö����$N�Ĺ��ơ�\n",
	"$nһ��"MAG"������öݡ�"NOR"����̬����ض��˿�ȥ��\n"
});

int valid_enable(string usage) { return usage == "dodge" || usage == "move"; }
int valid_learn(object me) 
{      	
	if( (int)me->query_skill("kuihua-xinfa", 1) < 10 )
	return notify_fail("��Ŀ����ķ��������죬�޷����Ʈ�ݲ�����\n");
	return 1;
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 10|| (int)me->query("neili") < 2 )
		return notify_fail("�������̫���ˣ�������Ʈ�ݲ�����\n");
	me->receive_damage("qi", 10);
	me->add("neili", -2);	
	return 1;
}
string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int learn_bonus() { return 25; }
int practice_bonus() { return 25; }
int success() { return 20; }
int power_point(object me) { return 1.1; }

int help(object me)
{
	write(HIC"\nƮ�ݲ�����"NOR"\n");
	write(@HELP

    ������̺�ľ�±����Ṧ��

	ѧϰҪ��
	  �����ķ�10��
HELP
	);
	return 1;
}


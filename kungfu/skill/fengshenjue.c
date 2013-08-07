// fengshenjue.c  �����
// Last Modified by sir on 10.18.2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "dodge"; }

string *dodge_msg = ({
	"ֻ��$nʹ��" HIC"�������貨��"NOR"���¾�ƮƮ���������貨̤ˮ�����ټ������ѱܿ�������\n",
	"����$nʹ��" HIW"�������ȡ�"NOR"�����������ڿ��������߲�������$NѰ��֮�⡣\n",
	"$nһ��"HIY"���������ơ�"NOR"����̤���磬�Ʒ��������������ܹ�$N��һ�С�\n",
	"����$nһ��" HIC"��������ӿ��"NOR"�������类���������ƮƮ�����䵽$N���\n",
	"ȴ��$nʹ��" GRN"�����������"NOR"��һ��ż��أ���������������������$N���п����˿ա�\n",
	"$nʹ��"YEL "�������ɪ��"NOR"��һ�����أ�ͦ��ǰ�У�����׳ʿһȥ������֮�ƣ�$N�����������壬ֻ���˿���\n",
});

int valid_enable(string usage) { return (usage=="dodge") || (usage=="move"); }
int valid_learn(object me) 
{      	
	if( (int)me->query_skill("panshi-shengong", 1) < 10 )
	return notify_fail("�����ʯ�񹦲������죬�޷����������\n");
	return 1;
}

int practice_skill(object me)
{
	if( (int)me->query("qi") < 30 || (int)me->query("neili") < 6 )
		return notify_fail("�������̫���ˣ��޷���ϰ�������\n");
	me->receive_damage("qi", 30);
	me->add("neili", -6);
	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int learn_bonus() { return 15; }
int practice_bonus() { return 15; }
int success() { return 15; }
int power_point(object me) { return 1.3; }

int help(object me)
{
	write(HIC"\n�������"NOR"\n");
	write(@HELP

    ̩ɽ�ɵ��Ṧ����

	ѧϰҪ��
	   ��ʯ��10��
HELP
	);
	return 1;
}


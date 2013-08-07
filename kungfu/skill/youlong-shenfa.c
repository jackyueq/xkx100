// youlong-shenfa.c ������
// Last Modified by sir on 10.18.2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "dodge"; }

string *dodge_msg = ({
	"ֻ��$nһ��"HIC"��������졹"NOR"���ҽ������أ����塸ಡ������ϱ�ֱ������
���࣬�����$N��һ�С�\n",
	"$nһ��"HIY"�������ĺ���"NOR"��˫��һ�ţ�������ˮ������ݳ����ܿ���$N������
���ơ�\n",
	"$nʹ��"MAG"���������衹"NOR"�����β�ס���������ڶ��$N�Ĺ�����\n",
	"$nʹ��"BLU"��������Ӱ��"NOR"��$N��ǰһ�����Ѳ���$n��Ӱ��\n",
});

int valid_enable(string usage) { return (usage=="dodge") || (usage=="move"); }
int valid_learn(object me) 
{      	
	if( (int)me->query_skill("honghua-shengong", 1) < 10 )
	return notify_fail("��ĺ컨�񹦲������죬�޷������������\n");
	return 1;
} 
int practice_skill(object me)
{
	if( (int)me->query("qi") < 30 || (int)me->query("neili") < 6 )
		return notify_fail("�������̫���ˣ��޷���ϰ��������\n");
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
	write(HIM"\n��������"NOR"\n");
	write(@HELP

    �컨���Ṧ����

	ѧϰҪ��
		�컨��10��
HELP
	);
	return 1;
}

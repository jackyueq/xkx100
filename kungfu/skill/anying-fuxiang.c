// anying-fuxiang.c 
// Last Modified by sir on 10.18.2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "dodge"; }

string *dodge_msg = ({
"$nһ��"HIC"����������ͷ��"NOR"�����׻��ţ�������ţ�����$N�Ĺ���Ʈ�𣬴��ݶ�����С�\n",
"$nʹһ��"HIM"����Į����ֱ��"NOR"���������ţ�������ţ���Ȼ�������࣬���$N���˸��ա�\n",
"$n����һҡ���ó�������Ӱ��������ţ��������ţ�һ��"BLU"����Ӱ��б����"NOR"���$N�Ĺ��ơ�\n",
"$nһ��"HIM"����������ˮ��"NOR"����Ծ�𣬳������ţ��������ţ�ٿ��������$N���\n",
"$n��һҡ����һ�Σ��������ţ�����ȸ�ţ�һ��"HIW"�����֪����"NOR"������������\n",
"$n˫��һ�㣬бб���𣬳���ȸ�ţ���׻��ţ�ʹ��"HIM"��б���ӻ��ɡ�"NOR"��������$N��ࡣ\n",
});

int valid_enable(string usage) { return (usage=="dodge") || (usage=="move"); }
int valid_learn(object me) 
{      	
	if( (int)me->query_skill("bibo-shengong", 1) < 10 )
	return notify_fail("��ı̲��񹦲������죬�޷���ᰵӰ���㡣\n");
	return 1;
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 30|| (int)me->query("neili") < 6 )
		return notify_fail("�������̫���ˣ���������Ӱ���㡣\n");
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
	write(HIC"\n��Ӱ���㣺"NOR"\n");
	write(@HELP

    �һ����Ķ����Ṧ����

	ѧϰҪ��
	   �̲��� 10 �� 	
HELP
	);
	return 1;
}


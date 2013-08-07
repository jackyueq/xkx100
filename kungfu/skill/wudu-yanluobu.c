// wudu-yanluobu �嶾���ܲ�
// Last Modified by sir on 10.18.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "dodge"; }

string *dodge_msg = ({
HIB"$n���Ų�æ��һʽ����ˮ������������ٿ����һ��ƽ�����ߣ����������$N�Ĺ��ơ�\n"NOR,
HIB"$n��������Ȱ�һ�Σ�ɲ�Ǽ���Զȥ����֮�⣬$N��ʱ���˸��ա�\n"NOR,
BLU"$n���к��ļӿ죬��һ�����̰�����$N�ɿ���ת������$Nһ��ͷ���ۻ�����æ����������\n"NOR,
BLU"$n�����һЦ�����к��ı�����ʲ��壬$N��������ʽ��Ȼ͸�������ԭ������һ�߻�Ӱ��\n"NOR,
BLU"$n�����ж�ʱ�������һ����������$N����ʽ���Ұڶ�����ʹ��$N������ա�\n"NOR,
});

int valid_enable(string usage) { return (usage=="dodge") || (usage=="move"); }
int valid_learn(object me)
{      	
	if( (int)me->query_skill("wudu-shengong", 1) < 10 )
	return notify_fail("����嶾�񹦲������죬�޷�����嶾���ܲ���\n");
	return 1;
}

int practice_skill(object me)
{
	if( (int)me->query("qi") < 10|| (int)me->query("neili") < 2 )
		return notify_fail("�������̫���ˣ��������嶾���ܲ���\n");
	me->receive_damage("qi", 10);
	me->add("neili", -2);	
	return 1;
}
string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 20; }
int power_point(object me) { return 1.1; }

int help(object me)
{
	write(HIC"\n�嶾���ܲ���"NOR"\n");
	write(@HELP

    �嶾����ʦģ�¶��涯����������һ���Ṧ�����嶾�̱�����
����

	ѧϰҪ��
	   �嶾��10
HELP
	);
	return 1;
}


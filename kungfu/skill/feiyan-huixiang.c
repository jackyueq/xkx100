// feiyan-huixiang.c �������
// Last Modified by sir on 10.18.2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "dodge"; }

string *dodge_msg = ({
	"����$n����Ʈ��������һ�ݣ�һ��"GRN"������Ͷ�֡�"NOR"����������ıܿ���һ����\n",
	"$n������ת��һʽ"HIW"��ѩ�����衹"NOR"��ٿ����һ��Ʈ�����ߣ��ܹ�����һ�С�\n",
	"����$n����һ�ã�ʹ��"HIG"��������Ʈ��"NOR"��$N��һ�����˸��ա�\n",
	"ȴ��$n�㲻��أ�һ��"WHT"�����Ƽ���"NOR"�����ε�����һת�������������ߣ����˿�ȥ��\n",
	"$n���һ���ҽű�����������һ�Σ�һ��"HIC"��һ�׳��졹"NOR"���������ɵرܿ�����һ�С�\n",
});

int valid_enable(string usage) { return (usage=="dodge") || (usage=="move"); }
int valid_learn(object me)
{
	if( (int)me->query_skill("zixia-shengong", 1) < 10 )
	return notify_fail("�����ϼ�񹦲������죬�޷���������衣\n");
	return 1;
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 20 || (int)me->query("neili") < 4 )
		return notify_fail("�������̫���ˣ�������������衣\n");
	me->receive_damage("qi", 20);
	me->add("neili", -4);
	return 1;
}
string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int learn_bonus() { return 20; }
int practice_bonus() { return 20; }
int success() { return 20; }
int power_point(object me) { return 1.2; }

int help(object me)
{
	write(HIC"\n������裺"NOR"\n");
	write(@HELP

    �������Ϊ��ɽ�ɱ����Ṧ��

	ѧϰҪ��
	 ��ϼ��10��
HELP
	);
	return 1;
}


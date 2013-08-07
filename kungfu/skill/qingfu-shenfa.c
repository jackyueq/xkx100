// qingfu-shenfa.c ������
// Last Modified by sir on 10.18.2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "dodge"; }

string *dodge_msg = ({
	"ֻ��$nһ��"HIC"������Ǭ����"NOR"�����ζ�Ȼ���𣬶����$N��һ�С�\n",
	"$nһʽ"HIC"���������١�"NOR"�����λζ�����һ��Ʈ�����ܿ���$N��һ�С���\n",
	"$nʹ��"HIC"�����츣�ء�"NOR"��һ�����Ľ��󷭳����ܿ���$N���������ơ�\n",
	"$nһ��"HIC"����������"NOR"��������ת��$Nֻ����ǰһ����$n������$N�����\n",
});

int valid_enable(string usage) { return usage == "dodge" || usage == "move"; }
int valid_learn(object me)
{      	
	if( (int)me->query_skill("jiuyang-shengong", 1) < 10 )
	return notify_fail("��ľ����񹦲������죬�޷������������\n");
	return 1;
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 40|| (int)me->query("neili") < 8 )
		return notify_fail("�������̫���ˣ���������������\n");
	me->receive_damage("qi", 40);
	me->add("neili", -8);	
	return 1;
}
string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int learn_bonus() { return 10; }
int practice_bonus() { return 10; }
int success() { return 10; }
int power_point(object me) { return 1.4; }

int help(object me)
{
	write(HIC"\n��������"NOR"\n");
	write(@HELP

    ���̵ı����Ṧ������Ҫ�Ǵ�ΤһЦ���Ṧ��������

	ѧϰҪ��
		��
HELP
	);
	return 1;
}


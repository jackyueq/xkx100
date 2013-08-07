// yanling-shenfa.c ������
// Last Modified by sir on 18.10.2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "dodge"; }

string *dodge_msg = ({
	"$n�������ɵ�����һԾ���������࣬һʽ"BLU"�������Ϸɡ�"NOR"��$N��������ʱ�þ���\n",
	"$n���˷����������Ȼ�۽���һʽ"BLU"��һҶ��Ŀ��"NOR"���ſ�������$N��ǰһ�������$N���߱���������������ʱ����һ����\n",
	"$n˫����������ΰεض����ڿ���һ���շ���"HIW"��˫��ַɡ�"NOR"��Ծ��$N���\n",
	"$n�����������������ţ�һʽ"HIC"�����ӳ�����"NOR"��Ծ�ڼ��ɿ��⡣\n",
	"$n��һ������һת��б����һ�壬һʽ"GRN"������������"NOR"��Χ��$Nת�˰�Ȧ���ܿ���$N�ĳ��С�\n",
	"$nһ����Х��һʽ"HIM"����������"NOR"������𣬲����ù���$N���С�\n",
	"$n��$N�������ţ����˼�����ͻȻ���κ�죬����һʽ"HIM"�����ӻ�ͷ��"NOR"���������$N��һ�С�\n",
	"$nһʽ"HIB"�����Ϲ鳲��"NOR"��һ������ƮȻ����ת������$N���\n",
});

int valid_enable(string usage) { return (usage=="dodge") || (usage=="move"); }
int valid_learn(object me) 
{      	
	if( (int)me->query_skill("shenyuan-gong", 1) < 10 )
	return notify_fail("�����Ԫ���������죬�޷������������\n");
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
	write(HIC"\n��������"NOR"\n");
	write(@HELP

    ��������Ľ�������Ṧ����ʩչʱ��������ӿգ�����Ѹ
�ݶ�������

	ѧϰҪ��
	  ��Ԫ��10��
HELP
	);
	return 1;
}


// taxue-wuhen.c ̤ѩ�޺� 

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "dodge"; }

string *dodge_msg = ({
"$nһʽ"YEL"������ƽɳ��"NOR"���������٣�������ǰ�߳���������Ȼ�����������ɵ�����һ�ԡ�\n",
"$nһʽ"HIW"����������"NOR"�������Ծ�������һ��һת����Ʈ��������֮�⡣\n",
"$nһʽ"HIY"���������ڡ�"NOR"��������������������ĥ��������֮��ת��ж����$N��һ�С�\n",
"$nһʽ"HIB"�����ɵ��ҡ�"NOR"��ֻ��$n���Ӻ�����˫��������һ�ţ����ӽ��Ƶ��������$N���Ѵ�$n���š�\n",
"$nһʽ"HIW"����ѩ��̲��"NOR"���ݸ߷��ͣ���������������Ʈ��������$N������룬ֻ�û������ء�\n",
"$nһʽ"HIW"����˿���꡹"NOR"��ͻȻ����һ�У���Ȼ�����ܾ��˵Ĵ򷨣���$N��æ���Ұ�ȫ����\n",
"$nһʽ"HIM"��������ѩ��"NOR"�����в��ܣ�ֻ΢΢һ����$N���籩�������Ľ����㼴��ա�\n",
"$nһʽ"HIY"������ǱԾ��"NOR"����Ȼ�����ΰ���ֱ��������ֱ��ӥ��������������ƮƮ������������֮�⡣\n",
"$nһʽ"HIW"��̤ѩ�޺ۡ�"NOR"�����μ�����ת�����¾ͻ�������֮�⡣\n",
});

int valid_enable(string usage) { return (usage=="dodge") || (usage=="move"); }
int valid_learn(object me) 
{      	
	if( (int)me->query_skill("xuantian-wuji", 1) < 10 )
	return notify_fail("��������޼����������죬�޷����̤ѩ�޺ۡ�\n");
	return 1;
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 20|| (int)me->query("neili") < 4 )
		return notify_fail("�������̫���ˣ�������̤ѩ�޺ۡ�\n");
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
	write(HIC"\n̤ѩ�޺ۣ�"NOR"\n");
	write(@HELP

    ̤ѩ�޺�Ϊ�����ɱ����Ṧ��

	ѧϰҪ��
	  �����޼���10��
HELP
	);
	return 1;
}


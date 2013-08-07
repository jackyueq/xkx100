// kunlun-shenfa.c (kunlun) ������

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "dodge"; }

string *dodge_msg = ({
"$nһʽ"HIC"������ƽɳ��"NOR"���������٣�������ǰ�߳���������Ȼ�����������ɵ�����һ�ԡ�\n",
"$nһʽ"HIY"����������"NOR"�������Ծ�������һ��һת����Ʈ��������֮�⡣\n",
"$nһʽ"HIY"���������ڡ�"NOR"��������������������ĥ��������֮��ת��ж����$N��һ�С�\n",
"$nһʽ"YEL"�����ɵ��ҡ�"NOR"��ֻ��$n���Ӻ�����˫��������һ�ţ����ӽ��Ƶ��������$N���Ѵ�$n���š�\n",
"$nһʽ"HIW"����ѩ��̲��"NOR"���ݸ߷��ͣ���������������Ʈ��������$N������룬ֻ�û������ء�\n",
"$nһʽ"HIW"����˿���꡹"NOR"��ͻȻ����һ�У���Ȼ�����ܾ��˵Ĵ򷨣���$N��æ���Ұ�ȫ����\n",
"$nһʽ"HIW"��������ѩ��"NOR"�����в��ܣ�ֻ΢΢һ����$N���籩�������Ľ����㼴��ա�\n",
"$nһʽ"HIY"������ǱԾ��"NOR"����Ȼ�����ΰ���ֱ��������ֱ��ӥ��������������ƮƮ������������֮�⡣\n",
});

int valid_enable(string usage) { return usage=="dodge" || usage=="move"; }
int valid_learn(object me)
{
	int ng, nl, nk;
	ng = (int)me->query_skill("goplaying", 1);
	nl = (int)me->query_skill("luteplaying", 1);
	nk = (int)me->query_skill("kunlun-shenfa", 1);

	if (me->query("family/master_name") != "�����" )
	{
		if ( nl < nk || ng < nk  )
		return notify_fail("���弼�յ����书���أ���Ȼ���޷������������������\n");
	}

	if( (int)me->query_skill("xuantian-wuji", 1) < 10 )
	return notify_fail("��������޼����������죬�޷������������\n");
	return 1;
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 40 || (int)me->query("neili") < 6  )
		return notify_fail("�������̫���ˣ���������������\n");
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
int power_point(object me) { return 1.4; }

int help(object me)
{
	write(HIC"\n��������"NOR"\n");
	write(@HELP

    ������Ϊ���ظ߼��Ṧ��

	ѧϰҪ��
		�൱�����弼�յ�����
		������ĵմ�����
HELP
	);
	return 1;
}


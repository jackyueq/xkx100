// zhutian-bu.c ���컯��
// Last Modified by sir on 10.18.2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "dodge"; }

string *dodge_msg = ({
"ֻ��$nһ��"MAG"����ع���"NOR"�������ڿգ�˫�����ϣ���ֱ���������࣬�����$N��һ�С�\n",
"$n������ת��һʽ"HIM"�����ͷ��"NOR"ͷ��ǰͦ�������ո���ٿ����һ��Ų�������ߣ��ܹ�����һ�С�\n",
"$n˫��ץ�أ�����΢�Σ�һ��"BLU"��ӥצ�ɡ�"NOR"�о����յرܿ���$N��һ�С�\n",
"����$n����Ʈ����һʽ"GRN"���������"NOR"������һ�ݣ����ѱܿ���\n",
"$nһ��"HIB"����������"NOR"������ݳ�����֮Զ���ܿ���$N���������ƣ��������۽�$N���ԡ�\n",
"$nʹ��"HIW"�����¿ۡ�"NOR"��˫���繳��һ��ƮȻ�ݳ��������ŵء�\n",
});

int valid_enable(string usage) { return (usage=="dodge") || (usage=="move"); }
int valid_learn(object me) 
{      	
	if( (int)me->query_skill("linji-zhuang", 1) < 10 )
	return notify_fail("����ټ�ʮ��ׯ�������죬�޷�������컯����\n");
	return 1;
}

int practice_skill(object me)
{
	if( (int)me->query("qi") < 20|| (int)me->query("neili") < 4 )
		return notify_fail("�������̫���ˣ����������컯����\n");
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
	write(HIC"\n���컯����"NOR"\n");
	write(@HELP

    ���컯���Ƕ����ɱ����Ṧ����

	ѧϰҪ��
          �ټ�ʮ��ׯ10��
HELP
	);
	return 1;
}


// xiaoyaoyou.c ��ң��
// Last Modified by sir on 18.10.2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "dodge"; }

string *dodge_msg = ({
	"$nһ��"RED"�����ѵ�ˮ��"NOR"�������$N��һ�С�\n",
	"$n�������һ�ݣ�ʹ��һ��"HIW"��ϸ���ɷ��ơ�"NOR"���ܹ���$N�Ĺ�����\n",
	"$nʹ��"BLU"���黳���ȡ�"NOR"��ǡ�ö����$N�Ĺ��ơ�\n"
	"����$nһ��"HIY"�����ѵ�ˮ��"NOR"����Ʈ��������һ�ݣ����ѱܿ���\n",
	"$n������ת��һ��"MAG"��ϸ���ɷ��ơ�"NOR"ٿ����һ��Ų�������ߣ��ܹ�����һ�С�\n",
	"����$n����һ�ã�һ��"HIY"���黳���ȡ�"NOR"$N��һ�����˸��ա�\n",
	"ȴ��$n�㲻��أ�һ��"GRN"�����ѵ�ˮ��"NOR"���Դܿ����ߣ����˿�ȥ��\n",
	"$n����΢�Σ�һ��"HIB"���黳���ȡ�"NOR"�о����յرܿ���$N��һ�С�\n"
});

int valid_enable(string usage) { return (usage=="dodge") || (usage=="move"); }
int valid_learn(object me) 
{      	
	if ((int)me->query("can_learn/hong/xiaoyaoyou"))
 	return 1;
	if( (int)me->query_skill("huntian-qigong", 1) < 10 )
	return notify_fail("��Ļ��������������죬�޷������ң�Ρ�\n");
	return 1;
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 30 || (int)me->query("neili") < 6 )
		return notify_fail("�������̫���ˣ��޷���ϰ��ң�Ρ�\n");
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
	write(HIC"\n��ң�Σ�"NOR"\n");
	write(@HELP

    ��ң����ؤ�ﱾ���Ṧ����

	ѧϰҪ��

	   ��������10�����к��߹�ָ��
HELP
	);
	return 1;
}


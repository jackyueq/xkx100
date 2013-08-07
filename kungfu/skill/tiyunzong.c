// tiyunzong.c ������
// Last Modified by sir on 10.18.2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "dodge"; }

string *dodge_msg = ({
	"ֻ��$nһ��"HIW"���׺׳��졹"NOR"���������ϱ�ֱ���������࣬�����$N��һ�С�\n",
	"$nһ��"BLU"�����ӷ���"NOR"������ݳ�����֮Զ���ܿ���$N���������ơ�\n",
	"$nʹ��"HIY"������չ�᡹"NOR"����һ��ƮȻ�ݳ��������ŵء�\n",
	"����$nһ��"HIC"���׺׳��졹"NOR"����Ʈ��������һ�ݣ����ѱܿ���\n",
	"$n������ת��һ��"HIB"�����ӷ���"NOR"ٿ����һ��Ų�������ߣ��ܹ�����һ�С�\n",
	"����$nһ��"YEL"������չ�᡹"NOR"����һ�ã�$N��һ�����˸��ա�\n",
	"ȴ��$n�㲻���һ��"HIC"���׺׳��졹"NOR"�����Դܿ����ߣ����˿�ȥ��\n",
	"$n����΢�Σ�һ��"MAG"�����ӷ���"NOR"�о����յرܿ���$N��һ�С�\n",
});

int valid_enable(string usage) { return (usage=="dodge") || (usage=="move"); }
int valid_learn(object me) 
{      	
	if( (int)me->query_skill("taiji-shengong", 1) < 10 )
	return notify_fail("���̫���񹦲������죬�޷���������ݡ�\n");
	return 1;
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 50 || (int)me->query("neili") < 10 )
		return notify_fail("�������̫���ˣ��޷���ϰ�����ݡ�\n");
	me->receive_damage("qi", 50);
	me->add("neili", -10);
	return 1;
}
string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int learn_bonus() { return 25; }
int practice_bonus() { return 25; }
int success() { return 20; }
int power_point(object me) { return 1.1; }

int help(object me)
{
	write(HIC"\n�����ݣ�"NOR"\n");
	write(@HELP

    ������Ϊ�䵱����Ṧ�ķ���

	ѧϰҪ��
	  ̫����10��
HELP
	);
	return 1;
}


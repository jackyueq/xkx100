// chanchu_bufa.c ��ܲ���
// Last Modified by sir on 10.18.2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "dodge"; }

string *dodge_msg = ({
	"ֻ��$nһ��"HIY"���ɾ��졹"NOR"���������ϱ�ֱ���������࣬�����$N��һ�С�\n",
	"����$nһ��ʹ��"HIY"���������졹"NOR"������Ʈ��������һ�ݣ����ѱܿ���\n",
	 "$nһ��"HIY"�����뵾�"NOR"����������ת��ٿ����һ��Ų�������ߣ��ܹ�����һ�С�\n",
	"����$nһ��"HIY"������˳桹"NOR"������һ�ã�$N��һ�����˸��ա�\n",
	"ȴ��$n"HIY"��󸷭�׶ǡ�"NOR"���㲻��أ����Դܿ����ߣ����˿�ȥ��\n",
	"$n����һ��"HIY"�������¡�"NOR"������΢�Σ��о����յرܿ���$N��һ�С�\n"
});

int valid_enable(string usage) { return (usage=="dodge") || (usage=="move"); }
int valid_learn(object me) 
{      	
	if( (int)me->query_skill("hamagong", 1) < 10 )
		return notify_fail("��ĸ�󡹦�������죬�޷������ܲ�����\n");
	return 1;
}

int practice_skill(object me)
{
	if( (int)me->query("qi") < 10 || (int)me->query("neili") < 2 )
		return notify_fail("�������̫���ˣ���������ܲ�����\n");
	me->receive_damage("qi", 10);
	me->add("neili", -2);
	return 1;
}
string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}
int learn_bonus() { return 25; }
int practice_bonus() { return 25; }
int success() { return 20; }
int power_point() { return 1.1; }

int help(object me)
{
	write(HIC"\n��ܲ�����"NOR"\n");
	write(@HELP

    ����ɽ�����Ṧ��

	ѧϰҪ��
	   ��󡹦10��
HELP
	);
	return 1;
}


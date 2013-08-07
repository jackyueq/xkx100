// zhaixinggong.c ժ�ǹ�
// Last Modified by sir on 10.18.2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "dodge"; }

string *dodge_msg = ({
	"$nһ��"HIW"������ժ�ǡ�"NOR"��Ծ�����ߣ������$N��һ�С�\n",
	"$n�������һ�ݣ�ʹ��һ��"HIC"��ƮȻ������"NOR"���ܹ���$N�Ĺ�����\n",
	"$nʹ��"HIG"��������ˮ��"NOR"��ǡ�ö����$N�Ĺ��ơ�\n",
	"$nһ��"HIW"��֯Ů����"NOR"����̬����ض��˿�ȥ��\n"
});

int valid_enable(string usage) { return (usage=="dodge") || (usage=="move"); }
int valid_learn(object me)
{      	
	if( (int)me->query_skill("huagong-dafa", 1) < 10 )
	return notify_fail("��Ļ����󷨲������죬�޷����ժ�ǹ���\n");
	return 1;
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 10|| (int)me->query("neili") < 2 )
		return notify_fail("�������̫���ˣ�����ժ�ǹ���\n");
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
int power_point(object me) { return 1.0; }

int help(object me)
{
	write(HIC"\nժ�ǹ���"NOR"\n");
	write(@HELP

    ժ�ǹ��������ɱ����Ṧ����

	ѧϰҪ��
	  ������10��
HELP
	);
	return 1;
}


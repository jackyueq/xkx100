// yunv-shenfa.c ��Ů��
// Last Modified by sir on 10.18.2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "dodge"; }

string *dodge_msg = ({
	"����$n����һת��ʹ��"HIW"����Ѭ΢�ȡ�"NOR"����ز������ܿ�����һ�С�\n",
	"$nһ��"HIW"����ʩ�ɴ��"NOR"��������ת��ٿ����һ��Ų�������ߡ�\n",
	"$n����Ʈ����հ֮��ǰ�������ں�ȴ��"HIW"��������̨��"NOR"������\n",
	"$nʹ��"HIW"������岨��"NOR"��������ˮ�滬��һ�㣬���λ��˿�ȥ��\n",
	"����$n����ӰƮƮ���죬��˿������������һʽ"HIW"����ɽ���ء�"NOR"������\n",
});

int valid_enable(string usage) { return (usage=="dodge") || (usage=="move"); }
int valid_learn(object me) 
{      	
	if( (int)me->query_skill("yunv-xinfa", 1) < 10 )
	return notify_fail("�����Ů�ķ��������죬�޷������Ů����\n");
	return 1;
}

int practice_skill(object me)
{
	if( (int)me->query("qi") < 40|| (int)me->query("neili") < 8 )
		return notify_fail("�������̫���ˣ���������Ů����\n");
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
	write(HIC"\n��Ů����"NOR"\n");
	write(@HELP

    ��Ĺ���Ṧ������£�Ʈ���鶯���仯�򷽣�������Բ֮��
�����������񣬵����ޱȡ�

	ѧϰҪ��
	  ��Ů�ķ�10��
HELP
	);
	return 1;
}


// lingxu-bu ���鲽
// Last Modified by sir on 10.18.2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "dodge"; }

string *dodge_msg = ({
	"$nһʽ"HIW"��ѩ��������"NOR"�����ӳ���һת��$Nֻ������ǰһ����ʧȥ��Ŀ�ꡣ\n",
	"$nһʽ"HIY"��һ�����졹"NOR"��˫�ŵ�أ�����ͻȻ�θ�����������Ʈ����$N���\n",
	"$nһʽ"CYN"�����л�Ӱ��"NOR"������һ�Σ���ʱ��������Ӱһ���ӳ�����$N����ǰ��\n",
	"$nһʽ"MAG"���������ߡ�"NOR"��ƮȻ���һ�ˣ��㿪$N���������ơ�\n",
	"$nһʽ"BLU"������Ʈ�졹"NOR"�����弱ת����Ϊһ���׹⣬��ò����ĳ�����$N����Χ��\n",
});

int valid_enable(string usage) { return (usage=="dodge") || (usage=="move"); }
int valid_learn(object me)
{      	
	if( (int)me->query_skill("baiyun-xinfa", 1) < 10 )
	return notify_fail("��İ����ķ��������죬�޷�������鲽��\n");
	return 1;
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 30 || (int)me->query("neili") < 6 )
		return notify_fail("�������̫���ˣ��޷�����ϰ���鲽��\n");
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
	write(HIC"\n���鲽��"NOR"\n");
	write(@HELP

    ���鲽Ϊ��ɽ���Ṧ��

	ѧϰҪ��
          �����ķ�10��
HELP
	);
	return 1;
}


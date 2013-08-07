// fuguanglueying.c  ������Ӱ
// Last Modified by sir on 10.18.2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "dodge"; }

string *dodge_msg = ({
	"ֻ��$nһ��"BLU"������������"NOR"��˫��һǰһ���ƽ����ȣ���$nһ㶼����˹�����\n",
	"����$nʹ��"CYN"�����ѵ�ˮ��"NOR"���ż�վ�أ����ζ�������䣬�������\n",
	"$nһ��"HIY"���ɻ��ڴ"NOR"��������ת��ɲ�Ǽ���ԭ��ת���߰�ʮȦ��ͻȻ������һ����\nԭ��ת���ˣ�ȴʹ$N���˿ա�\n",
	"����$nһ��"HIW"���׾Թ�϶��"NOR"������΢�࣬����ֱ�ݣ����$N������\n",
	"ȴ��$nʹ��"HIW"��������Ӱ��"NOR"����ԭ������һ����������㵽��һ�ߡ�\n",
	"$n����һ�٣�"HIB"��������˹��"NOR"������ƽƽ�ӳ����ڿ�������һ�����Ρ�\n"
});

int valid_enable(string usage) { return (usage=="dodge") || (usage=="move"); }
int valid_learn(object me) 
{ 
	if( (int)me->query_skill("hanbing-zhenqi", 1) < 10 )
	return notify_fail("��ĺ��������������죬�޷���ḡ����Ӱ��\n");
	return 1;
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 30 || (int)me->query("neili") < 6 )
		return notify_fail("�������̫���ˣ��޷�����ϰ������Ӱ��\n");
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
	write(HIC"\n������Ӱ��"NOR"\n");
	write(@HELP

    ��ɽ���Ṧ����

        ѧϰҪ��
            ��������10��	   
HELP
	);
	return 1;
}


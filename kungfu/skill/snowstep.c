// Last Modified by sir on 10.18.2001
// snowstep.c ÷ѩƮ�㲽

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "dodge"; }

string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

string *dodge_msg = ({
	"����$n��Цһ��������߲�����һʽ"+(order[random(13)])+"����÷Ʈѩ��"NOR"���������������С�\n",
	"$n����ת��һ��"+(order[random(13)]) +"��̴����ס�"NOR"�������ְ�Ʈ����ϣ��ܹ������С�\n",
	"ֻ��$n����һ�����������ʹ��"+(order[random(13)]) +"��÷�»ƻ衹"NOR"�������˶�ʧȥ����Ӱ����$N���˸��ա�\n",
	"ȴ��$n����������ңңһ�ģ�һʽ"+(order[random(13)]) +"��÷Ʈ������"NOR"��������������Ʈ�𣬶�������С�\n",
	"$n��Цһ����һʽ"+(order[random(13)]) +"����÷��ѩ��"NOR"���������һʱ����˷�����$n��Ӱ�ӣ�����ʵʵ����֪�ĸ�������ġ�\n",
});

int valid_enable(string usage) { return (usage=="dodge") || (usage=="move"); }
int valid_learn(object me)
{      	
	if( (int)me->query_skill("bingxue-xinfa", 1) < 10 )
		return notify_fail("��ı�ѩ�ķ��������죬�޷����÷ѩƮ�㲽��\n");
	return 1;
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 20|| (int)me->query("neili") < 4 )
		return notify_fail("�������̫���ˣ�������÷ѩƮ�㲽��\n");
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
	write(HIC"\n÷ѩƮ�㲽��"NOR"\n");
	write(@HELP

    ÷ѩƮ�㲽�������ɱ����Ṧ����

	ѧϰҪ��
          ��ѩ�ķ�10��
HELP
	);
	return 1;
}

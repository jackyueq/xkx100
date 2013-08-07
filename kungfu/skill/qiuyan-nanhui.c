// qiuyan-nanhui.c �����ϻ�
// Last Modified by sir on 10.18.2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "dodge"; }

string *dodge_msg = ({
	"$nһʽ"CYN"����ɺ�̶��"NOR"�����㣬�Ų��ƣ�������������ˮ��ֱ�������ࡣ\n",
	"$nһʽ"CYN"��ƽɳ���㡹"NOR"����Ȼһ������ȫ�����ض��У���ʱ������$N���������ơ�\n",
	"$nһʽ"CYN"��������á�"NOR"��һת��䣬����˷�Ʈ����������$n����Ӱ����$N�����޴롣\n",
	"$nһʽ"CYN"�����㾪�ʡ�"NOR"������һ����ȫ��Ϊһ����Ӱ�����ĵش�$Nͷ��Ʈ�䡣\n",
	"$nһʽ"CYN"����Ӱ���ޡ�"NOR"�����������ݰ㼱ת����ʱһ������ӿ������$N���Զ�����\n",
});


int valid_enable(string usage) { return (usage=="dodge") || (usage=="move"); }
int valid_learn(object me) 
{      	
	if( (int)me->query_skill("huiyan-xinfa", 1) < 10 )
	return notify_fail("��Ļ����ķ��������죬�޷���������ϻء�\n");
	return 1;
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 30 || (int)me->query("neili") < 6 )
		return notify_fail("�������̫���ˣ��޷���ϰ�����ϻء�\n");
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
	write(HIC"\n�����ϻأ�"NOR"\n");
	write(@HELP

    ��ɽ�ɵ��Ṧ����

	ѧϰҪ��
	   �����ķ�10��
HELP
	);
	return 1;
}


// chuanhua.c ��������
// Last Modified by sir on 10.18.2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "dodge"; }

string *dodge_msg = ({
	"$nһʽ"GRN"��б�����ȥ��"NOR"������������Ͷ�ְ�ֱ�������ࡣ\n",
	"$nһʽ"MAG"������Ϸ���ġ�"NOR"����Ȼһ������ȫ����ն��У���ʱ������$N���������ơ�\n",
	"$nһʽ"HIY"����ȸ��Ҷ¶��"NOR"���㲻�����ֲ�̧��һת�ۼ���Ƶ���$N�����\n",
	"$nһʽ"GRN"�����Ū���ۡ�"NOR"��һת��䣬����˷�Ʈ����������$n����Ӱ����$N�����޴롣\n",
	"$nһʽ"HIW"����β��ˮ�衹"NOR"������һ����ȫ��Ϊһ����Ӱ�����ĵش�$Nͷ��Ʈ�䡣\n",
	"$nһʽ"MAG"��֪�˲�Ӱ�١�"NOR"������ٿ�Ĵ�$N����ǰƮ��������һ˦������֮����\n",
});

int valid_enable(string usage) { return (usage=="dodge") || (usage=="move"); }
int valid_learn(object me) 
{      	
       if( (int)me->query_skill("qingming-xuangong", 1) < 10 )
       return notify_fail("�����ڤ�����������죬�޷���ᴩ��������\n");
       return 1;
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 30 || (int)me->query("neili") < 6 )
		return notify_fail("�������̫���ˣ�����������������\n");
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
int power_point() { return 1.3; }

int help(object me)
{
	write(HIC"\n����������"NOR"\n");
	write(@HELP

    ����ɱ����Ṧ��

	ѧϰҪ��
            ��ڤ���� 10 ��		
HELP
	);
	return 1;
}


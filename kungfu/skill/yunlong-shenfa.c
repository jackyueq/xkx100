// yunlong-shenfa ������
// Last Modified by sir on 10.18.2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "dodge"; }

string *dodge_msg = ({
	"$nһʽ"HIY"�����ڻ�Ծ��"NOR"������һת���͵�����һ��,�����$N�Ĺ��ơ�\n",
	"$nһʽ"HIY"��ɳ�������"NOR"��˫��������󣬲������������״�$N��ǰ�����\n",
	"$nһʽ"HIG"������ͬ�ۡ�"NOR"�����˷�����һ�����Ƶ���$N�����\n",
	"$nһʽ"HIG"����������"NOR"�����������һ�ˣ������ù���$N���������ơ�\n",
	"$nһʽ"GRN"�����Ĳ�����"NOR"������һ�����һ�Σ�������Ʈ����Զ��\n",
	"$nһʽ"MAG"����ӥ���á�"NOR"��������һֻ��ӥ������һ����$N����ǰ�ɹ���\n",
	"$nһʽ"HIY"���������졹"NOR"�����İεض����ڰ����һת�����䵽����Զ�ĵط���\n",
	"$nһʽ"HIC"��������졹"NOR"��ȫ��Ϊһ����Ӱ������һ���շ��������Ʈ���ұߡ�\n",
	"$nһʽ"HIC"���������̡�"NOR"�����ζ��ر��Ʈ����������$N�޷����塣\n",
	"$nһʽ"HIW"���������¡�"NOR"������һ����ʸ������ٿ�İεض�����$N�������ӡ�\n",
});

int valid_enable(string usage) { return (usage=="dodge") || (usage=="move"); }
int valid_learn(object me) 
{      	
	if( (int)me->query_skill("yunlong-shengong", 1) < 10 )
	return notify_fail("��������񹦲������죬�޷������������\n");
	return 1;
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 40|| (int)me->query("neili") < 8 )
		return notify_fail("�������̫���ˣ���������������\n");
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
int power_point() { return 1.4; }

int help(object me)
{
	write(HIC"\n��������"NOR"\n");
	write(@HELP

    ������Ϊ��ػ������ű����Ṧ����

	ѧϰҪ��
	   ������10��
HELP
	);
	return 1;
}


// shenxing-baibian.c ���аٱ�
// Last Modified by sir on 10.18.2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "dodge"; }

string *dodge_msg = ({
"$nһʽ"HIC"��������ˮ��"NOR"�����㣬�Ų��ƣ�������������ˮ��ֱ�������ࡣ\n",
"$nһʽ"BLU"��Ǳ��ҹ�С�"NOR"����Ȼһ������ȫ�����ض��У���ʱ������$N���������ơ�\n",
"$nһʽ"HIW"���Ʋ����Ρ�"NOR"���㲻�����ֲ�̧��һת�ۼ���Ƶ���$N�����\n",
"$nһʽ"MAG"������Ӱ��"NOR"��һת��䣬����˷�Ʈ����������$n����Ӱ����$N�����޴롣\n",
"$nһʽ"HIB"���貨΢����"NOR"����̤�㣬��תǬ������һ�Σ��㵽����Զ�ĵط���\n",
"$nһʽ"HIM"�����ϲ�¥��"NOR"�����ڿ��У������������һ�㣬��$Nͷ���ڿն�����\n",
"$nһʽ"HIW"�����ӳ�ˮ��"NOR"������һ����ȫ��Ϊһ����Ӱ�����ĵش�$Nͷ��Ʈ�䡣\n",
"$nһʽ"HIG"�����·ת��"NOR"�����������ݰ㼱ת����ʱһ������ӿ������$N���Զ�����\n",
"$nһʽ"GRN"�������ﲨ��"NOR"������ٿ�Ĵ�$N����ǰֱ�Ƶ����$N�ɴ������ۣ��������ԡ�\n",
"$nһʽ"HIY"�����ӻ�ͷ��"NOR"������ٿ�Ĵ�$N����ǰƮ��������һ˦������֮����\n",
});

int valid_enable(string usage) { return (usage=="dodge") || (usage=="move"); }
int valid_learn(object me) 
{      	
	if( (int)me->query("kar", 1) < 25 || (int)me->query("sta", 1) < 25 
             ||(int)me->query("int",1)<29 )
		return notify_fail("��������Ե�������аٱ䡣\n");
	return 1;
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 40|| (int)me->query("neili") < 8 )
		return notify_fail("�������̫���ˣ����������аٱ䡣\n");
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
int power_point(object me) {
	if (me->query("skybook/luding/dubi"))	return 1.4;
	else	return 0.9; }

int help(object me)
{
	write(HIC"\n���аٱ䣺"NOR"\n");
	write(@HELP

    ���аٱ���������ľɣ���������������Ṧ�������������ĸ��С�

	ѧϰҪ��
	   һ���Ļ�Ե���������ѧϰ 
HELP
	);
	return 1;
}


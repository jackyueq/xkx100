// shaolin-shenfa.c ������
// Last Modified by sir on 10.18.2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "dodge"; }

string *dodge_msg = ({
"$nһʽ"HIW"��һέ�ɽ���"NOR"��ǰ��Žż�Ÿ��࿿��������������ˮ�㻬�����ࡣ\n",
"$nһʽ"BLU"�������Ӳ���"NOR"��˫��ǰ�죬ȫ������ƽ�ɣ���ʱ������$N���������ơ�\n",
"$nһʽ"HIC"���Ʋ����Ρ�"NOR"���㲻�����ֲ�̧��һת�ۼ���Ƶ���$N�����\n",
"$nһʽ"HIG"������Ӱ��"NOR"��һת��䣬����˷�Ʈ����������$n����Ӱ����$N������롣\n",
"$nһʽ"HIY"���������ա�"NOR"��ȫ���ֱ���εض����ڰ����һת�����䵽����Զ�ĵط���\n",
"$nһʽ"HIB"������˫�ɡ�"NOR"�������������������ݷ����У���$Nͷ����Ծ������\n",
"$nһʽ"HIY"��������ˮ��"NOR"��˫�ŵ�أ�ȫ��Ϊһ����Ӱ����������$N���˼�ת��\n",
"$nһʽ"GRN"���ɷ�鳲��"NOR"�����������ݰ㼱ת�������γ�һ�������У���$N������䣬�������á�\n",
});

int valid_enable(string usage) { return (usage=="dodge") || (usage=="move"); }
int valid_learn(object me)
{      	
	if( (int)me->query_skill("hunyuan-yiqi", 1) < 10 )
	return notify_fail("��Ļ�Ԫһ�����������죬�޷������������\n");
	return 1;
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 30 || (int)me->query("neili") < 6 )
		return notify_fail("�������̫���ˣ��޷�����ϰ��������\n");
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
int river_point() {return 2;} // ���ӱ���ͨ���� Խ��Խ��
string river_go_msg() {	return HIW"$N����һ��«έ����ˮ�У������ŷ���Ծ��«έ������ƮƮ���ɹ���ˮ�档\n"NOR;}
string river_come_msg() {	return HIW"ֻ��$N����һ��«έ�Ӷ԰���������̬���������ڰ��ߡ�\n"NOR;}

int help(object me)
{
	write(HIC"\n��������"NOR"\n");
	write(@HELP

    ������Ϊ���ֱ����Ṧ���������Ṧ�������¡�

	ѧϰҪ��
		��Ԫһ����10��
HELP
	);
	return 1;
}



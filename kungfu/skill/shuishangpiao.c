// shuishangpiao.c ����ˮ��Ʈ
// Last Modified by sir on 10.18.2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "dodge"; }

string *dodge_msg = ({
"$n���һ֧��ȫ�������һ��"BLU"�����㵹������"NOR"�����ܳ����࣬�����$N�Ĺ�����\n",
"$n�����Ȼ�����޹ǣ�����ҡ�ڣ�ʹ��һ��"BLU"�����ƯƼ��"NOR"���ܹ���$N�Ĺ�����\n",
"$nʹ��"HIB"���ﻻ���ơ�"NOR"��������һ��ת����$N���Բ����������������$N���\n",
"$nһ��"HIY"����Ҷ��硹"NOR"��������һƬ��Ҷһ��Ʈ�˳�ȥ������֮������Ѹ�ٵ��˼�����\n",
});

int valid_enable(string usage) { return (usage=="dodge") || (usage=="move"); }
int valid_learn(object me) 
{      	
	if( (int)me->query_skill("guiyuan-tunafa", 1) < 10 )
	return notify_fail("��Ĺ�Ԫ���ɷ��������죬�޷��������ˮ��Ʈ��\n");
	return 1;
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 30 || (int)me->query("neili") < 6 )
		return notify_fail("�������̫���ˣ��޷���ϰ����ˮ��Ʈ��\n");
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
int river_point() {return 1.5;} // ���ӱ���ͨ���� Խ��Խ��
string river_go_msg() {	return HIW"$N����Ծ��ˮ�棬������������ˮֻ��С�ȣ�һ�������˹�ȥ��\n"NOR;}
string river_come_msg() {	return HIW"ֻ��ˮ������Ӱ������$N��Ʈ������һ�㣬ֱ�߹�����\n"NOR;}

int help(object me)
{
	write(HIC"\n����ˮ��Ʈ��"NOR"\n");
	write(@HELP

    ���ư�Ķ����Ṧ����

	ѧϰҪ��
	  ��Ԫ���ɷ�10��
HELP
	);
	return 1;
}


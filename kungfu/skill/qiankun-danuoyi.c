// qiankun-danuoyi.c Ǭ����Ų��
// Last Modified by sir on 10.18.2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "dodge"; }

string *parry_msg = ({
	HIY"$Nһ�л���$n���ϣ�ȴ��$n����Ǭ����Ų�ƣ�����������������¡�\n"NOR,
	HIW"$n����һ����$N�����Լ������ػ��������ŵ������˼�����\n"NOR,
	HIC"$n�ֱۻ�ת����$N����������һ�ƣ�$N������ա�\n"NOR,
	HIG"$n�����������$N����������һ����$N���Ʋ�ס��ֱ��ǰ��ȥ��\n"NOR,
	MAG"$n���β�����$Nһ�л��£�����ʯ���󺣣�������ס�ˡ�\n"NOR,
	HIM"$n��ǣ������$N��������������ת�˺ü���Ȧ��\n"NOR,
	GRN"$n˫�ֻ�Ȧ��$Nֻ����ǰ�������һ��ǽ����Ҳ������ȥ��\n"NOR,
	HIY"$n����һת��$Nһ�л��ڵ��ϣ�ֻ��ó������\n"NOR,
});

string *dodge_msg = ({
	"$Nһ�л���$n���ϣ�ȴ��$n����Ǭ����Ų�ƣ�����������������¡�\n",
	"$n����һ����$N�����Լ������ػ��������ŵ������˼�����\n",
	"$n�ֱۻ�ת����$N����������һ�ƣ�$N������ա�\n",
	"$n�����������$N����������һ����$N���Ʋ�ס��ֱ��ǰ��ȥ��\n",
	"$n���β�����$Nһ�л��£�����ʯ���󺣣�������ס�ˡ�\n",
	"$n��ǣ������$N��������������ת�˺ü���Ȧ��\n",
	"$n˫�ֻ�Ȧ��$Nֻ����ǰ�������һ��ǽ����Ҳ������ȥ��\n",
	"$n����һת��$Nһ�л��ڵ��ϣ�ֻ��ó������\n",
});

int valid_enable(string usage) 
{ 
	return (usage == "parry") || (usage == "dodge") || (usage=="move"); }

string query_parry_msg(string limb)
{
	return parry_msg[random(sizeof(parry_msg))];
}
string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}
int valid_learn(object me)
{
	int lvl = (int)me->query_skill("qiankun-danuoyi", 1);

	if ( me->query("gender") == "����" && lvl > 99)
		return notify_fail("�����첻�㣬��ѧ��ȥ�����߻���ħ��\n");
	if ((int)me->query_skill("force", 1) < 100)
		return notify_fail("����ô������ڹ�����ѧǬ����Ų�ƣ�\n");
	if (lvl > 50)
		return notify_fail("Ǭ����Ų��ֻ��ͨ����<<Ǭ����Ų���ķ�>>��ߡ�\n");
	if ((int)me->query("max_neili", 1) < 1500)
		return notify_fail("����ô����������ѧǬ����Ų�ƣ�\n");
	if ((int)me->query_skill("force", 1) < lvl)
		return notify_fail("��Ļ����ڹ���򻹲�����С���߻���ħ��\n");
	if ((int)me->query_skill("jiuyang-shengong", 1) < lvl)
		return notify_fail("��ľ����񹦻�򻹲�����С���߻���ħ��\n");
	if ((int)(me->query("max_neili")/15) < lvl)
		return notify_fail("���������򻹲�����С���߻���ħ��\n");
	return 1;
}
int practice_skill(object me)
{
	return notify_fail("Ǭ����Ų��ֻ��ͨ����<<Ǭ����Ų���ķ�>>��ߡ�\n");
}
string perform_action_file(string action)
{
	return __DIR__"qiankun-danuoyi/" + action;
}

int learn_bonus() { return 0; }
int practice_bonus() { return 0; } 
int success() { return 5; }
int power_point(object me) { return 1.5; }

int help(object me)
{
	write(HIC"\nǬ����Ų�ƣ�"NOR"\n");
	write(@HELP

    ��Ǭ����Ų�ơ������������ഫһ�����������书�������̵�
�����񹦡�Ϊ��˹���ɽ������������ר�Ž�������ʹ���ķ��š�
��ԭ���õ������٣���������ʮ�����������������󣬼���ʧ����
���������޼�һ�����������������ڹ�һ�����ɡ�Ǭ����Ų��ֻ
���мܺ��Ṧ�ã����߹�����������֮�����ǿ��԰ѱ��˵�������
�����ڶԷ���
    Ǭ����Ų���񹦵���ּ�����ڵߵ�һ��һ�ᡢһ��һ����Ǭ��
�����������ֳ����֮ɫ����������ѪҺ�����������任֮����
��������ʱ��ȫ���ܺ�����࣬�������߲�ʱ����������ת����
��֪����֮�䣬�����ϱ���Ҳ�Ʋ��������ˡ����������Ҳ����
��ΰ��ֻ�������󼤷�����Ǳ����Ȼ��ǣ��Ų�Ƶо���������
�仯���棬ȴ�Ƿ�����˼��

	ѧϰҪ��
		�����ڹ�100�������õ���Ǭ����Ų�Ƶļ���
		�����񹦲��õ���Ǭ����Ų�Ƶļ���
		����1500�����õ���Ǭ����Ų�Ƶļ����15��
		̫���޷�����100�����ϵ�Ǭ����Ų��
HELP
	);
	return 1;
}


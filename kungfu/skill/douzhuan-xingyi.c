// douzhuan-xingyi.c ��ת����
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

string *parry_msg = ({
	YEL"�����һ��������������$nһ��һ����$n��������Խ����������һ�ԡ�\n"NOR,
	BLU"$n����һ����������$l��$N����$n��$l������Ī��������ﻬ��һ�ԡ�\n"NOR,
	HIW"$n˫��ǰ̽����۴���$N�ұۣ��ұ�ʹ��$N��������$N���л�ȥ��\n"NOR,
	HIY"$n���ƶ�ת��$N����Ī�����������;ת�˷���ֱ���Լ�Ϯ����\n"NOR,
	YEL"$n�����Ϲۣ�˫����Է��ཻ���ƣ�̸Ц�侹ʹ��$N�������գ�ʹ��$N��֪����Ǻá�\n"NOR,
	BLU"$n����������$N�͹����ʹ������������$N�ĳ�����������$N�������������С�\n"NOR,
	HIW"ֻ��$n����Ʈ�磬ǡ���������ƣ������һʽ��˫�ƶ����޶�����׽��������$N��$l��\n"NOR,
	HIY"$n����Ʈ�������������ƶ�ת֮�䷴��$N����������$N��ȴ����$N��˼������⡣\n"NOR,
	HIY"$n����һ����$N�����Լ������ػ��������ŵ������˼�����\n"NOR,
	HIY"$n�ֱۻ�ת����$N����������һ�ƣ�$N������ա�\n"NOR,
	HIY"$n�����������$N����������һ����$N���Ʋ�ס��ֱ��ǰ��ȥ��\n"NOR,
	HIY"$n˫�ֻ�Ȧ��$Nֻ����ǰ�������һ��ǽ����Ҳ������ȥ��\n"NOR,
});

int valid_enable(string usage) { return usage=="parry"; }
string query_parry_msg(string limb)
{
	return parry_msg[random(sizeof(parry_msg))];
}
int valid_learn(object me)
{
	object ob;
	int d_lvl = (int) me->query_skill("douzhuan-xingyi",1);
	int s_lvl = (int) me->query_skill("shenyuan-gong",1);
	int l_lvl = (int) me->query_skill("literate",1);

	mapping myfam;
	myfam = (mapping)me->query("family");
	if(!myfam || myfam["family_name"] != "����Ľ��" ||
		myfam["master_id"] != "murong fu")
		return notify_fail("��ת����ֻ����Ľ�ݹ���ѧϰ��\n");
	if( (int)me->query("betrayer") > 0 )
		return notify_fail("��������ʦ�ţ���־������û�а취����ת���ơ�\n");
	if( (int)me->query_int() < 40 )
		return notify_fail("����ϸ������һ�ᣬ����û���׽��������ĵ���\n");
 	if( (int)me->query("max_neili") < 600 )
		return notify_fail("�������������û�а취����ת���ơ�\n");
	if( s_lvl < 100)
		return notify_fail("��ת���Ʊ�����ѧ����Ԫ��������ϰ��\n");
	if( s_lvl + 30 < d_lvl)
		return notify_fail("�����Ԫ�����𲻹������������߼��Ķ�ת���ơ�\n");
	if( l_lvl + 50 < d_lvl)
		return notify_fail("��Ķ���д��ˮƽ�����������߼��Ķ�ת���ơ�\n");
	return 1;
}
int practice_skill(object me)
{
	return notify_fail("��ת����ֻ��ͨ��ѧϰ����ߡ�\n");
}
int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 20; }
int power_point(object me) { return 1; }

string perform_action_file(string action)
{
	return __DIR__"douzhuan-xingyi/" + action;
}
int help(object me)
{
	write(HIC"\n��ת���ƣ�"NOR"\n");
	write(@HELP

    ����Ľ�ݼ������ֵľ���������һ�Ž�������֮������������
ת���ơ������˲�֪��ϸ������Ľ���ϡ��Ա�֮������ʩ������
���似��������������֮ʱ�������ԶԷ��ĳ�����������������
Ȼ���¸��Ÿ��ɵľ���������Ľ������һ���ᣬ��һ��������ʵ��
���о���ǧǧ����������δ���Ԩ�������ѽ�ÿһ�������ѧ��
�ˣ��ο����Ǿ������Էǳ�Ϧ֮���������ɡ���Ľ����������һ��
�����ޱȵġ���ת���ơ�֮�������۶Է�ʩ�����ֹ����������ܽ�
֮ת���������������Է��������ֵ����书Խ�ߣ�������Խ����
�Ľ�������ǵ���������������а��ն����µ��������⡰��ת
���ơ��Ĺ�������ʹ�ã����Թ���Ľ�������𽭺��������Ĺ���
���ڣ�ȴ��˭Ҳ��֪�������ֵı���ȭ��ת�����������������
�ܣ����е���ȫ�ڡ����������֡���������һȭ����ʯǽ֮�ϣ�
����Խ�أ�ȭͷ�����ܵ�����Խ������ǿ��������ֺ���ֻ����
ת�����εı���ȭ�����ף�ת���������ʵ������������Ǿͼ��ѡ�

	ѧϰҪ��
                ����ʦ
                Ľ�ݸ��ĵմ�����
		��������40
		��Ԫ��100��
		��Ԫ�����ܵ��ڶ�ת����30��
		����д�ֲ��ܵ��ڶ�ת����50��
		����600
HELP
	);
	return 1;
}


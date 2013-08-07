// sanshou.c ����ɢ��
// Last Modified by winder on Nov. 15 2000

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

string *msg = ({
"$N����Ծ�𣬰����һ������$n���ţ�ȴ�Ǹ����С� \n˵ʱ����ʱ�죬ֻ��$Nһ��������һ�С��������ơ���˫���ѵ���$n��$l",
"$Nʹһ�С��������¡�����ȭ�������б�ɣ�����$n��$l",
"$Nһ�С������ڡ���б��Ť�������͵���$n���ؿ�ײȥ",
"$N����б��������ǰ̽����צ��һ�С�׳־���͡�ץ��$n��$l",
"$N������������ǰ����ؽ����������ֲ�ָ�罣��һ�С�Ц̸����������$n��$l",
"$N�Ჽ��ǰ��һ�ǡ�Ī���С���˫�ƻ����Ƴ�������$n��ǰ��",
"$N�Ų����Ƿ�λ��˫�Ʒ���ʩ����������Ъ����������Ӱ����$n��$l",
"$N���һ����һ�С�ŭ����ڡ���˫�ƴ������������Ѹ���ޱȵĻ���$n��$l",
"$N���ֵݳ������۾�����°���ת��һ�С���ͷ��ʰ��ɽ�ӡ����ַ��ֶ�׼$n$l��ȥ",
});

int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }
int valid_combine(string combo) { return combo=="changquan"; }

int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("������ɢ�ֱ�����֡�\n");
	return 1;
}
int practice_skill(object me)
{
	if( (int)me->query("jing") < 30)
		return notify_fail("��ľ����޷������ˣ���Ϣһ�������ɡ�\n");
	if( (int)me->query("qi") < 30 )
		return notify_fail("����������������Ϣһ�������ɡ�\n");
	if( (int)me->query("neili") < 10 )
		return notify_fail("������������ˡ�\n");

	me->receive_damage("qi", 30);
	me->add("neili", -10);

	return 1;
}
mapping query_action(object me, object weapon)
{
	return ([
		"action" : msg[random(sizeof(msg))],
		"dodge"  : -30+random(30),
		"parry"  : 30+random(30),
		"force"  : 50+random(100),
		"damage_type" : random(2)?"����":"����",
	]);
}

int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 20; }
int power_point(object me) { return 1.0; }

int help(object me)
{
	write(HIC"\n����ɢ�֣�"NOR"\n");
	write(@HELP

    ������ɢ�֡��ֳ�����ɢ�֡�����ɢ�ƣ���������ȭ���ݿ�֤��
�δ�����������������������ĸȭ���������������������ں���
��÷������������ȭ����Ԫʱ�ڣ���ֹ���䣬��ͳ�����ܵ��ݲУ���
��ȭҲ�����⡣�������壬������ʢ������ȭ�ŵ��Է�չ��ʷ�ϼ��أ�
��ĩ����������ҷ���ʦ������ɽ����������ȭ�ף�����ȭ������
��ȭ���Գ�һ�ɡ���������ȭ��Ҫ�����ںӱ�һ������ĩ�ӱ�������
���̿��ι�͢���������Ӫ�̹٣������ڡ�����ɢ�֡�������ɢ�ֹ���
ʮ��·һ����ʮ���֣���Ҫ�ص�Ϊ�Ծ��������Կ���ʤ���������ͣ�
������롣ǿ�����۵������͹��ϣ����ֺݶ���Ѹ���ɿ졣ƽ����
ָͷ����Ҫ����ϣ�����ʱ�������棬�˳�һ�������ݣ����졣����
ɢ�ֵ���Ҫ�������е󿨼�������������ȣ�ÿһ�ַ�����һ������
��Ӧ�ַ�����������Ҫ�䣬������Ҫ�𡱣����ִ򣬻��ⶥ��ײ��һ��
��һ����������䣬���������������롣


	ѧϰҪ��
		��
HELP
	);
	return 1;
}
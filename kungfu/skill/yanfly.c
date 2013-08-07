// yanfly.c ��˫��
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "dodge"; }

/* �Ṧ��Ϣ */
string *dodge_msg = ({
	"$nһ��"HIW"������˫�ɡ�"NOR"������$N�Ĺ���Ʈ�𣬴��ݶ����һ�С�\n",
	"$nʹ��һ��"HIC"�����ഩ�ơ�"NOR"����Ȼ�������࣬���$N���˸��ա�\n",
	"$n����һҡ���ó�������Ӱ��һ��"HIW"��������ˮ��"NOR"�����$N�Ĺ��ơ�\n",
	"$nһ��"MAG"������Ͷ�֡�"NOR"����Ծ��ٿ��������$N���\n",
	"$n��һҡ����һ�Σ�һ��"HIM"��������ૡ�"NOR"������������\n",
});

/* �ɼ������书���� */
int valid_enable(string usage) { return usage=="dodge" || usage=="move"; }

/* ѧϰ��������practiceҲҪ��Ȿ���������ԣ������������ڹ��������͹��ˡ� */
int valid_learn(object me)
{
	object ob;

	if( (int)me->query_skill("king-of-dragon", 1) < 20 )
		return notify_fail("��ĵ����񹦲������죬û������˫�ɡ�\n");
	if( (int)me->query("max_neili") < 10 )
		return notify_fail("�������������û�а취����˫�ɡ�\n");
	return 1;
}

/* ��ϰ������ */
int practice_skill(object me)
{
	if( (int)me->query("qi") < 30 )
		return notify_fail("�������̫���ˣ���������˫�ɡ�\n");
	if (me->query_skill("yanfly", 1) < 30)
		me->receive_damage("qi", 10);

	me->receive_damage("qi", 20);
	return 1;
}

/* �������Ṧ�Ĵ���Ϣ */
string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

/* �书�Ѷ�ϵ�� = 100 / (learn_bonus+parctice_bonus+10) ��skill.c���������� */
/* ÿ��Ǳ������ѧ���ı����ܵ��� = random(query_int()/2+query("int")/2+bonus) */
/* ���Ʒ�Χ 0 - 30 */
int learn_bonus() { return 10; }

/* ÿ����ϰ��ü��ܵ��� = (random(�����书*�����书/(skill+1)))/5+bonus */
/* ���Ʒ�Χ 0 - 30 */
int practice_bonus() { return 5; }

/* ��ʦ�����ڲ������ı��ʡ�random(success()) == 0��ʱ����⡣��ʱ���á�
��ֵԽ��Խ��������⡣��������˻�ͣ�ͣ���������learn & teach */
int success() { return 10; }

/* �����������������ɲ��������Ʒ�Χ1��1.5���Ͻ����꣡Ŀǰ�������Ṧ�� */
int power_point(object me) { return 1.5; }

/* �����ļ�Ŀ¼ */
string perform_action_file(string action)
{
        return __DIR__"yanfly/" + action;
}

/* ������Ϣ */
int help(object me)
{
	write(HIC"\n��˫�ɣ�"NOR"\n");
	write(@HELP

	ѧϰҪ��
		������20��
		������Ϊ10
HELP
	);
	return 1;
}


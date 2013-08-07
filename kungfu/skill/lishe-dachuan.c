// xianglong-zhang.c ����ʮ����֮�����
// Last Modified by sega on Mar. 10 2000

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
int d_e1 = -60;
int d_e2 = -40;
int p_e1 = -20;
int p_e2 = 10;
int f_e1 = 350;
int f_e2 = 550;
int ttl = 17;
int seq = 5;
mapping *action = ({
	([
		"action"      : "$Nʩ��һ��"+(order[random(13)])+"������󴨡�"NOR"�����Ʋ�������������$n��$l",
		"skill_name" : "�����",
		"dodge"       : d_e1 + (d_e2 - d_e1) * seq / ttl,
		"parry"       : p_e1 + (p_e2 - p_e1) * seq / ttl,
		"force"       : f_e1 + (f_e2 - f_e1) * seq / ttl,
		"damage_type" : random(2) ? "����" : "����",
	]),
});


string main_skill() { return "xianglong-zhang"; }
int valid_enable(string usage) { return usage=="strike" ; }

int valid_learn(object me)
{
		if (me->query_skill("xianglong-zhang", 1) > 0)
				return notify_fail("���Ѿ�ѧȫʮ�����ˣ������ٵ���ѧϰ��\n");

    if (!me->query("can_learn/hong/sub-xianglong-zhang"))
    		return notify_fail("��δ�ú��߹��׵㣬���򲻵�����ʮ���Ƶľ��衣\n");

		if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
				return notify_fail("������ʮ���Ʊ�����֡�\n");

		if ((int)me->query("max_neili") < 1000)
				return notify_fail("�������̫�����޷�������ʮ���ơ�\n");

		if ((int)me->query("str") < 25)
				return notify_fail("�����������������������������ʮ���ơ�\n");

		if ((int)me->query("con") < 20)
				return notify_fail("����������������������������ʮ���ơ�\n");

		if ((int)me->query_skill("strike", 1) < 180)
				return notify_fail("��Ļ����Ʒ���򲻹���������������ʮ���ơ�\n");

		if ((int)me->query_skill("strike", 1) < (int)me->query_skill("lishe-dachuan", 1))
				return notify_fail("��Ļ����Ʒ�ˮƽ���ޣ��޷���������Ľ���ʮ���ơ�\n");

	return 1;
}

int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��ı�����ֲ�����ϰ��\n");
	if ((int)me->query("qi") < 100)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 40)
		return notify_fail("�����������������ʮ���ơ�\n");
	me->receive_damage("qi", 100);
	me->add("neili", -40);
	return 1;
}
string query_skill_name(int level)
{
			return action[0]["skill_name"];
}
mapping query_action(object me, object weapon)
{
	return action[0];
}
int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 5; }
int power_point(object me) {
	if (userp(me)) return 0.5; //��Ϊ�ǰ��Ʒ �������
  return 1;
} 

int help(object me)
{
	write(HIC"\n����ʮ����֮����󴨣�"NOR"\n");
	write(@HELP

    ����ʮ������ؤ�����֮��������������͵��书��

	ѧϰҪ��
		�õ����߹�����ָ��
		����1000
		�������25
		�������20
		�����Ʒ�180
HELP
	);
	return 1;
}
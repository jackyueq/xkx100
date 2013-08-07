// sougu.c �ѹ�ӥצ��
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N˫��һ£����צֱ��$n���̣���צȴЮ����֮������$n���䣬һ��һʵ������һ��"HIM"����צʽ��"NOR"",
	"lvl"    : 0,
	"skill_name" : "��צʽ"
]),
([	"action" : "$N���ζ�������ӥ���հ㡰ٿ���ش�$nͷ��Խ����ʹһ��"HIR"����צʽ��"NOR"˫צ����$n�Ժ����",
	"lvl"    : 5,
	"skill_name" : "��צʽ"
]),
([	"action" : "$N�͵�һ����ͻȻ����$n��ǰ��ʹһ��"HIB"����צʽ��"NOR"����צֱ��$nС��",
	"lvl"    : 10,
	"skill_name" : "��צʽ"
]),
([	"action" : "\n$N��צ���أ���צ�����󷢣�һ��"HIC"����צʽ��"NOR"����������$n��$l",
	"lvl"    : 20,
	"skill_name" : "��צʽ"
]),
([	"action" : "\n$N���ι��죬����ǰ�ˣ�ʹһ��"HIG"����צʽ��"NOR"��ֱ��$n�ɲ�",
	"lvl"    : 35,
	"skill_name" : "��צʽ"
]),
([	"action" : "\n$N����Ʈ������Ȼת��$n���һ��"HIW"����צʽ��"NOR"��˫צֱ��$n�ʺ����",
	"lvl"    : 60,
	"skill_name" : "��צʽ"
]),
([	"action" : "\n$Nһ����Х�����ΰ���ʹ��"HIC"��ǧצʽ��"NOR"���ɰ�������»���$n�پ�����צӰ������ȫ����Ѩ",
	"lvl"    : 85,
	"skill_name" : "ǧצʽ"
])
});

int valid_enable(string usage) { return usage=="claw" || usage=="parry"; }
int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("���ѹ�ӥצ��������֡�\n");
	if (me->query_skill("jiuyang-shengong") < 30)
		return notify_fail("��ľ�����̫�����޷�ѧ�ѹ�ӥצ����\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷�ѧ�ѹ�ӥצ����\n");
	if ((int)me->query("str") < 24)
		return notify_fail("�������̫��޷�ѧ�ѹ�ӥצ����\n");
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��ı�����ֲ�����ϰ��\n");
	if ((int)me->query("qi") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("�������������ӥצ����\n");
	me->receive_damage("qi", 25);
	me->add("neili", -5);
	return 1;
}
string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action); i > 0; i--)
		if(level >= action[i-1]["lvl"])
			return action[i-1]["skill_name"];
}
mapping query_action(object me, object weapon)
{
/* d_e=dodge_effect p_e=parry_effect f_e=force_effect m_e=damage_effect */
	int d_e1 = 40;
	int d_e2 = 20;
	int p_e1 = -10;
	int p_e2 = -40;
	int f_e1 = 250;
	int f_e2 = 300;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int)me->query_skill("sougu", 1);
	for(i = ttl; i > 0; i--)
		if(lvl > action[i-1]["lvl"])
		{
			seq = i; /* �������������� */
			break;
		}
	seq = random(seq);       /* ѡ������������ */
	return ([
		"action"      : action[seq]["action"],
		"dodge"       : d_e1 + (d_e2 - d_e1) * seq / ttl,
		"parry"       : p_e1 + (p_e2 - p_e1) * seq / ttl,
		"force"       : f_e1 + (f_e2 - f_e1) * seq / ttl,
		"damage_type" : random(2) ? "ץ��" : "����",
	]);
}
int learn_bonus() { return 15; }
int practice_bonus() { return 10; }
int success() { return 10; }
int power_point(object me) { return 1; }

string perform_action_file(string action)
{
	return __DIR__"sougu/" + action;
}
int help(object me)
{
	write(HIC"\n�ѹ�ӥצ����"NOR"\n");
	write(@HELP

    ���̰�üӥ��������֮���У�������ӥצ���ֵ�������������
�������书��

	ѧϰҪ��
		��������24
		������30��
		����100
HELP
	);
	return 1;
}


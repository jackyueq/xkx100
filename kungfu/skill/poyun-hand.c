// poyun-hand.c ������
// Last Modified by sir 10.23.2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N˫��һ£����צֱ��$n���̣���צȴЮ����֮������$n���䣬һ��һʵ������һ��"BLU"�����Ƹ��꡹"NOR"",
	"lvl"    : 0,
	"skill_name"  : "���Ƹ���"
]),
([	"action" : "$N���ζ�������ӥ���հ㡰ٿ���ش�$nͷ��Խ����ʹһ��"CYN"����ɽ������"NOR"˫�ּ���$n�Ժ�����",
	"lvl"    : 10,
	"skill_name"  : "��ɽ����"
]),
([	"action" : "$N�͵�һ����ͻȻ����$n��ǰ��ʹһ��"MAG"�������ơ�"NOR"��˫��ֱ��$nС��",
	"lvl"    : 20,
	"skill_name"  : "������"
]),
([	"action" : "$N���ֻ��أ����������󷢣�һ��"HIC"���ƹ����硹"NOR"����������$n��$l",
	"lvl"    : 40,
	"skill_name"  : "�ƹ�����"
]),
([	"action" : "$N΢΢һЦ������ǰ�ˣ�ʹһ��"HIW"���λó�Ե��"NOR"��ֱ��$n��ǰ����ҪѨ",
	"lvl"    : 60,
	"skill_name"  : "�λó�Ե"
]),
([	"action" : "$N���ι��죬������ң���Ȼת��$n���һ��"HIR"������ʯ��"NOR"��˫��ֱ��$n�ʺ����",
	"lvl"    : 80,
	"skill_name"  : "����ʯ"
]),
([	"action" : "$Nһ����Х������ͻȻ����ʹ��"HIG"����ˮ���¡�"NOR"���ɰ�������»���$n�پ�������Ӱ������ȫ��ҪѨ",
	"lvl"    : 100,
	"skill_name"  : "��ˮ����"
])
});

int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }
int valid_combine(string combo) { return combo=="songyang-strike"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�������ֱ�����֡�\n");
	if ((int)me->query_skill("hanbing-zhenqi", 1) < 10)
		return notify_fail("��ĺ���������򲻹����޷�ѧ�����֡�\n");
	if ((int)me->query("max_neili") < 10)
		return notify_fail("�������̫�����޷�ѧ�����֡�\n");
	if ((int)me->query("str") < 25)
		return notify_fail("��ı���̫��޷�ѧ�����֡�\n");
	return 1;
}
int practice_skill(object me)
{
	if ((int)me->query("qi") < 50)
		return notify_fail("��ľ���̫���ˡ�\n");
	if ((int)me->query("neili") < 30)
		return notify_fail("������������������֡�\n");
	me->receive_damage("qi", 30);
	me->add("neili", -20);
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
	int d_e1 = -40;
	int d_e2 = -10;
	int p_e1 = 20;
	int p_e2 = 50;
	int f_e1 = 120;
	int f_e2 = 220;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("poyun-hand", 1);
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
		"damage_type" : random(2) ? "����" : "����",
	]);
}
int learn_bonus() { return 20; }
int practice_bonus() { return 20; }
int success() { return 15; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"poyun-hand/" + action;
}

int help(object me)
{
	write(HIC"\n�����֣�"NOR"\n");
	write(@HELP

    ������Ϊ��ɽ���ַ�������������ƻ�����

	ѧϰҪ��
		��������10��
		��������25
		����10
HELP
	);
	return 1;
}


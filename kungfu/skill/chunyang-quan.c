// chunyang-quan.c ����ȭ
// Last Modified by sega on Mar. 10 2000

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action":
"ֻ��$N����һ�������������ȭ����һ��"HIW"�����ײ�ʳ��"NOR"��׼$n��$l���˹�ȥ",
	"lvl" : 0,
	"skill_name" : "���ײ�ʳ"
]),
([	"action":
"$N����һ�֣�����Ťת��ȭ����������ǰ�죬һ��"HIY"������Ѱ�꡹"NOR"����$n��$l
�к���ȥ",
	"lvl" : 20,
	"skill_name" : "����Ѱ��"
]),
([	"action":
"$N��ȭ��$n����һ�Σ�������ǰһ����ȭʹ�˸�"HIB"��Ұ���ϲۡ�"NOR"��$n��$l����һ��",
	"lvl" : 40,
	"skill_name" : "Ұ���ϲ�"
]),
([	"action":
"$N����һ������ȭ��������ȭ���磬һ��"HIR"���ڻ����ġ�"NOR"�Ʋ��ɵ��ػ���$n$l",
	"lvl" : 60,
	"skill_name" : "�ڻ�����"
]),
([	"action":
"ֻ��$N������ʽ��һ��"HIM"������Ϸ�项"NOR"˫ȭ�������$n$l�������з�",
	"lvl" : 80,
	"skill_name" : "����Ϸ��"
]),
([	"action":
"$N���һȭ���������ߣ�ֻ���Ǽ�����һ�࣬������������"RED"�����뷴�ҡ�"NOR"��",
	"lvl" : 100,
	"skill_name" : "���뷴��"
]),
([	"action":
"$N�����󹭲�����ȭһ�Σ���ȭ���������ȭ�ƽ����õ�����һ��"GRN"������
��ʳ��"NOR"��$n��$l��ȥ",
	"lvl" : 120,
	"skill_name" : "������ʳ"
]),
([	"action":
"ֻ��$N����������һ��������ȭ����ȭ�������������ȭ��������ǧ����
��һ�е����ֽ���"HIR"���������ơ�"NOR"",
	"lvl" : 140,
	"skill_name" : "��������"
]),
});

int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }
int valid_combine(string combo) { return combo=="haotian-zhang"; }

int valid_learn(object me)
{
	if(me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("������ȭ������֡�\n");
	if ((int)me->query_skill("xiantian-qigong", 1) < 20)
		return notify_fail("�������������򲻹����޷�ѧ����ȭ��\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷�������ȭ��\n");
	return 1;
}

int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��ı�����ֲ�����ϰ��\n");
	if ((int)me->query("qi") < 40)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 40)
		return notify_fail("�����������������ȭ��\n");
	me->receive_damage("qi", 35);
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
	int d_e1 = 20;
	int d_e2 = 40;
	int p_e1 = -40;
	int p_e2 = -20;
	int f_e1 = 200;
	int f_e2 = 400;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("chunyang-quan", 1);
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
int learn_bonus() { return 10; }
int practice_bonus() { return 10; }
int success() { return 10; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"chunyang-quan/" + action;
}
int help(object me)
{
	write(HIC"\n����ȭ��"NOR"\n");
	write(@HELP

    ����ȭΪ������������ȫ����ȭ����
    ��������ƻ�����

	ѧϰҪ��
		������Ԫ��20��
		����100
HELP
	);
	return 1;
}


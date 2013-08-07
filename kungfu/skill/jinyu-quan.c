// jinyu-quan.c ����ȭ
// Last Modified by sega on Mar. 10 2000

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$Nһ��"HIY"�������á�"NOR"��˫ȭһ��һ��, ��$n��ȥ",
	"lvl"    : 0,
	"skill_name" : "������"
]),
([	"action" : "$Nһ��"MAG"�������Ͻ�"NOR"���ó�һƬȭӰ��������磬����$n��ͷ��",
	"lvl"    : 20,
	"skill_name" : "�����Ͻ�"
]),
([	"action" : "$N��Ӱ����Ʈ������΢Ц��һ��"BLU"����������"NOR"����������$n��$l",
	"lvl"    : 40,
	"skill_name" : "��������"
]),
([	"action" : "$Nһ��"HIC"���������⡹"NOR"��˫ȭһ�ϣ�$nֻ��������$N��ȭӰ",
	"lvl"    : 60,
	"skill_name" : "��������"
]),
([	"action" : "$N����$nһת���������ߣ�ȭ����磬��������$n������һ��
"GRN"���������á�"NOR"",
	"lvl"    : 80,
	"skill_name" : "��������"
]),
([	"action" : "ֻ��$Nһ�������˲���������Σ�ͻȻ�Ϳ��������ѵ�$n��ǰ��
��ȭ���������Ⱦ������ף�Ѹ����ף�һ��"HIM"����ʯ�ɽ�"NOR"����$n��ǰ��",
	"lvl"    : 100,
	"skill_name" : "��ʯ�ɽ�"
]),
([	"action" : "$Nһ��"CYN"���ڿ����"NOR"������$n���ƺ�$n��ȫ����ȭӰ����",
	"lvl"    : 120,
	"skill_name" : "�ڿ����"
]),
});

int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }
int valid_combine(string combo) { return combo=="wuluo-zhang"; }

int valid_learn(object me)
{
	if ((int)me->query_skill("kurong-changong",1) < 20)
		return notify_fail("��Ŀ���������򲻹����޷�������ȭ��\n");
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("������ȭ������֡�\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷�������ȭ��\n");
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��ı�����ֲ�����ϰ��\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("�����������������ȭ��\n");
	me->receive_damage("qi", 30);
	me->add("neili", -10);
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
	int d_e1 = 35;
	int d_e2 = 55;
	int p_e1 = -25;
	int p_e2 = -5;
	int f_e1 = 90;
	int f_e2 = 240;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("jinyu-quan", 1);
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
		"damage_type" : "����",
	]);
}
int learn_bonus() { return 30; }
int practice_bonus() { return 25; }
int success() { return 20; }
int power_point(object me) { return 1.0; }

int help(object me)
{
	write(HIC"\n����ȭ��"NOR"\n");
	write(@HELP

    ����ȭΪ���ϴ���μҵ��书��
    �������������ƻ�����

	ѧϰҪ��
		��������20��
		����100
HELP
	);
	return 1;
}


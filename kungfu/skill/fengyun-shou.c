// fengyun-shou.c ������
// Last Modified by sir 10.23.2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$Nһʽ"HIC"���������ա�"NOR"�����ƻ�צ����ָ�繳��ֱ��$n������ҪѨ",
	"lvl" : 0,
	"skill_name" : "��������"
]),
([	"action" : "$N������Σ�һʽ"HIR"���һ����ơ�"NOR"����������ֱ��������$n�ļ羮��Ѩ
",
	"lvl" : 8,
	"skill_name" : "�һ�����"
]),
([	"action" : "$Nʹһʽ"HIG"����������"NOR"����ָ��������ò�ʩ������$n����·Ҫ��",
	"lvl" : 16,
	"skill_name" : "��������"
]),
([	"action" : "$N����ӥץ�������߾٣�һʽ"HIW"����Ŀ�ѻԡ�"NOR"����$n���нڴ���",	
	"lvl" : 24,
	"skill_name" : "��Ŀ�ѻ�"
]),
([	"action" : "$Nʹһʽ"HIM"�������ķ���"NOR"������˷�����������Ӱ��һצͻ����ץ��$n
���ؿ�",
	"lvl" : 40,
	"skill_name" : "�����ķ�"
]),
([	"action" : "$N���ֻ��ۣ�ȫ��ؽ�žž���죬һʽ"HIC"��ˮ�����ɡ�"NOR"������$n��$l",
	"lvl" : 48,
	"skill_name" : "ˮ������"
]),
([	"action" : "$Nһʽ"HIB"��ɽ�����ܡ�"NOR"��ʮָ���죬������հ������$n��ȫ��ҪѨ",
	"lvl" : 54,
	"skill_name" : "ɽ������"
]),
([	"action" : "$N�������ţ�һʽ"HIY"��������ġ�"NOR"����һ�������У�˫��ͬʱ����$n
���ߵ���Ѩ",
	"lvl" : 60,
	"skill_name" : "�������"
])
});

int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }
int valid_combine(string combo) { return combo=="yingzhua-gong"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�������ֱ�����֡�\n");
	if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
		return notify_fail("��Ļ�Ԫһ������򲻹����޷�ѧ�����֡�\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷��������֡�\n");
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��ı�����ֲ�����ϰ��\n");
	if ((int)me->query("qi") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("������������������֡�\n");
	me->receive_damage("qi", 20);
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
	int d_e1 = -35;
	int d_e2 = 0;
	int p_e1 = 30;
	int p_e2 = 55;
	int f_e1 = 70;
	int f_e2 = 170;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("fengyun-shou", 1);
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
int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 20; }
int power_point(object me) { return 1.0; }

int help(object me)
{
	write(HIC"\n�����֣�"NOR"\n");
	write(@HELP

    ������Ϊ������ʮ������֮һ��
    ����ӥצ��������

	ѧϰҪ��
		��Ԫһ����20��
HELP
	);
	return 1;
}


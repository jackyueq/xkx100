// zhentian-cuff.c ����ȭ��

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N��һ��������΢��������һ����һ��"HIW"�����°��졹"NOR"��һȭֱͱ$n��$l",
	"lvl" : 0,
	"skill_name" : "���°���"
]),
([	"action" : "$N��������һЦ����ȭ�������ϣ���ȭƽƽ������һ��"RED"���������졹"NOR"���������$n",
	"lvl" : 15,
	"skill_name" : "��������"
]),
([	"action" : "$N��$nһ����ȣ�ʹһ��"HIC"�����羭�졹"NOR"����ȭ�������漴��ȭ���ϣ�������������$n��$l",
	"lvl" : 30,
	"skill_name" : "���羭��"
]),
([	"action" : "$N�ƺ�һ����˫ȭ���Ϸֿ���һ��"HIR"���ٻ����졹"NOR"��ȭ�����ߣ�����ͬʱ����$n��$l",
	"lvl" : 45,
	"skill_name" : "�ٻ�����"
]),
([	"action" : "$Nʩ��"YEL"��һ�����졹"NOR"��һ�����һȭ��մ����ȭ��ֱ��$n��$l",
	"lvl" : 60,
	"skill_name" : "һ������"
]),
([	"action" : "$Nһ����Х��˫ȭ���������һ��"BLU"��ʯ���쾪��"NOR"��ȭ���ܲ�$n��ǰ������",
	"lvl" : 70,
	"skill_name" : "ʯ���쾪"
]),
([	"action" : "$Nŭ��һ������շ���һʽ"MAG"��������ѡ�"NOR"��˫ȭ�Ӹ����£����봷��$n",
	"lvl" : 80,
	"skill_name" : "�������"
]),
([	"action" : "$N�����Ц������������۷��裬һ��"HIW"���޷����졹"NOR"��ȭ����������������$n��ȥ",
	"lvl" : 90,
	"skill_name" : "�޷�����"
]),
([	"action" : "$N������ʽͻȻ�ӿ죬һ��"MAG"��ȭ��˫����"NOR"��������$n����һȭ���漴˫�������߳�",
	"lvl" : 100,
	"skill_name" : "ȭ��˫��"
])
});

int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }
int valid_combine(string combo) { return combo=="chuanyun-leg"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��������ȭ��������֡�\n");
	if ((int)me->query_skill("xuantian-wuji", 1) < 25)
		return notify_fail("��ġ������޼�������򲻹����޷�ѧ������ȭ����\n");
	if ((int)me->query("max_neili") < 50)
		return notify_fail("�������̫�����޷���������ȭ����\n");
	return 1;
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 40)
		return notify_fail("������������ˡ�\n");
	if ((int)me->query("qi") < 40)
		return notify_fail("�������������������ȭ����\n");
	me->receive_damage("qi", 35);
	me->add("qi", -20);
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
	int d_e1 = 25;
	int d_e2 = 45;
	int p_e1 = -35;
	int p_e2 = -15;
	int f_e1 = 140;
	int f_e2 = 290;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("zhentian-cuff", 1);
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
int learn_bonus() { return 20; }
int practice_bonus() { return 15; }
int success() { return 15; }
int power_point(object me) {
	if (me->query("gender")=="����")
	return 1.2;
	else
	 return 0.8; 
}

int help(object me)
{
	write(HIC"\n����ȭ����"NOR"\n");
	write(@HELP

    ����ȭ��Ϊ�����ɲ����е��ӵ��似��

	ѧϰҪ��
		�����޼���25��
		����50
HELP
	);
	return 1;
}


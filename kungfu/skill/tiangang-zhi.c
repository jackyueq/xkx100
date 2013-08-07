// tiangang-zhi.c ���ָѨ��
// Last Modified by sir 10.22.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N�������Ღ����������ָ���쵯������һʽ"CYN"��������ġ�"NOR"������$n��$l",
	"lvl" : 0,
	"skill_name" : "�������"
]),
([	"action" : "$N˫���������䣬��������$n��һʽ"HIC"��������̶��"NOR"�����ֻ��Ƴ�ָ����ӿϮ��$n��$l",
	"lvl" : 12,
	"skill_name" : "������̶"
]),
([	"action" : "$N������ȭ���ƣ�����Ť�������ߣ�һʽ"BLU"�����߾��ɡ�"NOR"�����Ҳ��ã�����$n��$l",
	"lvl" : 24,
	"skill_name" : "���߾���"
]),
([	"action" : "$Nһʽ"YEL"��������ɽ��"NOR"�����ֳ�أ�����ǰ̽���ָ����$n��$l",	
	"lvl" : 36,
	"skill_name" : "������ɽ"
]),
([	"action" : "$Nʹһʽ"MAG"������������"NOR"����Ӱ��ò���������$n����͵�����$n��$l",
	"lvl" : 48,
	"skill_name" : "��������"
]),
([	"action" : "$N���۴󿪴��أ���һ������һʽ"HIB"���ض�ɽҡ��"NOR"������͸����˫�ֿ���һ��������������������$n��$l",
	"lvl" : 60,
	"skill_name" : "�ض�ɽҡ"
]),
([	"action" : "$N������������Ʈ����˫�������Ķ���һʽ"HIW"��ˮ�����¡�"NOR"���Ӹ����£����಻������$n��$l",
	"lvl" : 72,
	"skill_name" : "ˮ������"
]),
([	"action" : "$N�ڿն���˫�ƺ�һ��ʮָ�繳��һ��"HIY"��̩ɽѹ����"NOR"������$n�Ļ��䣬�Ƶ������Ѽ�",
	"lvl" : 84,
	"skill_name" : "̩ɽѹ��"
])
});

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }
int valid_combine(string combo) { return combo=="jinding-zhang"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail(HIC"�����ָѨ��������֡�\n"NOR);
	if ((int)me->query_skill("linji-zhuang", 1) < 20)
		return notify_fail("����ټ�ʮ��ׯ��򲻹����޷�ѧ���ָѨ����\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷������ָѨ����\n");
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��ı�����ֲ�����ϰ��\n");
	if ((int)me->query("qi") < 40)
		return notify_fail("�������̫���ˣ��޷������ָѨ����\n");
	if ((int)me->query("neili") < 25)
		return notify_fail("����������������ָѨ����\n");
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
	int d_e1 = 30;
	int d_e2 = 55;
	int p_e1 = -25;
	int p_e2 = -10;
	int f_e1 = 260;
	int f_e2 = 360;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("tiangang-zhi", 1);
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
int learn_bonus() { return 15; }
int practice_bonus() { return 15; }
int success() { return 15; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"tiangang-zhi/" + action;
}
int help(object me)
{
	write(HIC"\n���ָѨ����"NOR"\n");
	write(@HELP

    ���ָѨ��Ϊ�������书��
    ��������ƻ�����

	ѧϰҪ��
		�ټ�ʮ��ׯ20��
		����100
HELP
	);
	return 1;
}


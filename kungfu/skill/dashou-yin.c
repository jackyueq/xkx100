// dashou-yin.c ���ڴ���ӡ
// Last Modified by sir 10.23.2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$Nʹ��һ��"HIC"����������ӡ��"NOR"��˫�ƺ�ʮ��ֱֱײ��$n��ǰ��",
	"skill_name" : "��������ӡ",
	"lvl" : 0
]),
([	"action" : "$Nʹ��һ��"HIW"�����ƹ���ӡ��"NOR"������Ծ��˫���繴��ץ��$n��$l",
	"skill_name" : "���ƹ���ӡ",
	"lvl" : 8
]),
([	"action" : "$Nʹ��һ��"HIY"��׼���ĸӡ��"NOR"��������ָ��ֱȡ$n��$l",
	"skill_name" : "׼���ĸӡ",
	"lvl" : 16
]),
([	"action" : "$Nʹ��һ��"HIR"����������ӡ��"NOR"��ŭ��һ����һ�Ƶ�ͷ����$n��$l",
	"skill_name" : "��������ӡ",
	"lvl" : 24
]),
([	"action" : "$Nʹ��һ��"HIG"��ҩʦ�����ӡ��"NOR"���ͳ���ǰ�����������㹥��$n",
	"skill_name" : "ҩʦ�����ӡ",
	"lvl" : 32
]),
([	"action" : "$Nʹ��һ��"HIM"�����½��ӡ��"NOR"����������˫������ɨ��$n��$l",
	"skill_name" : "���½��ӡ",
	"lvl" : 40
]),
([	"action" : "$Nʹ��һ��"HIB"�����ֽ��ӡ��"NOR"�������Ծ��˫��ǰ�������ץ��$n����
��",
	"skill_name" : "���ֽ��ӡ",
	"lvl" : 48
]),
([	"action" : "$Nʹ��һ��"HIW"�������ǻ�ӡ��"NOR"����ʱ��������������г���������Ӱ��
��$n��$l",
	"skill_name" : "�����ǻ�ӡ",
	"lvl" : 56
]),
});

int valid_enable(string usage) { return usage == "hand" || usage == "parry"; }
int valid_combine(string combo) { return combo=="yujiamu-quan"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�����ڴ���ӡ������֡�\n");
	else if ((int)me->query("max_neili") < 50)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("longxiang", 1) >= 20 ||
		(int)me->query_skill("xiaowuxiang", 1) >= 20)
		return 1;
	else if ((int)me->query_skill("longxiang", 1) < 20)
		return notify_fail("���������������̫ǳ��\n");
	else if ((int)me->query_skill("xiaowuxiang", 1) < 20)
		return notify_fail("���С���๦���̫ǳ��\n");
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�������ڴ���ӡ��������֡�\n");
	if(!me->query_skill("longxiang",1) && !me->query_skill("xiaowuxiang",1))
		return notify_fail("�������ڴ���ӡ������Ҫ��ѩɽ�ɵ��ڹ���Ϊ������\n");
	if ((int)me->query("qi") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("������������������ڴ���ӡ����\n");
	me->receive_damage("qi", 25);
	me->add("neili", -15);
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
	int d_e2 = -5;
	int p_e1 = 25;
	int p_e2 = 50;
	int f_e1 = 100;
	int f_e2 = 200;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("dashou-yin", 1);
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
int learn_bonus() { return 25; }
int practice_bonus() { return 25; }
int success() { return 15; }
int power_point() { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"dashou-yin/" + action;
}

int help(object me)
{
	write(HIC"\n���ڴ���ӡ��"NOR"\n");
	write(@HELP

    ���ڴ���ӡΪѩɽ���ַ���
    ���������ĸȭ������

	ѧϰҪ��
		���󹦻�С���๦20��
		����50
HELP
	);
	return 1;
}


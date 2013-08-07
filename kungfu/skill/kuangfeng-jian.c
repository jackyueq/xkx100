//kuangfeng-jian ���콣
// Last Modified by sir 10.22.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N����Ծ������$w��ӣ�ն��$n��",
	"lvl"    : 0,
	"skill_name" : "��ƽ�˾�"
]),
([	"action" : "$N����$w�����������Σ���$n���ұ����ն��",
	"lvl"    : 20,
	"skill_name" : "������ӿ"
]),
([	"action" : "$N����һ����ˢˢˢˢ�Ľ�����$n�أ������������Ĵ�����",
	"lvl"    : 40,
	"skill_name" : "������"
]),
([	"action" : "$N����һ����Х��б����ǰ��$w����ֱ����Ѹ���ޱȣ�����$n��$l",
	"lvl"    : 60,
	"skill_name" : "������ɢ"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; } 
int valid_learn(object me)
{
	mapping myfam;
	myfam = (mapping)me->query("family");

	if ((int)me->query("max_neili") < 300)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("huashan-neigong", 1) < 60)
		return notify_fail("����ڹ��ķ����̫ǳ��\n");
	if ((int)me->query_skill("dodge", 1) < 60)
		return notify_fail("����Ṧ���̫ǳ��\n");
	if ((int)me->query_dex() < 25)
		return notify_fail("�������������\n");
	return 1;
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("qi") < 40 || (int)me->query("neili") < 30 )
		return notify_fail("��������������������콣��\n");
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
	int d_e1 = 15;
	int d_e2 = 35;
	int p_e1 = -15;
	int p_e2 = 5;
	int f_e1 = 100;
	int f_e2 = 150;
	int m_e1 = 80;
	int m_e2 = 180;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("kuangfeng-jian", 1);
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
		"damage"      : m_e1 + (m_e2 - m_e1) * seq / ttl,
		"damage_type" : random(2) ? "����" : "����",
	]);
}
int learn_bonus() { return 20; }
int practice_bonus() { return 20; }
int success() { return 15; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"kuangfeng-jian/" + action;
}
int help(object me)
{
	write(HIC"\n���콣��"NOR"\n");
	write(@HELP

    ���콣Ϊ��ɽ���ڵĽ�����
    ���ס����콣�����Ƿⲻƽ������ɽ����ʮ��������Ƴ���
�ĵ��⽣��������һ������һ�������ػ���־������Ҫִ�ƻ�ɽһ
�ɣ�������˻�ɽ��������֮�󣬸�����Ϊ����������������ƾ��
�ı�������һ�����ʽ�����콣����

	ѧϰҪ��
		��ɽ�ڹ�60��
		�����Ṧ60��
		������25����
		����300
HELP
	);
	return 1;
}


// tianyu-qijian.c �����潣
// Last Modified by sir 10.22.2001

#include <ansi.h>;
#include <xiaoyao.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action":"$Nʹһʽ"HIC"������һ�ߡ�"NOR"������$w����΢�񣬻ó�һ���������$n��$l",
	"lvl" : 0,
	"skill_name" : "����һ��"
]),
([	"action":"$N����ǰ��ʹ��"HIM"�����羪�硹"NOR"������$w����һ����������$n��$l",
	"lvl" : 9,
	"skill_name" : "���羪��"
]),
([	"action":"$N����$wһ����һ��"HIY"�����ھ��졹"NOR"��ббһ�������ó�������$n��$l",
	"lvl" : 18,
	"skill_name" : "���ھ���"
]),
([	"action":"$N���н����ॳ���һ����һʽ"HIB"��������ġ�"NOR"��һ���������$n��$l",
	"lvl" : 27,
	"skill_name" : "�������"
]),
([	"action":"$Nһʽ"HIR"��ŭ���񻨡�"NOR"������$w�������������ʹ$n�Ѷ���ʵ���޿ɶ��",
	"lvl" : 36,
	"skill_name" : "ŭ����"
]),
([	"action":"$N����$wбָ���죬��â���£�һʽ"BLU"���Ż����ա�"NOR"����׼$n��$lбб����",
	"lvl" : 44,
	"skill_name" : "�Ż�����"
]),
([	"action":"$Nһʽ"HIW"�������ѩ��"NOR"�����󼱶�������������⣬����$n��$l",
	"lvl" : 52,
	"skill_name" : "�����ѩ"
]),
([	"action":"$Nһʽ"GRN"����ӵ�к��"NOR"��$w��ն�������缲�������$n���ؿ�",
	"lvl" : 60,
	"skill_name" : "��ӵ�к"
]),
([	"action":"$Nһʽ"HIG"��������ɡ�"NOR"��$wͻȻ���������һƬ���Χ��$nȫ��",
	"lvl" : 70,
	"skill_name" : "�������"
])
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }
int valid_learn(object me)
{
	if(((int)me->query_skill("bahuang-gong", 1) < 20 ))
		return notify_fail("��ı����ڹ���������졣\n");
	if ((int)me->query("max_neili") < 80)
		return notify_fail("�������������\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("qi") < 50 || (int)me->query("neili") < 35 )
		return notify_fail("����������������������潣��\n");
	me->receive_damage("qi", 45);
	me->add("neili", -30);
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
	int d_e1 = -15;
	int d_e2 = 5;
	int p_e1 = -45;
	int p_e2 = -25;
	int f_e1 = 150;
	int f_e2 = 200;
	int m_e1 = 170;
	int m_e2 = 270;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("tianyu-qijian", 1);
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
int learn_bonus() { return 10; }
int practice_bonus() { return 10; }
int success() { return 5; }
int power_point(object me) { 
	if (fam_type(me)=="lingjiu")
	  return 1.4; 
  return 1.0;
}

string perform_action_file(string action)
{
	return __DIR__"tianyu-qijian/" + action;
}
int help(object me)
{
	write(HIC"\n�����潣��"NOR"\n");
	write(@HELP

    �����潣Ϊ��ɽ���չ�������

	ѧϰҪ��
		�˻�����Ω�Ҷ���20��
		����80
HELP
	);
	return 1;
}


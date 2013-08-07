// wuhu-duanmendao.c �廢���ŵ�
// Last Modified by sega on Mar. 10 2000

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N����$wбָ��һ��"HIC"��ֱ��ֱȥ��"NOR"������һ�٣�һ����$n��$l��ȥ",
	"lvl"    : 0,
	"skill_name" : "ֱ��ֱȥ",
]),
([	"action" : "$Nһ��"HIM"��ͯ�ӹһ���"NOR"����������㣬$wһ��һ�գ�ƽ�л���$n�ľ���",
	"lvl"    : 10,
	"skill_name" : "ͯ�ӹһ�",
]),
([	"action" : "$Nչ���鲽������Ծ�䣬һ��"HIW"���ƴ����¡�"NOR"������һ������ն��$n",
	"lvl"    : 20,
	"skill_name" : "�ƴ�����",
]),
([	"action" : "$Nһ��"HIB"��������ɽ��"NOR"��$w�󿪴��أ����϶��»���һ�����磬ֱ����$n",
	"lvl"    : 30,
	"skill_name" : "������ɽ",
]),
([	"action" : "$N����$wһ����һ��"MAG"����Ϫ���㡹"NOR"��˫�ֳ����������У�����$n���ؿ�",
	"lvl"    : 40,
	"skill_name" : "��Ϫ����",
]),
([	"action" : "$N����$w��ʹ��һ��"HIR"���Ź����ġ�"NOR"���������ã����ҿ�����������$n",
	"lvl"    : 50,
	"skill_name" : "�Ź�����",
]),
([	"action" : "$Nһ��"HIW"���������ۡ�"NOR"�����Ծ����أ�$w˳����ǰ��Ю��������$n��$l",
	"lvl"    : 60,
	"skill_name" : "��������",
]),
([	"action" : "$N����פ�أ�һ��"CYN"��������Ϣ��"NOR"���ӳ�һƬ�����ĵ�Ӱ����$n��ȫ��ӿȥ",
	"lvl"    : 70,
	"skill_name" : "������Ϣ",
]),
([	"action" : "$N���ֺ󳷣�����һ����һ��"YEL"��׳ʿ����"NOR"����ʱһ���׹�ֱն��$n���ֱ�",
	"lvl"    : 80,
	"skill_name" : "׳ʿ����",
]),
([	"action" : "$N�߸�Ծ��һ��"HIR"����ͷ��ء�"NOR"������$wֱ����$n�ľ���",
	"lvl"    : 90,
	"skill_name" : "��ͷ���",
]),
([	"action" : "$N���ػ��У�һ��"BLU"�����Ӿ��"NOR"������$wֱ��ȥ$n���ɲ�",
	"lvl"    : 100,
	"skill_name" : "���Ӿ���",
]),
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }
int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("blade", 1) < 20)
		return notify_fail("��Ļ����������̫ǳ��\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "blade")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("��������������廢���ŵ�����\n");
	me->receive_damage("qi", 30);
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
	int d_e1 = 55;
	int d_e2 = 35;
	int p_e1 = 5;
	int p_e2 = -15;
	int f_e1 = 50;
	int f_e2 = 100;
	int m_e1 = 30;
	int m_e2 = 140;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int)me->query_skill("wuhu-duanmendao", 1);
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
		"damage_type" : "����",
	]);
}
int learn_bonus() { return 30; }
int practice_bonus() { return 25; }
int success() { return 15; }
int power_point(object me) { return 1; }
/*
mapping query_action(object me, object weapon)
{
	int zhaoshu, level;

	zhaoshu = sizeof(action)-1;
	level = (int) me->query_skill("wuhu-duanmendao",1);

	if (level < 60 ) zhaoshu--;
	if (level < 50 ) zhaoshu--;
	if (level < 40 ) zhaoshu--;
	if (level < 30 ) zhaoshu--;
	if (level < 20 ) zhaoshu--;
	if (level < 10 ) zhaoshu--;
	return action[random(zhaoshu)];
}
*/
string perform_action_file(string action)
{
	return __DIR__"wuhu-duanmendao/" + action;
}
int help(object me)
{
	write(HIC"\n�廢���ŵ���"NOR"\n");
	write(@HELP

    �廢���ŵ���éʮ���ݺὭ��������͵���Ĺ���

	ѧϰҪ��
		��������20��
		����100
HELP
	);
	return 1;
}


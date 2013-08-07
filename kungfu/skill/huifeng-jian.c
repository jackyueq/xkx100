//huifeng-jian.c �ط������
// Last Modified by sir 10.22.2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"skill_name":   "���Ϯ��",
	"action" : "$N���⽣â������һ��"HIC"�����Ϯ�¡�"NOR"������$w�����´󿪴��أ�һ����������$n��$l",
	"lvl" : 0
]),
([	"skill_name":   "Ʈѩ����",
	"action" : "$N����Ȧת��һ��"HIW"��Ʈѩ���ơ�"NOR"������$wƽչ�´̣�һ�����Ữ��$n��$l",
	"lvl" : 10
]),
([	"skill_name":   "ǧ�徺��",
	"action" : "$N��������������������������$wʹ��һʽ"GRN"��ǧ�徺�㡹"NOR"����$n��$l",
	"lvl" : 20
]),
([	"skill_name":   "��������",
	"action" : "$N������ָ��������ת��һ��"HIB"���������ڡ�"NOR"ֱȡ$n��$l",
	"lvl" : 30
]),
([	"skill_name":   "��������",
	"action" : "$N��â���£��������ߣ�����$wʹ��һʽ"BLU"������������"NOR"�������������$n��$l",
	"lvl" : 40
]),
([	"skill_name":   "������ɳ",
	"action" : "$N�����ƽ���������ʵ��׷ɣ��ó�����ǹ⣬����$wʹ��һʽ
"HIY"��������ɳ��"NOR"ԾԾ����Ʈ��$n��$l",
	"lvl" : 50
]),
([	"skill_name":   "��������",
	"action" : "$N�ӽ��ֻ�����������ǰԾ��������$wһʽ"HIM"���������Ρ�"NOR"����������֮�ƣ�����$n��$l",
	"lvl" : 60
]),
([	"skill_name":   "��غ���",
	"action" : "$N�˲������ֽ�ָ��ת������һŤ������$wһ��"MAG"����غ��衹"NOR"���¶��ϴ���$n��$l",
	"lvl" : 70
]),
});

int valid_enable(string usage) { return (usage=="sword") || (usage=="parry") ; }
int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 50)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("linji-zhuang", 1) < 20)
		return notify_fail("����ټ�ʮ��ׯ���̫ǳ��\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("qi") < 50 || (int)me->query("neili") < 35 )
		return notify_fail("������������������ط��������\n");
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
	int d_e1 = -10;
	int d_e2 = 10;
	int p_e1 = -40;
	int p_e2 = -20;
	int f_e1 = 150;
	int f_e2 = 200;
	int m_e1 = 160;
	int m_e2 = 260;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("huifeng-jian", 1);
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
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"huifeng-jian/" + action;
}

int help(object me)
{
	write(HIC"\n�ط��������"NOR"\n");
	write(@HELP

    �ط������Ϊ�������书��

	ѧϰҪ��
		�ټ�ʮ��ׯ20��
		����50
HELP
	);
	return 1;
}


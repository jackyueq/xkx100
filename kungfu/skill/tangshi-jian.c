// tangshi-jian.c ��ʫ����
// Last Modified by winder on Mar. 10 2000
// Edited by fandog, 02/13/2000

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N����$w�����Ϸ�б�����£��������ͦ���̳���һ��"HIC"���º躣���������겻�ҹˡ�"NOR"������$w������ͷ��һ��������$n��$l��",
	"lvl" : 0,
	"skill_name" : "�º躣���������겻�ҹ�"
]),
([	"action" : "$N����������$w�󿪴��أ�һ��ߺ�ȣ�����������һ��"HIB"�����̺��������Ǻ᲻�ҹ���"NOR"ֱ��$n��$l",
	"lvl" : 10,
	"skill_name"  : "���̺��������Ǻ᲻�ҹ�"
]),
([	"action" : "ͻȻ��������������$N��$n����������һʽ"HIG"�������ž��磬��ɽ�����Ρ�"NOR"��������$n��$l�߿����ӹ���$nֻ��$l���쬵أ����һ������æ���ˡ�",
	"lvl" : 20,
	"skill_name" : "�����ž��磬��ɽ������"
]),
([	"action" : "$N����$w�ݳ���һ������ָ��$n����磬����ȴʹ��һʽ"HIY"�������մ��죬������������"NOR"�����¶���$w����$n��$l",
	"lvl" : 30,
	"skill_name" :"�����մ��죬����������"
]),
([	"action" : "$Nһ��"HIW"����ͷ�����£���ͷ˼���硹"NOR"������ǰ�㣬���ػؽ�б��������$wƽƽ����$n��$l��ȥ",
	"lvl" : 40,
	"skill_name" : "��ͷ�����£���ͷ˼����"
]),
([	"action" : "$N���������һš��һ��"BLU"������һƬ�£��򻧵�������"NOR"������$w������$n��$l��ȥ",
	"lvl" : 50,
	"skill_name" : "����һƬ�£��򻧵�����"
]),
([	"action" : "$N��һ��"MAG"����������ܡ�"NOR"����һ��"HIM"���¹ڰ���켡�"NOR"������ƽָ��һ���ǳɺ�ɨ$n��$l",
	"lvl" : 60,
	"skill_name" : "��������� �¹ڰ����"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }
int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������������\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("qi") < 30 || (int)me->query("neili") < 10 )
		return notify_fail("�������������������ʫ������\n");
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
	int d_e1 = 40;
	int d_e2 = 60;
	int p_e1 = 10;
	int p_e2 = 30;
	int f_e1 = 50;
	int f_e2 = 100;
	int m_e1 = 10;
	int m_e2 = 110;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("tangshi-jian", 1);
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
int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 20; }
int power_point(object me) { return 1.0; }

int help(object me)
{
	write(HIC"\n��ʫ������"NOR"\n");
	write(@HELP

    ����ī��÷���ϴ���������ͽ������������ɽ��½�������Դ�
ƽ�������Ὥ�ݳ����Ľ�����

	ѧϰҪ��
		����100
HELP
	);
	return 1;
}

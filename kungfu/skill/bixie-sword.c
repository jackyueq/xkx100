// bixie-sword.c
// Last Modified by sir 10.21.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$Nʹһ��"HIM"��Ⱥа���ס�"NOR"������$wȦ��ٿ�ش̳������ǵ�㣬����ֱ��$n��$l��ȥ",
	"lvl"    : 0,
	"skill_name" : "Ⱥа����"
]),
([	"action" : "$Nһ��"HIB"����ظ��Ŀ��"NOR"��������ת��Χ��$n��Χ���̣������������$n��$l",
	"lvl"    : 10,
	"skill_name" : "��ظ��Ŀ"
]),
([	"action" : "$N�趯$w��һ��"MAG"����������"NOR"Ю�������������$n��$l",
	"lvl"    : 20,
	"skill_name": "��������"
]),
([	"action" : "$N����$wһ����Х������"HIW"�����Ǹ��¡�"NOR"������˸������������裬�͵���һ��ͦ����ֱ��$n$l",
	"lvl"    : 30,
	"skill_name": "���Ǹ���"
]),
([	"action" : "$N����$w���Ⱪ����һ��"GRN"�����ഩ����"NOR"��$n$l��ȥ",
	"lvl"    : 40,
	"skill_name": "���ഩ��"
]),
([	"action" : "$N����$w����һ���⻡��ֱָ$n$l��һ��"HIG"������Ū�ѡ�"NOR"��������������ȥ",
        "lvl"    : 50,
	"skill_name": "����Ū��"
]),
});

int valid_enable(string usage) { return usage=="sword" || usage=="parry"; }

int valid_learn(object me)
{
	object ob;

	if ( (string)me->query("gender")=="Ů��" )
		return notify_fail("Ů�Ӳ���ѧ��а������\n");
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("�������������û�а취����а������\n");
	if( !(ob = me->query_temp("weapon"))
		|| (string)ob->query("skill_type") != "sword" )
		return notify_fail("���������һ�ѽ�������������\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("qi") < 30 || (int)me->query("neili") < 10 )
		return notify_fail("�����������������û�а취��ϰ��а������\n");
	me->receive_damage("qi", 30);
	me->add("neili", -10);
//	write("�㰴����ѧ����һ���а������\n");
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
	int m_e2 = 100;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("bixie-sword", 1);
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
int valid_effect(object me, object weapon, string name, int skill)
{
}

int help(object me)
{
	write(HIC"\n��а������"NOR"\n");
	write(@HELP

    ��а����ԭ�ԡ��������䡷����help bixie-jian��
    ���ױ�а�����������ϴ��µģ�������ѵ����ȱ������������
���ţ�û���Թ��������ʹ����ˡ�

	ѧϰҪ��
		Ů�Բ���ѧ
		����100
HELP
	);
	return 1;
}


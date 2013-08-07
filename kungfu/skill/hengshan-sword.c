// hengshan-sword.c ��ɽ����
// Last Modified by sir 10.22.2001
// Modified by Java Sep.1998
//�ؽ��������

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([      "skill_name" :"��ɽ����",
	"action":  "$N����$w����ָ����ͻȻ���ڿ���һ������������֮�������ű�������������һ��"HIW"����ɽ����"NOR"����$w���Ⱪ������$n��$l��ȥ",
        "lvl" : 0
]),
([      "skill_name" :"�ٱ�ǧ��",
	"action":  "$Nһ��"HIC"���ٱ�ǧ�á�"NOR"����$w������ȣ���Ȼ���Ƶ���$n����$n��æת������ֻ������������",
	"lvl" : 10
]),
([      "skill_name":    "Ȫ��ܽ��",
	"action":  "$N�����Է�������·������$wˢ��һ��"MAG"��Ȫ��ܽ�ء�"NOR"����$nС����ȥ",
	"lvl" : 20
]),
([      "skill_name":    "�����ϸ�",
	"action":  "$N�����Է�������·������$wˢ��һ��"HIM"�������ϸǡ�"NOR"����$n��ͷ��ȥ",
	"lvl" : 30
]),
([      "skill_name":    "ʯ������",
	"action":  "$N����$wٿ�ش̳������ƴ����ػأ�������ã�����һ��" HIG"��ʯ��������"NOR"����$n$l��ȥ",
	"lvl" : 40
]),
([      "skill_name":    "��������",
	"action":  "$N����$wٿ�ش̳�����������֮���£������޶�������׽��������һ��"RED"������������"NOR"��ָ��$n$l",
	"lvl" : 50
]),
([      "skill_name":    "���ף��",
	"action" : "$N����Ծ��"HIR"�����ף�ڡ�"NOR"����$w����һ�������Ӱ��������$n��$l",
	"lvl" : 60
]),
});

int valid_enable(string usage) { return usage=="sword" || usage=="parry"; }
int valid_learn(object me)
{
	object ob;
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("�������������û�а취����ɽ������\n");
	if( (string)me->query_skill_mapped("force")!= "huiyan-xinfa")
		return notify_fail("��ɽ����������ϻ����ķ���������\n");
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
	if( (int)me->query("qi") < 40 || (int)me->query("neili") < 30 )
		return notify_fail("�����������������û�а취��ϰ��ɽ������\n");
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
	int d_e1 = 5;
	int d_e2 = 30;
	int p_e1 = -20;
	int p_e2 = -5;
	int f_e1 = 100;
	int f_e2 = 150;
	int m_e1 = 110;
	int m_e2 = 200;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("hengshan-sword", 1);
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
int success() { return 10; }
int power_point(object me) { return 1.0; }

int valid_effect(object me, object weapon, string name, int skill)
{
}

string perform_action_file(string action)
{
	return __DIR__"hengshan-sword/" + action;
}
int help(object me)
{
	write(HIC"\n��ɽ������"NOR"\n");
	write(@HELP

    ��ɽ����Ϊ��ɽ�书��

	ѧϰҪ��
		�����ķ�
		����50
HELP
	);
	return 1;
}


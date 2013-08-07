// riyue-bian.c ���±޷�
// Last Modified by sir 10.20.01

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action":      "$N����������һ��"HIY"����ʯʽ��"NOR"������$w���ñ�ֱ����׼$n���ظ�Ҫ����������",
	"lvl" :        0,
	"skill_name" : "��ʯʽ",
]),
([	"action":      "$N����һת��һ��"HIB"���ϴ�ʽ��"NOR"������$w��������ڿ�һ���͵���$n��ͷ����",
	"lvl" :        60,
	"skill_name" : "�ϴ�ʽ",
]),
([	"action":      "$N������ң�һ��"HIC"������ʽ��"NOR"������$w��������Ӱ����ɽ������ɨ��$nȫ��",
	"lvl" :        90,
	"skill_name" : "����ʽ",
]),
([	"action":"$N������ң�һ��"HIW"���ֺ�ʽ��"NOR"������$w��������Ӱ����ɽ������ɨ��$nȫ��",
	"lvl" :        100,
	"skill_name" : "�ֺ�ʽ",
]),
([	"action":"$N������ң�һ��"HIG"���ѿ�ʽ��"NOR"������$w��������Ӱ����ɽ������ɨ��$nȫ��",
	"lvl" :        110,
	"skill_name" : "�ѿ�ʽ",
]),
([	"action":"$N������ң�һ��"HIY"��������ա�"NOR"������$w��������Ӱ����ɽ������ɨ��$nȫ��",
	"lvl" :        120,
	"skill_name":  "�������",
]),
([	"action":"$N������ң�һ��"HIY"����շ�ħ��"NOR"������$w��������Ӱ����ɽ������ɨ��$nȫ��",
	"lvl" :        130,
	"skill_name" : "��շ�ħ",
]),
([	"action":"$N������ң�һ��"HIM"�����ޱߡ�"NOR"������$w��������Ӱ����ɽ������ɨ��$nȫ��",
	"lvl" :        200,
	"skill_name" : "���ޱ�",
]),
});

int valid_enable(string usage) { return usage == "whip" || usage =="parry"; }
int valid_learn(object me)
{
	object weapon;

	if( (int)me->query("max_neili") < 500 )
		return notify_fail("����������㣬û�а취�����±޷�, ����Щ���������ɡ�\n");
	if ((int)me->query_skill("hunyuan-yiqi", 1) < 50)
		return notify_fail("��Ļ�Ԫһ�������̫ǳ��\n");
	if ( !objectp(weapon = me->query_temp("weapon"))
		|| ( string)weapon->query("skill_type") != "whip" )
		return notify_fail("���������һ�����Ӳ������޷���\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "whip")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("qi") < 30 || (int)me->query("neili") < 30 )
		return notify_fail("����������������±޷���\n");
	me->receive_damage("qi", 30);
	me->add("neili", -30);
	return 1;
}
string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action)-1; i >= 0; i--)
		if(level >= action[i]["lvl"])
			return action[i]["skill_name"];
}
mapping query_action(object me, object weapon)
{
	int d_e1 = -60;
	int d_e2 = -50;
	int p_e1 = -25;
	int p_e2 = -5;
	int f_e1 = 150;
	int f_e2 = 200;
	int m_e1 = 300;
	int m_e2 = 550;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("riyue-bian", 1);
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

int learn_bonus() { return 5; }
int practice_bonus() { return 5; }
int success() { return 5; }
int power_point(object me) { 
	object weapon;
	if ( objectp(weapon = me->query_temp("weapon")) 
	           && weapon->query("id")=="heisuo")
	 return 1.3;
	else 
	return 1.0; 
}

string perform_action_file(string action)
{
	if ( this_player()->query_skill("riyue-bian", 1) >= 50 )
		return __DIR__"riyue-bian/" + action;
}
int help(object me)
{
	write(HIC"\n���±޷���"NOR"\n");
	write(@HELP

    ���±޷�Ϊ���ֳ������ɵ���ɽ������

	ѧϰҪ��
		��Ԫһ����50��
		����500
HELP
	);
	return 1;
}


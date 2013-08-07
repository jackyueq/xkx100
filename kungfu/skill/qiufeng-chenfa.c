// qiufeng-chenfa.c ������
// Last Modified by sir 10.20.01

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N����������һ��"HIC"������Ҷ��"NOR"������$w����һ�ɾ��磬����$n������",
	"lvl"    : 0,
	"skill_name" : "����Ҷ",
]),
([	"action" : "$N����һ�ӣ�һ��"HIW"�����Χ����"NOR"������$wֱ����$n�����",
	"lvl"    : 20,
	"skill_name" : "���Χ��",
]),
([	"action" : "$N����һת��һ��"HIB"�����ƶϴ���"NOR"������$w��������ڿ�һ���͵���$n��ͷ����",
	"lvl"    : 40,
	"skill_name" : "���ƶϴ�",
]),
([	"action" : "$N���᳾�ң�һ��"HIG"�����绯�꡹"NOR"������$w��������Ӱ����ɽ������ɨ��$nȫ��",
	"lvl"    : 50,
	"skill_name" : "���绯��",
]),
([	"action" : "$N������ǰһԾ��һ��"HIY"��Ұ����ס�"NOR"������$w�ֻ�$n����",
	"lvl"    : 60,
	"skill_name" : "Ұ�����",
]),
([	"action" : "$N������ǰ��һ��"GRN"����Ӱɨ�ס�"NOR"������$w��������$nǰ��",
	"lvl"    : 70,
	"skill_name" : "��Ӱɨ��",
])
});

int valid_enable(string usage) { return usage == "whip" || usage == "parry"; }
int valid_learn(object me)
{
	object weapon;

	if( (int)me->query("max_neili") < 300 )
		return notify_fail("����������㣬û�а취����糾��, ����Щ���������ɡ�\n");
	if ((int)me->query_skill("force", 1) < 50)
		return notify_fail("��Ļ����ڹ����̫ǳ��\n");
        if ((int)me->query_skill("yunv-xinfa",1)<10)
                return notify_fail("�����Ů�ķ����̫ǳ��\n");
        if ( !objectp(weapon = me->query_temp("weapon"))
		|| ( string)weapon->query("skill_type") != "whip" )
		return notify_fail("���������һ������������������\n");

	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "whip")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("���������������糾����\n");
	me->receive_damage("qi", 30);
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
	int d_e1 = -45;
	int d_e2 = -35;
	int p_e1 = 5;
	int p_e2 = 15;
	int f_e1 = 50;
	int f_e2 = 100;
	int m_e1 = 150;
	int m_e2 = 250;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("qiufeng-chenfa", 1);
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

int learn_bonus() { return 15; }
int practice_bonus() { return 15; }
int success() { return 15; } 
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	if ( this_player()->query_skill("qiufeng-chenfa", 1) >= 40 )
		return __DIR__"qiufeng-chenfa/" + action;
}

int help(object me)
{
	write(HIC"\n��������"NOR"\n");
	write(@HELP

    ������Ϊ��Ĺ����Ī���������µ��书��

	ѧϰҪ��
		�����ڹ�50��
		��Ů�ľ�10��
		����300
HELP
	);
	return 1;
}


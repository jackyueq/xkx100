// yunlong-bian.c �����޷�
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action": "$N����һ�һ��"MAG"������ٵء�"NOR"������$w���ñ�ֱ����׼$n��ͷ����",
	"lvl" : 0,
	"skill_name" : "����ٵ�",
]),
([	"action": "$N����һת��һ��"BLU"�������ĺ���"NOR"������$w��������ڿ�һ���͵ػ���$n̫��Ѩ",
	"lvl" : 10,
	"skill_name" : "�����ĺ�",
]),
([	"action": "$N৵�һ�����ޣ�һ��"HIM"��������ˮ��"NOR"������$w���ñ�ֱ������$n˫��",
	"lvl" : 20,
	"skill_name" : "������ˮ",
]),
([	"action": "$N������ң�һ��"HIC"�����Ƽ��ա�"NOR"������$w��������Ӱ����ɽ������ɨ��$nȫ��",
	"lvl" : 30,
	"skill_name" : "���Ƽ���",
]),
([	"action": "$N��������һ��"HIY"����ɽ��ʯ��"NOR"������$w��һ��ͭ����ֱ����$n",
	"lvl" : 40,
	"skill_name" : "��ɽ��ʯ",
]),
([	"action": "$N����һ�ӣ�һ��"HIW"�����Χ����"NOR"������$wֱ����$n����",
	"lvl" : 50,
	"skill_name" : "���Χ��",
]),
([	"action": "$N�߸�Ծ��һ��"HIB"����Į���̡�"NOR"������$w��ֱ��$n��ͷ����",
	"lvl" : 60,
	"skill_name" : "��Į����",
])
});

int valid_enable(string usage) { return usage == "whip" || usage == "parry"; }
int valid_learn(object me)
{
	object weapon;

	if( (int)me->query("max_neili") < 200 )
		return notify_fail("����������㣬û�а취�������޷�, ����Щ���������ɡ�\n");

	if ((int)me->query_skill("yunlong-shengong", 1) < 40)
		return notify_fail("��������񹦻��̫ǳ��\n");

	if ( !objectp(weapon = me->query_temp("weapon")) ||
		( string)weapon->query("skill_type") != "whip" )
		return notify_fail("���������һ�����Ӳ������޷���\n");

	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "whip")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query_skill("yunlong-shengong", 1) < 40)
		return notify_fail("��������񹦻��̫ǳ��\n");
	if( (int)me->query("qi") < 30 || (int)me->query("neili") < 30 )
		return notify_fail("������������������޷���\n");
	me->receive_damage("qi", 25);
	me->add("neili", -25);
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
	int d_e1 = -50;
	int d_e2 = -40;
	int p_e1 = -5;
	int p_e2 = 10;
	int f_e1 = 100;
	int f_e2 = 150;
	int m_e1 = 300;
	int m_e2 = 450;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("yunlong-bian", 1);
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
int success() { return 10; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"yunlong-bian/" + action;
}
int help(object me)
{
	write(HIC"\n�����޷���"NOR"\n");
	write(@HELP

    �����޷�Ϊ��ػ��������书��

	ѧϰҪ��
		������40��
		����200
HELP
	);
	return 1;
}


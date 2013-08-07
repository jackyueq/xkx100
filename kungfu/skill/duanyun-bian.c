// duanyun-bian.c ���Ʊ޷�
// Last Modified by sir 10.20.01

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N�й��о࣬һ��"HIR"���ۻ�"NOR"������$w���������һ��޼����$n��$l",
	"lvl" :	0,
	"skill_name" : "�ۻ�",	
]),
([	"action" : "$N��ǰ����һ�������ֻػ�������$wʹ��һʽ"HIW"����⡹"NOR"��б��ɨ��$n��$l",	
	"lvl" :	15,
	"skill_name" : "���",
]),
([	"action" : "$N����һ�죬�޽����֣���������һ�ƣ�$w�漴���ϻӳ���ʹ��"HIG"�����꡹"NOR"����$n��$l",	
	"lvl" :	30,
	"skill_name" : "����",
]),
([	"action" : "$N����һչ������$wʹ��һʽ"HIC"�����ס�"NOR"�����϶��¼���$n��$l",	
	"lvl" :	45,
	"skill_name" : "����",
]),
([	"action" : "$Nһ��"HIM"���Ƶ硹"NOR"��$w�����϶����»���һ���󻡣�ƽƽ����$n��$l��ȥ",
	"lvl" :	60,
	"skill_name" : "�Ƶ�",
]),
([	"action" : "$N���������һš��һ��"HIM"�����硹"NOR"������$w���ֶ�������$n��$l��ȥ",
	"lvl" :	75,
	"skill_name" : "����",
]),
([	"action" : "$N������ϥ������$wбָ��һ��"HIC"��ֹ�硹"NOR"����$n��$l",
	"lvl" :	90,
	"skill_name" : "ֹ��",
]),
([	"action" : "$N�͵ļ��٣�$wʱ��ʱ������$n׼����ʱ��$wһ��"HIW"�����ơ�"NOR"����ɨ$n��$l",
	"lvl" :	105,
	"skill_name" : "����",
]),
([	"action" : "$N����Ծ��һ��"HIB"�����¡�"NOR"��$w�ڰ���л�ΪһȦ��â������$n��$l",
	"lvl" :	110,
	"skill_name" : "����",
]),
([	"action" : "$Nʹ��"HIY"�����ա�"NOR"��$w����������ԲȦ����Եֱ������ע���������಻�ϻ���$n��$l",
	"lvl" :	120,
	"skill_name" : "����",
])
});

int valid_enable(string usage) { return (usage=="whip") || (usage=="parry"); }

int valid_learn(object me)
{
	object weapon;

	if( (int)me->query("max_neili") < 200 )
		return notify_fail("����������㣬û�а취�����Ʊ޷���\n");

	if ((int)me->query_skill("xiantian-qigong", 1) < 40)
		return notify_fail("��������������̫ǳ��\n");

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
	if( (int)me->query("qi") < 30 || (int)me->query("neili") < 30 )
		return notify_fail("����������������Ʊ޷���\n");
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
	int d_e1 = -55;
	int d_e2 = -45;
	int p_e1 = -20;
	int p_e2 = 0;
	int f_e1 = 150;
	int f_e2 = 200;
	int m_e1 = 350;
	int m_e2 = 500;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("duanyun-bian", 1);
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
int practice_bonus() { return 15; }
int success() { return 10; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"duanyun-bian/" + action;
}
int help(object me)
{
	write(HIC"\n���Ʊ޷���"NOR"\n");
	write(@HELP

    ���Ʊ޷�Ϊȫ���ƽ����ڵĶ����书��

	ѧϰҪ��
		��������40��
		����200
HELP
	);
	return 1;
}

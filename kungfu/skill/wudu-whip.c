// wudu-whip.c �嶾�޷�

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action":  "$N�ᶶ����һ��"HIG"��������о��"NOR"������$w���ñ�ֱ��ֱ��$n��ȥ",
	"lvl"   :  0,
	"skill_name" : "������о",
]),
([	"action":  "$N����һת��һ��"RED"����Ы��β��"NOR"��$w�ڿ���ת�˸�Ȧ���Թ���ĽǶ�����$n",
	"lvl"   :  10,
	"skill_name" : "��Ы��β",
]),
([	"action":  "$Nһ�����ޣ�һ��"BLK"��������˿��"NOR"������$w����������Ӱ������$n",
	"lvl"   :  20,
	"skill_name" : "������˿",
]),
([	"action":  "$N������ң�һ��"YEL"����ܳ�����"NOR"������$w������ң�ֱ����$n�ؿ�",
	"lvl"   :  30,
	"skill_name" : "��ܳ���",
]),
([	"action":  "$N��������һ��"BLU"����򼷭��"NOR"������$wת��������ȦȦ������һ�����磬ֱ��$n��ȥ",
	"lvl"   :  40,
	"skill_name" : "��򼷭��",
])
});

int valid_enable(string usage) { return usage == "whip" || usage == "parry"; }
int valid_learn(object me)
{
	object weapon;

	if( (int)me->query_skill("wudu-shengong", 1) < 30 )
		return notify_fail("����嶾��̫�ͣ��������嶾�ޡ�\n");
	if( (int)me->query("max_neili") < 30 )
		return notify_fail("���������Ϊ̫�ͣ��������嶾�ޡ�\n");
	if ( !objectp(weapon = me->query_temp("weapon")) ||
		( string)weapon->query("skill_type") != "whip" )
		return notify_fail("���������һ�����Ӳ������޷���\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "whip")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("qi") < 30 || (int)me->query("neili") < 30 )
		return notify_fail("��������������嶾�޷���\n");
	me->receive_damage("qi", 20);
	me->add("neili", -20);
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
	int d_e2 = -40;
	int p_e1 = 0;
	int p_e2 = 15;
	int f_e1 = 100;
	int f_e2 = 150;
	int m_e1 = 200;
	int m_e2 = 350;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("wudu-whip", 1);
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
	return __DIR__"wudu-whip/" + action;
}
int help(object me)
{
	write(HIC"\n�嶾�޷���"NOR"\n");
	write(@HELP

    �嶾�޷�Ϊ�嶾�̵Ķ��ű޷���

	ѧϰҪ��
		�嶾��30��
		����30
HELP
	);
	return 1;
}


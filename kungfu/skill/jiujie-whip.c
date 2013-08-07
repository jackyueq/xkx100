// jiujie-whip �Žڱ޷�
// Last Modified by sir 10.20.01

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action": "$Nʹһ��"HIB"������������"NOR"������$w����һ��͵Ķ�׼$n��$l��ɨ��ȥ",
	"lvl" : 0,
	"skill_name" : "��������",
]),
([	"action": "$N����˫�ۣ�һ��"BLU"������쪡�"NOR"$w�ó������Ӱ������ʵʵ��Ϯ��$n��$l",
	"lvl" : 20,
	"skill_name" : "�����",
]),
([	"action": "$N���Ų�æ��ȥ$w��һ��"MAG"�������ڿա�"NOR"����ӰƮ�������ص���$n��$l",
	"lvl" : 60,
	"skill_name" : "�����ڿ�",
]),
([	"action": "$N����$w�ڿ�������������һ��"MAG"����������"NOR"��Ȼ�ݺ���$n��$l��ȥ��",
	"lvl" : 90,
	"skill_name" : "��������",
]),
([	"action": "$N������$w����һ����һ��"HIG"�������ơ�"NOR"����������$n������ȥ",
	"lvl" : 120,
	"skill_name" : "������",
]),
});

int valid_enable(string usage) { return (usage=="whip") || (usage=="parry"); }
int valid_learn(object me)
{
	object weapon;

	if( (int)me->query("max_neili") < 100 )
		return notify_fail("���������Ϊ���㣬û�а취���Žڱ޷���\n");
	if ((int)me->query_skill("zhanzhuang-gong", 1) < 20)
		return notify_fail("���վ׮�����̫ǳ��\n");
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
	if ((int)me->query_skill("yijinjing", 1) < 10)
		return notify_fail("����׽���̫ǳ��\n");
	if ((int)me->query("qi") < 30)
		return notify_fail("��������������Žڱ޷���\n");
	me->receive_damage("qi",25);
 
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
	int d_e1 = -40;
	int d_e2 = -30;
	int p_e1 = 10;
	int p_e2 = 20;
	int f_e1 = 50;
	int f_e2 = 100;
	int m_e1 = 50;
	int m_e2 = 150;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("jiujie-whip", 1);
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
		"damage_type" : random(2) ? "����": "����",
	]);
}
int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 20; }
int power_point(object me) { return 1.0; }

int help(object me)
{
	write(HIC"\n�Žڱޣ�"NOR"\n");
	write(@HELP

    �Žڱ������������ű޷���

	ѧϰҪ��
		վ׮��50��
		������Ϊ100
HELP
	);
	return 1;
}


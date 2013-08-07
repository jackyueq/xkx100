// ��������Դ��书����
// qingyun
// ����
// ��ң�ɵ���������
// 14125858
// ����
// blade
// ��˼���ε�
#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }
string owner() {return "qingyun";}

mapping *action = ({
// ZHAOSHI :0
([
	"action" : "[1;36m$N����ִ$w[1;36m��������ˮ��ʹ��[1;33m���������Ρ�[1;36m�����⵭����
��Զɽ����ü��Ϧ�յ���ϡ����������$n�����$n�䲻�����ܵ����ҵĹ���[2;37;0m",
	"lvl" : 0,
	"skill_name" : "��������",
]),
// ZHAOSHI :1
([
	"action" : "�ڶ��е�����[2;37;0m",
	"lvl" : 20,
	"skill_name" : "�ڶ���",
]),
});
// ZHAOSHI :2
int valid_learn(object me)
{
	object weapon;
	string creater;

	if( (int)me->query("max_neili") < 50 )
		return notify_fail("�������������û�а취��"+"��˼���ε�"+"��\n");
	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "blade")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	creater = this_object()->owner();
	if (userp(me) &&
	me->query("id")!=creater && 
	me->query("couple/couple_id")!=creater)
	return notify_fail("�������������ѧϰ�Դ����书��\n");
	return 1;
}
int valid_enable(string usage)
{
	return usage=="blade" || usage=="parry";
}
int practice_skill(object me)
{
	object weapon; 
	string skname=explode(__FILE__,"/")[<1][0..<3];
	int lvl = me->query_skill(skname,1);
	int i=sizeof(action);
	int qicost;
	int nlcost;
	
	qicost = (272 + 272)/10;
	nlcost = (153 + 153)/15;
	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "blade")
		return notify_fail("��ʹ�õ��������ԡ�\n");	
	if( (int)me->query("qi") < qicost )
		return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
	if( (int)me->query("neili") < nlcost )
		return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
	me->receive_damage("qi", qicost);
	me->add("neili", -nlcost);
	if (lvl>=action[i-1]["lvl"]+20)
		return notify_fail("��һ�����Ѿ��������ˣ������������µ���ʽ�ˡ�\n");
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
	int d_e1 = 20;
	int d_e2 = 20;
	int p_e1 = 42;
	int p_e2 = 42;
	int f_e1 = 153;
	int f_e2 = 153;
	int m_e1 = 272;
	int m_e2 = 272;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("dream-blade", 1);
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

string perform_action_file(string action)
{
	return __DIR__+"dream-blade"+"/" + action;
}
int help(object me)
{
	write(HIC"\n"+"��˼���ε�"+"��"NOR"\n");
	write(@HELP

	��ˮ¥���������֮һ��������齣ʹ�á�
ÿһ�����֮ʱ���������޵���Թ֮��������˷���ʤ����
HELP
	);
	return 1;
}
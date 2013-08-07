// shigu-bifa.c ʯ�Ĵ�Ѩ�ʷ�
// Last Modified by sir 10.22.2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action": "$Nһ��"HIG"��ָ�㽭ɽ��"NOR"������$w������$n������Ѩ!",
	"lvl" : 0,
	"skill_name" : "ָ�㽭ɽ"
]),
([	"action": "$N��������һ��"HIB"������������"NOR"��$w���������£���$n�׺�Ѩ��ȥ!",
	"lvl" : 9,
	"skill_name": "��������"
]),
([	"action": "$N��ǰ����һ�����������ս�⣬����$wʹ��"CYN"����ƿէ�ơ�"NOR"������$n�ĵز�Ѩ!",
	"lvl" : 19,
	"skill_name" : "��ƿէ��"
]),
([	"action": "$N���е�$w������ҵ�һ�Σ�ʹ��"BLU"������ͻ����"NOR"���ź����������$n������Ѩ!",
	"lvl" : 29,
	"skill_name": "����ͻ��"
]),
([	"action": "$N����Ծ��һʽ"MAG"����ҫ������"NOR"�����������Ӱ��$w��$n�����ȥ",
	"lvl" : 39,
	"skill_name": "��ҫ����"
]),
([	"action": "$N�������У�$w�Ƴ�����ѩ���ʷ棬�ӳ�"GRN"����̨�۾���"NOR"��һ�ʿ���һ�ʵع���$n",
	"lvl" : 59,
	"skill_name": "��̨�۾�"
]),
([	"action": "$Nʹ��һ��"HIW"��ң�����项"NOR"ͦ���й�ֱ�����ʼ��������;��Ȼת�����ϱ���޷�",
	"lvl" : 79,
	"skill_name": "ң������"
]),
([	"action": "$N����б��һ�ʣ�һ��"HIC"��������ɷ��"NOR"����ź����ʷ磬��$n��Χ����",
	"lvl" : 99,
	"skill_name": "������ɷ"
]),
});

int valid_enable(string usage) { return usage == "dagger" || usage == "parry";}
int valid_learn(object me)
{
	if( (int)me->query("max_neili") < 100 )
		return notify_fail("�������������û�а취��ʯ�Ĵ�Ѩ��\n");
	if( (string)me->query_skill_mapped("force")!= "kuihua-xinfa")
		return notify_fail("ʯ�Ĵ�Ѩ�ʷ�����Ͽ����ķ���\n");
	if( (int)me->query_skill("kuihua-xinfa",1) < 20 )
		return notify_fail("��Ŀ����ķ���򲻹���������ѧϰʯ�Ĵ�Ѩ�ʷ�!\n");
	return 1;
}
int practice_skill(object me)
{
	object ob;
	if( !(ob = me->query_temp("weapon")) ||
		(string)ob->query("skill_type") != "dagger" )
		return notify_fail("���������һ���йٱʲ���ѧϰʯ�Ĵ�Ѩ�ʷ���\n");
	if( (int)me->query("qi") < 30 || (int)me->query("neili") < 30 )
		return notify_fail("�����������������û�а취��ϰʯ�Ĵ�Ѩ�ʷ���\n");
	me->receive_damage("qi", 20);
	me->add("neili", -20);
//	write("�㰴����ѧ����һ��ʯ�Ĵ�Ѩ�ʷ���\n");
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
	int d_e1 = 0;
	int d_e2 = 20;
	int p_e1 = -40;
	int p_e2 = -30;
	int f_e1 = 250;
	int f_e2 = 300;
	int m_e1 = 400;
	int m_e2 = 600;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("shigu-bifa", 1);
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
		"damage_type" : "����",
	]);
}
int learn_bonus() { return 10; }
int practice_bonus() { return 10; }
int success() { return 10; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__ "shigu-bifa/" + action;
}

int help(object me)
{
	write(HIC"\nʯ�Ĵ�Ѩ�ʷ���"NOR"\n");
	write(@HELP

    ������̺�ľ���书��÷ׯ��ׯ��ͺ���̿��ұ��죬���йٱ�
��д�����ұ�����������������������������

	ѧϰҪ��
		�����ķ�20��
		����100
HELP
	);
	return 1;
}


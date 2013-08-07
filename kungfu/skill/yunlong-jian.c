// yunlong-jian.c ������
// Last Modified by sir 10.22.2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action":"\n$Nʹһʽ"GRN"������˳��Ȼ��"NOR"������$w����΢�񣬻ó�һ���׹����$n��$l",
	"lvl" : 0,
	"skill_name" : "����˳��Ȼ"
]),
([	"action":"\n$N����ǰ��ʹ��"HIC"����ȥ�����С�"NOR"�������������ޣ�$w��������$n��$l��ȥ",
	"lvl" : 8,
	"skill_name" : "��ȥ������"
]),
([	"action":"\n$Nһʽ"HIB"��־�����Զ��"NOR"������Ʈ�����ߣ��˷�����������$wңҡָ��$n��$l",
	"lvl" : 15,
	"skill_name" : "־�����Զ"
]),
([	"action":"$N��������Ծ��һʽ"HIW"�������γ���"NOR"��������ˮ��һкǧ�����$nȫ��",
	"lvl" : 20,
	"skill_name" : "�����γ�"
]),
([	"action":"$N����$w�й�ֱ����һʽ"BLU"�����Ǳ��ҹ��"NOR"��������Ϣ�ض�׼$n��$l�̳�һ��",
	"lvl" : 30,
	"skill_name" : "���Ǳ��ҹ"
]),
([	"action":"$N����$wһ����һʽ"HIG"������ϸ������"NOR"��������Ϣ�ػ���$n��$l",
	"lvl" : 40,
	"skill_name" : "����ϸ����"
]),
([	"action":"\n$N����$wбָ���죬��â���£�һʽ"HIY"��������������"NOR"����׼$n��$lбб����",
	"lvl" : 50,
	"skill_name" : "����������"
]),
([	"action":"$N��ָ�����㣬����$w�Ƴ�����ѩ����â��һʽ"RED"������һ��졹"NOR"����$n���ʺ�",
	"lvl" : 60,
	"skill_name" : "����һ���"
]),
([	"action":"$N���Ƶ�����һʽ"MAG"�����Ļ�������"NOR"��$w�Ի���Ծ�����缲�������$n���ؿ�",
	"lvl" : 70,
	"skill_name" : "���Ļ�����"
]),
([	"action":"\n$N����һ���εض���һʽ"HIY"��������ͬ�ԡ�"NOR"��$w�ó������Ӱ����$n����Χס",
	"lvl" : 80,
	"skill_name" : "������ͬ��"
]),
([	"action":"$N�������Ʈ�䣬һʽ"GRN"�����֪���⡹"NOR"������$wƽָ����������$n����",
	"lvl" : 90,
	"skill_name" : "���֪����"
]),
([	"action" : "$N����΢����������һ��"HIW"���ߴ���ʤ����"NOR"���йǽ�����쫷�����$nȫ��",
	"lvl" : 100,
	"skill_name" : "�ߴ���ʤ��"
]),
([	"action" : "$Nļ��ʹһ��"HIR"����Ҷ����ɽ��"NOR"����ʱ�����м���Ѫ������$nȫ��",
	"lvl" : 110,
	"skill_name" : "��Ҷ����ɽ"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }
int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 200)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("yunlong-shengong", 1) < 20)
		return notify_fail("��������񹦻��̫ǳ��\n");
	if ((int)me->query_skill("yunlong-xinfa", 1) < 20)
		return notify_fail("��������ķ����̫ǳ��\n");
	if ((int)me->query_skill("force", 1) < 40)
		return notify_fail("��Ļ����ڹ����̫ǳ��\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query_skill("yunlong-shengong", 1) < 20)
		return notify_fail("��������񹦻��̫ǳ��\n");
	if( (int)me->query("qi") < 55 || (int)me->query("neili") < 40 )
		return notify_fail("���������������������������\n");
	me->receive_damage("qi", 50);
	me->add("neili", -35);
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
	int d_e1 = -15;
	int d_e2 = 5;
	int p_e1 = -45;
	int p_e2 = -25;
	int f_e1 = 150;
	int f_e2 = 200;
	int m_e1 = 180;
	int m_e2 = 270;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("yunlong-jian", 1);
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
	if ((int)me->query_skill("yunlong-xinfa",1) < 100)
	return 0.7; 
	else if ((int)me->query_skill("yunlong-xinfa",1) > 200)
	return 1.4;
	else return ( ((int)me->query_skill("yunlong-xinfa",1)-100)/100*0.7+0.7 );
}
string perform_action_file(string action)
{
	return __DIR__"yunlong-jian/" + action;
}
int help(object me)
{
	write(HIC"\n����������"NOR"\n");
	write(@HELP

    ��ػῴ�ұ��죬�����⹥����������󣬿�������һ����

	ѧϰҪ��
		�����ڹ�40��
		������20��
		�����ķ�20��
		����200
HELP
	);
	return 1;
}


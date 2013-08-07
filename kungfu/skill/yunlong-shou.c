// yunlongshou.c -������
// Last Modified by sir 10.22.2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$Nһʽ"GRN"����ľ�Ա���"NOR"��ʮָ����������ʵʵ��Ϯ��$n��ȫ��ҪѨ",
	"lvl" : 0,
	"skill_name" : "��ľ�Ա�"
]),
([	"action" : "�ں��������У�$Nʹһ��"BLU"������׽Ӱ��"NOR"��˫���繳��ꫣ�����$n��$l",
	"lvl"   : 20,
	"skill_name" : "����׽Ӱ" 
]),
([	"action" : "$N˫ȭ���裬һʽ"CYN"������ȥ����"NOR"�����ֻ��ۣ�£��Ȧ״���ͻ�$n�����",
	"lvl" : 30,
	"skill_name" : "����ȥ��"
]),
([	"action" : "$N˫��ƽ�죬ʮָ΢΢���¶�����һ��"YEL"��ʮָǬ����"NOR"����$n��$l",
	"lvl"   : 40,
	"skill_name" : "ʮָǬ��" 
]),
([	"action" : "$N���ֻ��أ�Ҹ�º��գ�������ָ�繳��һ��"MAG"��������ȱ��"NOR"����$n�Ķ���",
	"lvl"   : 50,
	"skill_name" : "������ȱ" 
]),
([	"action" : "$N����б��$n����֮�䣬һ��"RED"���������项"NOR"������ȡĿ�����ַ���$n���ɲ�",
	"lvl"   : 60,
	"skill_name" : "��������" 
]),
([	"action" : "$Nһ����ָ$n�Ľ�����һ��"HIC"���������С�"NOR"������ץ��$n���еı���",
	"lvl"   : 70,
	"skill_name" : "��������" 
]),
([	"action" : "$N����ָ��$n��ǰ�������Ѩ������бָ̫��Ѩ��һ��"HIY"������������"NOR"ʹ$n��������",
	"lvl"   : 80,
	"skill_name" : "��������" 
]),
([	"action" : "$Nһ�ֶ����צ��һ��ָ�أ�һ��"HIR"�����Ƽ��ա�"NOR",��������$n��ȫ��",
	"lvl"   : 90,
	"skill_name" : "���Ƽ���" 
]),
([	"action" : "$Nһʽ"HIM"���������¡�"NOR"��ȭ���������֣��������ޣ�����������$n�ĵ���",
	"lvl" : 100,
	"skill_name" : "��������"
]),
([	"action" : "$N���������ʹһʽ"HIR"���������ɡ�"NOR"������΢��,��������$n��$l",
	"lvl" : 80,
	"skills_name" : "��������"
]),
});

int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }
int valid_combine(string combo) { return combo=="yunlong-zhua"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�������ֱ�����֡�\n");
	if ((int)me->query_skill("yunlong-shengong", 1) < 50)
		return notify_fail("��������񹦻�򲻹����޷�ѧ�����֡�\n");
	if ((int)me->query_skill("force", 1) < 50)
		return notify_fail("��Ļ����ڹ���򲻹����޷�ѧ�����֡�\n");
	if ((int)me->query("max_neili") < 250)
		return notify_fail("�������̫�����޷��������֡�\n");
	if ((int)me->query_skill("hand",1) <30)
		return notify_fail("��Ļ����ַ���򲻹����޷�ѧ�����֡�\n");
	if ((int)me->query_skill("yunlong-xinfa")<100 && 2*(int)me->query_skill("yunlong-xinfa",1) <(int)me->query_skill("yunlong-shou",1))
		return notify_fail("��������ķ���򲻹����޷�����ѧ�����֡�\n");
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��ı�����ֲ�����ϰ��\n");
	if ((int)me->query("qi") < 40)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 40)
		return notify_fail("������������������֡�\n");
	me->receive_damage("qi", 35);
	me->add("neili", -25);
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
	int d_e1 = -45;
	int d_e2 = -15;
	int p_e1 = 15;
	int p_e2 = 45;
	int f_e1 = 140;
	int f_e2 = 240;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("yunlong-shou", 1);
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
		"damage_type" : random(2) ? "����" : "����",
	]);
}
int learn_bonus() { return 20; }
int practice_bonus() { return 20; }
int success() { return 15; }
int power_point(object me) { 
	if ((int)me->query_skill("yunlong-xinfa",1) < 100)
	return 0.7; 
	else if ((int)me->query_skill("yunlong-xinfa",1) > 200)
	return 1.4;
	else return ( ((int)me->query_skill("yunlong-xinfa",1)-100)/100*0.7+0.7 );
}

string perform_action_file(string action)
{
	return __DIR__"yunlong-shou/" + action;
}
int help(object me)
{
	write(HIC"\n�����֣�"NOR"\n");
	write(@HELP

    ��ػ��������书��
    ��������צ������

	ѧϰҪ��
		�����ַ�30��
		�����ڹ�50��
		������50��
		����250
		��Ӧ�������ķ�
HELP
	);
	return 1;
}


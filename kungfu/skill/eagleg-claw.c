// Last Modified by Winder on May. 29 2001
// eagleg-claw.c ӥצ�� ����ָ����

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$Nȫ��εض��𣬰����һ�����һʽ"HIB"����ӥϮ�á�"NOR"��Ѹ�͵�ץ��$n��$l",
	"lvl"   : 0,
	"skills_name" : "��ӥϮ��",
]),
([	"action" : "$N����ֱ����˫��ƽ�죬ȫ��һת��һʽ"HIY"����ӥչ�᡹"NOR"��˫צһǰһ��£��$n��$l",
	"lvl"   : 10,
	"skills_name" : "��ӥչ��",
]),
([	"action" : "$Nһʽ"HIM"���γ��ɡ�"NOR"��ȫ����б��ƽ�ɣ�����һ����˫צ���䣬����$n��$l",
	"lvl"   : 20,
	"skills_name" : "�γ���",
]),
([	"action" : "$N˫צ�����Ͼ٣�ʹһʽ"HIC"��ӭ������"NOR"��һ������ն��𣬷ֱ�Ϯ��$n���ҿ���",
	"lvl"   : 30,
	"skills_name" : "ӭ������",
]),
([	"action" : "$Nȫ�������ǰ��һʽ"HIM"��������צ��"NOR"��צӰ����צ�͵�ͻ�������Ȱ�ץ��$n���ؿ�",
	"lvl"   : 40,
	"skills_name" : "������צ",
]),
([	"action" : "$N���ػ��У�һʽ"HIW"������հ�ա�"NOR"��˫ץһ��������Ϯ�����д�Ѩ�����ַ�ץ$n��$l",
	"lvl"   : 50,
	"skills_name" : "����հ��",
]),
([	"action" : "$N��������צ���棬Ծ��һʽ"CYN"���������ա�"NOR"������������ֱָ���ƿն�����Ѹ���ޱȵػ���$n",
	"lvl"   : 55,
	"skills_name" : "��������",
]),
([	"action" : "$N�ڿո߷����ɣ�һʽ"RED"��ӥ�����"NOR"����Хһ����������лû���һ������צӰ����������$n",
	"lvl"   : 60,
	"skills_name" : "ӥ������",
])
});

int valid_enable(string usage) { return usage=="claw" || usage=="parry"; }
int valid_combine(string combo){ return combo=="nianhua-finger"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��ӥצ��������֡�\n");
	if ((int)me->query_skill("zhanzhuang-gong", 1) < 60)
		return notify_fail("����׽�ڹ���򲻹����޷�ѧӥצ����\n");
	if ((int)me->query("max_neili") < 600)
		return notify_fail("�������̫�����޷���ӥצ����\n");
	if ((me->query_skill("jimie-claw", 1) < 50) ||
		(me->query_skill("jingang-strike", 1) < 50))
		return notify_fail("��Ĵ������ƺͼ���צ��򲻹����޷�ѧӥצ����\n");
	return 1;
}
int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("�������������ӥצ����\n");
	me->receive_damage("qi", 30);
	me->add("neili", -10);
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
	int d_e1 = 50;
	int d_e2 = 20;
	int p_e1 = -10;
	int p_e2 = -30;
	int f_e1 = 200;
	int f_e2 = 350;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int)me->query_skill("eagleg-claw", 1);
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
		"damage_type" : random(2) ? "����" : "ץ��",
	]);
}
int learn_bonus() { return 20; }
int practice_bonus() { return 15; }
int success() { return 15; }
int power_point(object me) { return 1; }

string perform_action_file(string action)
{
	 return __DIR__"eagleg-claw/" + action;
}

int help(object me)
{
	write(HIC"\nӥצ����"NOR"\n");
	write(@HELP

    ӥצ����������צ�������黨ָ������

	ѧϰҪ��
		վ׮��60��
		��������50��
		����צ50��
		������Ϊ600
HELP
	);
	return 1;
}


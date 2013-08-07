// shenlong-bashi ������ʽ
// Last Modified by sir 10.22.2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$Nʹһ��"GRN"����Ӱ��б��"NOR"����������һĨ����$n��$l��ȥ",
	"lvl"    : 0,
	"skill_name" : "��Ӱ��б"
]),
([	"action" : "$N������ȣ�˫��ʹһ��"HIY"���嶡��ɽ��"NOR"������$n��$l",
	"lvl"    : 10,
	"skill_name" : "�嶡��ɽ"
]),
([	"action" : "$N˳��ʹһ��"GRN"�����в��ȡ�"NOR"���Ƽ�ת�����ƻ��棬����ֱ��$n",
	"lvl"    : 20,
	"skill_name" : "���в���"
]),
([	"action" : "$N�˺󼸲���ͻȻ����һ�ƣ�һ��"RED"��������β��"NOR"���ޱȹ���ػ���$n",
	"lvl"    : 30,
	"skill_name" : "������β"
]),
([	"action" : "$Nʹһʽ"CYN"�������ơ�"NOR"��ȫ�������ת��˫��һǰһ���͵�����$n���ؿ�",
	"lvl"    : 40,
	"skill_name" : "������"
]),
([	"action" : "$N����ʹ��"HIW"��Ǭ��������"NOR"������֧�أ�˫�ȷ�������$n",
	"lvl"    : 50,
	"skill_name" : "Ǭ������"
]),
([	"action" : "$N���һ����ʹ��"BLU"��ͬ���ھ���"NOR"������һ�а�����$n",
	"lvl"    : 60,
	"skill_name" : "ͬ���ھ�"
]),
([	"action" : "$N����һ������ʹ��"HIW"�����Ǹ��¡�"NOR"�����ǳ���״����Ȼ���Ǹ��°�ֱײ��$n",
	"lvl"    : 70,
	"skill_name" : "���Ǹ���"
]),
});

int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }
int valid_combine(string combo) { return combo=="yingxiong-sanzhao"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��������ʽ������֡�\n");
	if ((int)me->query_skill("dulong-dafa", 1) < 25)
		return notify_fail("��Ķ����󷨻�򲻹����޷�ѧ������ʽ.\n");
	if ((int)me->query_skill("force", 1) < 25)
		return notify_fail("��Ļ����ڹ���򲻹����޷�ѧ������ʽ��\n");
	if ((int)me->query("max_neili") < 150)
		return notify_fail("�������̫�����޷���������ʽ��\n");
	if (2*(int)me->query_skill("dulong-dafa",1) <(int)me->query_skill("shenlong-bashi",1))
		return notify_fail("��Ķ����󷨻�򲻹����޷�����ѧ������ʽ��\n");
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��ı�����ֲ�����ϰ��\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 50)
		return notify_fail("�������������������ʽ��\n");
	me->receive_damage("qi", 40);
	me->add("neili", -30);
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
	int d_e1 = -55;
	int d_e2 = -25;
	int p_e1 = 5;
	int p_e2 = 35;
	int f_e1 = 200;
	int f_e2 = 300;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("shenlong-bashi", 1);
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
int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 5; }
int power_point(object me) { return 1.0; }

int help(object me)
{
	write(HIC"\n������ʽ��"NOR"\n");
	write(@HELP

    ������ʽΪ�������书������Ӣ�����л�����

	ѧϰҪ��
		�����ڹ�25��
		������25��
		����150
HELP
	);
	return 1;
}


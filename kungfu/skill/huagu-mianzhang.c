// huagu-mianzhang ��������
// Last Modified by sir 10.22.2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N����΢�Σ�һ��"HIB"����������ǡ�"NOR"��ʮָ��ꪣ�����$n��˫������",
	"lvl"   : 0,
	"skill_name" : "���������" 
]),
([	"action" : "$N������磬ʮָ΢΢������һ��"HIB"�������Ѻ��ѡ�"NOR"ץ��$n��ǰ��",
	"lvl"   : 20,
	"skill_name" : "�����Ѻ���" 
]),
([	"action" : "$N˫�ֺ������֣�һ��"HIB"�����紵�䳾��"NOR"�����Ȱ��ץ��$n�ļ�ͷ",
	"lvl"   : 40,
	"skill_name" : "���紵�䳾" 
]),
([	"action" : "$N���ֵ��ػ��������ּ�����һ��"HIB"������ӳ��ɳ��"NOR"���͵�ץ��$n�Ķ�
ͷ",
	"lvl"   : 60,
	"skill_name" : "����ӳ��ɳ" 
]),
([	"action" : "$Nʹһ��"HIB"��ɭȻ���ķ���"NOR"����������ľ��磬ײ��$n",
	"lvl"   : 80,
	"skill_name" : "ɭȻ���ķ�" 
]),
([	"action" : "$N���ޱ��飬˫�ۺ�����ҵؼ��ӣ�ʹ��"HIB"�������ֹǺ���"NOR"��ʮָ\n���������Ѹ���ޱȵ�Ϯ��$nȫ�������Ѩ",
	"lvl"   : 100,
	"skill_name" : "�����ֹǺ�" 
]),
([	"action" : "$Nʹ��"HIB"����ɳƮ���꡹"NOR"����Ȼ������ϣ�����$n��ת��Ȧ��$n���ۻ����Ҽ䣬\n$N����Ȼͣ��$n������ֻ���һ����Ȧ���������ֳ����Ȧ��ץ$n�ĺ�",
	"lvl"   : 120,
	"skill_name" : "��ɳƮ����" 
]),
([	"action" : "$NͻȻ˫��ƽ�٣�$nһ�������ڲ²�䣬���$Nವ�һ�½�˫��\n�ջ���ǰ������һ��"HIB"���׹����޺���"NOR"����ָ�繳��ֱץ��$n������",
	"lvl"   : 140,
	"skill_name" : "�׹����޺�" 
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }
int valid_combine(string combo) { return combo=="jueming-leg"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("���������Ʊ�����֡�\n");
	if (2*(int)me->query_skill("dulong-dafa",1) <
		(int)me->query_skill("huagu-mianzhang",1))
		return notify_fail("��Ķ����󷨻�򲻹����޷�����ѧ�������ơ�\n");
	if ((int)me->query_skill("force", 1) < 50)
		return notify_fail("����ڹ��ķ���򲻹������������ƻ��߻���ħ��\n");
	if ((int)me->query("max_neili") < 300)
		return notify_fail("�������̫�����޷����������ơ�\n");
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��ı�����ֲ�����ϰ��\n");
	if ((int)me->query("qi") < 60)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 50)
		return notify_fail("��������������������ơ�\n");
	if (me->query_skill("huagu-mianzhang", 1) < 60)
		me->receive_damage("qi", 60);
	else
		me->receive_damage("qi", 40);
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
	int d_e2 = -20;
	int p_e1 = 0;
	int p_e2 = 25;
	int f_e1 = 200;
	int f_e2 = 300;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("huagu-mianzhang", 1);
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
int learn_bonus() { return 10; }
int practice_bonus() { return 10; }
int success() { return 10; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"huagu-mianzhang/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	if( random(me->query_skill("huagu-mianzhang",1)) > 50)
	{
		victim->receive_damage("jing", (int)random(me->query_skill("huagu-mianzhang",1)/5) + 10);
	}
}

int help(object me)
{
	write(HIC"\n�������ƣ�"NOR"\n");
	write(@HELP

    ��������Ϊ�ߵ������̾�������������Ȼ�����

	ѧϰҪ��
		�����󷨼����ܵ��ڻ�������
		�����ڹ�50
		����300
HELP
	);
	return 1;
}


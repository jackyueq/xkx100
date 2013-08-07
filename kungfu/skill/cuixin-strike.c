// cuixin-strike.c ������

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N����΢�Σ�һ��"CYN"����߱�����"NOR"����Ю��磬����$n���ķ�",
	"lvl"   : 0,
	"skill_name" : "��߱���",
]),
([	"action" : "$N������磬˫��΢΢������һ��"BLU"����Ӱ���ġ�"NOR"����$n���ظ�",
	"lvl"   : 20,
	"skill_name" : "��Ӱ����",
]),
([	"action" : "$N˫�ƺ������֣�һ��"HIW"������ѩ�衹"NOR"�����Ȱ��ɨ��$n�ļ�ͷ",
	"lvl"   : 40,
	"skill_name" : "����ѩ��",
]),
([	"action" : "$N���Ƶ��ػ��������Ƽ�����һ��"GRN"����ӫ��Ӱ��"NOR"���͵�����$n�Ķ�ͷ",
	"lvl"   : 60,
	"skill_name" : "��ӫ��Ӱ",
]),
([	"action" : "$Nʹһ��"HIC"�������꾡��"NOR"��˫���������������ľ��磬ײ��$n",
	"lvl"   : 80,
	"skill_name" : "�����꾡",
]),
([	"action" : "$N���ޱ��飬˫�ۺ�����ҵؼ��ӣ�ʹ��"HIM"��ѩԭ���衹"NOR"��ʮ���������������Ѹ���ޱȵ�Ϯ��$nȫ�������Ѩ",
	"lvl"   : 100,
	"skill_name" : "ѩԭ����",
]),
([	"action" : "$Nʹ��"RED"��������ա�"NOR"����Ȼ������ϣ�����$n��ת��Ȧ��$n���ۻ����Ҽ䣬$N����Ȼͣ��$n������ֻ���һ����Ȧ���������ֳ����Ȧ����$n�ĺ�",
	"lvl"   : 120,
	"skill_name" : "�������",
]),
([	"action" : "$NͻȻ˫��ƽ�٣�$nһ�������ڲ²�䣬���$Nವ�һ�½�˫���ջ���ǰ������һ��"HIG"������������"NOR"��˫����磬ֱ����$n������",
	"lvl"   : 140,
	"skill_name" : "��������",
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry" ; }
int valid_combine(string combo) { return combo=="wuying-leg"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�������Ʊ�����֡�\n");
	if ((int)me->query_skill("qingming-xuangong", 1) < 15)
		return notify_fail("�����ڤ������򲻹����޷�ѧϰ�����ơ�\n");
	if ((int)me->query_skill("force", 1) < 20)
		return notify_fail("����ڹ���򲻹����������ƻ��߻���ħ��\n");
	if ((int)me->query("max_neili") < 300)
		return notify_fail("�������̫�����޷��������ơ�\n");
	return 1;
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 50)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 50)
		return notify_fail("������������������ơ�\n");
	if (me->query_skill("cuixin-strike", 1) < 60)
		me->receive_damage("qi", 45);
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
	int d_e2 = -25;
	int p_e1 = -5;
	int p_e2 = 25;
	int f_e1 = 200;
	int f_e2 = 310;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("cuixin-strike", 1);
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
	return __DIR__"cuixin-strike/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	if( random(me->query_skill("cuixin-strike",1)) > 50)
	{
		victim->receive_damage("qi", random(10) + 1);
	}
}

int help(object me)
{
	write(HIC"\n�����ƣ�"NOR"\n");
	write(@HELP

    ������Ϊ����ɴ����Ʒ����ݻٵз����ࡣ
    ������Ӱ�Ȼ�����

	ѧϰҪ��
		��ڤ����15��
		�����ڹ�20��
		����300
HELP
	);
	return 1;
}


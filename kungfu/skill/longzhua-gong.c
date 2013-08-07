// longzhua-gong.c ��צ��
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "�ں��������У�$Nʹһ��"GRN"������ʽ��"NOR"��˫���繳��ꫣ�����$n��$l",
	"lvl"    : 0,
	"skill_name" : "����ʽ" ,
]),
([	"action" : "$N�͵���ǰԾ����һ��"HIB"��׽Ӱʽ��"NOR"�������߳���˫��ץ��$n������",
	"lvl"    : 6,
	"skill_name" : "׽Ӱʽ" ,
]),
([	"action" : "$N˫��ƽ�죬ʮָ΢΢���¶�����һ��"HIC"������ʽ��"NOR"����$n��$l",	
	"lvl"    : 12,
	"skill_name" : "����ʽ" ,
]),
([	"action" : "$N���������������ڻӣ�һ��"RED"������ʽ��"NOR"����$n�ؿ�",
	"lvl"    : 18,
	"skill_name" : "����ʽ" ,
]),
([	"action" : "$N�������գ�����������ɽ��һ��"HIM"������ʽ��"NOR"���͵ػ���$n��$l",
	"lvl"    : 24,
	"skill_name" : "����ʽ" ,
]),
([	"action" : "$N�ڲ���ǰ�����ֻ��أ�����̽����һ��"YEL"������ʽ��"NOR"����$n���ɲ�",
	"lvl"    : 30,
	"skill_name" : "����ʽ" ,
]),
([	"action" : "$N˫��ƽ����ǰ�����ֻ�ס���ţ�һ��"HIY"������ʽ��"NOR"��������$n��$l",
	"lvl"    : 35,
	"skill_name" : "����ʽ" ,
]),
([	"action" : "$N������ǰ������Ҹ�º��գ���ָ�繳��һ��"HIC"����ȱʽ��"NOR"����$n�Ķ�
��",
	"lvl"    : 40,
	"skill_name" : "��ȱʽ" ,
]),
([	"action" : "$N����б��$n����֮�䣬һ��"HIB"������ʽ��"NOR"������ȡĿ�����ַ���$n��
�ɲ�",
	"lvl"    : 45,
	"skill_name" : "����ʽ" ,
]),
([	"action" : "$Nһ����ָ$n�Ľ�����һ��"HIR"���ὣʽ��"NOR"��һ������ץ��$n���еĳ���
",
	"lvl"    : 50,
	"skill_name" : "�ὣʽ" ,
]),
([	"action" : "$N����ָ��$n��ǰ�������Ѩ������бָ̫��Ѩ��һ��"HIW"������ʽ��"NOR"ʹ
$n��������",
	"lvl"    : 55,
	"skill_name" : "����ʽ" ,
]),
([	"action" : "$Nǰ���ŵأ�һ�ֶ����צ��һ��ָ�أ�һ��"HIY"��׷��ʽ��"NOR"��������$n
��ȫ��",
	"lvl"    : 60,
	"skill_name" : "׷��ʽ" ,
])
});

int valid_enable(string usage) { return usage=="claw" || usage=="parry"; }
int valid_combine(string combo) { return combo=="qianye-shou"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("����צ��������֡�\n");
	if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
		return notify_fail("��Ļ�Ԫһ������򲻹����޷�ѧ��צ����\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷�����צ����\n");
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��ı�����ֲ�����ϰ��\n");
	if ((int)me->query("qi") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("���������������צ����\n");
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
	int d_e1 = 30;
	int d_e2 = 10;
	int p_e1 = -15;
	int p_e2 = -50;
	int f_e1 = 300;
	int f_e2 = 450;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int)me->query_skill("longzhua-gong", 1);
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
int learn_bonus() { return 10; }
int practice_bonus() { return 5; }
int success() { return 10; }
int power_point() { return 1; }

int help(object me)
{
	write(HIC"\n��צ����"NOR"\n");
	write(@HELP

    ��צ��ֻ����ʮ���У�Ҫּ������������������仯���ࡣΪ
������ʮ������֮һ��
    ��������ǧҶ�ֻ�����

	ѧϰҪ��
		��Ԫһ����20��
		����100
HELP
	);
	return 1;
}


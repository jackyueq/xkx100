// zhemei-shou.c ��ɽ��÷��
// Last Modified by sir 10.23.2001

#include <ansi.h>;
#include <xiaoyao.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$Nһ��"GRN"����÷��Թ��"NOR"��˫�ֺ�ӣ�ץ��$n",
	"lvl" : 0,
	"skill_name" : "��÷��Թ"
]),
([	"action" : "$Nһ��"YEL"���ƻ���Գ"NOR"������ԾȻ����ץ��$n��ͷ��",
	"lvl" : 10,
	"skill_name" : "�ƻ���Գ�"
]),
([	"action" : "$Nһ��"CYN"����ɽһ�����ı̡�"NOR"��˫�ַ׷ɣ�$nֻ���ۻ�����",
	"lvl" : 30,
	"skill_name" : "��ɽһ�����ı�"
]),
([	"action" : "$Nһ��"MAG"��÷��ѩ�串��ƻ��"NOR"��˫�ֺϻ���$nֻ���޴��ɱ�",
	"lvl" : 40,
	"skill_name" : "÷��ѩ�串��ƻ"
]),
([	"action" : "$Nһ��"HIW"��������÷��ѩ�ҡ�"NOR"��˫��ƮȻץ��$n",
	"lvl" : 50,
	"skill_name" : "������÷��ѩ��"
]),

([	"action" : "$N˫��ƽ�٣�һ��"GRN"������������ŪӰ��"NOR"����$n",
	"lvl" : 60,
	"skill_name" : "����������ŪӰ"
]),
([	"action" : "$Nһ��"HIB"����������ֱ���ۡ�"NOR"������$n���ƺ�$n��ȫ��������",
	"lvl" : 70,
	"skill_name" : "��������ֱ����"
]),

([	"action" : "$N������Σ�����һ��"HIR"������δ�϶��Ⱦ���"NOR"����$n��ͷ��",
	"lvl" : 80,
	"skill_name" : "����δ�϶��Ⱦ�"
]),
([	"action" : "$Nʩ��"HIM"������Ц�졹"NOR"�����ֺ�ɨ$n��$l�����ֹ���$n���ؿ�",
	"lvl" : 90,
	"skill_name" : "����Ц��"
]),
([	"action" : "$Nʩ��"HIR"����ʯ��١�"NOR"������һ������$n",
	"lvl" : 100,
	"skill_name" : "��ʯ���"
])
});

int valid_enable(string usage) { return usage=="parry" || usage=="hand"; }
int valid_combine(string combo) { return combo=="liuyang-zhang"; }

int valid_learn(object me)
{
	if(((int)me->query_skill("bahuang-gong", 1) < 15 ) &&
		((int)me->query_skill("beiming-shengong", 1) < 15 ))
		return notify_fail("��ı����ڹ���������졣\n");
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("����ɽ��÷�ֱ�����֡�\n");
	if ((int)me->query("max_neili") < 50)
		return notify_fail("�������̫�����޷�����ɽ��÷�֡�\n");
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��ı�����ֲ�����ϰ��\n");
	if ((int)me->query("qi") < 60)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 60)
		return notify_fail("���������������ɽ��÷�֡�\n");
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
	int d_e1 = -60;
	int d_e2 = -30;
	int p_e1 = 0;
	int p_e2 = 35;
	int f_e1 = 120;
	int f_e2 = 220;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("zhemei-shou", 1);
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
mixed hit_ob(object me, object victim, int damage_bonus)
{
	if (me->query("jiali") <= 10) return 0;
	if (fam_type(me)!="xiaoyao") return 0;
	if( damage_bonus < 100 ) return 0;

	if( random(damage_bonus/3) > victim->query_str() ) 
	{
		victim->receive_wound("qi", (damage_bonus - 80) / 3, me);
		return HIC "������һ�����죬�·���÷֦�۶ϵ�������\n" NOR;	
	}
}
int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 5; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"zhemei-shou/" + action;
}
int help(object me)
{
	write(HIC"\n��ɽ��÷�֣�"NOR"\n");
	write(@HELP

    ��ɽ��÷������ң���ַ���
    ������ɽ�����ƻ�����

	ѧϰҪ��
		��ڤ��15����˻�����Ψ�Ҷ���15��
		����50
HELP
	);
	return 1;
}


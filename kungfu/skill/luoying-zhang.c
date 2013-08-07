// luoying-zhang.c ��Ӣ����
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N˫��ƽ�죬�����ӳ���һʽ"GRN"������էչ��"NOR"��ָ����ӯƯ�������ᷴ��$n��$l",
	"lvl" : 10,
	"skill_name" : "����էչ"
]),
([	"action" : "$N������ָ����һ�գ�һʽ"HIG"���ط������"NOR"����ָ��Ȼңң����$n��$nֻ������ɼ���Ϯ���Լ��崦��Ѩ",
	"lvl" : 0,
	"skill_name" : "�ط����"
]),
([	"action" : "$NͻȻ����Ծ���գ�һ������ת���������䣬һʽ"MAG "�����Ƿɻ���"NOR"������$n��ͷ��",
	"lvl" : 10,
	"skill_name" : "���Ƿɻ�"
]),
([	"action" : "$NͻȻԾ��˫�������������罣�����缲�������һʽ"HIM "���꼱���"NOR"������$n��ȫ��",
	"lvl" : 10,
	"skill_name" : "�꼱���"
]),
([	"action" : "$N���ֻ������ĳ��죬������ֲ�£ʳָ��ָ�����������һʽ"CYN"���Ǻ����졹"NOR"��ֱָ$n������",
	"lvl" : 20,
	"skill_name" : "�Ǻ�����"
]),
([	"action" : "$NͻȻ������ˣ�����һʽ"HIW"�������׷ɡ�"NOR"��ƽ�����˫����$n�ĺ�����������",
	"lvl" : 30,
	"skill_name" : "�����׷�"
]),
([	"action" : "$NͻȻ����Ծ������Ю�ž�����ӿ�ĳ����������������ƺ�ͻ�������һʽ"HIR"������׷�¡�"NOR"��������ǰ��$n��$l��ȥ",
	"lvl" : 30,
	"skill_name" : "����׷��"
]),
([	"action" : "$Nʹһʽ"HIC"�������®��"NOR"��ȫ��ͻȻ������ת��˫�ƺ�ǰ�����͵�����$n���ؿ�",
	"lvl" : 40,
	"skill_name" : "�����®"
]),
([	"action" : "$Nǰ��һ�࣬һʽ"HIB"�����ƺ�ȡ�"NOR"�������罣��һ����������Ϯ��$n������",
	"lvl" : 50,
	"skill_name" : "���ƺ��"
]),
([	"action" : "$Nʹһʽ"HIW"���׺羭�졹"NOR"��˫���������Ȧ������һ������$n��$l�ȥ",
	"lvl" : 70,
	"skill_name" : "�׺羭��"
]),
([	"action" : "$N˫��ʳָ����ָһ�ͣ�һʽ"HIM"������������"NOR"��һ��ǿ�ҵ�����ӿ��$n��ȫ��",
	"lvl" : 60,
	"skill_name" : "��������"
]),
([	"action" : "$Nһʽ"HIC"����Ӣ���졹"NOR"��˫������ǰ��ת���ƻ����裬����ǵ�ֱָ��$n��$nֻ�������ƻ����ۻ����ҡ�",
	"lvl" : 99,
	"skill_name" : "��Ӣ����"
])
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; } 
int valid_combine(string combo) { return combo=="xuanfeng-leg"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("����Ӣ���Ʊ�����֡�\n");
	if ((int)me->query_skill("bibo-shengong", 1) < 15)
		return notify_fail("��ı̲��񹦻�򲻹����޷�ѧ��Ӣ���ơ�\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷�����Ӣ���ơ�\n");
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��ı�����ֲ�����ϰ��\n");
	if ((int)me->query("qi") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("���������������Ӣ���ơ�\n");
	me->receive_damage("qi", 25);
	me->add("neili", -15);
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
	int d_e1 = -35;
	int d_e2 = -15;
	int p_e1 = 5;
	int p_e2 = 35;
	int f_e1 = 180;
	int f_e2 = 280;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("luoying-zhang", 1);
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
int learn_bonus() { return 15; }
int practice_bonus() { return 15; }
int success() { return 15; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"luoying-zhang/" + action;
}


int help(object me)
{
	write(HIC"\n��Ӣ���ƣ�"NOR"\n");
	write(@HELP

    ��Ӣ������̥����Ӣ�񽣣����ƴ�����������ѷ��
    ��������ɨҶ�Ȼ�����

	ѧϰҪ��
		�̲���15��
		����100
HELP
	);
	return 1;
}


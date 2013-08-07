// Last Modified by winder on May. 29 2001
// ranmu-blade.c ȼľ����

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N���΢Ц��һ��"HIR"���һ�����"NOR"����$w����$n�����˰˰���ʮ�ĵ��������ݺᣬѸ�ײ��ɵ�",
	"lvl"    : 0,
	"skill_name"  : "�һ�����",
]),
([	"action" : "$N�����ڹ�һ��"GRN"����ľ����"NOR"��$w�ϴ����ޱȾ���������һ���󻡣����϶�������$n��$l",
	"lvl"    : 20,
	"skill_name"  : "��ľ����",
]),
([	"action" : "$N�ֱ�һ����һ��"HIM"���Ź����¡�"NOR"��˫�ֳ�$w����һ��ѩ�����⣬�����������У�����$n��$l",
	"lvl"    : 40,
	"skill_name"  : "�Ź�����",
]),
([	"action" : "$N����$w�������ã����ҿ���ʹ��һ��"RED"���һ����ơ�"NOR"���������󵶷磬��������$n",
	"lvl"    : 60,
	"skill_name"  : "�һ�����",
]),
([	"action" : "$Nһ��"MAG"������ȡ����"NOR"�����Ծ����أ�����$w������ǰ��Ю�����ȵķ�������$n��$l",
	"lvl"    : 80,
	"skill_name"  : "����ȡ��",
]),
([	"action" : "$N�ڿն��𣬰����һ��"HIW"����ʯ��١�"NOR"������$w�ӳ����������ĵ�Ӱ����$n��ȫ���ȥ",
	"lvl"    : 100,
	"skill_name"  : "��ʯ���",
]),
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }
int valid_learn(object me)
{
	if ((int)me->query_skill("riyue-whip",1) > 1 ||
		(int)me->query_skill("weituo-chu",1) > 1)
		return notify_fail("������д�Ħ�������Ϊ������ͬʱѧϰ��������������\n");
	if ((int)me->query("max_neili") < 1500)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("yijinjing", 1) < 150)
		return notify_fail("����׽�񹦻��̫ǳ��\n");
	if ((int)me->query_skill("zhanzhuang-gong", 1) < 150)
		return notify_fail("���վ׮�����̫ǳ��\n");
	if ((int)me->query_skill("xiuluo-blade", 1) < 150)
		return notify_fail("������޵����̫ǳ��\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;
	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "blade")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("qi") < 80 )
		return notify_fail("�������������ȼľ������\n");
	if ((int)me->query("neili") < 50 )
		return notify_fail("�������������ȼľ������\n");
	me->receive_damage("qi", 65);
	if((int)me->query_skill("ranmu-blade",1)> 200)
	{
		me->add("neili",-20);
	}
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
	int p_e1 = -20;
	int p_e2 = -40;
	int f_e1 = 100;
	int f_e2 = 250;
	int m_e1 = 190;
	int m_e2 = 300;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int)me->query_skill("ranmu-blade", 1);
	if (random(lvl) > 120 &&
		me->query_skill("force") > 100 &&
		me->query("neili") > 1000 && me->query_temp("ranmu")
		&& random(10) >6)
	{
		me->add("neili", -150);
		return ([
			"action": HIR"$N��Ȼ����һ����ţ����弱�ٵ���ת�����е�"+me->query_temp("weapon")->query("name")+"ɢ����һ�����ȵ�������Ϯ��$n��\n"NOR,
			"force" : 380,
			"damage": 120,
			"dodge" : -10,
			"damage_type": "����"
		]);
	}
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
int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 5; }
int power_point(object me) { return 1; }

string perform_action_file(string action)
{
	return __DIR__"ranmu-blade/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{		
	if(userp(me) && me->query_temp("fenwo_hit") &&
		victim->query("combat_exp") >= me->query("combat_exp")/2 &&
		me->query("fenwo") < me->query_skill("blade"))
		me->add("fenwo", 1);
// for rmd's fenwo pfm 
}

int help(object me)
{
	write(HIC"\nȼľ������"NOR"\n");
	write(@HELP

    ȼľ�����������ֶ���������
    Τ���ơ����±޷���ȼľ��������Ϊ��������������
    ����������ͬʱ��ϰ��

	ѧϰҪ��
		�׽150��
		վ׮��150��
		���޵�150��
		������Ϊ1500
HELP
	);
	return 1;
}



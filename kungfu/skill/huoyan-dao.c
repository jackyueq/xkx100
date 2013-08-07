// huoyan-dao.c ���浶
// Last Modified by sir 10.22.2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$Nʹ��һ��"RED"����ľȡ��"NOR"������ת��˫����ǰƽƽ����$n",
	"skill_name" : "��ľȡ��",
	"lvl" : 0
]),
([	"action" : "$Nʹ��һ��"HIR"��ף�ڻ��桹"NOR"�������絶��бб����$n��$l",
	"skill_name" : "ף�ڻ���",
	"lvl" : 10
]),
([	"action" : "$Nʹ��һ��"HIR"������ޱߡ�"NOR"��˫��һ�ģ�һ�����������й���$n��$l",
	"skill_name" : "����ޱ�",
	"lvl" : 20
]),
([	"action" : "$Nʹ��һ��"RED"�������ֻء�"NOR"��˫�ֺ�ʮ����ͷ����$n",
	"skill_name" : "�����ֻ�",
	"lvl" : 30
]),
([	"action" : "$Nʹ��һ��"HIR"��˫�����桹"NOR"��˫��һ�������������湥��$n��$l",
	"skill_name" : "˫������",
	"lvl" : 40
]),
([	"action" : "$Nʹ��һ��"HIB"����ɽ�𺣡�"NOR"��˫������б�ģ���ʱ��ǧ������������˷�����$n",
	"skill_name" : "��ɽ��",
	"lvl" : 60
]),
([	"action" : "$Nʹ��һ��"RED"���׷��ȡ�"NOR"����ۻ��գ�����������ֱ��$n��$l",
	"skill_name" : "�׷���",
	"lvl" : 80
]),
([	"action" : "$Nʹ��һ��"RED"������������"NOR"��˫��΢��������ǰ�죬һ���ھ�����ɽ�����㹥��$n",
	"skill_name" : "��������",
	"lvl" : 100
]),
});

int valid_enable(string usage) { return usage == "strike" || usage == "parry"; }
int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�����浶������֡�\n");

	else if ((int)me->query("max_neili") < 800)
//	���浶Ҫ�кܸߵ���������ѧ
		return notify_fail("�������������\n");

	if ((int)me->query_skill("xiaowuxiang", 1) < 60)
		return notify_fail("���С���๦���̫ǳ��\n");

	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�����浶������֡�\n");
	if ((int)me->query("qi") < 60)
		return notify_fail("������������������˻��浶��\n");
	if ((int)me->query("neili")<40)
		return notify_fail("������������������˻��浶��\n");
        me->receive_damage("qi", 55);
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
	int d_e1 = -55;
	int d_e2 = -35;
	int p_e1 = -15;
	int p_e2 = 15;
	int f_e1 = 310;
	int f_e2 = 460;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("huoyan-dao", 1);
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
		"damage_type" : "����",
	]);
}
int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 5; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"huoyan-dao/" + action;
}

int help(object me)
{
	write(HIR"\n���浶��"NOR"\n");
	write(@HELP

    ���浶Ϊѩɽ������ס���Ħ�ǵĶ��ž�����
    ԭΪ������ʮ������֮һ�����Ħ�ǵ�Ľ�ݲ��������ÿ�����
���գ�������С���๦�������С�

	ѧϰҪ��
		С���๦60��
		����800
HELP
	);
	return 1;
}


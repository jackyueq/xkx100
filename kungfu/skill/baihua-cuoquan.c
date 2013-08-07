// Last Modified by winder on Sep. 12 2001
// baihuacuo-quan.c �ٻ���ȭ

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N���һ�ӣ�ʹһ��"HIC"����ת���ơ�"NOR"��˫�����������$n",
	"skill_name" : "��ת����",
	"lvl" : 0
]),
([	"action" : "$Nʹһ��"HIW"�����ƶϷ塹"NOR"�����ֳ��ƣ���סǰ�أ����ֳ�ȭ������$n��$l",
	"skill_name" : "���ƶϷ�",
	"lvl" : 5
]),
([	"action" : "$N������������ֽ��գ�ʹһ��"GRN"���ֻ�������"NOR"��ֱ���й�����$n��$l��ȥ",
	"skill_name" : "�ֻ�����",
	"lvl" : 10
]),
([	"action" : "$N˫��һ���������øգ��������ᣬʹһ��"RED"���ߵ�������"NOR"���ֻ�$n��ǰ�غ�$l",
	"skill_name" : "�ߵ�����",
	"lvl" : 15
]),
([	"action" : "$N˫��˫���Ƴ������������һת������һ����Ȧ��ʹһ��"BLU"��ҹս�˷���"NOR"������$n��$l",
	"skill_name" : "ҹս�˷�",
	"lvl" : 20
]),
([	"action" : "$NһԾ��ǰ��ʹһ��"MAG"���绢������"NOR"����ȭ������$n��$l��ȥ",
	"skill_name" : "�绢����",
	"lvl" : 25
]),
([	"action" : "$Nȭ��һ�֣�б���ϲ���һ��"HIG"������������"NOR"������$n��$l",
	"skill_name" : "��������",
	"lvl" : 30
]),
([	"action" : "$N���ǰ̤�벽������ʹһ��"HIY"��������ӡ�"NOR"��ָ������$n��$l��ȥ",
	"skill_name" : "�������",
	"lvl" : 35
]),
([	"action" : "$Nһ��"YEL"��ָ�컮�ء�"NOR"��С�ۻ��˰��Բ����˫�ƻ��������Ƴ�����$n��$l��ȥ",
	"skill_name" : "ָ�컮��",
	"lvl" : 40
]),
([	"action" : "$N���ֺᵲ������һ�ӣ�����ʹһ��"GRN"������б�ɡ�"NOR"������$n��$l",
	"skill_name" : "����б��",
	"lvl" : 45
]),
([	"action" : "$N�����鹥�����ֽ���,ʹһ��"HIR"���ƻ���ľ��"NOR"����$n��$l��ȥ",
	"skill_name" : "�ƻ���ľ",
	"lvl" : 50
]),
([	"action" : "$N����ǰ�ˣ�һ��"HIM"�������߶���"NOR"ȭ�м��ȴ���$n��$l",
	"skill_name" : "�����߶�",
	"lvl" : 55
]),
([	"action" : "$N������$n����һ�Σ�����һ��"HIW"���ƺ����롹"NOR"����$n��$l",
	"skill_name" : "�ƺ�����",
	"lvl" : 60
]),
([	"action" : "$Nʩ��"MAG"�����ƻ�Ӱ��"NOR"�����β�ס������˫��ͬʱ����$n��$l",
	"skill_name" : "���ƻ�Ӱ",
	"lvl" : 65
]),
([	"action" : "$N������������������"HIY"������������"NOR"��˫ȭ����$n��$l",
	"skill_name" : "��������",
	"lvl" : 70
]),
});
int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }
int valid_combine(string combo) { return combo=="benlei-shou"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("���ٻ���ȭ������֡�\n");
	if ((int)me->query_skill("honghua-shengong", 1) < 20)
		return notify_fail("��ĺ컨�񹦻�򲻹����޷�ѧ�ٻ���ȭ��\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷����ٻ���ȭ��\n");
	return 1;
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 50)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 50)
		return notify_fail("��������������ٻ���ȭ��\n");
	me->receive_damage("qi", 35);
	me->add("neili", -20);
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
	int d_e1 = 25;
	int d_e2 = 50;
	int p_e1 = -30;
	int p_e2 = -15;
	int f_e1 = 130;
	int f_e2 = 280;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("baihua-cuoquan", 1);
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
int learn_bonus() { return 20; }
int practice_bonus() { return 15; }
int success() { return 15; }
int power_point() { return 1.0; }
string perform_action_file(string action)
{
	return __DIR__"baihua-cuoquan/" + action;
}

int help(object me)
{
	write(HIM"\n�ٻ���ȭ��"NOR"\n");
	write(@HELP

    �ٻ���ȭ����ع���Ԭʿ��������Ԭʿ��ʹ�ڵ����������Ե��
������������������ȭ����ȭȡ�ڼ�֮�����������Ƕ��ǣ��յ�
��찣��ʳƴ�ȭ��
    �컨���ܶ����¼���ΪԬʿ�����ҵ��ӣ��ô���ȭ��

	ѧϰҪ��
		�컨��20��
		������Ϊ100
HELP
	);
	return 1;
}

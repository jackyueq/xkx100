//tianchang-zhang �쳤��
// Last Modified by sir on 5/19/ 2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$Nʹһ��"GRN"����ɽ������"NOR"��˫�ֻ��˸���Ȧ������$n��$l",
	"skill_name" : "��ɽ����",
	"lvl" : 5
]),
([	"action" : "$Nʹһ��"MAG"����ϼ������"NOR"����������һ�ӣ�����$n��$l",
	"skill_name" : "��ϼ����",
	"lvl" : 15
]),
([	"action" : "$N�����������⣬��������ʹһ��"CYN"���Ǻ�����"NOR"����$n��$l��ȥ",
	"skill_name" : "�Ǻ�����",
	"lvl" : 10
]),
([	"action" : "$Nʹһ��"HIM"�������Ƶ���"NOR"���ֻ�$n���ؿں�$l",
	"skill_name" : "�����Ƶ�",
	"lvl" : 20
]),
([	"action" : "$Nʹһ��"HIB"���������֡�"NOR"��������ͬʱ�������ڿ���ͻȻ�����Ʒ��򻥱�",
	"skill_name" : "��������",
	"lvl" : 30
]),
([	"action" : "$N���ֲ�ס�ζ�������һ��"HIW"�����ղγ���"NOR"����$n��$l��ȥ",
	"skill_name" : "���ղγ�",
	"lvl" : 50
]),
([	"action" : "$N���ֱ���Ϊ�ģ����������絶��һ��"HIY"�������ɳ��"NOR"������$n��$l",
	"skill_name" : "�����ɳ",
	"lvl" : 70
]),
([	"action" : "$N����˺�벽������ʹһ��"HIC"��ˮ��һɫ��"NOR"�������$n",
	"skill_name" : "ˮ��һɫ",
	"lvl" : 80
]),
([	"action" : "$Nһ��"CYN"���»����ա�"NOR"�������ȷ������������ƺ󷢶�����",
	"skill_name" : "�»�����",
	"lvl" : 90
]),
([	"action" : "$N˫���������У�˫�����ɨ��$n��$l��ȴ��һ��"HIR"���϶��¡�"NOR"����̬����",
	"skill_name" : "�϶���",
	"lvl" : 100
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry" ; }
int valid_combine(string combo) { return combo=="chuanyun-shou"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("���쳤�Ʊ�����֡�\n");
	if ((int)me->query_skill("baiyun-xinfa", 1) < 20)
		return notify_fail("��İ����ķ���򲻹����޷�ѧ�쳤�ơ�\n");
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��ı�����ֲ�����ϰ��\n");
	if ((int)me->query("qi") < 40)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 40)
		return notify_fail("��������������쳤�ơ�\n");
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
	int d_e1 = -35;
	int d_e2 = -5;
	int p_e1 = 5;
	int p_e2 = 35;
	int f_e1 = 170;
	int f_e2 = 280;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("tianchang-zhang", 1);
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
int learn_bonus() { return 20; }
int practice_bonus() { return 20; }
int success() { return 15; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"tianchang-zhang/" + action;
}
int help(object me)
{
	write(HIC"\n�쳤�ƣ�"NOR"\n");
	write(@HELP

    �쳤��Ϊ��ɽ���书��
    ���봩���ֻ�����

	ѧϰҪ��
		�����ķ�20��
HELP
	);
	return 1;
}


// houquan.c ��ȭ
// Last Modified by sega on Mar. 10 2000

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "\$N����΢����������ǰ�˳���һʽ"HIM"���ɺ�ժ�ҡ�"NOR"����צֱ����ץ��$n��˫��",
	"lvl" : 0,
	"skill_name" : "��ճ���"
]),
([	"action" : "$N������Σ�һʽ"GRN"�������֦��"NOR"������ֱ��������$n�ļ羮��Ѩ",
	"lvl" : 8,
	"skill_name" : "�����֦"
]),
([	"action" : "$Nһ��ǰ�죬һ�ۺ�ָ��һʽ"HIW"��Գ�����桹"NOR"������$n������",
	"lvl" : 15,
	"skill_name" : "Գ������"
]),
([	"action" : "\n$N��Ȼ����һ�ţ�ʹһʽ"CYN"���˷���Ӱ��"NOR"��˫�������޶���һצץ��$n���ؿ�",
	"lvl" : 15,
	"skill_name" : "�˷���Ӱ"
]),
([	"action" : "$N����һ������һ������ʹһʽ"HIB"��ˮ�����¡�"NOR"��˫צ������$n��С��",
	"lvl" : 20,
	"skill_name" : "ˮ������"
]),
([	"action" : "$N�͵����ϸ߸�Ծ��һʽ"HIY"�����ժ�ǡ�"NOR"���Ӹ����£�һצ����$n��ͷ��",
	"lvl" : 30,
	"skill_name" : "���ժ��"
]),
});

int valid_enable(string usage)
{
	return usage=="unarmed" || usage=="parry" || usage=="cuff";
}
int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("����ȭ������֡�\n");
	if ((int)me->query_skill("yunlong-shengong",1) < 10)
	  return notify_fail("��������񹦻�򲻹����޷�ѧ��ȭ��\n");
	if ((int)me->query_skill("force", 1) < 30)
		return notify_fail("��Ļ����ڹ���򲻹����޷�ѧ��ȭ��\n");
	if ((int)me->query("max_neili") < 200)
		return notify_fail("�������̫�����޷�����ȭ��\n");
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��ı�����ֲ�����ϰ��\n");
	if ((int)me->query("qi") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 15)
		return notify_fail("���������������ȭ��\n");
	me->receive_damage("qi", 20);
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
	int d_e1 = 35;
	int d_e2 = 55;
	int p_e1 = -25;
	int p_e2 = -5;
	int f_e1 = 80;
	int f_e2 = 230;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("houquan", 1);
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
int learn_bonus() { return 30; }
int practice_bonus() { return 25; }
int success() { return 20; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"houquan/" + action;
}
int help(object me)
{
	write(HIC"\n��ȭ��"NOR"\n");
	write(@HELP

    ����ǰ��ģ��Գ���˻�������������һ��ȭ�����������趯Ϊ
����Ҫ�ص㡣 
    ��ȭΪ��ػ��������书��

	ѧϰҪ��
		������10��
		�����ڹ�30��
		����200
HELP
	);
	return 1;
}


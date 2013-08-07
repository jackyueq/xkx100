// shenlong-staff �����ȷ�
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$Nһ��һ������һʽ����������������β���غ�������ɨ��$n��$l",
        "lvl"    : 0,
        "skill_name" : "��������"
]),
([	"action" : "$N���һ��������$w����һƬ���⣬һ�С�ҹս�˷�������$n��$l��ɨ��ȥ",
        "lvl"    : 10,
        "skill_name" : "ҹս�˷�"
]),
([	"action" : "$N��Ȼһ����Х��һ�С����Ǹ��¡�������$w�ó������׹⣬��Ϯ$n�ظ�ҪѨ",
        "lvl"    : 15,
        "skill_name" : "���Ǹ���"
]),
([	"action" : "$N���ζ�Ȼ�������ɶ࣬һʽ��ǧ��ѹ����������$w���ź�Х�ƿ����������",
        "lvl"    : 20,
        "skill_name" : "ǧ��ѹ��"
]),
([      "action" : "$N����$n�Ų�δ�ȣ�������ǰ���У���Ȼһָ����β�𴦣�������ѰѨ����ֱȡ��$n�����¡�Ѫ��Ѩ��",
        "lvl"    : 25,
        "skill_name" : "����ѰѨ"
]),
([      "action" : "$N��ͷһת��Ѹ��һ�С���ɨǧ����������Ѹ�ݣ�������������$n����·��ɨ��ȥ",
        "lvl"    : 30,
        "skill_name" : "��ɨǧ��"
]),
([	"action" : "��Ȼ�䣬$N�����ȹ⻪��ʢ��$w���ơ���������������ʱ��$nȦ�ڵ���",
        "lvl"    : 35,
        "skill_name" : "��������"
]),
([	"action" : "$N����$w���������ҷ������������뺣��ʮ��ʮ����һʽ�����ƶϷ塹��$n��$l��ɨ��ȥ",
        "lvl"    : 40,
        "skill_name" : "���ƶϷ�",
]),
([      "action" : "$N�߸�Ծ�𣬻��������е�$wһ�С�һ�����졹����һ����������$n��ͷֱ�����",
        "lvl"    : 50,
        "skill_name" : "һ������",
]),
([	"action" : "$Nһ�����ȡ�������ա�����$w��������һ�ã�˫����ס$wβ��ת���͵ú�ɨ����$n��$l",
        "lvl"    : 60,
        "skill_name" : "�������",
]),
([      "action" : "$N��Ȼ����һ�䣬ʹ�������߳��������ȷ��Ե�����֮��������$w����������Ӱ����$n",
        "lvl"    : 70,
        "skill_name" : "���߳���"
]),
([      "action" : "$N���ȴ�����$w�й�ֱ��������һ����̳�������$n��$l�������С����Ի�����",
        "lvl"    : 80,
        "skill_name" : "���Ի���"
]),
([	"action" : "$Nһʽ��һ�ȶ���������ͷһ$w������������ͷδ����һ�ɷ��ѽ�$n�Ƶ����Դ���",
        "lvl"    : 90,
        "skill_name" : "һ�ȶ���"
]),
([	"action" : "$N���С�Ⱥ�߿��衹��$wɨ��һ������Ӱ������˷�Χ��$n��Ҫ��$n��û��ʳ",
        "lvl"    : 100,
        "skill_name" : "Ⱥ�߿���"
]),
});

int valid_enable(string usage) { return usage=="staff" || usage=="parry"; }
int valid_learn(object me)
{
	object weapon;

	if (objectp(weapon = me->query_temp("weapon")))
	if ((string)weapon->query("skill_type") != "staff")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query_skill("dulong-dafa", 1) < 30)
		return notify_fail("��Ķ����󷨻�򲻹����޷�ѧ�����ȷ���\n");
	if ((int)me->query_skill("force", 1) < 30)
		return notify_fail("��Ļ����ڹ���򲻹����޷�ѧ�����ȷ���\n");
	if ((int)me->query_skill("shenlong-bashi", 1) < 30)
		return notify_fail("���������ʽ��򲻹����޷�ѧ�����ȷ���\n");
	if ((int)me->query_skill("dulong-dafa",1) <(int)me->query_skill("shenlong-staff",1))
		return notify_fail("��Ķ����󷨻�򲻹����޷�����ѧ�����ȷ���\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "staff")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("qi") < 60)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 50)
		return notify_fail("������������������ȷ���\n");
	me->receive_damage("qi", 55);
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
	int p_e2 = 30;
	int f_e1 = 300;
	int f_e2 = 400;
	int m_e1 = 220;
	int m_e2 = 300;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("shenlong-staff", 1);
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
		"damage_type" : "����",
	]);
}
int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 5; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"shenlong-staff/" + action;
}
int help(object me)
{
	write(HIC"\n�����ȷ���"NOR"\n");
	write(@HELP

    �����ȷ����������ȷ����൱������

	ѧϰҪ��
		�����ڹ�30��
		������30���Ҳ����������ȷ��ļ���
		������ʽ30��
		����100
HELP
	);
	return 1;
}


// sun-finger.c һ��ָ book: һ��ָ��
// Last Modified by sir 10.23.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$Nһʽ"GRN"������������"NOR"��������ָ���籡������������ָ���������������$n��$l",
	"lvl" : 0,
	"skill_name" : "��������"
]),
([	"action" : "$N����һת��һ���絽$n���$n��æת��$N���������Ծ�أ�
һʽ"YEL"��³�����ա�"NOR"������ʳָ������ָ��$n��$l",
	"lvl" : 20,
	"skill_name" : "³������"
]),
([	"action" : "$N����̤��һ���������������ʳָЮ���ۻ���������$n��$l��
��ʽ����̹��������һʽ"HIW"��������ѩ��"NOR"",
	"lvl" : 40,
	"skill_name" : "������ѩ"
]),
([	"action" : "$N��ӰƮ��һʽ"MAG"���������졹"NOR"�����϶��£���������繳������$n���Ҽ磬$n������ܣ�$N���ֳ��Ƶ���$n��$l",
	"lvl" : 60,
	"skill_name" : "��������"
]),
([	"action" : "ֻ��$N���Ϻ���һ�죬����һ�գ�һʽ"RED"�����ս�����"NOR"������ʳָбָ����$n��$l��ȥ",
	"lvl" : 70,
	"skill_name" : "���ս���"
]),
([	"action" : "$N����б����ͻȻ�����Ϊָ���͵�һ���죬һʽ"HIM"�����ﳯ����"NOR"��ʹ��һ��ָ��������$n��$l",
	"lvl" : 90,
	"skill_name" : "���ﳯ��"
]),
([	"action" : "$N����һԾ������$n������ϥһ��������ʳָ����һʽ"BLU"����������"NOR"������$n�ĺ���",
	"lvl" : 100,
	"skill_name" : "��������"
]),
([	"action" : "$Nһ�����, һʽ"HIY"��������̩��"NOR"���þ�ȫ����$n��$l��ȥ",
	"lvl" : 130,
	"skill_name" : "������̩"
]),
});

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }
int valid_combine(string combo) { return combo=="haotian-zhang"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��һ��ָ������֡�\n");
	if (me->query("gender") != "����")
		return notify_fail("���������㣬�޷�ѧһ��ָ��\n");
	if ((int)me->query("max_neili") < 700)
		return notify_fail("�������̫�����޷���һ��ָ��\n");
	if ((int)me->query_skill("kurong-changong", 1) > 80 ||
		(int)me->query_skill("xiantian-qigong", 1) > 80)
		return 1;
	else
		return notify_fail("��ı����ڹ���򲻹����޷�ѧһ��ָ��\n");
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��ı�����ֲ�����ϰ��\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 30)
		return notify_fail("�������������һ��ָ!\n");
	me->receive_damage("qi", 50);
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
	int d_e2 = 45;
	int p_e1 = -35;
	int p_e2 = -15;
	int f_e1 = 390;
	int f_e2 = 490;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("sun-finger", 1);
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
int learn_bonus() { return 5; }
int practice_bonus() { return 5; }
int success() { return 10; }
int power_point(object me) 
{
  if(me->query_skill("kurong-changong") > 10) return 1.0;
  else return 0.6;
}


string perform_action_file(string action)
{
	return __DIR__"sun-finger/" + action;
}
int help(object me)
{
	write(HIC"\nһ��ָ��"NOR"\n");
	write(@HELP

    ԭΪ������϶��������书������һ�ƴ�ʦ������Ю�˼�����
��ɽ�۽�������ϵ۳ƺš���һ�ƴ�ʦ��һ��ָ���������˽�����
���������˼�������ȫ�����С�
    ����ȫ�������ƻ�����

	ѧϰҪ��
		����
		������������������80��
		����700
HELP
	);
	return 1;
}


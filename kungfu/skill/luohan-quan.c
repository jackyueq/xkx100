// luohan-quan.c �޺�ȭ
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N�����ϲ���һʽ"HIY"����ݺ��ܡ�"NOR"�������ַֿ�����ȭΪ�ƣ�����$n��
$l",
	"lvl" : 0,
	"skill_name" : "��ݺ���"
]),
([	"action" : "$N�����̤��ȫ����ת��һ��"HIM"�����ﳯ����"NOR"�������͵ز���$n��$l",
	"lvl" : 8,
	"skill_name" : "���ﳯ��"
]),
([	"action" : "$N˫�ִ󿪴��أ����߾٣�ʹһ��"HIB"�����Ӷ�Ӧ��"NOR"��˫ȭ��$n��$l��
ȥ",
	"lvl" : 15,
	"skill_name" : "���Ӷ�Ӧ"
]),
([	"action" : "$N����Ȧ���������⵱�أ����ڳ��ϣ�һ��"HIC"��ƫ�����ǡ�"NOR"����$n��
$l",
	"lvl" : 24,
	"skill_name" : "ƫ������"
]),
([	"action" : "$Nʹһ��"HIM"���ຣ��ͷ��"NOR"������ǰ̽��˫�ֻ��˸���Ȧ������$n��$l",
	"lvl" : 33,
	"skill_name" : "�ຣ��ͷ"
]),
([	"action" : "$N˫�ƻ�����һ��"HIY"��Юɽ������"NOR"���Ƴ���磬һ�����е�$n������",
	"lvl" : 42,
	"skill_name" : "Юɽ����"
]),
([	"action" : "$Nʩ��"HIG"����������"NOR"��˫ȭȭ����磬ͬʱ����$nͷ���أ�������Ҫ
��",
	"lvl" : 50,
	"skill_name" : "������"
]),
([	"action" : "$N����ڿۣ�����������һʽ"BLU"�����������"NOR"��˫�����밴��$n���ؿ�
",
	"lvl" : 58,
	"skill_name" : "�������"
]),
});

int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }	
int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("���޺�ȭ������֡�\n");
	if ((int)me->query_skill("hunyuan-yiqi", 1) < 10)
		return notify_fail("��Ļ�Ԫһ������򲻹����޷�ѧ�޺�ȭ��\n");
	if ((int)me->query("max_neili") < 50)
		return notify_fail("�������̫�����޷����޺�ȭ��\n");
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��ı�����ֲ�����ϰ��\n");
	if ((int)me->query("qi") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("��������������޺�ȭ��\n");
	me->receive_damage("qi", 30);
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
	int d_e1 = 30;
	int d_e2 = 50;
	int p_e1 = -30;
	int p_e2 = -10;
	int f_e1 = 110;
	int f_e2 = 260;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("luohan-quan", 1);
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
int practice_bonus() { return 20; }
int success() { return 15; }
int power_point(object me) { return 1.0; }

int help(object me)
{
	write(HIC"\n�޺�ȭ��"NOR"\n");
	write(@HELP

    �޺�ȭΪ������ʮ������֮һ��
    ���뻥����

	ѧϰҪ��
		��Ԫһ����10��
		����50
HELP
	);
	return 1;
}


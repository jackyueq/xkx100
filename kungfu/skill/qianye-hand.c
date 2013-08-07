// Last Modified by winder on May. 29 2001
// qianye-shou.c ����ǧҶ�� ��Τ���ƻ��� ���ԡ���չǧ�ַ�����

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$Nһʽ"HIR"�����ֽ�ӡ��"NOR"��˫��̧���������ϣ�����Ĵָָ������Ӵ�����ǰ����",
	"lvl"   : 0,
	"skill_name" : "���ֽ�ӡ"
]),
([	"action" : "$N����ӡ��̧������ת�ƣ�һʽ"YEL"������������"NOR"��ȫ������ֱ��˫����$n�ķ���γ�",
	"lvl"   : 10,
	"skill_name" : "��������"
]),
([	"action" : "$Nһʽ"CYN"�������ඥ��"NOR"������ͬʱ����ת�ƣ����ֳ�©��״�������������ƣ�����$n����",
	"lvl"   : 20,
	"skill_name" : "�����ඥ"
]),
([	"action" : "$N�������ֵ���ǰ������"BLU"��˫�ֺ�ʮ��"NOR"���������Ŀտ����������������С�۳�һֱ��ֱ��$n",
	"lvl"   : 30,
	"skill_name" : "˫�ֺ�ʮ"
]),
([	"action" : "$Nʹһʽ"HIC"����ָǬ����"NOR"�������ɿ�ת�ƣ�������ָ����ǰ������ȴ�������£�����$n$l",
	"lvl"   : 40,
	"skill_name" : "��ָǬ��"
]),
([	"action" : "$Nһʽ"HIY"��������"NOR"����������ǰ������������չ����$n��ƽ����������������һ˦",
	"lvl"   : 50,
	"skill_name" : "������"
]),
([	"action" : "$N����һ�߷ֿ���һ����ǰ�·���չ��һʽ"MAG"��˫���º���"NOR"���ֱ۱�ã���$n��ǰӡ�˲���ʮ��",
	"lvl"   : 60,
	"skill_name" : "˫���º�"
]),
([	"action" : "$Nһʽ"CYN"������������"NOR"��ȫ������ֱ����ָ����$n���㣬Ȼ��ȫ���������ɣ����ָֻ�����ǰ��ʮ",
	"lvl"   : 70,
	"skill_name" : "��������"
]),
([	"action" : "$Nһʽ"HIG"���޺���ɽ��"NOR"������һ�߷ֿ���һ����$n�����չ��ͬʱ������ת��󷽣���$pˤ�˳�ȥ",
	"lvl"   : 80,
	"skill_name" : "�޺���ɽ"
]),
([	"action" : "$Nһʽ"HIM"�������ɽ��"NOR"��ָ�����ϣ������ͬ�ߣ�������ֱ������һ�ӣ���$n�����Ƴ�",
	"lvl"   : 90,
	"skill_name" : "�����ɽ"
]),
([	"action" : "$N���ֻ������䣬��������ת��$n������һʽ"GRN"������С����"NOR"�������ص����͵طž�",
	"lvl"   : 100,
	"skill_name" : "����С��"
]),
});

int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }
int valid_combine(string combo){ return combo=="weituo-strike"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("������ǧҶ�ֱ�����֡�\n");
	if ((int)me->query_skill("zhanzhuang-gong", 1) < 20)
		return notify_fail("���վ׮����򲻹����޷�ѧ����ǧҶ�֡�\n");
	if ((int)me->query("max_neili") < 50)
		return notify_fail("�������̫�����޷���ϰ����ǧҶ�֡�\n");
	if (me->query_skill("fengyun-hand", 1) < 20 ||
		me->query_skill("luohan-cuff", 1) < 20)
		return notify_fail("�㻹δ���շ����ֺ��޺�ȭ���޷�ѧϰ����ǧҶ�֡�\n");
	return 1;
}
int practice_skill(object me)
{
	if ((int)me->query("qi") < 40)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 40)
		return notify_fail("�����������������ǧҶ�֡�\n");
	me->receive_damage("qi", 35);
	me->add("neili", -25);
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
	int d_e1 = -45;
	int d_e2 = -15;
	int p_e1 = 15;
	int p_e2 = 45;
	int f_e1 = 150;
	int f_e2 = 250;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("qianye-hand", 1);
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
int success() { return 10; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	 return __DIR__"qianye-hand/" + action;
}

int help(object me)
{
	write(HIC"\n����ǧҶ�֣�"NOR"\n");
	write(@HELP

    ����ǧҶ�����������ַ�����Τ���ƻ��������ԡ���չǧ�ַ�����

	ѧϰҪ��
		վ׮��20��
		�޺�ȭ20��
		������20��
		������Ϊ50
HELP
	);
	return 1;
}


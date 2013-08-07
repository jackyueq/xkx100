// jueming-leg.c ������
// Last Modifyed by Winder on Jan. 14 2002

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$n���ҽŹ���$N������̣�$N��űܿ�$n��â��һ�С��ڻ���ɽ����\nѸ�������������߻�$n��$l��",
	"lvl"   : 0,
	"skill_name" : "�ڻ���ɽ" 
]),
([	"action" : "$n��ȭ��$Nͷ����$N���������ͬʱ���ҽ��͵�$n����������Գ��֦����\nͻȻ������������߻�$n$l��",
	"lvl"   : 10,
	"skill_name" : "��Գ��֦" 
]),
([	"action" : "$N��ȭ�ò�$nȭͷ���ҽ��ڲ�Ȼ�$n���ֹǣ�һ�С���β���֡�\n�����ȹ���$n$l",
	"lvl"   : 20,
	"skill_name" : "��β����" 
]),
([	"action" : "$N���ҽŹ���$n�������̣�ͬʱ�ҹ���ͻȻ��ɨ$n������һ�С�����Ҷ��",
	"lvl"   : 30,
	"skill_name" : "����Ҷ" 
]),
([	"action" : "$n����ȭ�ͻ�$N�沿��$N����������ȹ���$n�󲿣�һ�С����˷�������\n��Ϊ��������$n��$l",
	"lvl"   : 40,
	"skill_name" : "���˷���" 
]),
([	"action" : "$Nͻ�����ȵ���$n�ɲ������������򡹣������ٱ��������߻�$n֮$l",
	"lvl"   : 60,
	"skill_name" : "��������" 
]),
([	"action" : "$N���ҽŹ���$n�����ʹ����˳�糶�졹��˳�Ʊ�Ϊ���ȣ��൹��ɨ$n$l",
	"lvl"   : 80,
	"skill_name" : "˳�糶��" 
]),
([	"action" : "$N���ҽŵ���$n������һ�С�Ұ���㡹������֮�ȼ���Ϊ�����ȣ���������$n$l",
	"lvl"   : 100,
	"skill_name" : "Ұ����" 
]),
});

int valid_enable(string usage) { return  usage=="leg" || usage=="parry"; }
int valid_combine(string combo) { return combo=="huagu-mianzhang"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�������ȱ�����֡�\n");
	if ((int)me->query_skill("dulong-dafa", 1) < 20)
		return notify_fail("��Ķ����󷨻������޷�ѧ�����ȡ�\n");
	if ((int)me->query_skill("leg", 1) < 20)
		return notify_fail("��Ļ����ȷ��������޷�ѧ�����ȡ�\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷��������ȡ�\n");
	return 1;
}
int practice_skill(object me)
{
	if ((int)me->query("qi") < 40)
		return notify_fail("�����Ѫ̫���ˡ�\n");
	if ((int)me->query("neili") < 10)
		return notify_fail("������������������ȡ�\n");
	me->receive_damage("qi", 30);
	me->add("neili", -5);
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
	int f_e1 = 220;
	int f_e2 = 320;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("jueming-leg", 1);
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
int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 5; }
int power_point(object me) { return 1.0; }
string perform_action_file(string action)
{
	return __DIR__"jueming-leg/" + action;
}

int help(object me)
{
	write(HIC"\n������"NOR"\n");
	write(@HELP

    �����������������ȷ������뻯�����ƻ�����

	ѧϰҪ��
		������20��
		�����ȷ�20��
		������Ϊ100
HELP
	);
	return 1;
}


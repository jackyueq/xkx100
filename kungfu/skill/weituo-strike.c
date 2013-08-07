// Last Modified by winder on May. 29 2001
// weituo-strike.c Τ���� ������ǧҶ�ֻ���

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N˫��΢��������΢΢������˫�����ƣ�һ��"HIC"������ٵء�"NOR"��һ����ɽ֮��ѹ��$n",
	"lvl"   : 0,
	"skill_name" : "����ٵ�"
]),
([	"action" : "$N���а����ӷ�һ��"HIW"���������ա�"NOR"�����ƻ���$n���ţ���һ��ȴ����$n��С��",
	"lvl"   : 15,
	"skill_name" : "��������"
]),
([	"action" : "$N˫�ƻ������Ī�⣬һ��"MAG"��������ɫ��"NOR"��˲Ϣ֮����$n����������һʮ����",
	"lvl"   : 30,
	"skill_name" : "������ɫ"
]),
([	"action" : "$N����һ�ƣ�û�а�����ף�һ��"HIY"�����ޱߡ�"NOR"���͵���$n��$l�����ȥ",
	"lvl"   : 40,
	"skill_name" : "���ޱ�"
]),
([	"action" : "$N˫�ƽ����������ޣ�һ��"HIB"��˭�������"NOR"�����ž�������$n�ļ�ͷ��ǰ��",
	"lvl"   : 50,
	"skill_name" : "˭�����"
]),
([	"action" : "$Nһ��"HIM"������������"NOR"������һ�ƻ�����������������һ�����$n��$l",
	"lvl"   : 60,
	"skill_name" : "��������"
]),
([	"action" : "$N˫���ڿ����뻮������˫�����ƣ�һ��"HIR"���ҷ�ȱ���"NOR"��һ����ɽ������������ֱ��$n����",
	"lvl"   : 70,
	"skill_name" : "�ҷ�ȱ�"
]),
([	"action" : "$NͻȻ���м�ת��һ��"GRN"���ຣ��ͷ��"NOR"����Ӱ���裬��ʱ֮�佫$n����˷�����ס��",
	"lvl"   : 80,
	"skill_name" : "�ຣ��ͷ"
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }
int valid_combine(string combo) { return combo=="qianye-hand"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��Τ���Ʊ�����֡�\n");
	if ((int)me->query_skill("zhanzhuang-gong", 1) < 20)
		return notify_fail("���վ׮����򲻹����޷���Τ���ơ�\n");
	if ((int)me->query_skill("luohan-cuff", 1) < 20)
		return notify_fail("����޺�ȭ��򲻹����޷���Τ���ơ�\n");
	if ((int)me->query("max_neili") < 50)
		return notify_fail("�������̫�����޷���Τ���ơ�\n");
	return 1;
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("�������������Τ���ơ�\n");
	me->receive_damage("qi", 25);
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
	int d_e1 = -10;
	int d_e2 = 10;
	int p_e1 = 30;
	int p_e2 = 60;
	int f_e1 = 100;
	int f_e2 = 200;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("weituo-strike", 1);
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
int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 20; }
int power_point(object me) { return 1.0; }

int help(object me)
{
	write(HIC"\nΤ���ƣ�"NOR"\n");
	write(@HELP

    Τ�����������������Ʒ���������ǧҶ�ֻ�����

	ѧϰҪ��
		վ׮��20��
		�޺�ȭ20��
		������Ϊ50
HELP
	);
	return 1;
}


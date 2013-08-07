// kunlun-strike.c ������

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N�Ʒ缤����˫�ƴ��䣬���������޷���һ��"HIY"�������ɽ��"NOR"������$n��$l",
	"lvl" : 0,
	"skill_name" : "�����ɽ"
]),
([	"action" : "$N˫������һ��"HIC"�������Ƶ���"NOR"��һ�ƻ���$n���ţ���һ��ȴ����$nС��",
	"lvl" : 20,
	"skill_name" : "�����Ƶ�"
]),
([	"action" : "$N˫�ƻ������Ī�⣬һ��"HIC"����粻����"NOR"��ǰ�����ң�˲Ϣ֮����$n����������һʮ����",
	"lvl" : 38,
	"skill_name" : "��粻��"
]),
([	"action" : "$Nһ����Х������һ�ƣ�һ��"HIB"��ɽ��·ת��"NOR"������ת׾��ȴ��ȥ����죬��$n��$l�ͻ���ȥ��",
	"lvl" : 55,
	"skill_name" : "ɽ��·ת"
]),
([	"action" : "$N˫�ƽ����������ޣ�һ��"BLU"�������޷졹"NOR"������$n��$l",
	"lvl" : 72,
	"skill_name" : "�����޷�"
]),
([	"action" : "$Nһ��"GRN"����ɽ�Ϻӡ�"NOR"������һȭ���������ƽ���������ȭ��һ����˫������������$n��$l",
	"lvl" : 87,
	"skill_name" : "��ɽ�Ϻ�"
]),
([	"action" : "$N˫���뻮������˫�����ƣ�һ��"MAG"�������ء�"NOR"��һ����ɽ������������ֱ��$n����",
	"lvl" : 101,
	"skill_name" : "������"
]),
([	"action" : "$NͻȻ�������ת��һ��"HIW"����ɽѩƮ��"NOR"����Ӱ���裬��ʱ֮�佫$n����˷�����ס��",
	"lvl" : 120,
	"skill_name" : "��ɽѩƮ"
])
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }
int valid_learn(object me)
{
	mapping fam = me->query("family");
	if (fam["family_name"] != "������" || fam["generation"] != 2)
		return notify_fail("������ֻ�ܴӺ������ѧ����\n");
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�������Ʊ�����֡�\n");
	if ((int)me->query_skill("xuantian-wuji", 1) < 120)
		return notify_fail("��������޼�����򲻹����޷��������ơ�\n");
	if(me->query("gender")!="Ů��")
	{
		if ((int)me->query_skill("zhentian-cuff", 1) < 80)
			return notify_fail("�����ع����򲻹����޷��������ơ�\n");
	} else
	{
		if ((int)me->query_skill("chuanyun-leg", 1) < 80)
			return notify_fail("�����ع����򲻹����޷��������ơ�\n");
	}
	if ((int)me->query("max_neili") < 800)
		return notify_fail("���������Ϊ�������޷��������ơ�\n");
	return 1;
}
int practice_skill(object me)
{
	int lvl = me->query_skill("kunlun-strike", 1);
	int i = sizeof(action);

	while (i--) if (lvl == action[i]["lvl"]) return 0;

	if ((int)me->query("qi") < 50)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("������������������ơ�\n");
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
	int d_e1 = -30;
	int d_e2 = -10;
	int p_e1 = 10;
	int p_e2 = 40;
	int f_e1 = 160;
	int f_e2 = 260;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("kunlun-strike", 1);
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
int learn_bonus() { return 25; }
int practice_bonus() { return 25; }
int success() { return 15; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"kunlun-strike/" + action;
}

int help(object me)
{
	write(HIC"\n�����Ʒ���"NOR"\n");
	write(@HELP

    �����Ʒ�Ϊ�������ϳ˾�����

	ѧϰҪ��
		�����޼���120��
		����ȭ��������80��
		����800
		������ĵմ�����
HELP
	);
	return 1;
}


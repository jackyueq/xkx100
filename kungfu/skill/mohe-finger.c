// Last Modified by Winder on May. 29 2001
// mohe-finger.c Ħڭָ ��ɢ���ƻ��� �������С��Դȶ��ģ�Ħڭ������һ�䡣

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N����һ�ڣ�������ǰ����������ʳָ����һ��"HIB"���ԡ�"NOR"�֣��������$n$l",
	"lvl"   : 0,
	"skill_name" : "��"
]),
([	"action" : "$N����ʳָ�������˸�"HIM"���ȡ�"NOR"�֣�������ָ΢��������Ϊ���ģ�����$nһ��",
	"lvl"   : 20,
	"skill_name" : "��"
]),
([	"action" : "$N˫�ƺ�ʮ������΢Ƿ��˫ָ��һ"HIG"���ȡ�"NOR"�֣���Ʋ����������������֦�㣬����$n$l",
	"lvl"   : 30,
	"skill_name" : "��"
]),
([	"action" : "$N˫��Сָ��$n�Ӷ����������㣬����˫ָ��£��һ��б����ƴ����һ��"HIR"���ġ�"NOR"��",
	"lvl"   : 50,
	"skill_name" : "��"
]),
([	"action" : "$N�������У��ó�����ָӰ���·�侹Ȼ�γ���һ��"HIC"��Ħ��"NOR"�֣�����$n�����ȥ��Խ��Խ��",
	"lvl"   : 60,
	"skill_name" : "Ħ"
]),
([	"action" : "$N����ʳָ������ڿ���д����"HIW"��ڭ��"NOR"�����������ݣ�����$n���һ��ʱ�������һ������",
	"lvl"   : 70,
	"skill_name" : "ڭ"
]),
([	"action" : "ֻ��$N��ָ������������ָ���ڿ������᲻ɢ���γ�һ��"CYN"���ޡ�"NOR"�֣�����$n����ѹ��",
	"lvl"   : 80,
	"skill_name" : "��"
]),
([	"action" : "$N˫ȭ��£���г�һ��"HIY"������"NOR"��������������$n��ͻȻ�°���һ�䣬����һָ�ƿջ���",
	"lvl"   : 100,
	"skill_name" : "��"
]),
});

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }
int valid_combine(string combo){ return combo=="sanhua-strike"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��Ħڭָ������֡�\n");
	if ((int)me->query_skill("zhanzhuang-gong", 1) < 30)
		return notify_fail("���վ׮����򲻹����޷�ѧĦڭָ��\n");
	if ((int)me->query("max_neili") < 200)
		return notify_fail("�������̫�����޷���Ħڭָ��\n");
	if (me->query_skill("weituo-strike", 1) < 30)
		return notify_fail("���Τ���ƻ�򲻹����޷�ѧĦڭָ��\n");
	return 1;
}
int practice_skill(object me)
{
	if ((int)me->query("qi") < 40)
		return notify_fail("��ľ���̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("�������������Ħڭָ��\n");
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
	int d_e1 = 40;
	int d_e2 = 60;
	int p_e1 = -20;
	int p_e2 = 0;
	int f_e1 = 100;
	int f_e2 = 200;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("mohe-finger", 1);
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

string perform_action_file(string action)
{
	 return __DIR__"mohe-finger/" + action;
}

int help(object me)
{
	write(HIC"\nĦڭָ��"NOR"\n");
	write(@HELP

    Ħڭָ������������ָ������ɢ���ƻ��������Է��С��Դȶ��ģ�Ħڭ��������

	ѧϰҪ��
		վ׮��30��
		Τ����30��
		������Ϊ200
HELP
	);
	return 1;
}


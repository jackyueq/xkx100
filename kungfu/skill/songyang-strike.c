// songyang-strike.c ��������
// Last Modified by sir 10.22.2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N����΢Ƿ���й�һ�ƻ����ĳ������������Ǵ����Ʒ�������ʽ"HIR"����������"NOR"",
	"lvl" : 0,
	"skill_name" : "������"
]),
([	"action" : "$N��ȭ���ƣ���ָ��ץ��һʽȡ����ɽ���ٵ�"HIC"�����ˮ��"NOR"������$n��Ƭ�̼��ѱ���ʮ��������",
	"lvl" : 10,
	"skill_name" : "���ˮ"
]),
([	"action" : "$N���һ����ʹ��һ·�������Ʒ��е�"BLU"����������"NOR"��˫�����·��ɡ��󿪴��أ���������$n",
	"lvl" : 30,
	"skill_name" : "������"
]),
([	"action" : "$N�˾��ڱۣ����һ��"HIB"�������֡�"NOR"�������ĳ������ֳ�ץ��ͬʱϮ�������ɾ�����ɽ��������$nѹ�˹���",
	"lvl" : 50,
	"skill_name" : "������",
]),
([	"action" : "$N������֮���ͺ�һ����һʽ"GRN"����ʤ�塹"NOR"������Ю���ſ�磬��ǰб�ƣ���������ɽ���ư�ѹ��$n",
	"lvl" : 70,
	"skill_name" : "��ʤ��"
]),
([	"action" : "$N˫�ֺ���ץ��������������ȭ�������ƣ��������֣�ʹһ��"MAG"��С������"NOR"�ַ�������һ�Σ�������$n��$l��ȥ",
	"lvl" : 90,
	"skill_name" : "С����"
]),
([	"action" : "$N���������Ȼŭ��һ������ǰһ��������˫�ƺϳ�"HIM"������բ��"NOR"�����ŷ���֮����������$n",
	"lvl" : 110,
	"skill_name" : "����բ"
]),
([	"action" : "$N������ǰ������һ��"CYN"��ǧ��Ԩ��"NOR"�����ֻ�ȭΪ�ƣ�����ʮ�㣬����������������$n",
	"lvl" : 130,
	"skill_name" : "ǧ��Ԩ"
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }
int valid_combine(string combo) { return combo=="poyun-hand"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("���������Ʊ�����֡�\n");
	if ((int)me->query_skill("hanbing-zhenqi", 1) < 10)
		return notify_fail("��ĺ���������򲻹����޷�ѧ�������ơ�\n");
	if ((int)me->query("max_neili") < 10)
		return notify_fail("�������̫�����޷����������ơ�\n");
	return 1;
}
int practice_skill(object me)
{
	if ((int)me->query("qi") < 50)
		return notify_fail("��ľ���̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("��������������������ơ�\n");
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
	int d_e2 = -10;
	int p_e1 = 10;
	int p_e2 = 35;
	int f_e1 = 170;
	int f_e2 = 270;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("songyang-strike", 1);
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
	return __DIR__"songyang-strike/" + action;
}

int help(object me)
{
	write(HIC"\n�������ƣ�"NOR"\n");
	write(@HELP

    ��������Ϊ��ɽ����ɽ�Ʒ������������ֻ�����

	ѧϰҪ��
		��������10��
		����10
HELP
	);
	return 1;
}


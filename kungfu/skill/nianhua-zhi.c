// nianhua-zhi.c -�黨ָ

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N����̧�ۣ���ָ���˸���Ȧ��һʽ"HIG"��ƿ�����⡹"NOR"����$n��$l",
	"lvl" : 0,
	"skill_name" : "ƿ������"
]),
([	"action" : "$N�������У�һʽ"MAG"����÷���"NOR"����ָ��Ҹ������ָ��$n����ǰ",
	"lvl" : 10,
	"skill_name" : "��÷����"
]),
([	"action" : "$N����б�У����ְ��ƣ�����һʽ"BLU"�������ʾơ�"NOR"����$n��$l����",
	"lvl" : 20,
	"skill_name" : "�����ʾ�"
]),
([	"action" : "$N˫Ŀ΢����һʽ"RED"��¶��б����"NOR"��˫�ֻû���ǧ�ٸ�ָӰ������$n��$l",
	"lvl" : 30,
	"skill_name" : "¶��б��"
]),
([	"action" : "$Nһʽ"HIB"�����³��ء�"NOR"�����ƻ�ס�������бָ���죬���Ƶ���$n��$l",
	"lvl" : 40,
	"skill_name" : "���³���"
]),
([	"action" : "$N˫��ƽ����ǰ��ʮָ�濪��һʽ"CYN"��Ҷ��������"NOR"��ָ��$n�������Ѩ",
	"lvl" : 50,
	"skill_name" : "Ҷ������"
]),
([	"action" : "$N˫�Ʒ��ɣ�һʽ"HIW"��������"NOR"��ָ�˱ų�����������������$n��ȫ��",
	"lvl" : 60,
	"skill_name" : "������"
]),
([	"action" : "$Nһʽ"YEL"��������˪��"NOR"����ָ���У�һ����������ٱ�ĵ�����������$n��$l��ȥ",
	"lvl" : 70,
	"skill_name" : "������˪"
]),
([	"action" : "$Nһʽ"HIG"��٤Ҷ΢Ц��"NOR"��˫��ʳָ���棬ָ�����һ�����������$n��$l",
	"lvl" : 80,
	"skill_name" : "٤Ҷ΢Ц"
]),
([	"action" : "$N����������ǰ��һʽ"HIY"�������黨��"NOR"������ʳָ��סĴָ���������$nһ��",
	"lvl" : 90,
	"skill_name" : "�����黨"
])
});

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }
int valid_combine(string combo) { return combo=="sanhua-zhang"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("���黨ָ������֡�\n");
	if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
		return notify_fail("��Ļ�Ԫһ������򲻹����޷�ѧ�黨ָ��\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷����黨ָ��\n");
	return 1;
}
int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("��������������黨ָ��\n");
	me->receive_damage("qi", 35);
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
	int d_e1 = 35;
	int d_e2 = 55;
	int p_e1 = -25;
	int p_e2 = -5;
	int f_e1 = 220;
	int f_e2 = 320;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("nianhua-zhi", 1);
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
	return __DIR__"nianhua-zhi/" + action;
}
int help(object me)
{
	write(HIC"\n�黨ָ��"NOR"\n");
	write(@HELP

    �黨ָΪ������ʮ������֮һ��
    ������Ҷ��������ɽ����𷨣��黨΢Ц�����黨ָ��ȡ����
���������
    ����ɢ���ƻ�����

	ѧϰҪ��
		��Ԫһ����20��
		����100
HELP
	);
	return 1;
}


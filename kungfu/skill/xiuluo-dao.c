// xiuluo-dao.c ���޵�
// Last Modified by sega on Mar. 10 2000

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N�ص����գ�һ��"HIY"��������ӥ��"NOR"���������¶��ϻ��˸��뻡����$n��
$l��ȥ",
	"lvl" : 0,
	"skill_name" : "������ӥ",
]),
([	"action" : "$N�����������⣬һ��"MAG"��Ͷ�������"NOR"������$w��ֱ����$n��$l",	
	"lvl" : 10,
	"skill_name" : "Ͷ�����",
]),
([	"action" : "$Nһ��"BLU"���ͷл�졹"NOR"��$w�ƾ�������ˢ��һ�����϶�����$n����",
	"lvl" : 20,
	"skill_name" : "�ͷл��",
]),
([	"action" : "$N���ַ�ִ������һ��"HIW"���۹ǳ��衹"NOR"����һ����$wֱ��$n�ľ���ն
ȥ",
	"lvl" : 30,
	"skill_name" : "�۹ǳ���",
]),
([	"action" : "$Nһ��"GRN"������ǧ�ơ�"NOR"���������⻯����㷱�ǣ���$n��$l��ȥ",	
	"lvl" : 40,
	"skill_name" : "����ǧ��",
]),
([	"action" : "$N˫�ֺ�ִ$w��һ��"BLU"�����۲�ʩ��"NOR"��š��ת������ֱ����$n��˫��
",
	"lvl" : 50,
	"skill_name" : "���۲�ʩ",
]),
([	"action" : "$Nһ��"CYN"����Ƥ�龭��"NOR"������$w����һ����ƽʮ�֣���$n�ݺ���ȥ",
	"lvl" : 60,
	"skill_name" : "��Ƥ�龭",
]),
([	"action" : "$N��ת�����׼�Լ���һ��"RED"�����ľ�־��"NOR"��ȫ��һ��������$w��$n��
��նȥ",
	"lvl" : 70,
	"skill_name" : "���ľ�־",
]),
([	"action" : "$Nһ��"HIB"��������"NOR"��$w�ĵ���·𻯳�һ�ش����棬��$n����Χ��
",
	"lvl" : 80,
	"skill_name" : "������",
]),
([	"action" : "$N����ƽָ��һ��"HIR"����Ѫ���ء�"NOR"��һƬƬ�йǵ�����쫷�����$n��
ȫ��",
	"lvl" : 90,
	"skill_name" : "��Ѫ����",
]),
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; } 
int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 50)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("hunyuan-yiqi", 1) < 10)
		return notify_fail("��Ļ�Ԫһ�������̫ǳ��\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("����������������޵���\n");
	me->receive_damage("qi", 35);
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
	int d_e2 = 20;
	int p_e1 = -10;
	int p_e2 = -30;
	int f_e1 = 100;
	int f_e2 = 150;
	int m_e1 = 130;
	int m_e2 = 240;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int)me->query_skill("xiuluo-dao", 1);
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
		"damage_type" : random(2) ? "����" : "����",
	]);
}
int learn_bonus() { return 10; }
int practice_bonus() { return 5; }
int success() { return 10; }
int power_point(object me) { return 1; }

int help(object me)
{
	write(HIC"\n���޵���"NOR"\n");
	write(@HELP

    ���޵�Ϊ������ʮ������֮һ��

	ѧϰҪ��
		��Ԫһ����10��
		����50
HELP
	);
	return 1;
}


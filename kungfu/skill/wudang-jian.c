// wudang-jian.c �䵱����
// Last Modified by sir 10.21.2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"skill_name" :  "��������",
	"action" : "$N������ת�����ֽ�ָ��������ϥ����ǰ������������ǰ��һ�紦�̴ٶ�������һ��"HIB"���������֡�"NOR"������$w���������һ�����϶�������$n��$l",
	"lvl" : 0
]),
([	"skill_name" :  "������ˮ",
	"action" : "$N���β�������ǰ�������������ϱ������������󹭲���һ��"HIG"��������ˮ��"NOR"������$w��ǰ�·��̣�һ��ָ��$n��$l",
	"lvl" : 10
]),
([	"skill_name" :   "���ֿ��",
	"action" : "$N�����ǰһ�����ŵ����������ڿռ�����ת������$w����ǰ�̣���ת�����ʹ��һʽ"MAG"�����ֿ�ѡ�"NOR"��������ƥ����й��$n��$l",
	"lvl" : 20
]),
([	"skill_name" :   "��������",
	"action" : "$N�鲽�������ὣ�ؽ��������ϱ���һ��"HIW"���������š�"NOR"ֱȡ$n��$l",
	"lvl" : 30
]),
([	"skill_name" :   "��Ů����",
	"action" : "$Nƽ��бϴ����Բ��ֱ��˫�Ž��满������������$wʹ��һʽ"HIC"����Ů����"NOR"������������ת�������಻������$n��$l",
	"lvl" : 40
]),
([	"skill_name" :   "����ָ·",
	"action" : "$N����̧�ۣ�����ǰ����Ϸ������ͦ����ƽ��������ǰ������$wʹ��һʽ"HIY"������ָ·��"NOR"����$n��$l",
	"lvl" : 50
]),
([	"skill_name" :  "���б���",
	"action" : "$N�󳷲����������أ��ӽ���Բ���Σ���������������$wһʽ"HIG"�����б��¡�"NOR"������Բ�󣬴���$n��$l",
	"lvl" : 60
]),
([	"skill_name" :   "������",
	"action" : "$N�����˲������ֽ�ָ��ת������һŤ���������������$wһ��"HIM"����������"NOR"��������ָ��$n��$l",
	"lvl" : 70
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }
int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 10)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("taiji-shengong", 1) < 10)
		return notify_fail("���̫���񹦻��̫ǳ��\n");
	if ((int)me->query_skill("sword", 1) < 10)
		return notify_fail("��Ļ����������̫ǳ��\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("qi") < 30 || (int)me->query("neili") < 10 )
		return notify_fail("������������������䵱������\n");
	me->receive_damage("qi", 30);
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
	int d_e1 = 35;
	int d_e2 = 55;
	int p_e1 = 5;
	int p_e2 = 25;
	int f_e1 = 50;
	int f_e2 = 100;
	int m_e1 = 20;
	int m_e2 = 120;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("wudang-jian", 1);
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
int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 20; }
int power_point(object me) { return 1.0; }

int help(object me)
{
	write(HIC"\n�䵱������"NOR"\n");
	write(@HELP

    �䵱����Ϊ�䵱�����Ž�����

	ѧϰҪ��
		̫����10��
		��������10��
		����10
HELP
	);
	return 1;
}


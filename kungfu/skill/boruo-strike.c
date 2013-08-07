// Last Modified by Winder on May. 29 2001
// boruo-strike.c ������ ����צ������ ȡ�Է��š�ʮԸ����

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N���Ƚż��ض�����һʽ"HIY"�������"NOR"�����ƺ�ʮ�����ֱ��������$nȫ��",
	"lvl"   : 0,
	"skill_name" : "�����"
]),
([	"action" : "$N���ƻ�һ��Բ���أ�һʽ"YEL"������������"NOR"�����ƻ���б������������$n$l",
	"lvl"   : 10,
	"skill_name" : "��������"
]),
([	"action" : "$Nʹһʽ"HIB"�����޹�����"NOR"�����������������ɺ����һ��˦�ģ�����$n��ǽ����",
	"lvl"   : 30,
	"skill_name" : "���޹���"
]),
([	"action" : "$N���ƻ��أ���ȭ������һʽ"MAG"�����ҵ�ϡ�"NOR"������������������ƻ�������$n$l",
	"lvl"   : 50,
	"skill_name" : "���ҵ��"
]),
([	"action" : "$Nʹһʽ"BLU"����ת���֡�"NOR"��ȫ�������ת������ɾ�˫��һǰһ���͵ذ���$n���ؿ�",
	"lvl"   : 60,
	"skill_name" : "��ת����"
]),
([	"action" : "$N���Ʊ�������һ������һʽ"HIM"����ϲ���¡�"NOR"��ȫ�����������������˫�Ƽ���$n",
	"lvl"   : 80,
	"skill_name" : "��ϲ����"
]),
([	"action" : "$N���ϸ߸�Ծ��һʽ"RED"�����������"NOR"������Ӹ����£���ɢ������������������$n��ȫ��",
	"lvl"   : 100,
	"skill_name" : "�������"
]),
([	"action" : "$Nʹһʽ"HIR"����˳������"NOR"��˲�侢��������$P˫���������֣�һ������$n��$lնȥ",
	"lvl"   : 120,
	"skill_name" : "��˳����"
]),
([	"action" : "$N�������»��أ�һʽ"HIC"���սԻ���"NOR"�ĳ�����Ӱ���ص����������ޱ��������$n",
	"lvl"   : 150,
	"skill_name" : "�սԻ���"
]),
});
int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }
int valid_combine(string combo){ return combo=="dragon-claw"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�������Ʊ�����֡�\n");
	if ((int)me->query_skill("zhanzhuang-gong", 1) < 80)
		return notify_fail("���վ׮����򲻹����޷�ѧ�����ơ�\n");
	if ((int)me->query("max_neili") < 800)
		return notify_fail("�������̫�����޷��������ơ�\n");
	if ((me->query_skill("nianhua-finger", 1) < 50) ||
		(me->query_skill("jingang-strike", 1) < 50))
		return notify_fail("��Ĵ������ƺ��黨ָ��򲻹����޷�ѧ�����ơ�\n");
	return 1;
}
int practice_skill(object me)
{
	if ((int)me->query("qi") < 55)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 35)
		return notify_fail("������������������ơ�\n");
	me->receive_damage("qi", 50);
	me->add("neili", -30);
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
	int d_e1 = -50;
	int d_e2 = -30;
	int p_e1 = -10;
	int p_e2 = 20;
	int f_e1 = 260;
	int f_e2 = 360;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("banruo-strike", 1);
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
int learn_bonus() { return 5; }
int practice_bonus() { return 5; }
int success() { return 5; }
int power_point(object me) { return 1.0; }
string perform_action_file(string action)
{
	return __DIR__"boruo-strike/" + action;
}

int help(object me)
{
	write(HIC"\n�����ƣ�"NOR"\n");
	write(@HELP

    ���������������Ʒ�������צ��������
    ���Է��š�ʮԸ����

	ѧϰҪ��
		վ׮��80��
		�黨ָ50��
		��������50��
		������Ϊ800
HELP
	);
	return 1;
}


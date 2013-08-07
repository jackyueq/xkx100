// Last Modified by winder on May. 29 2001
// wuchang-staff.c �޳��ȷ�

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action": "$N΢һ����һ��"GRN"��ӹ�����š�"NOR"��$w"NOR"���Ŵ̶���֨֨��������ɨ��$n�Ľ���",
	"lvl" : 0,
	"skill_name" : "ӹ������"
]),
([	"action": "$Nһ��"CYN"������Ƿǡ�"NOR"��������ס�ȶˣ����ƾ���һ��������ƾ���Ե���$n�ļ�ͷ",
	"lvl" : 7,
	"skill_name" : "����Ƿ�"
]),
([	"action": "$Nһ��"RED"�����񲻰���"NOR"������$w"NOR"ƹƹ���ҵ��������ã���$n�����ұܣ��Ǳ�����",
	"lvl" : 14,
	"skill_name" : "���񲻰�"
]),
([	"action": "$Nһ��"MAG"��������ɫ��"NOR"������$w"NOR"�������ض���һ�ᣬͻȻ�͵�һ�ȴ���$n��$l",
	"lvl" : 20,
	"skill_name" : "������ɫ"
]),
([	"action": "$N��$w"NOR"��ס�Լ������ţ�һ��ָ��$n��һ��"YEL"���ľ�������"NOR"�������к��ų���$n",
	"lvl" : 25,
	"skill_name" : "�ľ�����"
]),
([	"action": "$Nһ��"BLU"����ʬ���⡹"NOR"��ȫ��ֱ�������ų���ǰ�У��䲻������������$n��ȥ",
	"lvl" : 30,
	"skill_name" : "��ʬ����"
]),
([	"action": "$N�����ɫ��һ��"GRN"������������"NOR"����$n˵���䣬һ����$n�Ŵ�����ͱ�˹�ȥ",
	"lvl" : 35,
	"skill_name" : "��������"
]),
([	"action": "$Nһ��"YEL"���������ġ�"NOR"�����⽫$w"NOR"ˤ����ϣ���$n������һ�Ź��𣬻���$n��$l",
	"lvl" : 40,
	"skill_name" : "��������"
]),
([	"action": "$N����װ����һ��"MAG"����;û·��"NOR"��һ������������$w"NOR"��������������$n���ɲ�",
	"lvl" : 45,
	"skill_name" : "��;û·"
]),
([	"action": "$Nһ��"BLU"������ľ����"NOR"���������Ų��ƣ�$w"NOR"ȴֱ�ɰ�գ���ƫ���е�����$n��$l",
	"lvl" : 50,
	"skill_name" : "����ľ��"
]),
([	"action": "$N�߾�$w��һ��"HIB"���˹���;��"NOR"����������Ȱ�Ʈ������׼$n�������һ�ȴ���",
	"lvl" : 55,
	"skill_name" : "�˹���;"
]),
([	"action": "$Nһ��"HIR"�����������"NOR"�����ȶ�����$w"NOR"���ǧ�ٸ����ƣ���������$nȫ�����Ҫ��",
	"lvl" : 60,
	"skill_name" : "�������"
]),
});

int valid_enable(string usage) { return usage == "staff" || usage == "parry"; }
int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 500)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("zhanzhuang-gong", 1) < 50)
		return notify_fail("���վ׮�����̫ǳ��\n");
	if ((int)me->query_skill("pudu-staff", 1) < 20)
		return notify_fail("����ն��ȷ����̫ǳ��\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "staff")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("qi") < 40 || (int)me->query("neili") < 30 )
		return notify_fail("������������������޳��ȷ���\n");
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
	int d_e1 = -35;
	int d_e2 = -5;
	int p_e1 = 20;
	int p_e2 = 55;
	int f_e1 = 250;
	int f_e2 = 300;
	int m_e1 = 160;
	int m_e2 = 260;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("wuchang-staff", 1);
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
		"damage_type" : "����",
	]);
}
int learn_bonus() { return 20; }
int practice_bonus() { return 20; }
int success() { return 15; }
int power_point(object me) { return 1.0; }

int help(object me)
{
	write(HIC"\n�޳��ȷ���"NOR"\n");
	write(@HELP

    �޳��ȷ��������ָ߼��ȷ���

	ѧϰҪ��
		վ׮��50��
		�ն��ȷ�20��
		������Ϊ500
HELP
	);
	return 1;
}


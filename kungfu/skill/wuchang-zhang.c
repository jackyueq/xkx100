// wuchang-zhang.c �޳��ȷ�
// Last Modified by sir 10.22.2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action":"$N΢һ����һ��"HIG"��ӹ�����š�"NOR"��$w���Ŵ̶���֨֨��������ɨ��$n�Ľ���",
	"lvl" : 0,
	"skill_name" : "ӹ������"
]),
([	"action":"$Nһ��"HIM"������Ƿǡ�"NOR"��������ס�ȶˣ����ƾ���һ��������ƾ���Ե���$n�ļ�ͷ",
	"lvl" : 7,
	"skill_name" : "����Ƿ�"
]),
([	"action":"$Nһ��"HIR"�����񲻰���"NOR"������$wƹƹ���ҵ��������ã���$n�����ұܣ��Ǳ�����",
	"lvl" : 14,
	"skill_name" : "���񲻰�"
]),
([	"action":"$Nһ��"HIY"��������ɫ��"NOR"������$w�������ض���һ�ᣬͻȻ�͵�һ�ȴ���$n��$l",
	"lvl" : 20,
	"skill_name" : "������ɫ"
]),
([	"action":"$N��$w��ס�Լ������ţ�һ��ָ��$n��һ��"HIB"���ľ�������"NOR"�������к��ų���$n",
	"lvl" : 25,
	"skill_name" : "�ľ�����"
]),
([	"action":"$Nһ��"HIC"����ʬ���⡹"NOR"��ȫ��ֱ�������ų���ǰ�У��䲻������������$n��ȥ",
	"lvl" : 30,
	"skill_name" : "��ʬ����"
]),
([	"action":"$N�����ɫ��һ��"HIM"������������"NOR"����$n˵���䣬һ����$n�Ŵ�����ͱ�˹�ȥ",
	"lvl" : 35,
	"skill_name" : "��������"
]),
([	"action":"$Nһ��"HIW"���������ġ�"NOR"�����⽫$wˤ����ϣ���$n������һ�Ź��𣬻���$n��$l",
	"lvl" : 40,
	"skill_name" : "��������"
]),
([	"action":"$N����װ����һ��"HIG"����;û·��"NOR"��һ������������$w��������������$n���ɲ�",
	"lvl" : 45,
	"skill_name" : "��;û·"
]),
([	"action":"$Nһ��"HIR"������ľ����"NOR"���������Ų��ƣ�$wȴֱ�ɰ�գ���ƫ���е�����$n��$l",
	"lvl" : 50,
	"skill_name" : "����ľ��"
]),
([	"action":"$N�߾�$w��һ��"HIG"���˹���;��"NOR"����������Ȱ�Ʈ������׼$n�������һ�ȴ���",
	"lvl" : 55,
	"skill_name" : "�˹���;"
]),
([	"action":"$Nһ��"HIB"�����������"NOR"�����ȶ�����$w���ǧ�ٸ����ƣ���������$nȫ�����Ҫ��",
	"lvl" : 60,
	"skill_name" : "�������"
]),
});

int valid_enable(string usage) { return usage == "staff" || usage == "parry"; }
int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
		return notify_fail("��Ļ�Ԫһ�������̫ǳ��\n");
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
	int d_e1 = -40;
	int d_e2 = -5;
	int p_e1 = 20;
	int p_e2 = 50;
	int f_e1 = 250;
	int f_e2 = 300;
	int m_e1 = 170;
	int m_e2 = 270;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("wuchang-zhang", 1);
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

    �޳��ȷ�Ϊ������ʮ������֮һ��

	ѧϰҪ��
		��Ԫһ����20��
		����100
HELP
	);
	return 1;
}


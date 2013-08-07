// Last Modified by winder on May. 29 2001
// weituo-club.c Τ�ӹ�

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action":"$Nһ��"HIY"����ʯ���ġ�"NOR"������$w�����ѵ�ˮ�㣬������$n������Ҫ����ȥ
",
	"lvl"   : 0,
	"skill_name" : "��ʯ����"
]),
([	"action":"$N��$wƽ���ؿڣ�һš��һ��"HIG"������ͣ�桹"NOR"��$w�͵�����$n�ľ���",
	"lvl" : 8,
	"skill_name" : "����ͣ��"
]),
([	"action":"$Nһ��"HIY"��ƽ�����ɡ�"NOR"��ȫ���������ڵ��ϴ����ת���ٹ���$n���ظ�
���ȥ",
	"lvl" : 16,
	"skill_name" : "ƽ������"
]),
([	"action":"$N����һ��������һ��"HIM"���������硹"NOR"��$wЮ��������Ѹ��ɨ��$n������
",
	"lvl"   : 25,
	"skill_name" : "��������"
]),
([	"action":"$Nһ��"HIC"�����Ǹ��¡�"NOR"�������һ�����˱Ƴ�һ��ֱ�ߣ����ǰ�����$n
��$l",
	"lvl"   : 35,
	"skill_name" : "���Ǹ���"
]),
([	"action":"$N˫�ֳֹ����˸���ش�Ȧ��һ��"HIR"����ϼ���ա�"NOR"��һ����Բ�����л���
��ײ��$n���ؿ�",
	"lvl"   : 44,
	"skill_name" : "��ϼ����"
]),
([	"action":"$Nһ��"HIB"��Ͷ�޶�����"NOR"��$w�߾٣����������֮�ƶ�׼$n�����鵱ͷ����
",
	"lvl"   : 52,
	"skill_name" : "Ͷ�޶���"
]),
([	"action":"$NǱ��������һ��"HIY"�������麣��"NOR"��$w��ʱ�������ɣ�������ֱ��$n����
��",
	"lvl"   : 60,
	"skill_name" : "�����麣"
]),
});

int valid_enable(string usage) { return usage == "club" || usage == "parry"; }
int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("zhanzhuang-gong", 1) < 20)
		return notify_fail("���վ׮�����̫ǳ��\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "club")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("qi") < 50 || (int)me->query("neili") < 50 )
		return notify_fail("�����������������Τ�ӹ���\n");
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
	int d_e1 = -40;
	int d_e2 = -30;
	int p_e1 = 15;
	int p_e2 = 30;
	int f_e1 = 200;
	int f_e2 = 250;
	int m_e1 = 50;
	int m_e2 = 150;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("weituo-club", 1);
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
int learn_bonus() { return 15; }
int practice_bonus() { return 15; }
int success() { return 15; }
int power_point(object me) { return 1.0; }

int help(object me)
{
	write(HIC"\nΤ�ӹ���"NOR"\n");
	write(@HELP

    Τ�ӹ������������Ź�����

	ѧϰҪ��
		վ׮��20��
		������Ϊ100
HELP
	);
	return 1;
}


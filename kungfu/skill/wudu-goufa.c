// wudu-goufa.c �嶾����
// Last Modified by sir 10.22.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action":"$N����$wһ����һʽ"HIR"���������š�"NOR"�������ļ�����$n��$l",
	"lvl" : 0,
	"skill_name" : "��������"
]),
([	"action":"$Nһʽ"MAG"����˿��ϵ��"NOR"���������಻��������һ�����εĴ�����$n���ڵ���",
	"lvl" : 10,
	"skill_name" : "��˿��ϵ"
]),
([	"action":"$Nһ����Ц����������һʽ"BLU"��������צ��"NOR"������$w���裬�ó�ǧ�����ֱۣ���������$n",
	"lvl" : 25,
	"skill_name" : "������צ"
]),
([	"action":"$N����أ�����һ���������ߣ�����$wȴٿ�Ĵ�Ҹ�´�������
����$n��$l����һʽ"HIM"����Ы���롹"NOR"",
	"lvl" : 35,
	"skill_name" : "��Ы����"
]),
([	"action":"$N�Ų����ģ����κ�����ǰ������һʽ"HIC"���������¡�"NOR"������$w���¶���ֱ��$n��С��",
	"lvl" : 50,
	"skill_name" : "��������"
]),
([	"action":"$N����һ�Σ�һʽ"HIY"�����߲���"NOR"������$w�總��֮����������Ϣ�ش���$n������",
	"lvl" : 60,
	"skill_name" : "���߲���"
]),
([	"action":"\n$Nһ����Х�����γ������һʽ"HIG"�����ű䡹"NOR"������$w����Ȱ�����$nȫ��ŵ���Ѩ",
	"lvl" : 70,
	"skill_name" : "���ű�"
]),
([	"action":"$N����һ����˫���չ�������"GRN"��������"NOR"��$w���͸��һ��ǿ���ĺ�����������Ϯ��$n",
	"lvl" : 80,
	"skill_name" : "������"
]),
});

int valid_enable(string usage) { return usage == "hook" || usage == "parry"; }
int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("wudu-shengong", 1) < 20)
		return notify_fail("����嶾�񹦻��̫ǳ��\n");
	if ((int)me->query_skill("force", 1) < 20)
		return notify_fail("��Ļ����ڹ����̫ǳ��\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "hook")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("qi") < 50 || (int)me->query("neili") < 50 )
		return notify_fail("������������������嶾������\n");
	me->receive_damage("qi", 40);
	me->add("neili", -40);
	return 1;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	if( random(damage_bonus/2) > victim->query_con() )
	{
		victim->receive_wound("qi", damage_bonus/ 3 );
	}
	if ( victim->query("family/family_name")!= "�嶾��" &&
		me->query_skill("wudu-shengong",1)>40)
	{
		switch( random(5) )
		{
			case 0:
				victim->apply_condition("snake_poison", (me->query_skill("wudu-shengong"))/10 + victim->query_condition("snake_poison"));
				break;
			case 1:
				victim->apply_condition("zhizhu_poison", (me->query_skill("wudu-shengong"))/10 + victim->query_condition("zhizhu_poison"));
				break;
			case 2:
				victim->apply_condition("wugong_poison", (me->query_skill("wudu-shengong"))/10 + victim->query_condition("wugong_poison"));
				break;
			case 3:
				victim->apply_condition("xiezi_poison", (me->query_skill("wudu-shengong"))/10 + victim->query_condition("xiezi_poison"));
				break;
			case 4:
				victim->apply_condition("chanchu_poison", (me->query_skill("wudu-shengong"))/10 + victim->query_condition("chanchu_poison"));
				break;
		}
		return HIR "$nֻ�����˴�һ���飬�ƺ��ж��ˡ�\n" NOR;
	}
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
	int d_e2 = -20;
	int p_e1 = 20;
	int p_e2 = 50;
	int f_e1 = 100;
	int f_e2 = 200;
	int m_e1 = 200;
	int m_e2 = 400;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("wudu-goufa", 1);
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
int learn_bonus() { return 5; }
int practice_bonus() { return 5; }
int success() { return 5; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"wudu-goufa/" + action;
}
int help(object me)
{
	write(HIC"\n�嶾������"NOR"\n");
	write(@HELP

    �嶾�������嶾�̵Ĺ�����

	ѧϰҪ��
		�����ڹ�20��
		�嶾��20��
		����100
HELP
	);
	return 1;
}


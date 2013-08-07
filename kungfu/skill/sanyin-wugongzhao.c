//sanyin-wugongzhao.c �������צ
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$Nצ����ף��ǽ�¡�����϶���˺��$n��$l",
	"lvl"    : 0,
	"skill_name" : "�����צ" ,
]),
([	"action" : "$N˫�ֺ������֣�צצ���Ȱ�ץ��$n��$l",
	"lvl"    : 10,
	"skill_name" : "��Ӱ��צ" ,
]),
([	"action" : "$N����Χ$nһת��צӰ�ݺ�����������$n��$lץ��",
	"lvl"    : 20,
	"skill_name" : "���綾צ" ,
]),
([	"action" : "$Nһ���ֽУ�һצ���ֱ��$n�������",
	"lvl"    : 40,
	"skill_name" : "Ψ�Ҷ���" ,
]),
});

int valid_enable(string usage) { return usage=="claw" || usage=="parry"; }
int valid_combine(string combo) { return combo=="chousui-duzhang"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("���������צ������֡�\n");
	if (me->query_skill("huagong-dafa", 1) < 20)
		return notify_fail("��Ļ�������Ϊ̫�����޷����������צ��\n");
	if ((int)me->query("max_neili") < 200)
		return notify_fail("�������̫�����޷����������צ��\n");
	return 1;
}
int practice_skill(object me)
{
	object* ob;
	int i,damage;
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��ı�����ֲ�����ϰ��\n");
	if ((int)me->query("qi") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("��������������������צ��\n");
	me->receive_damage("qi", 30);
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
	int d_e1 = 60;
	int d_e2 = 40;
	int p_e1 = 0;
	int p_e2 = -20;
	int f_e1 = 100;
	int f_e2 = 250;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int)me->query_skill("sanyin-wugongzhao",1);
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
		"damage_type" : random(2) ? "ץ��" : "����",
	]);
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	if( random(me->query_skill("huagong-dafa",1)) > 5)
	{
		victim->apply_condition("xx_poison", random(2) + 1 + victim->query_condition("xx_poison"));
	}
}
int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 20; }
int power_point(object me) { return 1; }

int help(object me)
{
	write(HIC"\n�������צ��"NOR"\n");
	write(@HELP

    �������צΪ�����ɴ����书��
    ��������ƻ�����

	ѧϰҪ��
		������20��
		����200
HELP
	);
	return 1;
}


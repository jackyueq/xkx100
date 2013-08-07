// huashan-ken.c ��ɽȭ��
// Last Modified by sir 10.21.2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action":  "$Nʹһ��"HIW"������Ǭ����"NOR"��ȭ������������ʽʹ�ϣ���ȭ�Ѵ���ȭ֮�״�������׼$n��$l��������һȭ",
	"skill_name": "����Ǭ��",
	"lvl": 0,
]),
([	"action":  "$N��ȭͻȻ�ſ���ȭ�����ƣ�ֱ����Ϊ��ɨ��һ��"HIC"�����￴����"NOR"����$n��$l�к���ȥ",
	"skill_name": "���￴��",
	"lvl": 10,
]),
([	"action":  "$N���ֻ�����ԣ�����һȦ��һ��"HIY"�����������"NOR"��$n��$l����",
	"skill_name": "�������",
	"lvl": 20,
]),
([	"action":  "$N����һ������ȭ���һ�У���ȭʹ��"MAG"��÷��ŪӰ��"NOR"����$n$l",
	"skill_name": "÷��ŪӰ",
	"lvl": 30,
]),
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }

int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("����ɽȭ��������֡�\n");
	if ((int)me->query_skill("zixia-shengong", 1) < 10)
		return notify_fail("�����ϼ�񹦲��������޷�����ɽȭ����\n");	
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��ı�����ֲ�����ϰ��\n");
	if( (int)me->query("qi") < 30 || (int)me->query("neili") < 30 )
		return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
	me->receive_damage("qi", 20);
	me->add("neili", -20);
	return 1;
}
mapping query_action(object me, object weapon)
{
/* d_e=dodge_effect p_e=parry_effect f_e=force_effect m_e=damage_effect */
	int d_e1 = 40;
	int d_e2 = 60;
	int p_e1 = -20;
	int p_e2 = 0;
	int f_e1 = 100;
	int f_e2 = 200;	
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("huashan-ken", 1);
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

int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 20; }
int power_point(object me) { return 1.0; }

int help(object me)
{
	write(HIC"\n��ɽȭ����"NOR"\n");
	write(@HELP

    ��ɽȭ��Ϊ��ɽ����ȭ����

	ѧϰҪ��
	   ��ϼ10��
HELP
	);
	return 1;
}


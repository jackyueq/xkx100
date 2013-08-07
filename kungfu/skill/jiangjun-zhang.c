// jiangjun-zhang.c �Ὣ��ʫ�ȷ�
// Last Modified by sir 11.1.2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([      "action":               
"$N����$w��$n��$l�������㣬����"HIC"���᡹"NOR"���������ʣ�",
	"lvl" : 0,
	"skill_name" : "��"
]),
([      "action":               
"$N����$w����׼$n��$l��㣬�����Ͻ������½��������£�����"HIC"���硹"NOR"�ֲ��飡",
	"lvl" : 10,
	"skill_name" : "��"
]),
([      "action":               
"$N���$w��д�˸�"HIC"���͡�"NOR"�֣�����$nбɨ��ȥ��",
	"lvl" : 20,
	"skill_name" : "��"
]),
([      "action":               
"$N���һ�����ʷ�һ��д����"HIC"������"NOR"�֣�$wһͦײ��$n$l��",
	"lvl" : 30,
	"skill_name" : "��"
]),
([	"action":
"$N����΢ת��$w����$n��$l��ɨ��ȥ��˳�ƴ�����"HIC"������"NOR"�֣�",
	"lvl" : 40,
	"skill_name" : "��"
]),
([	"action":
"$N�߸�Ծ������$w������"HIC"��׳��"NOR"�֣�����$n��$lײ�˹�����",
	"lvl" : 50,
	"skill_name" : "׳"
]),
([	"action":
"$Nŭ��һ��������$w�������Ǹ�"HIC"���ڡ�"NOR"�֣���$n$l�������£�",
	"lvl" : 60,
	"skill_name" : "��"
]),
});
int valid_enable(string usage) { return usage == "staff" || usage == "parry";}
int valid_learn(object me)
{
	if ((int)me->query_skill("kuihua-xinfa", 1) < 20)
		return notify_fail("��Ŀ����ķ���򲻹���\n");
	if(me->query("max_neili")<200)
		return notify_fail("���������Ϊ������\n");
        return 1;
}

int practice_skill(object me)
{
        object weapon;

        if( !objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "staff" )
                return notify_fail("���������һ��ľ�Ȼ��������Ƶ��������������ȷ���\n");

	if( (int)me->query("qi") < 50 || (int)me->query("neili") < 50 )
                return notify_fail("����������������������ȷ�����������Ϣ��Ϣ�ɡ�\n");
	me->receive_damage("qi", 30);
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
	int d_e1 = -40;
	int d_e2 = -5;
	int p_e1 = 15;
	int p_e2 = 50;
	int f_e1 = 250;
	int f_e2 = 300;
	int m_e1 = 185;
	int m_e2 = 280;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("jiangjun-zhang", 1);
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
		"damage_type" : "����" ,
	]);
}
int learn_bonus() { return 10; }
int practice_bonus() { return 10; }
int success() { return 10; }
int power_point(object me) { return 1.0; }

int help(object me)
{
	write(HIC"\n�Ὣ��ʫ�ȷ���"NOR"\n");
	write(@HELP

    ������̺�ľ���书��÷ׯ��ׯ��ͺ���̿��ұ��졣

	ѧϰҪ��
		�����ķ�20��
		�������200
HELP
	);
	return 1;
}
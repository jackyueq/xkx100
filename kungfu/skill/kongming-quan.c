// kongming.c ����ȭ
// Last Modified by sir 10.21.2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action": "$Nʹһ��"HIW"������ס�ˡ�"NOR"��˫����ƮƮ�ع���$n$l",
	"lvl":0,
	"skill_name": "����ס��"
]),
([	"action": "$N����һƽ,����һ��,һ��"HIW"������ʢ����"NOR"ֱ��$n��$l",
	"lvl":10,
	"skill_name": "����ʢ��"
]),
([	"action": "$N������$nһת��˫������,һ��"HIW"���ղ�װˮ��"NOR"����$n$l",
	"lvl":20,
	"skill_name": "�ղ�װˮ"
]),
([	"action": "$N����һ��,����һ��,һ��"HIW"���黳���ȡ�"NOR"����$n��$l",
	"lvl":30,
	"skill_name": "�黳����"
]),
([	"action": "$Nʹһ��"HIW"����ɽ���"NOR"��$n��$l��Χ��$N��������Ӱ֮��",
	"lvl":40,
	"skill_name": "��ɽ����"
]),
([	"action": "$N��ɫһ����ʹ��"HIW"�����Ŀ�����"NOR"��Χ��$n��$l��������",
	"lvl":50,
	"skill_name": "���Ŀ���"
]),
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }

int valid_learn(object me)
{
	mapping myfam;
	myfam = (mapping)me->query("family");

  if (!me->query("zhou/jieyi") && !me->query_skill("kongming-quan",1)
   && me->query("family/family_name")!="ȫ���")
    return notify_fail("����ȭ�������ܲ�ͨ��̡�\n");
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("������ȭ������֡�\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷�������ȭ��\n");
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��ı�����ֲ�����ϰ��\n");
	if ((int)me->query("qi") < 70)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 70)
		return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
	me->receive_damage("qi", 60);
	me->add("neili", -60);
	return 1;
}
mapping query_action(object me, object weapon)
{
/* d_e=dodge_effect p_e=parry_effect f_e=force_effect m_e=damage_effect */
	int d_e1 = 5;
	int d_e2 = 20;
	int p_e1 = -50;
	int p_e2 = 30;
	int f_e1 = 400;
	int f_e2 = 500;	
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("kongming-quan", 1);
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

int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 5; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"kongming-quan/" + action;
}

int help(object me)
{
	write(HIC"\n����ȭ��"NOR"\n");
	write(@HELP

    ����ȭ������ͯ�ܲ�ͨ���һ�����������������书��
    ���ӡ����¾������о仰������������Ϊ���������ޣ�����֮
�á��仧���Ϊ�ң������ޣ�����֮�á�������˵����ֻ��Ϊ�м�
�ǿյģ�����ʢ���Ĺ��ã���������ʵ�ĵ�һ�����������װ��ô
�������췿�ݣ������Ŵ���ֻ��Ϊ�����ı��м�Ŀ�϶�����Ӳ���
ס�ˡ�����������ʵ�ĵģ������Ŵ������пգ�שͷľ�����ķ���
��������ôһ��ѣ��Ǿ�һ���ô�Ҳû���ˡ�ȫ�������ϳ˵��书��
Ҫּ���ڡ��ա��ᡱ���֣��Ǿ�����ν�������ȱ�����ò��ס���
ӯ���壬���ò��������ȭ��������������书������ǿ�мܡ�

	ѧϰҪ��
		����100
HELP
	);
	return 1;
}


// banruo-zhang.c ������
// Last Modified by sir 10.22.2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$Nǰ���߳������Ƚż��أ�һʽ"HIC"����ճ�����"NOR"������ֱ��������$n����������·",
	"lvl" : 0,
	"skill_name" : "��ճ���"
]),
([	"action" : "$N���ƻ�һ��Բ��һʽ"HIR"��������ա�"NOR"������б������������$n����ǰ��Ѩ",
	"lvl" : 12,
	"skill_name" : "�������"
]),
([	"action" : "$Nʹһʽ"HIB"���ƶ����롹"NOR"�����������������ɺ����һ��˦����ն��$n��$l",
	"lvl" : 18,
	"skill_name" : "�ƶ�����"
]),
([	"action" : "$N���ƻ��أ���ȭ�����󷢣�һʽ"HIM"������������"NOR"����������$n��$l",
	"lvl" : 24,
	"skill_name" : "��������"
]),
([	"action" : "$Nʹһʽ"HIY"������ء�"NOR"��ȫ�������ת��˫��һǰһ���͵�����$n���ؿ�",
	"lvl" : 30,
	"skill_name" : "�����"
]),
([	"action" : "$N���Ʊ�������һ������һʽ"HIW"�����б��¡�"NOR"��˫�Ƽ�����$n�ļ�ͷ",
	"lvl" : 36,
	"skill_name" : "���б���"
]),
([	"action" : "$N���ϸ߸�Ծ��һʽ"HIG"����ɽ��ˮ��"NOR"���Ӹ����£���������$n��ȫ��",
	"lvl" : 42,
	"skill_name" : "��ɽ��ˮ"
]),
([	"action" : "$Nʹһʽ"CYN"��ժ�ǻ�����"NOR"������������˫�����֣�һ������$n��$l�ȥ",
	"lvl" : 48,
	"skill_name" : "ժ�ǻ���"
]),
([	"action" : "$N�������»��أ�һʽ"HIW"������������"NOR"����Ȼ��Ϊ�������꣬����$n",
	"lvl" : 54,
	"skill_name" : "��������"
]),
([	"action" : "$Nһʽ"HIY"����շ�ħ��"NOR"��˫�ֺ�ʮ������$n΢΢һҾ��ȫ���ھ�����˰���ӿ����",
	"lvl" : 60,
	"skill_name" : "��շ�ħ"
])
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }
int valid_combine(string combo) { return combo=="yizhi-chan"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�������Ʊ�����֡�\n");
	if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
		return notify_fail("��Ļ�Ԫһ������򲻹����޷�ѧ�����ơ�\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷��������ơ�\n");
	return 1;
}

int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��ı�����ֲ�����ϰ��\n");
	if ((int)me->query("qi") < 60)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 50)
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
	int f_e1 = 250;
	int f_e2 = 350;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("banruo-zhang", 1);
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
	return __DIR__"banruo-zhang/" + action;
}

int help(object me)
{
	write(HIC"\n�����ƣ�"NOR"\n");
	write(@HELP

    ������ʮ������֮һ��
    ����һָ��������
    ��������һ�����͵ľ��У�������һ����ɢ������ν����ɢ������
ָ����ʯ�ϣ�ʯм�ġ�ɢ����������������ǡ�ɢ������·�Ʒ���ֻ
��ôһ�У�ֻ������̫���ۻ룬�ٵ�ʱ�ò���ʹ�ڶ��У����˱��ѱ�����
����һ���������ɽ�����������Ϊ������Ҫ����л�ʽ���������֮
���ܡ�

	ѧϰҪ��
		��Ԫһ����20��
		����100
HELP
	);
	return 1;
}


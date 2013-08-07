// meinv-quan.c ��Ůȭ
// Last Modified by sir 10.21.2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$Nʹһ��"RED"��������ġ� "NOR"��˫�۽������",
	"lvl" : 0,
	"skill_name" : "�������"
]),
([	"action" : "$NͻȻ��Ϊ"RED"�����ҹ����"NOR"�����䲻���ߵ��ֱ�룬��$n���һ��",
	"lvl" : 10,
	"skill_name" : "���ҹ��"
]),
([	"action" : "$N��ʽһ���"GRN"������׹¥��"NOR"���˵ع������̣�ίʵ�Ѳ�",
	"lvl" : 20,
	"skill_name" : "����׹¥"
]),
([	"action" : "$N˫���������£��������಻���ĳ���ԭ����"HIW"���ļ��麺��"NOR"��������ʮ����",
	"lvl" : 30,
	"skill_name" : "�ļ��麺"
]),
([	"action" : "$Nʹ��"RED"�����ߵ��С�"NOR"���Կ��������֮����$n���б��ж�ȥ",
	"lvl" : 40,
	"skill_name" : "���ߵ���"
]),
([	"action" : "$Nһʽ"HIB"��ľ���乭��"NOR"�������籧���£����ּ��Ӷ�������$nĿ�ɿڴ�",
	"lvl" : 60,
	"skill_name" : "ľ���乭"
]),
([	"action" : "$N��Ȼ�����������£�˫�ƴӲ���˼��ĽǶȹ��˹�����ԭ����һ��
"HIC"���༧��ʫ��"NOR"��",
	"lvl" : 70,
	"skill_name" : "�༧��ʫ"
]),
([	"action" : "$Nʹ��"HIC"���������ˡ�"NOR"����֫��ڱܿ��������Ż��ƹ���$n��ǰ��",
	"lvl" : 80,
	"skill_name" : "��������"
]),
([	"action" : "$N��ָ���Լ�ͷ����һ�ᣬ��������Ļ��˳�ȥ������΢΢һЦ��ȴ
��һ��"HIW"��������װ��"NOR"��",
	"lvl" : 90,
	"skill_name" : "������װ"
]),
([	"action" : "$N��$n��ס����ָ������ȴ��һ��"HIM"��Ƽ������"NOR"��",
	"lvl" : 110,
	"skill_name" : "Ƽ������"
]),
([	"action" : "$NͻȻ������üͷ������"MAG"���������ġ�"NOR"��˫�����Լ��ؿڹ���",
	"lvl" : 130,
	"skill_name" : "��������"
]),
([	"action" : "$N����������ѻ������������������ˮ��Ư��һ�㣬ȴ��һ��"HIW "������΢����"NOR"��",
	"lvl" : 150,
	"skill_name" : "����΢��"
]),
([	"action" : "$Nʹ��"HIM"�������ǡ�"NOR"���������Լ�����б��һ�ƣ������������������������಻��",
	"lvl" : 180,
	"skill_name" : "������"
])
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }
int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("����Ůȭ������֡�\n");
	if ((int)me->query_skill("yunv-xinfa", 1) < 10)
		return notify_fail("�����Ů�ķ���򲻹����޷�ѧ��Ůȭ��\n");
	if ((int)me->query("max_neili") < 30)
		return notify_fail("�������̫�����޷�ѧϰ��Ůȭ��\n");
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��ı�����ֲ�����ϰ��\n");
	if( (int)me->query("qi") < 70 || (int)me->query("neili") < 70 )
		return notify_fail("�������̫���ˣ�������ϰ��Ůȭ��\n");
	me->receive_damage("qi", 40);
	me->add("neili", -30);
	return 1;
}
string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action)-1; i >= 0; i--)
		if(level >= action[i]["lvl"])
			return action[i]["skill_name"];
}
mapping query_action(object me, object weapon)
{
/* d_e=dodge_effect p_e=parry_effect f_e=force_effect m_e=damage_effect */
	int d_e1 = 20;
	int d_e2 = 40;
	int p_e1 = -35;
	int p_e2 = 15;
	int f_e1 = 200;
	int f_e2 = 300;	
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("meinv-quan", 1);
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

int learn_bonus() { return 15; }
int practice_bonus() { return 15; }
int success() { return 15; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"meinv-quan/" + action;
}
int help(object me)
{
	write(HIC"\n��Ůȭ��"NOR"\n");
	write(@HELP

    ��Ĺ�����书�������ֻ��ɣ�ȭ����ÿһ�ж���ģ��һλ�Ŵ�
��Ů����ǧ��������Ů���Ī���������̬������������֮�У��
�����ġ�������翾�����֮�������Ѳ⡣
    ��Ĺ�����ֳ�Ӣ���ɣ�������Ů�����С����ס���Ůȭ������
ʹ����ʱ������ȣ�ȴҲ��������������ɱ�֡�


	ѧϰҪ��
		��Ů�ķ�10��
		����30
HELP
	);
	return 1;
}


// jingang-quan.c -����ȭ
// Last Modified by sega on Mar. 10 2000
// ���ֵ����ƿ��ֹ��򣬲��ܲ���

#include <ansi.h>;
inherit "/inherit/skill/cuff.c";
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N��ϥ���������ֺ�ʮ��һʽ"HIC"����������"NOR"��˫ȭ���ƶ���������$n��$l",
	"lvl" : 0,
	"skill_name" : "������"
]),
([	"action" : "$Nһʽ"HIR"���һ�׶��"NOR"��˫�������»���ȭ�����棬��ž����",
	"lvl" : 10,
	"skill_name" : "�һ�׶"
]),
([	"action" : "$N�ڿշ���һʽ"HIG"���˷��꡹"NOR"��˫��˫���������$n�޿ɶ��",	
	"lvl" : 20,
	"skill_name" : "�˷���"
]),
([	"action" : "$N˫���麬����Ե�³���һʽ"HIM"�������ס�"NOR"��������$n�Ƴ�",
	"lvl" : 30,
	"skill_name" : "������"
]),
([	"action" : "$Nһ��ǰ�죬һ�ۺ�ָ��һʽ"HIB"����ָɽ��"NOR"������$n����ǰ���",	
	"lvl" : 40,
	"skill_name" : "��ָɽ"
]),
([	"action" : "$Nһʽ"HIW"�������ɡ�"NOR"������ʮָ���$n��ȫ����ʮ����ҪѨ",
	"lvl" : 48,
	"skill_name" : "������"
]),
([	"action" : "$N��Ŀ���ӣ�˫��������һʽ"HIY"����������"NOR"������˷������������ǵ�
����",
	"lvl" : 54,
	"skill_name" : "������"
]),
([	"action" : "$N��Ц��Ц��˫ȭ�����޶���һʽ������Ц������Ȼ����$n��ǰ��",
	"lvl" : 60,
	"skill_name" : "����Ц"
])
});

int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }	 
int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("������ȭ������֡�\n");
	if ((int)me->query_skill("hunyuan-yiqi", 1) < 50)
		return notify_fail("��Ļ�Ԫһ������򲻹����޷�ѧ����ȭ��\n");
	if ((int)me->query("max_neili") < 200)
		return notify_fail("�������̫�����޷�������ȭ��\n");
	return 1;
}
int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��ı�����ֲ�����ϰ��\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("�����������������ȭ��\n");
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
	int d_e1 = 15;
	int d_e2 = 40;
	int p_e1 = -40;
	int p_e2 = -15;
	int f_e1 = 200;
	int f_e2 = 450;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("jingang-quan", 1);
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
		"damage_type" : "����",
	]);
}
int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 5; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"jingang-quan/" + action;
}

int help(object me)
{
	write(HIC"\n����ȭ��"NOR"\n");
	write(@HELP

    ����ȭΪ������ʮ������֮һ��
    ����ȭ���������ޣ�������ֺ��о��޷����ɡ�����������
Ҫ���ϰ����꣬����һ���س����������������ȭ����ֻ��������
���ϵȵȣ��ϴ���ɮ������侭֮�У���ʱȫ������ɮ�ھ���һ��
���ɣ�ȴҲ����ʧ����

	ѧϰҪ��
		��Ԫһ����50��
		����200
HELP
	);
	return 1;
}


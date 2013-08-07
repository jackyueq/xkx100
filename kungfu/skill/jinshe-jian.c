// jinshe-jian.c ���߽���
// Last Modified by sega on Mar. 10 2000
// �����ý��߽�ʱ����damage����,

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"skill_name" : "�����Ӱ",
	"action"     : "$Nʹһ��"HIY"�������Ӱ��"NOR"�����е�$w��һ��ָ������$n��$l��������",
	"lvl"        : 0
]),
([	"skill_name" : "��Ӱ���",
	"action"     : "$Nʹһ��"HIY"����Ӱ�����"NOR"������$w�����������$n��$l��������",
	"lvl"        : 10
]),
([	"skill_name" : "ѩ�ط���",
	"action"     : "$N����һת����������Ծ������$w�鶯زԾ��һ��"HIY"��ѩ�ط��ߡ�"NOR"����$n��$l",
	"lvl"        : 20
]),
([	"skill_name" : "��������",
	"action"     : "$N����һת��һ��"HIY"���������š�"NOR"�����е�$w����������$n��$l���˹�ȥ",
	"lvl"        : 30
]),
([	"skill_name" : "���߿���",
	"action"     : "$N����һ����һ��"HIY"�����߿��衹"NOR"��$wЮ���������⣬����޷�����$n��$l",
	"lvl"        : 40
]),
([	"skill_name" : "���ߵ���",
	"action"     : "$N������������񴦣�һ��"HIY"�����ߵ�����"NOR"��$w���޷����ݵ��ٶ�ֱ��$n��$l",
	"lvl"        : 50
]),
([	"skill_name" : "�������",
	"action"     : "$N����һ����һ��"HIY"��������ǡ�"NOR"�����е�$w�������ϴ���$n��$l",
	"lvl" : 60
]),
([	"skill_name" : "���߻���",
	"action"     : "$N����$w���Ⱪ����һ��"HIY"�����߻�����"NOR"����ǧ����Ы��$n$lҧȥ",
	"lvl"        : 70
]),
});

int valid_enable(string usage) { return usage=="sword" || usage=="parry"; }
int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_neili") < 500 )
		return notify_fail("�������������û�а취�����߽�����\n");
	if( !(ob = me->query_temp("weapon")) ||
		(string)ob->query("skill_type") != "sword" )
		return notify_fail("���������һ�ѽ�������������\n");

	return notify_fail("���߽���û�����ڡ�\n");
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("qi") < 30
	|| (int)me->query("neili") < 15 )
		return notify_fail("�����������������û�а취��ϰ���߽�����\n");
	me->receive_damage("qi", 30);
	me->add("neili", -15);
	write("�㰴����ѧ����һ����߽�����\n");
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
	int d_e1 = 35;
	int d_e2 = 55;
	int p_e1 = 5;
	int p_e2 = 25;
	int f_e1 = 50;
	int f_e2 = 100;
	int m_e1 = 30;
	int m_e2 = 120;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("jinshe-jian", 1);
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
int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 20; }
int power_point(object me) { return 1.0; }

int valid_effect(object me, object weapon, string name, int skill)
{
}

int effective_level() { return 25;}

string *parry_msg = ({
	"$n���е�$W����ǧ�ٰѣ���ס��ȫ��\n",
	"$n���е�$W�������£�������$N��$w�������Ρ�\n",
	"$nʹ��$W������ǰ������һ��ͭǽ���ڣ���ס��$N�Ĺ��ơ�\n",
	"$n��$W������һ�̣�$W�����������պ�ֱ��$N��˫�ۡ�\n",
	"$n�ٽ�������һ�������ӽ���͸�����ƿ���$N��\n",
	"$nһ�����е�$W����ס��ȫ��\n",
});

string *unarmed_parry_msg = ({
	"$n�������أ���ס��$N��$w��\n",
	"$n���˷������������죬�ݺݿĿ���$N��$w��\n",
});

string query_parry_msg(object weapon)
{
	if( weapon )
		return parry_msg[random(sizeof(parry_msg))];
	else
		return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
string perform_action_file(string action)
{
	return __DIR__"jinshe-jian/" + action;
}

int help(object me)
{
	write(HIC"\n���߽�����"NOR"\n");
	write(@HELP

    ���߽������ڡ��������š����˽����ɾ���ѩ�˵Ķ����书��
��ѩ����ʱȫ�Ҳ��ұ��¼����Ͻ������ţ���־���𡣺����置��
ʶ�嶾�̽���֮�úκ�ҩ��������������嶾�̵ġ�������������
�߽�������׶���ر�ͼ��������ɾ����书��
    ��ѩ������Ź֣�Ϊ�����ݣ��书���������˰�����Ѳ⡣��
����������������Ϊ֮ɫ�䣬���ǳ������Ѳ������ѩ�����µ�
���������š�������һ���书�������߽���������׶���ͽ�������
�ơ� 

	ѧϰҪ��
		����500
HELP
	);
	return 1;
}


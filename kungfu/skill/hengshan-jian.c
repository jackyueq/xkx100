// hengshan-jian.c ��ɽ����
/// Last Modified by sir on 5/17/2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action":"$N������У�һʽ"HIG"������ӭ�͡�"NOR"��$w����ɶ�������һƬ���⣬Χ��$nȫ��",
	"lvl" : 0,
	"skill_name" : "����ӭ��"
]),
([	"action":"$Nʹһ��"HIR"�����Ƽ��ա�"NOR"����������Ʈ������$w����ʵʵ�ó���㺮������$n$l",
	"lvl" : 20,
	"skill_name" : "���Ƽ���"
]),
([	"action":"$N����һת����Ȼһʽ"HIY"�������ɽ��"NOR"��������콣Ӱ��Ю�ž�����$n��$lɨȥ",
	"lvl" : 40,
	"skill_name" : "�����ɽ"
]),
([	"action":"$N���쳤Ц������ƮȻ�����ڰ��������һ����һʽ"HIB"�����Ʊ�
�¡�"NOR"����ػ���$n",
	"lvl" : 50,
	"skill_name" : "���Ʊ���"
]),
([	"action":"$N�������Ž���������̤��һ��"HIC"���ǻ����ա�"NOR"����б�̣�������ȻԾ��ٿ�Ļ��������ǹ�����$n��$l",
	"lvl" : 80,
	"skill_name" : "�ǻ�����"
]),
([	"action":"$N��ǰ��ȥһ�󲽣�ʹ��"HIW"��֯Ů����"NOR"������$w���һ������Ѹ�����׻���$n��$l",
	"lvl" : 100,
	"skill_name" : "֯Ů����"
]),
([	"action":"$N����һ��$w��һʱ"MAG"��ƮȻ������"NOR"��$w�ó���㽣����ƮȻ����$n��$l",
	"lvl" : 110,
	"skill_name" : "ƮȻ����"
]),
([	"action":"$N���һ����һ��"GRN"������ͨ�ġ�"NOR"��$w����㻮��һ����Բ������$n��$l",
	"lvl" : 130,
	"skill_name" : "����ͨ��"
]),
([	"action":"$N��������Ʈ��ͻȻһת��ͷ�½��ϣ�����$w��һ��"HIM"����ϼ
������"NOR"��������Ϣ�ع���$n��$l",
	"lvl" : 150,
	"skill_name" : "��ϼ����"
]),
([	"action":"$N����$wһ����һ��"BLU"�����ո��֡�"NOR"��$w�Ƴ�ҫ�۹�â����������$n��$l",
	"lvl" : 160,
	"skill_name" : "���ո���"
]),
([	"action":"$N��Ȼ���θ߸�Ծ��ʹ��"RED"������Ǭ����"NOR"��$w�ó����컨�꣬Ѹ����������$n��$l",
	"lvl" : 180,
	"skill_name" : "����Ǭ��"
])
});

int valid_enable(string usage) { return (usage=="sword") || (usage=="parry") ; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail(HIC"�������������\n"NOR);
	if( (string)me->query_skill_mapped("force")!= "baiyun-xinfa")
		return notify_fail("��ɽ����������ϰ����ķ���������\n");
	if ((string)me->query("gender") != "Ů��" )
		return notify_fail(HIY"��������Ľ���ֻ��Ů�Ӳ��ʺ�ѧ��\n"NOR);
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("qi") < 40 || (int)me->query("neili") < 30 )
		return notify_fail("�������������������ɽ������\n");
	me->receive_damage("qi", 35);
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
	int d_e1 = 10;
	int d_e2 = 30;
	int p_e1 = -20;
	int p_e2 = 0;
	int f_e1 = 100;
	int f_e2 = 150;
	int m_e1 = 100;
	int m_e2 = 200;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("hengshan-jian", 1);
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
int learn_bonus() { return 20; }
int practice_bonus() { return 20; }
int success() { return 10; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"hengshan-jian/" + action;
}

int help(object me)
{
	write(HIC"\n��ɽ������"NOR"\n");
	write(@HELP

    ��ɽ����Ϊ��ɽ�书��

	ѧϰҪ��
		��߰����ķ���Ů��
		����100
HELP
	);
	return 1;
}


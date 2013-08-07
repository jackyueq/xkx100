// quanzhen-sword.c ȫ�潣��
// Last Modified by sir 10.22.2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action":"$N������У�һʽ"GRN"���ֻ�������"NOR"��$w����ɶ�������һƬ���⣬Χ��$nȫ��",
	"lvl" : 0,
	"skill_name" : "�ֻ�����"
]),
([	"action":"$Nʹһ��"HIY"������������"NOR"����������Ʈ������$w����ʵʵ�ó����㺮������$n$l",
	"lvl" : 9,
	"skill_name" : "��������"
]),
([	"action":"$N����һת����Ȼһʽ"HIG"���ɨҶ��"NOR"��������콣Ӱ��Ю�ž�����$n��$lɨȥ",
	"lvl" : 18,
	"skill_name" : "�ɨҶ"
]),
([	"action":"$N���쳤Ц������ƮȻ�����ڰ��������һ����һʽ"HIM"�����ʹ����"NOR"����ػ���$n",
	"lvl" : 27,
	"skill_name" : "���ʹ��"
]),
([	"action":"$N�������Ž���������̤��һ��"RED"�������롹"NOR"����б�̣�������ȻԾ��ٿ�Ļ��������ǹ�����$n��$l",
	"lvl" : 36,
	"skill_name" : "������"
]),
([	"action":"$N��ǰ��ȥһ�󲽣�ʹ��"HIB"��̽��������"NOR"������$w���һ������Ѹ�����׻���$n��$l",
	"lvl" : 45,
	"skill_name" : "̽������"
]),
([	"action":"$N����һ��$w��һʱ"HIM"�������仨��"NOR"��$w�ó���㽣����ƮȻ����$n��$l",
	"lvl" : 54,
	"skill_name" : "�����仨"
]),
([	"action":"$N����$wбָ���죬�������࣬һʱ"YEL"������Į����"NOR"��$w����������$n��$l",
	"lvl" : 63,
	"skill_name" : "����Į��"
]),
([	"action":"$N���һ����һ��"HIW"���׺羭�졹"NOR"��$w����㻮��һ����Բ������$n��$l",
	"lvl" : 72,
	"skill_name" : "�׺羭��"
]),
([	"action":"$N��������Ʈ��ͻȻһת��ͷ�½��ϣ�����$w��һ��"HIW"����׹������"NOR"��������Ϣ�ع���$n��$l",
	"lvl" : 81,
	"skill_name" : "��׹����"
]),
([	"action":"$N����$wһ����һ��"HIR"��������Ե��"NOR"��$w�Ƴ�ҫ�۹�â����������$n��$l",
	"lvl" : 90,
	"skill_name" : "������Ե"
]),
([	"action":"$N��Ȼ���θ߸�Ծ��ʹ��"HIC"���˼����ġ�"NOR"��$w�ó����컨�꣬Ѹ����������$n��$l",
	"lvl" : 150,
	"skill_name" : "�˼�����"
])
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }
int valid_learn(object me)
{
	if ((int)me->query_skill("yunv-xinfa", 1) < 25 &&
		(int)me->query_skill("xiantian-qigong", 1) < 25)
		return notify_fail("����ڹ��ķ���򲻵����޷�ѧϰȫ�潣����\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("qi") < 55)
		return notify_fail("�������������ȫ�潣����\n");
	if ((int)me->query("neili") < 40)
		return notify_fail("���������������ȫ�潣����\n");
	me->receive_damage("qi", 50);
	me->add("neili", -35);
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
	int d_e1 = -20;
	int d_e2 = 0;
	int p_e1 = -50;
	int p_e2 = -30;
	int f_e1 = 150;
	int f_e2 = 200;
	int m_e1 = 190;
	int m_e2 = 280;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("quanzhen-jian", 1);
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
int power_point(object me) 
{ 
  if(me->query_skill("xiantian-qigong",1) > 10) return 1.0;
  else return 0.6;
}

string perform_action_file(string action)
{
	return __DIR__"quanzhen-jian/" + action;
}
int help(object me)
{
	write(HIC"\nȫ�潣����"NOR"\n");
	write(@HELP

    ȫ�潣���Է����Ͻ�����ʽ�������ƣ�������ʦ����������ʱ
�̴˽�����ɱ��а�������ŷ�ɥ����

	ѧϰҪ��
		������������Ů�ķ�25��
		����100
HELP
	);
	return 1;
}


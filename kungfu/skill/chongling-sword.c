// chongling-sword.c
// Last Modified by Winder on May. 29 2001
// Modified by Venus Oct.2000

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N����$w��������ʹһ��"GRN"����÷�綹��"NOR"����$n��$l��ȥ",
	"lvl"    : 0,
	"skill_name" : "��÷�綹"
]),
([	"action" : "$N����$w�����ӹ���бб����$n��䡣$nһ��������������"GRN "����Ҷ��ü��"NOR"��",
	"lvl"    : 10,
	"skill_name" : "��Ҷ��ü"
]),
([	"action" : "$N�趯$w��һ��"HIW"�����г�����"NOR"Ю�������������$n��$l",
	"lvl"    : 20,
	"skill_name" :  "���г���"
]),
([	"action" : "$N����$w���������һ��"HIB"�����է�꡹"NOR"ֱ����$n��˫��",
	"lvl"    : 30,
	"skill_name" :   "���է��"
]),
([	"action" : "$Nʹһ��"HIC"��һ�����项"NOR"������$w���Ⱪ������$n��$l��ȥ",
	"lvl"    : 40,
	"skill_name" :   "һ������"
]),
([	"action" : "$N������ת��һ��"HIM"����С�޲¡�"NOR"����$n��$l",
	"lvl"    : 50,
	"skill_name" : "��С�޲�"
]),
([	"action" : "$N����$w���Ⱪ�����������һ��"MAG"��ͬ��������"NOR"��$n�ʺ��ȥ",
	"lvl"    : 60,
	"skill_name" :  "ͬ������"
]),
([	"action" : "$N����$w����һ���⻡��ֱָ$n$l��һ��"HIG"�������ѷ֡�"NOR"��������������ȥ",
	"lvl"    : 70,
	"skill_name" :   "�����ѷ�"
]),
});

int valid_enable(string usage) { return usage=="sword" || usage=="parry"; }
int valid_learn(object me)
{
	object ob;
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("�������������û�а취�����齣����\n");
	if( (string)me->query_skill_mapped("force")!= "zixia-shengong")
		return notify_fail("���齣�����������ϼ�񹦲�������\n");
	if( !(ob = me->query_temp("weapon")) ||
		(string)ob->query("skill_type") != "sword" )
		return notify_fail("���������һ�ѽ�������������\n");
	return 1;
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 30 || (int)me->query("neili") < 10 )
		return notify_fail("������������������޷���ϰ���齣����\n");
	me->receive_damage("qi", 30);
	me->add("neili", -10);
	write("�㰴����ѧ����һ����齣����\n");
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
	int d_e2 = 60;
	int p_e1 = 10;
	int p_e2 = 25;
	int f_e1 = 50;
	int f_e2 = 100;
	int m_e1 = 20;
	int m_e2 = 110;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("chongling-sword", 1);
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
int power_point() { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"chongling-sword/" + action;
}

int help(object me)
{
	write(HIC"\n���齣����"NOR"\n");
	write(@HELP

    ����������Сʦ������ɺ�����ڻ�ɽ����ʱ�����ġ����齣
���������塱������壬���顱������ɺ���Ƕ��˺������ͬ����
�����Ľ�������������ݱ�ʦ�øߵö࣬��������ô�¶�ϲ����
�ɷ��������⣬��·������˵�Ƕ��˹�����ʮ֮�˾�ȴ�������
������ġ���ʱ�����书������ǳ����·������Ҳ��û��ô������
��ʽ��ֻ�Ƕ��˳������˴���⣬����ȴʮ�ִ��졣


	ѧϰҪ��
		��ϼ��1��
		������Ϊ50
HELP
	);
	return 1;
}


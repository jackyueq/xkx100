// Last Modified by winder on Jul. 9 2001
// jinwu-blade.c ���ڵ���

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

string *mjj = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([	"action" : "$N����$wֱ����һ��"+(mjj[random(13)])+"������Ҿ����"NOR"��Ю�ž�������֮ʽ����$n��ͷ����",
	"lvl"    : 0,
	"skill_name" : "����Ҿ��"
]),
([	"action" : "$Nһ��"+(mjj[random(13)])+"��÷ѩ���ġ�"NOR"������һƬ��Ļ��ֻ���������죬��$n�����ȥ",
	"lvl"    : 10,
	"skill_name" : "÷ѩ����"
]),
([	"action" : "$N�ᵶֱ�ӣ�һ��"+(mjj[random(13)])+"���������ء�"NOR"�������£�£��һ��쭣���$n$l��ȥ",
	"lvl"    : 20,
	"skill_name" : "��������"
]),
([	"action" : "$Nһ��"+(mjj[random(13)])+"�����ս�ġ�"NOR"��$w��������������һ���â�Ե��ϼ��������ӳ��$n\n˫�۽��գ�$N�˻�������ǰ���ӵ���ն$n$l",
	"lvl"    : 30,
	"skill_name" : "���ս��"
]),
([	"action" : "$N����$wһ����һ��"+(mjj[random(13)])+"��ǧ��ѹ�ա�"NOR"��$w���Ƴ��Ͳ�����ʵ���ƻ�ʵ�죬��������һ��������\nֱ��$n$l",
	"lvl"    : 40,
	"skill_name" : "ǧ��ѹ��"
]),
([	"action" : "$N��$w����һ����ʹ��һ��"+(mjj[random(13)])+"���󺣳�ɳ��"NOR"��$w��ʱ��ʧ����Ӱ���٣�$n�����ɼ䣬\nֻ������һ����$w��Ѹ�������ն��$l",
	"lvl"    : 50,
	"skill_name" : "�󺣳�ɳ"
]),
([	"action" : "$Nһ��"+(mjj[random(13)])+"������֮����"NOR"������$w����ʮ�˵������ƻ��Ҳ�����ʵ�򵶵�����$nҪ��",
	"lvl"    : 60,
	"skill_name" : "����֮��"
]),
([	"action" : "$N̤����ǰ��ʹ��"+(mjj[random(13)])+"���������ס�"NOR"������$w�����ӣ�����һ�ش����棬��$n��ͷ������նȥ",
	"lvl"    : 70,
	"skill_name" : "��������"
]),
([	"action" : "$Nһ��"+(mjj[random(13)])+"�����ò����"NOR"������$w����һ����ƽʮ�֣���$n�ݺ���ȥ",
	"lvl"    : 80,
	"skill_name" : "���ò��"
]),
([	"action" : "$N��ת�����׼�Լ���һ��"+(mjj[random(13)])+"��������֦��"NOR"��ȫ��һ��������$w��$n����նȥ",
	"lvl"    : 90,
	"skill_name" : "������֦"
]),
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }
int valid_learn(object me)
{
	object ob;
	if( (int)me->query("max_neili") < 500 )
		return notify_fail("�������������û�а취�����ڵ�����\n"); 
	if( (int)me->query_skill("xueshan-sword",1) < 80)
		return notify_fail("���ڵ���������ѩɽ����Ϊ���ײ�����ϰ��\n");
	if( (int)me->query_skill("bingxue-xinfa",1) < 50)
		return notify_fail("���ڵ��������б�ѩ�ķ�Ϊ���ײ�����ϰ��\n");
	if( !(ob = me->query_temp("weapon")) ||
		(string)ob->query("skill_type") != "blade" )
	return notify_fail("���������һ�ѵ�������������\n");

	return 1;
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 20 || (int)me->query("neili") < 10 )
		return notify_fail("�����������������û�취��ϰ���ڵ�����\n");
	me->receive_damage("qi", 10);
	me->add("neili", -5);
//	write("�㰴����ѧ����һ����ڵ�����\n");
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
	int d_e1 = 40;
	int d_e2 = 15;
	int p_e1 = -15;
	int p_e2 = -30;
	int f_e1 = 150;
	int f_e2 = 200;
	int m_e1 = 150;
	int m_e2 = 260;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int)me->query_skill("jinwu-blade", 1);
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
int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 5; }
int power_point(object me) { return 1; }

string perform_action_file(string action)
{
	return __DIR__"jinwu-blade/" + action;
}

int help(object me)
{
        write(HIC"\n���ڵ�����"NOR"\n");
        write(@HELP

    ���ڵ���Ϊѩɽ�����ŷ���ʷС��������ʷС������������
���������˵���רΪ����ѩɽ�����������ڸ�ʯ���죬��ͼ��ʯ��
���ܰ���֮�ƣ���ѹ���˷�����棬��һ���Լ���ʮ�걻��ѹ
���������˵���רΪ����ѩɽ������������ѩɽ�������֣�ȴ�ܾ�
����©ʧ��������ٱ��

        ѧϰҪ��
                ��ѩ�ķ�50��
                ѩɽ����80��
                ����100
HELP
        );
        return 1;
}


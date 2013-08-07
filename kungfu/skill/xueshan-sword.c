// Last Modified by winder on Jul. 9 2001

// xueshan-sword ѩɽ����
#include <ansi.h>
inherit SKILL;  
string type() { return "martial"; }
string martialtype() { return "skill"; }

string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([	"action": "$N����$w���ͣ�һ��" +(order[random(13)])+"�������ơ�"NOR"��ǰ�̳�,����$n��$l",
	"lvl" : 0,
	"skill_name" : "������"
]),
([	"action": "$N������ǰ���������������һʽ"+(order[random(13)])+"����ѩ�ŵ㡹"NOR"��$n���Ƶ��ۻ����ң���æ����֮�ʣ�\nͻȻ��$l��һ������",
	"lvl" : 10,
	"skill_name" : "��ѩ�ŵ�"
]),
([	"action": "$N����ٿ�ط��ϣ�б��$n��$l������ѩɽ�ɽ����е�"+(order[random(13)])+"����֦��б��"NOR"",
	"lvl" : 30,
	"skill_name" : "��֦��б"
]),
([	"action":  "$N����һ��������$n�����мܣ�$N���ٺ���������������ʱ���У���ת���棬\nб���к�����ѩɽ�ɽ����е�"+(order[random(13)])+"��ѩ���צ��"NOR"",
	"lvl" : 50,
	"skill_name" : "ѩ���צ"
]),
([	"action": "$N����$wһ��" +(order[random(13)])+"��������Ӱ��"NOR"����������Ӱ�������������ޣ�б��������$n���Եֵ�����һ������$l",
	"lvl" : 80,
	"skill_name" : "������Ӱ"
]),
([	"action": "$N����$w�������Ȧ�ӣ�һ��"+(order[random(13)])+"��˷�����"NOR"�������â����Х����$n���ζ�ȥ",
	"lvl" : 110,
	"skill_name" : "˷�����"
]),
([	"action": "$Nһʽ" +(order[random(13)])+"������������"NOR"������$w���Ƴ��Ͳ�����ȴ����ʵ�죬��$n�Ѷ���ʵ���޿ɶ��",
	"lvl" : 130,
	"skill_name" : "��������"
]),
([	"action": "$N��Ȼ�ս��ػ���һʽ" +(order[random(13)])+"����ɳ��ʯ��"NOR"���͵ؼ��������Ҷ��ʯ�Ĵ����Ю�ޱ����ƣ���$n$l��ȥ",
	"lvl" : 150,
	"skill_name" : "��ɳ��ʯ"
]),
([	"action": "$N�ٽ�����Ծ����һʽ" +(order[random(13)])+"������Խ�롹"NOR"��$w�ó������â���ڽ����м�ȡ$n��$l",
	"lvl" : 150,
	"skill_name" : "����Խ��"
]),
([	"action": "$N���ֽ��ս�ָ���ҽ�Ĭ�˱�ѩ�ķ���������������͸����һʽ"+(order[random(13)])+"������˫÷��"NOR"��\n��ָ�������Ҽй���ֱ��$n$l",
	"lvl" : 160,
	"skill_name" : "����˫÷"
]),
([	"action": "$Nһʽ" +(order[random(13)])+"������Ǽ�ѡ�"NOR"��$w����һ�����»��Σ�����������⣬����$n��$l",
	"lvl" : 160,
	"skill_name" : "����Ǽ��"
]), 
([	"action": "$Nһ��" +(order[random(13)])+"����ɫ�ƻ衹"NOR"��ʹ���������ޣ��������ʣ�$wбб������ֱȡ$n$l",
	"lvl" : 170,
	"skill_name" : "��ɫ�ƻ�"
]), 
([	"action": "$N����$w������һ��" +(order[random(13)])+"��÷ѩ������"NOR"��������ʵ��ʵ�����飬���⽣�����ã�\n������ѩ�㣬�����˸�֦������˷�����$n���˹���",
	"lvl" : 180,
	"skill_name" : "÷ѩ����"
]), 
([	"action": "$N����$w˦����һ��" +(order[random(13)])+"���׷ɾ��졹"NOR"���ڿ����������ģ����������$n�̳��ž�\n��ʮһ����Ȼ��ɻ�$N����",
	"lvl" : 190,
	"skill_name" : "�׷ɾ���"
]), 
([	"action": "$N��Хһ�������ӿ죬һ��"+(order[random(13)])+"����Ӱ���㡹"NOR"��$w��÷������ݳ���$n�����ɼ䣬\n����ͻȻ��������,����������$n���ֶ�ȥ",
	"lvl" : 200,
	"skill_name" : "��Ӱ����"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }
int valid_learn(object me)
{
	object ob;
	if( (int)me->query("max_neili") < 50 )
		return notify_fail("�������������û�а취��ѩɽ������\n");
	if( (string)me->query_skill_mapped("force")!= "bingxue-xinfa")
		return notify_fail("ѩɽ����������ϱ�ѩ�ķ���������\n");
	if( !(ob = me->query_temp("weapon")) ||
		(string)ob->query("skill_type") != "sword" )
		return notify_fail("���������һ�ѽ�������������\n");

	return 1;
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 50 || (int)me->query("neili") < 35 )
		return notify_fail("�����������������û�취��ϰѩɽ������\n");
	me->receive_damage("qi", 45);
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
	int d_e1 = -15;
	int d_e2 = 10;
	int p_e1 = -40;
	int p_e2 = -25;
	int f_e1 = 150;
	int f_e2 = 200;
	int m_e1 = 170;
	int m_e2 = 260;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("xueshan-sword", 1);
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
int learn_bonus() { return 10; }
int practice_bonus() { return 10; }
int success() { return 5; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"xueshan-sword/" + action;
}

int help(object me)
{
        write(HIC"\nѩɽ������"NOR"\n");
        write(@HELP

    ѩɽ����Ϊѩɽ�ɱ��Ž�����

        ѧϰҪ��
                ��ѩ�ķ�
                ����50
HELP
        );
        return 1;
}


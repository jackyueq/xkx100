// Last Modified by winder on Jul. 9 2001
// snow-strike.c
#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([	"action":  "$Nһ��"+(order[random(13)])+"��÷��С�á�"NOR"��˫�ֻ������磬��ƮƮ�ص���$n$l", 
	"lvl"    : 0,
	"skill_name" : "÷��С��"
]),
([	"action":  "$N��ȭƽ������ȭ���»��˸��뻡��һ��" +(order[random(13)])+"��÷�޺��ӡ�"NOR",��ȡ$n��$l",
	"lvl"    : 10,
	"skill_name" : "÷�޺���"
]),
([	"action":  "$Nһ��" +(order[random(13)])+"����ѩ��÷��"NOR"��˫������о��ݣ��������ǰ�����$n$l",
	"lvl"    : 20,
	"skill_name" : "��ѩ��÷"
]),
([	"action":  "$N����һ��"+(order[random(13)])+"��˪ѩ���졹"NOR"��ɢ��ɭɭ����������$n��$l",
	"lvl"    : 30,
	"skill_name" : "˪ѩ����"
]),
([	"action":  "$Nʹһ��"+(order[random(13)])+"����ѩ��÷��"NOR"��������ת����������$n$l",
	"lvl"    : 40,
	"skill_name" : "��ѩ��÷"
]),
([	"action":  "$N����һЦ���������һʽ" +(order[random(13)])+"������Ʈ÷��"NOR"��Χ��$n��$l��ƮƮ��������",
	"lvl"    : 50,
	"skill_name" : "����Ʈ÷"
]),
});

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }
int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("����ѩӳ÷�Ʊ�����֡�\n");
	if ((int)me->query_skill("bingxue-xinfa", 1) < 10)
		return notify_fail("��ı�ѩ�ķ���Ϊ̫�����޷���ϰ��\n");
	if ((int)me->query("max_neili") < 10)
		return notify_fail("���������Ϊ̫�����޷���ϰ��\n");
	return 1;
}
int practice_skill(object me)
{
	if ((int)me->query("qi") < 40)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 10)
		return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
	me->receive_damage("qi", 25);
	me->add("neili", -10);
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
	int p_e1 = 20;
	int p_e2 = 50;
	int f_e1 = 130;
	int f_e2 = 240;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("snow-strike", 1);
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
int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 20; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"snow-strike/" + action;
}

int help(object me)
{
        write(HIC"\n��ѩӳ÷�ƣ�"NOR"\n");
        write(@HELP

    ��ѩӳ÷����ѩɽ���Ʒ���

        ѧϰҪ��
                ��ѩ�ķ�10��
                ����10
HELP
        );
        return 1;
}


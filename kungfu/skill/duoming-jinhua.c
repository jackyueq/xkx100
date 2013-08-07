// duoming-jinhua.c ������
// Last Modified by sega on Mar. 10 2000

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action":"$Nʹһ�С���է����������$w�������ɢ����$n��$l",
	"lvl" : 0,
	"skill_name" : "��է��",
]),
([	"action":"$Nʹ�������ջƻ�����˫���Ͷ���$w�׷�׹Ҷ��ֱϮ$n��$l",
	"lvl" : 20,
	"skill_name": "���ջƻ�",
]),
([	"action":"$Nһ�С���ѩ�ƻ���������һ�ӣ�����$w����ѩ�����켤
��$n��$l",
	"lvl" : 40,
	"skill_name": "��ѩ�ƻ�",
]),
([	"action":"$N����$wһʽ����ҫ�ա���$w����һ���׹�ֱ��$n��$l",
	"lvl" : 80,
	"skill_name": "��ҫ��",
]),
([	"action":"$N����һԾ������$wһ�С���ػƻ���������������$nȫ��",
	"lvl" : 100,
	"skill_name":"��ػƻ�",
]),
([	"action":"$N�ֿ�$w������һ�Σ�ƾ��һָ��һ�С��𻨶�Ŀ����
��$n��$l",
	"lvl" : 120,
	"skill_name": "�𻨶�Ŀ",
]),
});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_neili") < 100 )
		return notify_fail("�������������û�а취�������𻨡�\n");
	if( me->query_skill("jiuyang-shengong") < 40 )
		return notify_fail("������񹦻��������û��ѧ�����𻨡�\n");
	if( !(ob = me->query_temp("weapon")) ||
		(string)ob->query("skill_type") != "throwing" )
		return notify_fail("���������һЩ����֮��Ķ���������������\n");
	return 1;
}

int valid_enable(string usage) { return usage=="throwing" || usage=="parry"; }

string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action)-1; i >= 0; i--)
		if(level >= action[i]["lvl"])
			return action[i]["skill_name"];
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "throwing")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("qi") < 30 ||(int)me->query("neili") < 3 )
		return notify_fail("�����������������û�а취��ϰ�����𻨡�\n");
	me->receive_damage("qi", 30);
	me->add("neili", -3);
//	write("�㰴����ѧ����һ������𻨡�\n");
	return 1;
}
mapping query_action(object me, object weapon)
{
/* d_e=dodge_effect p_e=parry_effect f_e=force_effect m_e=damage_effect */
	int d_e1 = 10;
	int d_e2 = 45;
	int p_e1 = -20;
	int p_e2 = 0;
	int f_e1 = 20;
	int f_e2 = 200;
	int m_e1 = 70;
	int m_e2 = 550;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("duoming-jinhua", 1);
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
		"damage"       : f_e1 + (f_e2 - f_e1) * seq / ttl,
  	"post_action": (: call_other, WEAPON_D, "throw_weapon" :),
		"damage_type" : random(2) ? "����" : "����",
	]);
}
int learn_bonus() { return 10; }
int practice_bonus() { return 10; }
int success() { return 10; }
int power_point(object me) { return 1; }

string perform_action_file(string action)
{
	return __DIR__"duoming-jinhua/" + action;
}

int help(object me)
{
	write(HIC"\n�����𻨣�"NOR"\n");
	write(@HELP

    ������Ϊ���������������������˿�ľ���������ݡ���
����������һ���������ޱȡ�

	ѧϰҪ��
		������40��
		����100
HELP
	);
	return 1;
}


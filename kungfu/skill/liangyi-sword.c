// liangyi-sword.c (kunlun) �����������ǽ���
// Last Modified by sir 10.22.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action= ({ // 12 ��
([	"action":"$Nһʽ"HIC"��˳ˮ���ۡ�"NOR"��$N����$wָ���Լ����ؿڣ�����бб�����⣬��������$n��$l",
	"lvl" : 0,
	"skill_name" : "˳ˮ����"
]),
([	"action":"$N����΢�࣬���ֺ�ڣ�����$wһ��"HIY"����ɨǧ����"NOR"��ֱ��$n�������ȥ",
	"lvl" : 10,
	"skill_name" : "��ɨǧ��"
]),
([	"action":"$N�����ǰ��$w��Ȼ���䵯�������ⱬ����һ��"HIB"���ͱڶ��ơ�"NOR"���͵ش���$n���ؿ�",
	"lvl" : 20,
	"skill_name" : "�ͱڶ���"
]),
([	"action":"$N�������������ƽ�ƶ�������ָ���������ֽ����첻����һ��"MAG"������ָ·��"NOR"������$n",
	"lvl" : 30,
	"skill_name" : "����ָ·"
]),
([	"action":"$N���к��䣬ʹ��һ��"GRN"�����ɻ���"NOR"��ȫ��б�ƣ����߰���б����ż����Ю��һ�����ƣ����˼���׽��",
	"lvl" : 40,
	"skill_name" : "���ɻ�"
]),
([	"action":"$N����$w�������𣬷�����£�һ��"BLU"����Įƽɳ��"NOR"�����ߵ��ƣ�����$n��$l",
	"lvl" : 50,
	"skill_name" : "��Įƽɳ"
]),
([	"action":"$Nһ��"YEL"��ľҶ������"NOR"��$N����$w������бָ���죬���϶��£�����$n��$l",
	"lvl" : 60,
	"skill_name" : "ľҶ����"
]),
([	"action":"$N��ǰһ����$w΢΢�����������㣬һ��"HIC"�����Ӳ��ߡ�"NOR"���ն���ʼ�����಻������$n",
	"lvl" : 70,
	"skill_name" : "���Ӳ���"
]),
([	"action":"$N���ֽ���һ�٣�������ʯ�⣬һ��"HIW"���������ơ�"NOR"���ý�����ס$n���б�����$wֱָ$n���ʺ�",
	"lvl" : 80,
	"skill_name" : "��������"
]),
([	"action":"$N����ؽ�������б����һ��"HIM"�����ɷ��١�"NOR"������Ӱ����ֱк��������ס$n�Ϸ�",
	"lvl" : 90,
	"skill_name" : "���ɷ���"
]),
([	"action":"$Nһʽ"HIB"��ѩӵ���š�"NOR"��$N���н������ţ�һ����������������$n",
	"lvl" : 100,
	"skill_name" : "ѩӵ����"
]),
([	"action":"$N�ڿն���ͻȻʹ��һ��"HIW"��������ɫ��"NOR"��������Ϣ�ؼ���$n�ı�����ȥ",
	"lvl" : 130,
	"skill_name" : "������ɫ"
]),
});

int valid_enable(string usage) { return (usage=="sword") || (usage=="parry"); }
int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 800)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("xuantian-wuji", 1) < 100)
		return notify_fail("��������޼������̫ǳ��\n");
	if ((int)me->query_skill("xunlei-sword", 1) < 80)
		return notify_fail("���Ѹ��ʮ�������̫ǳ��\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;
	int lvl = me->query_skill("liangyi-sword", 1);

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("qi") < 35 || (int)me->query("neili") < 15 )
		return notify_fail("��������������������ǽ�����\n");
	me->receive_damage("qi", 30);
	me->add("neili", -15);
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
	int d_e1 = 25;
	int d_e2 = 45;
	int p_e1 = -5;
	int p_e2 = 10;
	int f_e1 = 100;
	int f_e2 = 150;
	int m_e1 = 60;
	int m_e2 = 160;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("liangyi-sword", 1);
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
int learn_bonus() { return 25; }
int practice_bonus() { return 25; }
int success() { return 15; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"liangyi-sword/" + action;
}
/*mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int i;

	i=me->query_skill("liangyi-sword",1)/3;
	if(me->query_temp("ly_hebi")&& !me->query_temp("hebi_hit") 
		&& me->query_skill_mapped("parry") == "liangyi-sword")
	{
		me->set_temp("hebi_hit", 1);
		me->add_temp("apply/attack", i);
		COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), 1);
		me->add_temp("apply/attack", -i);
		me->delete_temp("hebi_hit");
	}
}*/
void double_attack(object me, object victim)
{
		int i;

	i=me->query_skill("liangyi-sword",1)/3;
	if(me->query_temp("ly_hebi")&& !me->query_temp("hebi_hit") 
		&& me->query_skill_mapped("parry") == "liangyi-sword")
	{
		me->set_temp("hebi_hit", 1);
		me->add_temp("apply/attack", i);
		COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), 1);
		me->add_temp("apply/attack", -i);
		me->delete_temp("hebi_hit");
	}
}
int help(object me)
{
	write(HIC"\n�����ǽ�����"NOR"\n");
	write(@HELP

    �����ǽ����������ɵĸ������
    ����˫����赣����ǻ��������������ԣ����������ˮ��
�ã�������ǿ��

	ѧϰҪ��
		�����޼���100��
		Ѹ��ʮ����80��
		����800
HELP
	);
	return 1;
}



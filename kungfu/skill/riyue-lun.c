// riyue-lun.c �����ַ�
// Last Modified by sir 10.23.2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$Nʹһ��"GRN"�������ơ�"NOR"���������е�$w��$n��$l��ȥ",
	"skill_name" : "������",
	"lvl" : 0
]),
([	"action" : "$Nʹһ��"BLU"����ɽ���ơ�"NOR"��˫��һ�����趯����$w��$n��$l��ɨ",
	"skill_name" : "��ɽ����",
	"lvl" : 8
]),
([	"action" : "$Nʹһ��"MAG"����΢�ơ�"NOR"���͵�һ�����������¶�������$n��$l",
	"skill_name" : "��΢��",
	"lvl" : 16
]),
([	"action" : "$Nʹһ��"RED"�������ơ�"NOR"���������֮��$wɨ��$n��$l",
	"skill_name" : "������",
	"lvl" : 24
]),
([	"action" : "$Nʹһ��"YEL"��Բ���ơ�"NOR"��$w������֮����ֱ��$n��$l",
	"skill_name" : "Բ����",
	"lvl" : 32
]),
([	"action" : "$NԾ���գ�ʹһ��"HIC"�����ػ��ơ�"NOR"���߾�$w����$n��$l",
	"skill_name" : "���ػ���",
	"lvl" : 40
]),
([	"action" : "$Nʹһ��"HIW"��׽���ơ�"NOR"��б������$w����$n��$l",
	"skill_name" : "׽����",
	"lvl" : 48
]),
([	"action" : "$N��һ��������ʹ��"HIR"���Լ��项"NOR"��$wɨ��$n��ͷ��",
	"skill_name" : "�Լ���",
	"lvl" : 56
]),
});

int valid_enable(string usage) { return usage == "hammer" || usage == "parry"; }
int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("longxiang", 1) < 20)
		return notify_fail("���������������̫ǳ��\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "hammer")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("qi") < 50 || (int)me->query("neili") < 50 )
		return notify_fail("���������������,�����������ַ���\n");
	me->receive_damage("qi", 40);
	me->add("neili", -40);
	return 1;
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
	object my_w, victim_w;
	object piece;
	victim_w = victim->query_temp("weapon");
	my_w = victim->query_temp("weapon");

//	if( me->query("dex") < 20 || me->query("str") < 20 )

	if (victim->query_temp("weapon") || victim->query_temp("secondary_weapon"))
	{
		if( (int)(me->query_skill("riyue-lun", 1)) < 20 )
			return HIW"һ�������ײ���������󣬶Է�������Ȼ�������\n"NOR;
		if( random(victim->query_temp("apply/damage")) < random(me->query_skill("riyue-lun", 1)/3 ) )
		{
			if (objectp(my_w = me->query_temp("weapon")) &&
				((string)my_w->query("id") == "fa lun" 
                                  ||(string)my_w->query("id")=="yin lun"
                                   ||(string)my_w->query("id")=="jin lun" ) 
                                   && my_w->query("ownmake") != 1)
			{
				seteuid(getuid());
				piece = new("/clone/misc/piece");
				piece->set_name(victim_w->query("name") + "����Ƭ",({victim_w->query("id"),"piece"}));
        piece->move(environment(victim));
				piece->set("long", "һ���������£������Ǳ�����Ƭ��\n");
				destruct(victim_w);
				return HIB "��������������һ�����������������������Ƭ����һ�أ�\n" NOR;
			}
			else return HIR"��ϧ��û�÷��֣�û������Է�������\n"NOR;
		}
	}
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
	int d_e1 = 20;
	int d_e2 = 40;
	int p_e1 = -40;
	int p_e2 = -20;
	int f_e1 = 300;
	int f_e2 = 400;
	int m_e1 = 100;
	int m_e2 = 250;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("riyue-lun", 1);
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
		"damage_type" : "����",
	]);
}
int learn_bonus() { return 10; }
int practice_bonus() { return 10; }
int success() { return 15; }
int power_point(object me) { return 1.0; }

int help(object me)
{
	write(HIC"\n�����ַ���"NOR"\n");
	write(@HELP

    �����ַ�Ϊ���ַ������书����ѩɽ�¼�Ϊ�Ե��Ĺ���

	ѧϰҪ��
		���������20��
		����100
HELP
	);
	return 1;
}


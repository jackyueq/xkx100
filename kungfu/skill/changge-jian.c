// changge-jian.c
// Last Modified by winder on May. 15 2001

#include <ansi.h>
inherit SKILL;
/* �书���ͣ���knowledge��martial martial��force��dodge��skill */
string type() { return "martial"; }
string martialtype() { return "skill"; }

/* ������Ϣ */
mapping *action = ({
([	"action"     : "$Nһ����̾��$w���һ��"MAG"�����Ĵ���ϧ���㡹"NOR"����$n��$l���̶�ȥ",
	"skill_name" : "���Ĵ���ϧ����",
	"lvl"        : 0,
]),
([      "action"     : "$N����üͷ���������к����Թ��$wһ��������һ��" MAG"���콫��������"NOR"����$n��$l",
	"skill_name" : "�콫��������",
	"lvl"        : 10,
]),
([      "action"     : "$N���첻������ӹ�һ˿�ǳ$w�ݻ���һ��" HIG"������İ������ݡ�"NOR"ңң����$n��$l",
	"skill_name" : "����İ�������",
	"lvl"        : 20,
]),
([      "action"     : "$N����������������˼����Ȼ���У���Ȼ�����ϯ��������������$n��$l����һ��"RED"������¥�е�Ϧ����"NOR,
	"skill_name" : "����¥�е�Ϧ��",
	"lvl"        : 30,
]),
([      "action"     : "$N���Ƿ��裬�����滺���裬������һ��" HIC"�������죬ˮãã��"NOR"��$w����$n��$l",
	"skill_name" : "�����죬ˮãã",
	"lvl"        : 40,
]),
([      "action"     : "$N΢��˫Ŀ��һ����į�����鲼�����ϣ��������أ�������ʱѹ������һ��"YEL"�����˹�·��೤��"NOR"�ɴ�$n��$l",
	"skill_name" : "���˹�·��೤",
	"lvl"        : 60,
]),
([      "action"     : "$Nб�г�������Х����ȴ�����˿�ɬ����ζ��$w�����·��̶���һ��"HIM"����˼������ƾ�"NOR"����$n��$l",
	"skill_name" : "��˼������ƾ��",
	"lvl"        : 80,
]),
([      "action"     : "$N����ҡͷ��˫Ŀ�������������$w��ӳ�Ų԰׵Ĺ�â�������ֵ����ֶ�����һ��"YEL"��Ī�򻨼�����С�"NOR+"����$n��$l",
	"lvl"        : 100,
	"skill_name" : "Ī�򻨼������",
]),
});

/* �м���Ϣ */
string *parry_msg = ({
	HIY"ȴ��$n̤ǰһ������ʽбָ$P���ұۣ���Ҫʹ$P������ˡ�\n"NOR,
	HIY"$nͻȻһ������$P��$l����һ��ȴ�����������ţ�$P�����޴룬���Ʋ�������ͣ��������\n"NOR,
});

/* �Ṧ��Ϣ */
string *dodge_msg = ({
	HIC"$nһ��"HIG"������Ū���ѡ�"HIC"��ƽ�ɺ�Ծ�������$N��һ�С�\n",
	HIC"$nһ��"HIY"����Į����ֱ��"HIC"������������������ܿ���$N����һ�С�\n",
	HIC"$nһ��"HIB"����������"HIY"��"HIB"��"HIC"�����λ�㱣�$Nֻ����ǰһ����������ա�\n",
	HIC"$n�ֱ�һת��˳��һ����һʽ"HIM"���������ϾƼ��ߡ�"HIC"����һ�ԡ�\n",
	HIC"$n����һ�ӣ�ת����ߣ�������"HIG"����������һ��ң��"HIC"�������۵�$N��ǰ��\n",
});

/* �ɼ������书���� */
int valid_enable(string usage)
{
	return usage=="sword" || usage=="parry" || usage == "dodge";
}

/* ���뻥�����书 */
int valid_combine(string combo) { return combo=="king-of-dragon"; }

/* ����Ч����������Ŀǰ����û���� */
int valid_effect(object me, object weapon, string name, int skill) { }

/* ѧϰ��������practiceҲҪ��Ȿ���������ԣ������������ڹ��������͹��ˡ� */
int valid_learn(object me)
{
	object ob;

	if( (int)me->query_skill("king-of-dragon", 1) < 200 )
		return notify_fail("��ĵ����񹦲������죬û�������轣����\n");
	if( (int)me->query("max_neili") < 200 )
		return notify_fail("�������������û�а취�����轣����\n");
	if( !(ob = me->query_temp("weapon")) || 
		(string)ob->query("skill_type") != "sword" )
		return notify_fail("���������һ�ѽ�������������\n");
	return 1;
}

/* ��ϰ������ */
int practice_skill(object me)
{
	if( (int)me->query("qi") < 30 || (int)me->query("neili") < 3 )
		return notify_fail("����������������û�а취��ϰ���轣����\n");
	me->receive_damage("qi", 30);
	me->add("neili", -3);
	write("�㰴����ѧ����һ�鳤�轣����\n");
	return 1;
}

/* ѧϰ���������� */
string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action); i > 0; i--)
		if(level >= action[i-1]["lvl"])
			return action[i-1]["skill_name"];
}

/* ��������Ϣ�������� */
void skill_improved(object me)
{
	tell_object(me, HIR "������һ�����棬����������\n" NOR );
	me->add("shen", 200);
}

/* ���жԷ��ĸ����� */
mixed hit_ob(object me, object victim, int damage_bonus)
{
	if( damage_bonus < 100 ) return 0;

	if( random(damage_bonus/2) > victim->query_temp("apply/armor") )
	{
		victim->receive_wound("qi", (damage_bonus - 20) / 2 );
		victim->apply_condition("xx_poison", 10 );
		return HIR "���������ۡ���һ�����죬��Ѫ�ɽ���\n" NOR;
	}
}

/* �����жԷ��ĸ����ã�Ŀǰ��Ҫ�����ڹ��� factor= ���� damage_bonus=���� */
mixed be_hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int ap, dp;

	ap=me->query_skill("force");
	dp=victim->query_skill("force");
	if ((int)random(ap/2)>dp && me->query("neili")>2000)
	{

		tell_object(me, HIY"��ֻ���þ���Ϯ�壬��æ����������񹦣�һ����������ȫ��\n"NOR);
		me->add("neili",-2*damage_bonus);
		return -damage_bonus;
	}
	return 0;
}

/* �����ɹ����书����Ϣ */
mapping query_action(object me, object weapon)
{
/* d_e=dodge_effect p_e=parry_effect f_e=force_effect m_e=damage_effect */
	int d_e1 = -30;
	int d_e2 = 30;
	int p_e1 = -30;
	int p_e2 = 30;
	int f_e1 = 150;
	int f_e2 = 230;
	int m_e1 = 250;
	int m_e2 = 350;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("changge-jian", 1);
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

/* �������м��书����Ϣ */
string query_parry_msg(string limb)
{
	return parry_msg[random(sizeof(parry_msg))];
}

/* �������Ṧ�Ĵ���Ϣ */
string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

/* �书�Ѷ�ϵ�� = 100 / (learn_bonus+parctice_bonus+10) ��skill.c���������� */
/* ÿ��Ǳ������ѧ���ı����ܵ��� = random(query_int()/2+query("int")/2+bonus) */
/* ���Ʒ�Χ 0 - 30 */
int learn_bonus() { return 10; }

/* ÿ����ϰ��ü��ܵ��� = (random(�����书*�����书/(skill+1)))/5+bonus */
/* ���Ʒ�Χ 0 - 30 */
int practice_bonus() { return 15; }

/* ��ʦ�����ڲ������ı��ʡ�random(success()) == 0��ʱ����⡣��ʱ���á�
��ֵԽ��Խ��������⡣��������˻�ͣ�ͣ���������learn & teach */
int success() { return 10; } 

/* �����������������ɲ��������Ʒ�Χ1��1.5���Ͻ����꣡Ŀǰ�������Ṧ�� */
int power_point() { return 1; }

/* �����ļ�Ŀ¼ */
string perform_action_file(string action)
{
	return __DIR__"changge-jian/" + action;
}

/* �ڹ�Ӧ���ļ�Ŀ¼ */
string exert_function_file(string func)
{
	return __DIR__"changge-jian/" + func;
}

/* ������Ϣ */
int help(object me)
{
	write(HIC"\n���轣����"NOR"\n");
	write(@HELP

    ���轣��������ҿ��š�
    ���轣���ɼ����ɽ������мܺ��Ṧ������NPC������
    
HELP
	);
	return 1;
}

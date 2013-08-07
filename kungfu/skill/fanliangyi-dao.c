// fanliangyi-dao.c �����ǵ���
// Last Modified by sega on Mar. 10 2000

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N����$wбָ��һ��"HIY"������һ�ơ�"NOR"������һ�٣�һ����$n��$l��ȥ",
	"lvl"    : 0,
	"skill_name" : "����һ��",
]),
([	"action" : "$Nһ��"HIC"��̫�����ȡ�"NOR"����������㣬$wһ��һ�գ�ƽ�л���$n�ľ���",
	"lvl"    : 20,
	"skill_name" : "̫������",
]),
([	"action" : "$Nչ���鲽������Ծ�䣬һ��"BLU"�����Ǻϵ¡�"NOR"�����滯������ն��$n",
	"lvl"    : 40,
	"skill_name" : "���Ǻϵ�",
]),
([	"action" : "$Nһ��"HIW"�����»�����"NOR"��$w�󿪴��أ����϶��»���һ���󻡣���ֱ����$n",
	"lvl"    : 60,
	"skill_name" : "���»���",
]),
([	"action" : "$N����$wһ����һ��"HIR"����ɫ���ࡹ"NOR"��˫�ֳ����������У�����$n���ؿ�",
	"lvl"    : 80,
	"skill_name" : "��ɫ����",
]),
([	"action" : "$N����$w��ʹ��һ��"HIB"����ٲ�����"NOR"���������ã����ҿ�����������$n",
	"lvl"    : 100,
	"skill_name" : "��ٲ���",
])
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 300)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("zixia-shengong", 1) < 50)
		return notify_fail("��ġ���ϼ�񹦡����̫ǳ��\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if( !me->query_skill("zixia-shengong",1))
		return notify_fail("���������ǵ���������Ҫ�ԡ���ϼ�񹦡�Ϊ������\n");
	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("��������������������ǵ�������\n");
	me->receive_damage("qi", 25);
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
	int d_e1 = 55;
	int d_e2 = 30;
	int p_e1 = 0;
	int p_e2 = -15;
	int f_e1 = 100;
	int f_e2 = 150;
	int m_e1 = 50;
	int m_e2 = 160;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int)me->query_skill("fanliangyi-dao", 1);
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
int learn_bonus() { return 20; }
int practice_bonus() { return 15; }
int success() { return 15; }
int power_point() { return 1; }
string perform_action_file(string action)
{
	return __DIR__"fanliangyi-dao/" + action;
}
/*
int form_array(object leader)
//int perform(object leader, object target)
{
	object *member,ob, weapon;
	int i,j,n;
	int max,min,skill;

	member = leader->query_team();
	if( sizeof(member) != 2 )
		return notify_fail("�����ǵ��������ˣ���һ����һ�������С�\n");

	j=sizeof (member);
	for (i=0;i<j;i++)
	{
		ob=member[i];
		if (!ob || !living(ob) || ob->query_temp("noliving") ||
			!ob->is_character())
		{
			return notify_fail("�����˭ͬʹ�����ǵ���\n");
		}
		if (ob->query_temp("array/name"))
		{
			return notify_fail("�Ѿ���ɵ����ˡ�\n");
		}
		if (environment(leader)!=environment(ob))
		{
			return notify_fail("�����������ˡ�\n");
		}
		if (!ob->query_skill("fanliangyi-dao",1))
		{
			return notify_fail(ob->name()+"�����ᷴ���ǵ�����\n");
		}
		if (ob->is_ghost())
		{
			return notify_fail("ֻ��������˲����鵶��\n");
		}

		if( (int)ob->query("max_neili") < 50 )
			return notify_fail(ob->query("name")+"������������\n");

		if( (string)ob->query_skill_mapped("force")!= "zixia-shengong")
			return notify_fail(ob->query("name")+"û��ʹ�û�ɽ���ڹ���\n");

		if( !(weapon = ob->query_temp("weapon"))
			|| (string)weapon->query("skill_type") != "blade" )
			return notify_fail(ob->query("name")+"�����ðѵ���������\n");

		if( (int)ob->query_skill("fanliangyi-dao",1)<30)
			return notify_fail(ob->query("name")+"�ķ����ǵ���������������\n");

		if( (string)ob->query_skill_mapped("blade")!="fanliangyi-dao")
			return notify_fail(ob->query("name")+"����ʹ�÷����ǵ�����\n");

	}

//get the average array skill of the team
	n=0;
	for (i=0;i<j;i++)
	{
		ob=member[i];
		n+=(int)ob->query_skill("fanliangyi-dao",1);
	}
	n/=2;

//get the difference of the array skill,
//first get the max and mix skill level of the array
	max=member[0]->query_skill("fanliangyi-dao",1);
	min=max;
	for (i=0;i<j;i++)
	{
		skill=member[i]->query_skill("fanliangyi-dao",1);
		if(skill>max)
			max=skill;
		else if(skill<min)
			min=skill;
	}

//and the leader is important
	n += leader->query_skill("fanliangyi-dao", 1) * 5;
	n /= max - min + 1;
	for (i=0;i<j;i++)
	{
		ob=member[i];
		ob->set_temp("no_quit",1);

		ob->set_temp("array/name","fanliangyi-dao");
		ob->set_temp("array/level",n);

		ob->add_temp("apply/attack",n);
		ob->add_temp("apply/defense", n);
		ob->add_temp("apply/damage",n);
		ob->add_temp("apply/armor", n);
	}
	message_combatd(HIG"$N����$Nվ�����Ƿ�λ����ʱ����֮���Եû�Ȼ��ɡ�����������\n" NOR, leader);
	return 1;
}
int dismiss_array(object person)
{
	int i,j,n;
	object *member,ob;

	member = person->query_team();
	j=sizeof(member);
	n=person->query_temp("array/level");
	for (i=0;i<j;i++)
	{
		ob=member[i];
		ob->delete_temp("array");
		ob->add_temp("apply/attack",-n);
		ob->add_temp("apply/damage",-n);
		ob->add_temp("apply/defense",-n);
		ob->add_temp("apply/armor", -n);
		tell_object(ob,"�����ɢ��\n");
	}
}

//if the leader kills enemy, then all members in the array kill enemy
int array_kill(object leader, object enemy)
{
	object *member, ob;
	int i,j;
	member=leader->query_team();
	j=sizeof(member);

	for(i=0;i<j;i++)
	{
		ob=member[i];
		ob->kill_ob(enemy);
	}

	return 1;
}
int effective_level() { return 10;}
*/
int help(object me)
{
	write(HIC"\n�����ǵ�����"NOR"\n");
	write(@HELP

    �����ǵ����ǻ�ɽ�ɹ������ǻ��������󻯰��ԣ������
����ʮ���У����˰���ʮ���У�������ϣ���ʮ��������ʮ�ı�
֮��������ǧ���ʮ���ֱ仯�������书�仯֮������˵�޳�����
�ˡ�������࣬�վ�������̫����Ϊ�������ǵĵ�������̫����
����������������̫������Ϊ����̫��ΪǬ�ң�����Ϊ������
��Ϊ�㿲��̫��Ϊ������Ǭ�ϡ��������붫���������𶫱����Ҷ�
�ϡ������ϡ���������������ǬΪ˳����������Ϊ�档��ض�λ��
ɽ��ͨ�����׷��ౡ��ˮ�����䣬�������������˳��֪����
�档�����ǽ�����������λ��Ǭλ��˳����ɽ�ɷ����ǵ���������
����λ����λ���档

	ѧϰҪ��
		��ϼ��50��
		����300
HELP
	);
	return 1;
}


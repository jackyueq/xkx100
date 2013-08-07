// six-fingers.c ������
// Last Modified by sir 10.22.2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"skill_name" : "���̽�",
	"action": "$N����������˫��Ĵָͬʱ����������������죬�����̽���
����ʯ���쾪���������֮�ƣ���ָ$n���к�$l",
	"lvl"   : 0
]),
([	"skill_name" : "������",
	"action": "$Nʳָ����������԰ת������������һ����һ���Ĵ̳�������
Ѹ�٣����ɻ��ã������ݺᣬ$n�����޷�������·",
	"lvl"   : 10
]),
([	"skill_name" : "�г彣",
	"action": "$N������ָһ�������г彣����ǰ�̳��������ĵ�����Ȼ���죬
���ν���ֱָ$n��$l",
	"lvl"   : 20
]),
([	"skill_name" : "�س彣",
	"action": "$N��������ָ��������س彣����·׾�͹��ӣ�һ���ۻ����
���ĵ�����������ɽ��������$nӿȥ",
	"lvl"   : 30
]),
([	"skill_name" : "����",
	"action": "$N����Сָһ�죬һ���������ٳ�Ѩ�м�������������󽣡�
������磬ָ��$n��$l",
	"lvl"   : 40
]),
([	"skill_name" : "�ٳ彣",
	"action": "$N���ַ�ָ��Сָ������������ٳ�Ѩ���������������󽣡�
������䣬��$n���벻���ķ������$n��$l",
	"lvl"   : 50
]),
});

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }
int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�������񽣱�����֡�\n");
	if ((int)me->query("max_neili") < 1200)
		return notify_fail("�������̫�����޷�ѧ�����񽣡�\n");
	if ((int)me->query_skill("kurong-changong",1) < 120)
		return notify_fail("��Ŀ�������̫�ͣ��޷�ѧ�����񽣡�\n");
	return 1;
}
int practice_skill(object me)
{
	object* ob, obj;
	int i,skill,damage,cost;
	cost=40;
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��ı�����ֲ�����ϰ��\n");
	if ((int)me->query("qi") < 160)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 50)
		return notify_fail("������������������񽣡�\n");
	if( skill > 100 && me->query("shen") < 1)
		return notify_fail("�����书�����������¡�\n");
	if ((int)me->query_skill("six-finger", 1)>150) cost=80;
	if ((int)me->query_skill("six-finger", 1)>250) cost=160;
	me->receive_damage("qi", cost);
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
mixed hit_ob(object me, object victim, int damage_bonus)
{
	if( damage_bonus < 100 ) return 0;

	if( random(damage_bonus/2) > victim->query_str() )
	{
		victim->receive_wound("qi", (damage_bonus - 100) / 3 );
		return HIR "��������������һ�����죬���Ͼ�����һЩѪ�Σ�\n" NOR;
	}
}
mapping query_action(object me, object weapon)
{
	int d_e1 = 25;
	int d_e2 = 5;
	int p_e1 = -30;
	int p_e2 = -50;
	int f_e1 = 500;
	int f_e2 = 600;
	int i, lvl, seq, ttl = sizeof(action);

	if (random(me->query_skill("six-finger",1)) > 60 &&
		me->query_skill("kurong-changong",1) > 60 &&
		me->query("neili") > 100)
	{
		me->add("neili",-50);
		return ([
			"action" : "$N��Ȼ���ý����е���·����һһӿ����ͷ��ʮָ�׵�����ȥ�����������޾��������ݺᣬ����������·������ת��ʹ��$n��ʱ������ң�����ȫ������ʹ��������Ѫ�����ϱ������ʹ̧ͷһ����һ������ӭ���ֵ�",
			"dodge": 5,
			"parry": -50,
			"force": 600,
			"damage_type": "����"]);
	}
	else
	{
		lvl = (int)me->query_skill("six-finger", 1);
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
}
int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 5; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"six-finger/" + action;
}
int help(object me)
{
	write(HIC"\n�����񽣣�"NOR"\n");
	write(@HELP

    �������Ǵ�����ϲ���֮�ء�������Ϊ������ѧ֮��������
����Ϊ��������֮�����׼ҵ����޷������ð¡������񽣲�����ͨ
����������������������ָ�������˵������Σ��༴����������

	ѧϰҪ��
		��������120��
		����1200
HELP
	);
	return 1;
}



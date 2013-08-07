// hamagong.c ��󡹦
// Last Modified by sega on Mar. 10 2000

#include <ansi.h>;
#include "force.h";
inherit FORCE;
string type() { return "martial"; }
string martialtype() { return "force"; }

int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 10; }
int power_point(object me) { return 1; }

mapping *action = ({
([	"action" : "$N����������һ�ֳŵأ����Ӻ�ͦ��ֻ��һ����$n��$l�ĳ�",
	"lvl" : 0,
	"skill_name" : "��󡹦"
]),
([	"action" : "$N˫���ڵ���һ�ţ����Ӻ��ذ���һԾ���ߣ�����$n����ǰ��������$pֱ������",
	"lvl" : 10,
	"skill_name" : "��󡹦"
]),
([	"action" : "$NͻȻ�������Լ�������ץһ�ѣ��ַ������Լ����Ϻ���һ�ţ�һ�ƻ�������;����ر䣬ʵ��֪����δ�",
	"lvl" : 20,
	"skill_name" : "��󡹦"
]),
([	"action" : "ͻȻ֮�䣬$N������������ȫȻ���أ�΢΢��ͷ��һ����ĭ��$n$l��ȥ",
	"lvl" : 30,
	"skill_name" : "��󡹦"
]),
([	"action" : "$N˿��������ɫ��˫��΢��������ƽ�죬���ƻ��������󡹦�ľ���������һ������$n",
	"lvl" : 80,
	"skill_name" : "��󡹦"
]),
([	"action" : "$NĬ��ھ�����������ֻ����ת����˳�죬����һ������Ծ�𣬹���һ���к���˫�ƶ���$n�ĳ�",
	"lvl" : 110,
	"skill_name" : "��󡹦"
]),
([	"action" : "����$N˫��΢����˫�ƻ��գ�Ȼ����$nһ��һ�£�һ��һ�գ���Ȼ����",
	"lvl" : 140,
	"skill_name" : "��󡹦"
]),
([	"action" : "$N���۱�ס����������Ƭ�̣���Ծ�����۾�Ҳ����������˫�Ʊ���$n�ķ������˳�ȥ",
	"lvl" : 170,
	"skill_name" : "��󡹦"
]),
([	"action" : "$N�Ų�ҡҡ�ϻϵĿ���ȥ���Ͼͻ��������Ȼ˫��һ�䡢һ�ǣ����и��һ���кȣ�������$n��Ȼ�Ƴ�",
	"lvl" : 199,
	"skill_name" : "��󡹦"
]),
});
/*
mapping *action = ({
([	"action": "$N����һԾ��ʹ��һ��" + HIY"��ɳĮ���ۡ�"NOR + "�����ƺᣬ���ƴ�����$n�ƿ���",
	"force" : 200,
	"dodge" : 20,
	"damage": 240,
	"skill_name": "ɳĮ����",
	"damage_type": "����"
]),
([	"action":"ֻ��$Nٿ����ǰ���һ����һ��" + WHT"��������项"NOR + "��˫��һ��˳�ƹ���$n",	
	"force" : 220,
	"dodge" : 20,
	"damage": 250,
	"skill_name": "�������",
	"damage_type": "����"
]),
([	"action":"$Nһ��" + HIW"����ɳ���̡�"NOR + "�����������޷�������΢�£�����$n����",
	"force" : 400,
	"dodge" : 30,
	"damage": 250,
	"skill_name": "��ɳ����",
	"damage_type": "����"
]),
([	"action":"$N��ü���������������ޣ�ǡǡ��$n����һһ��ס������������֮�⣬����һ��" + HIR"������Ūѩ��"NOR + "��",
	"force" : 225,
	"dodge" : 30,
	"damage": 270,
	"skill_name": "����Ūѩ",
	"damage_type": "����"
]),
([	"action":"$Nһ��" + HIB"����޿�;��"NOR + "�������Ჽ�����˷�����˫��ƽ�ƣ������������ֱ����$n��",
	"force" : 530,
	"dodge" :-20,
	"damage": 300,
	"skill_name": "��޿�;",
	"damage_type": "����"
]),
});
*/

int valid_enable(string usage) { return usage == "force"||usage == "strike"; }
int valid_combine(string combo) { return combo=="shexing-diaoshou"; }

int valid_learn(object me)
{
	int i = (int)me->query_skill("hamagong", 1);
	int t = 1, j;
	mapping myfam;
	
	myfam = (mapping)me->query("family");
/*
	if(!myfam || myfam["family_name"] != "����ɽ��"|| myfam["master_id"] != "ouyang feng")
		return notify_fail("��󡹦�˲����񹦣�����ŷ����������̡�\n");
*/
	if( i <= 100) for (j = 1; j < i / 10; j++) t*= 2;

	if ( me->query("gender") == "����" && i > 49)
		return notify_fail("���޸����ԣ���������������������ĸ�󡹦��\n");

	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("��Ļ����ڹ�����㣬����ѧ��󡹦��\n");

	if(i<=100)
	{
		if (i > 10 && -(int)me->query("shen") < t * 100) 
			return notify_fail("ѧ��󡹦��Ҫ�ĺ���������������������ò���ѽ��\n");
	}
	else
	{
		if (-(int)me->query("shen") < (51200 + (i - 100) * 1000)) 
			return notify_fail("ѧ��󡹦��Ҫ�ĺ���������������������ò���ѽ��\n");
	}
	return valid_public(me);
}
int practice_skill(object me)
{
	return notify_fail("��󡹦ֻ����ѧ(learn)�������������ȡ�\n");
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
	int d_e1 = -40;
	int d_e2 = -20;
	int p_e1 = 0;
	int p_e2 = 30;
	int f_e1 = 190;
	int f_e2 = 300;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("hamagong", 1);
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

string exert_function_file(string func)
{
	return __DIR__"hamagong/" + func;
}
string perform_action_file(string action)
{
	return __DIR__"hamagong/" + action;
}

int help(object me)
{
	write(HIC"\n��󡹦��"NOR"\n");
	write(@HELP

    ŷ���洴���˹���Ϊ����ɽ�ɱ����ڹ����˹�Ҳ����Ϊ�Ʒ�ʹ
�ã����������ε��ֻ�����
    ���󡹦��ϵ�Ծ��ƶ�����ȫ�������ƣ��������£�ֻҪ��
��һʩ��������ʱ���������ޱȵľ�������������������ƥ��

	ѧϰҪ��
		�����ڹ�10��
		̫���޷�����50�����ϵĸ�󡹦
		��Ӧ������
HELP
	);
	return 1;
}


// taixuan-gong.c ���͵�̫����
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>;
inherit SKILL;
inherit FORCE;
string type() { return "martial"; }
string martialtype() { return "force"; }

int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 10; }
int power_point(object me) { return 1; }

string *dodge_msg = ({
	"$n�����ĳ������絽������$N��һ�ߡ�\n",
	"$n�ֱۻ�ת��ץס$N����һ�ƣ���$NԶԶ������\n",
	"$n������ţ���Ծ��������������ʮ�����⡣\n",
	"$Nֻ����ǰһ����ֻ����$n����һ�ϣ��Լ���������ȻĪ�����������ˡ�\n",
});

mapping *action = ({
([	"action":"$N˫��һ�٣�һ�ɾ���������ӿ�������Ƶ�$n���Ժ���",
	"lvl": 0
]),
([	"action":"$N�����������$n�۰���Ѹ���ޱȵ�һ����$nһ�ӵ��˳�ȥ",
	"lvl": 10
]),
([	"action":"$N���һ�����ſ�һ��������$n������ȥ",
	"lvl": 20
]),
([	"action":"$N�����ϣ�˫���͵�����$n",
	"lvl": 30
]),
([	"action":"$N����΢�࣬ͻȻ����һ�ţ�����$n����·���ŵ���;���͵�һ̧������$n����",
	"lvl": 40
]),
([	"action":"$NͻȻ������һ�࣬��ס$n��·������������ӿ����",
	"lvl": 50
]),
});

int valid_enable(string usage)
{
	return usage == "unarmed" || usage == "dodge" || usage == "parry" || usage == "force";
}
mapping query_action(object me, object weapon)
{
/* d_e=dodge_effect p_e=parry_effect f_e=force_effect m_e=damage_effect */
	int d_e1 = 30;
	int d_e2 = 50;
	int p_e1 = -30;
	int p_e2 = 10;
	int f_e1 = 440;
	int f_e2 = 600;	
	int i, lvl, seq, ttl = sizeof(action);
	if (random(me->query_skill("taixuan-gong",1)) > 220 && me->query("neili") > 100)
	{
		me->add("neili", -50);
		return ([
	"action": HIR "$N������ͻȻһƬãȻ��ֻ���þ�������������������ڴ�����ȥ���ѹ��ǳ���
���²������룬˳����������һ��ȭ����ߣ����ܶ�ʱ������쩣��ò����֣�"NOR,
//	"damage": 1000,
  "parry" : -80,
  "dodge" : -40,
	"force" : 1000,
	"damage_type": "����"]);
	}
	lvl = (int) me->query_skill("taixuan-gong", 1);
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

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}
int valid_learn(object me)
{
	return notify_fail("�������̫������ֻ�ܵ����͵�ȥ��ڡ�\n");
}
string exert_function_file(string func)
{
	return __DIR__"taixuan-gong/" + func;
}
int help(object me)
{
	write(HIC"\n̫������"NOR"\n");
	write(@HELP

    ̫����Դ�����͵��϶����书��

	ѧϰҪ��
		�����Լ��ĸ�Ե
HELP
	);
	return 1;
}


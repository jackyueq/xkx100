// feixing-shu.c ������
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

string *dodge_msg = ({
	"$n��һ����һ�Σ��漴�ص�ԭ�أ����ɵض����$N��һ�С�\n",
	"$n����Ծ��һ���շ�����˳������һ�ߡ�\n",
	"$n�������Ա�һ�ݣ�������$N�����൱�ľ��룬$N��һ����ȻʧЧ��\n",
	"$n������ϣ������Ծ��$N��������$N�ı���\n",
	"$n���μ�����б��ǰһ������Ȼ�Ѿ��㿪��$N����һ�С�\n",
	"$N��ǰһ����ȴ��$n��Ȼ�����Լ�������֮Զ��ȴû��$n��ζ���Լ��Ĺ����ġ
�\n",
	"$Nһ��������$n��û����Ӱ��$N��ת��ȴ��$n���Ƕ����Լ����֡�\n",
	"$Nһ�й�����$n��Ȼ������$NãȻ�Ĺˣ�ȴ����$n��Ӱ�ӣ�\n",
});

mapping *action = ({
([	"action" : "$N������ˣ�һ�С���¶��â��������$w����һ�㺮â����$n",	
	"damage": 130,
	"dodge" : 40,
	"post_action": (: call_other, "/adm/daemons/weapond", "throw_weapon" :),
	"damage_type": "����",
	"lvl" : 0,
	"skill_name" : "��¶��â"
]),
([	"action" : "$N����΢��ǰһ�죬ʹ����է���ǳ���������$w��ֱ����$n��˫��",
	"damage": 40,
	"dodge" : 45,
	"post_action": (: call_other, "/adm/daemons/weapond", "throw_weapon" :),
	"damage_type": "����",
	"lvl" : 9,
	"skill_name" : "է���ǳ�"
]),
([	"action" : "$Nһ����Х��ʩչ������ҹ���ǡ�������΢��������$w��Ȼ���Ϸ�\n�����˸�Ȧ�����Ѹ��Ϯ��$n������",
	"damage": 50,
	"dodge" : 40,
	"post_action": (: call_other, "/adm/daemons/weapond", "throw_weapon" :),
	"damage_type": "����",
	"lvl" : 18,
	"skill_name" : "��ҹ����"
]),
([	"action" : "$Nʹһ�С��ǹ���˸����ͻȻ�������һ�����������ڿ���ص�һ˲�䣬$n��Ȼ���ּ��㺮����˸������Ϯ���Լ�",
	"damage": 135,
	"dodge" : 55,
	"post_action": (: call_other, "/adm/daemons/weapond", "throw_weapon" :),
	"damage_type": "����",
	"lvl" : 27,
	"skill_name" : "�ǹ���˸"
]),
([	"action" : "$N����һ�ӣ�һ�С���â��������$n��������$N�����$w�������Լ�����ǰ��Ѩ�����˽���ȴͻȻת�����Լ��ĺ���",
	"damage": 160,
	"dodge" : 50,
	"post_action": (: call_other, "/adm/daemons/weapond", "throw_weapon" :),
	"damage_type": "����",
	"lvl" : 36,
	"skill_name" : "��â����"
]),
([	"action" : "$N����������һ����ʹ����׹��֮�ǡ�������$wƽֱ������$n���ʺ�ȴ�ּ��ϰ���ʹ֮��;��������$n������",
	"damage": 140,
	"dodge" : 54,
	"post_action": (: call_other, "/adm/daemons/weapond", "throw_weapon" :),
	"damage_type": "����",
	"lvl" : 45,
	"skill_name" : "׹��֮��"
]),
([	"action" : "$N����һԾ����ʩչ��������֮�ǡ��������$w�������±�ֱ������$n��ͷ��",
	"damage": 85,
	"dodge" : 10,
	"post_action": (: call_other, "/adm/daemons/weapond", "throw_weapon" :),
	"damage_type": "����",
	"lvl" : 54,
	"skill_name" : "����֮��"
]),
([	"action" : "$Nԭ��һ����ת���漴˫��һ����$w��ƮƮ�����ط���$n��ԭ�������ǡ��ǳ����롻",
	"force":40,
	"damage": 110,
	"dodge" : 55,
	"post_action": (: call_other, "/adm/daemons/weapond", "throw_weapon" :),
	"damage_type": "����",
	"lvl" : 63,
	"skill_name" : "�ǳ�����"
]),
([	"action" : "$Nʹ��һ�С��ǹ���𡻣�ǰ��һ�壬�漴�����������$w����˿������ȴ��Ѹ���ޱȵ�����$n��ǰ��",
	"force":63,
	"damage": 120,
	"dodge" : 60,
	"post_action": (: call_other, "/adm/daemons/weapond", "throw_weapon" :),
	"damage_type": "����",
	"lvl" : 72,
	"skill_name" : "�ǹ����"
]),
([	"action" : "$NͻȻ��������ˣ�ʹ�����ǿ�ը�ס���˫����ǰһ�ƣ�����$w��������������������$n",
	"force":70,
	"damage": 110,
	"dodge" : -5,
	"post_action": (: call_other, "/adm/daemons/weapond", "throw_weapon" :),
	"damage_type": "����",
	"lvl" : 81,
	"skill_name" : "�ǿ�ը��"
]),
([	"action" : "$Nʩչ����"+HIW"�ǻ�����"NOR+"����ԭ�ز����������΢΢��ǰһ��������$w����һ�㺮���Բ��������$n",
	"force":90,
	"damage": 160,
	"dodge" : 50,
	"post_action": (: call_other, "/adm/daemons/weapond", "throw_weapon" :),
	"damage_type": "����",
	"lvl" : 90,
	"skill_name" : "�ǻ�����"
]),
([	"action" : "$N΢΢����ʹ����"+HIY"�ǹ�����"NOR+"������ӰƮ��������$n�پ�ʮ�ִ��ۣ�ȴ��$N�����$w��Ю�ŵ��ϵ�ɳʯ�Լ���Χ����ҳ�����Լ�",
	"force":100,
	"damage": 130,
	"dodge" : 65,
	"post_action": (: call_other, "/adm/daemons/weapond", "throw_weapon" :),
	"damage_type": "����",
	"lvl" : 99,
	"skill_name" : "�ǹ�����"
]),
([	"action" : "$N��Ȼ��̾һ����ת����У�$n�����ɼ䣬ȴ����ǰ�Ѿ���$w��Ӱ�ӣ��ۿ��޴��ɶ��ˣ�ֻ�����о��ǡ�"+HIC"��������"NOR+"���ˣ�$n���ɴ�ʧɫ",
	"force": 88,
	"damage": 120,
	"dodge" : 70,
	"post_action": (: call_other, "/adm/daemons/weapond", "throw_weapon" :),
	"damage_type": "����",
	"lvl" : 110,
	"skill_name" : "��������"
])
});

int valid_enable(string usage)
{
	return usage=="throwing" || usage=="dodge" || usage=="parry" || usage=="move";
}

int valid_learn(object me)
{
	if ((int)me->query_skill("huagong-dafa", 1) < 20)
		return notify_fail("��Ļ����󷨻�򲻹����޷�ѧ��������\n");
	if ((int)me->query_skill("dodge", 1) < 20)
		return notify_fail("����Ṧ��򲻹����޷������������\n");
	if ((int)me->query_dex() < 25)
		return notify_fail("������������ɣ��޷������������\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;
	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "throwing")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("qi") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 30)
		return notify_fail("���������������������\n");
	me->receive_damage("qi", 30);
	return 1;
}
string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action)-1; i >= 0; i--)
	if(level >= action[i]["lvl"])
		return action[i]["skill_name"];
}
mapping query_action(object me, object weapon)
{
	int i, level;
	level = (int)me->query_skill("feixing-shu", 1);
	for(i = sizeof(action); i > 0; i--)
	if(level > action[i-1]["lvl"])
		return action[NewRandom(i, 20, level/5)];
}
string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}
int learn_bonus() { return 10; }
int practice_bonus() { return 5; }
int success() { return 10; }
int power_point(object me) { return 1; }

string perform_action_file(string action)
{
	return __DIR__"feixing-shu/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	if( random(me->query_skill("poison",1)) > 20)
	{
		victim->apply_condition("xx_poison", random(2) + 1 + victim->query_condition("xx_poison"));
	}
}

int help(object me)
{
	write(HIC"\n��������"NOR"\n");
	write(@HELP

    �������������ɰ�����

	ѧϰҪ��
		������20��
		�����Ṧ20��
		������25
HELP
	);
	return 1;
}


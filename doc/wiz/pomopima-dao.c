// ��ī���鵶��

inherit SKILL;

mapping *action = ({
	([  "action":       "$Nʹһ�С��׺���ա�������$w��ƮƮ����$n��$lնȥ��",
		"damage":	100,
		"damage_type":	"����"
	]),
	([  "action":       "$N�������磬$w����һ�С�������硹���¶�������$n��$l",
		"damage":	120,
		"damage_type":	"����"
	]),
	([  "action":       "$N����һת��һ�С�����������$w���ⲻ����ն��$n��$l",
		"damage":	140,
		"damage_type":	"����"
	]),
	([  "action":       "$N�趯$w��һ�С��ĳ���ң��Ѹ�����׵�����$n��$l",
		"damage":	160,
		"damage_type":	"����",
	]),
	([  "action":       "$N����$wһ�Σ�һ�С���ɽ���ɡ���$n��$lбб����һ��",
		"damage":	180,
		"damage_type":	"����",
	]),
	([  "action":       "$N�ᵶ���磬�������һ�С�����������ֱ��$n$l",
		"damage":	200,
		"damage_type":	"����",
	]),
	([  "action":       "$N�Ʋ�����ʹһ�С���ɽ��Ұ���������ն��$n��$l",
		"damage":	250,
		"damage_type":	"����",
	]),
});

int valid_learn(object me)
{
	if(me->query_skill("xuantian-quan",1)<20)
		return notify_fail("��ġ�����ȭ����������졣\n");
	if(me->query_skill("xuantian-neigong",1)<20)
	return notify_fail("��ġ������ڹ�������������\n");
	if(me->query("max_force")<50)
	return notify_fail("���������Ϊ������\n");
	return 1;
}

int valid_enable(string usage)
{
	return (usage=="blade") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	object weapon;

	if( !objectp(weapon = me->query_temp("weapon"))
	||	(string)weapon->query("skill_type") != "blade" )
		return notify_fail("���������һ�ѵ���������������\n");

	if( (int)me->query("kee") < 40 )
		return notify_fail("����������������ŵ�������������Ϣ��Ϣ�ɡ�\n");
	me->receive_damage("kee", 40);
	return 1;
}

string perform_action_file(string action)
{
return "/daemon/class/meizhuang/pomopima-dao/"+action;
}
int power_point()	{	return 1.25;	}

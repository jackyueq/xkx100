// pomopima-jian.c��ī���齣��

inherit SKILL;

mapping *action = ({
([	"action":       "$Nʹһ�С��׺���ա�������$w��ƮƮ����$n��$lնȥ��",
	"damage":	100,
	"damage_type":	"����"
]),
([	"action":       "$N�������磬$w����һ�С�������硹���¶�������$n��$l",
	"damage":	120,
	"damage_type":	"����"
]),
([	"action":       "$N����һת��һ�С�����������$w���ⲻ����ն��$n��$l",
	"damage":	140,
	"damage_type":	"����"
]),
([	"action":       "$N�趯$w��һ�С��ĳ���ң��Ѹ�����׵�����$n��$l",
	"damage":	160,
	"damage_type":	"����",
]),
([	"action":       "$N����$wһ�Σ�һ�С���ɽ���ɡ���$n��$lбб����һ��",
	"damage":	180,
	"damage_type":	"����",
]),
([	"action":       "$N�ὣ���磬�������һ�С�����������ֱ��$n$l",
	"damage":	200,
	"damage_type":	"����",
]),
([	"action":       "$N�Ʋ�����ʹһ�С���ɽ��Ұ���������ն��$n��$l",
	"damage":	250,
	"damage_type":	"����",
]),
});

int valid_learn(object me)
{
	if(me->query_skill("xuantian-zhi",1)<20)
		return notify_fail("��ġ�����ָ����������졣\n");
	if ((int)me->query_skill("kuihua-xinfa", 1) < 80)
		return notify_fail("��Ŀ����ķ���򲻹���\n");
	if(me->query("max_neili")<50)
		return notify_fail("���������Ϊ������\n");
	return 1;
}

int valid_enable(string usage)
{
	return (usage=="sword") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	object weapon;

	if( !objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "sword" )
		return notify_fail("���������һ�ѽ���������������\n");

	if( (int)me->query("qi") < 40 )
		return notify_fail("����������������Ž�������������Ϣ��Ϣ�ɡ�\n");
	me->receive_damage("qi", 40);
	return 1;
}


// jiangjun-zhang.c �Ὣ��ʫ�ȷ�

inherit SKILL;

mapping *action = ({
([      "action":               
"$N����$w��$n��$l�������㣬���ǡ��᡹���������ʣ�",
	"damage":		100,
	"damage_type":  "����"
]),
([      "action":               
"$N����$w����׼$n��$l��㣬�����Ͻ������½��������£����ǡ��硹�ֲ��飡",
	"damage":		120,
	"damage_type":  "����"
]),
([      "action":               
"$N���$w��д�˸����͡��֣�����$nбɨ��ȥ��",
	"damage":		140,
	"damage_type":  "����"
]),
([      "action":               
"$N���һ�����ʷ�һ��д�����������֣�$wһͦײ��$n$l��",
	"damage":		160,
	"damage_type":  "����"
]),
([	"action":
"$N����΢ת��$w����$n��$l��ɨ��ȥ��˳�ƴ������������֣�",
	"damage":		180,
	"damage_type":		"����",
]),
([	"action":
"$N�߸�Ծ������$w��������׳���֣�����$n��$lײ�˹�����",
	"damage":		200,
	"damage_type":		"����",
]),
([	"action":
"$Nŭ��һ��������$w�������Ǹ����ڡ��֣���$n$l�������£�",
	"damage":	250,
	"damage_type":	"����",
]),
});

int valid_learn(object me)
{
	if(me->query_skill("xuantian-zhi",1)<20)
		return notify_fail("��ġ�����ָ����������졣\n");
	if ((int)me->query_skill("kuihua-xinfa", 1) < 120)
		return notify_fail("��Ŀ����ķ���򲻹���\n");
	if(me->query("max_neili")<50)
		return notify_fail("���������Ϊ������\n");
        return 1;
}

int valid_enable(string usage)
{
        return (usage=="staff") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        object weapon;

        if( !objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "staff" )
                return notify_fail("���������һ��ľ�Ȼ��������Ƶ��������������ȷ���\n");

	if((int)me->query("qi") <40)
                return notify_fail("������������������ȷ�����������Ϣ��Ϣ�ɡ�\n");
	me->receive_damage("qi",40);
        return 1;
}
 

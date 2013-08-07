// tiezhang-zhangfa.c �����Ʒ�
// Last Modified by winder on Nov. 15 2000

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N����һ������һ��"CYN"���ƴ����¡�"NOR"���Բ����������򣬵�ʱ��$n��������б��",
	"lvl"    : 0,
	"skill_name" : "�ƴ�����"
]),
([	"action" : "$Nʹһ��"YEL"����ˮ������"NOR"�����ƶ�Ȼ�����쳤���ұۣ��ɿ��һ��������ն��$n��$l",
	"lvl"    : 10,
	"skill_name" : "��ˮ����"
]),
([	"action" : "$NͻȻʹһʽ"HIW"�����ƻ��衹"NOR"��˫��������һ��һ����裬����һ����ת�����ˡ� ",
	"lvl"    : 20,
	"skill_name" : "���ƻ���"
]),
([	"action" : "$Nһ��"HIY"������Ǭ����"NOR"���͵ز���������ұ��������¼���������Ĵ������ָ��Ȧ�͵�$n��$l",
	"lvl"    : 30,
	"skill_name" : "����Ǭ��"
]),
([	"action" : "$Nһ��"RED"�����ո��¡�"NOR"������һ��һ�գ�һ����˿��������һ��֮�䣬һ�������ޱȵ������Ŷ�Ȼ������",
	"lvl"    : 40,
	"skill_name" : "���ո���"
]),
([	"action" : "$N���б���һʽ"BLU"������Ϊ����"NOR"��˫�ƺ���г�����Ե�ŵݳ������غ�Х֮��������",
	"lvl"    : 50,
	"skill_name" : "����Ϊ��"
]),
([	"action" : "$Nһ��"MAG"�����޵�����"NOR"�����ƴ�Ȧ����������СȦ�������������������һ��֮�£�����$n��$l",
	"lvl"    : 60,
	"skill_name" : "���޵���"
]),
([	"action" : "$Nһ��"HIG"����ָ��ɽ��"NOR"����һ�����������������ţ���һ��ȴ��Ѹ���ޱȵ�һ�Ƽ��ա�",
	"lvl"    : 80,
	"skill_name" : "��ָ��ɽ"
]),
([	"action" : "$NͻȻ���һ����һ��"HIR"���ͻ���ɽ��"NOR"���м��ɶ�������$nֱ�˶��£������б������ء���һ���̶���Х��",
	"lvl"    : 100,
	"skill_name" : "�ͻ���ɽ"
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }
int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�������Ʒ�������֡�\n");
	if ((int)me->query_skill("guiyuan-tunafa", 1) < 100)
		return notify_fail("���Ԫ���ŷ���򲻹����޷��������Ʒ���\n");
	if ((int)me->query("max_neili") < 1000)
		return notify_fail("���������Ϊ�������޷��������Ʒ���\n");
	return 1;
}
int practice_skill(object me)
{
	if ((int)me->query("qi") < 60)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 50)
		return notify_fail("������������������Ʒ���\n");
	if (me->query_skill("tiezhang-zhangfa", 1) < 50)
		me->receive_damage("qi", 60);
	else
		me->receive_damage("qi", 55);
	me->add("neili", -35);
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
	int d_e1 = -55;
	int d_e2 = -30;
	int p_e1 = -10;
	int p_e2 = 15;
	int f_e1 = 300;
	int f_e2 = 450;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("tiezhang-zhangfa", 1);
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
int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 5; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"tiezhang-zhangfa/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int lev,damage, i;
	string msg;
	object weap;
	object piece;
	weap = victim->query_temp("weapon");
	lev =me->query("tiezhang-zhangfa");

	if( (me->query("neili") > 1000) &&
		(victim->query_temp("weapon")) &&
		(me->query_temp("tzzf")) &&
		(random(me->query_str()) > victim->query_str()/2) )
	{	
		if (random((int)weap->query("rigidity")) <3)
		{
			message_combatd(HIW"$N�����絶��������ʮ���£�ֻ������ž����һ����$n���е�" + weap->name() + "�Ѿ���Ϊ���أ�\n" NOR, me, victim );
			seteuid(getuid());
			piece = new("/clone/misc/piece");
			piece->set_name("�ϵ���" + weap->query("name"),({weap->query("id"),"piece"}));
			piece->move(environment(me));
			destruct(weap);
		}
		else
		{
			message_combatd(HIW"$N�����絶��������ʮ���£�ֻ������������һ����$n���е�" + weap->name() + "���������䵽���ϣ�\n" NOR, me,victim );
			weap->move(environment(me));
		}
		victim->reset_action();
		me->add("neili", -100);
		return 1;
	}
}

int help(object me)
{
	write(HIC"\n�����Ʒ���"NOR"\n");
	write(@HELP

    �����Ʒ������ư�����Ʒ���
    �����������񶾣��뽵��ʮ���ơ���Ȼ�����Ʋ������¡�


	ѧϰҪ��
		��Ԫ���ɷ�100��
		������Ϊ1000
HELP
	);
	return 1;
}


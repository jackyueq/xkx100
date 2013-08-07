// Last Modified by winder on May. 29 2001
// weituo-chu.c Τ����

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }
 
mapping *action = ({
([
	"action" : "$NԾ�ڰ�գ�һ��"HIG"���ɺ�չ������ɽ��"NOR"������$w�ѻ���������Ӱ����$n�ۻ����ң���֪���룬��������",
	"lvl"    : 0,
	"skill_name" : "�ɺ�չ������ɽ"
]),
([
	"action" : "$Nͦ$w��$n��$W��ס��˳��һ��"HIC"�������λ����ɹ���"NOR"��$w�������ҷɿ������������ߣ���$nѹ������",
	"lvl"    : 40,
	"skill_name" : "�����λ����ɹ�"
]),
([
	"action" : "$Nһ��"HIY"����¹̤�����ɲݡ�"NOR"����ϥ��������$w����$n���̣�ȴδ���������ϣ��͵�һ�ᣬ��$n���ظ����ȥ",
	"lvl"    : 60,
	"skill_name" : "��¹̤�����ɲ�"
]),
([
	"action" : "$NͻȻ�����ڵأ�$n��㵼䣬һ��"HIR"������ԾˮǱ��ء�"NOR"������$n�����´ܹ���������ͷ��$w����ɨ��$n��$l",
	"lvl"    : 80,
	"skill_name" : "����ԾˮǱ���"
]),
([
	"action" : "$Nһ��"HIM"����Գ�׹���������"NOR"��������磬����$n�ɿ챼�ܣ�����$wһ�п���һ�У�ɲ�Ǽ���$n�����ʮ����",
	"lvl"    : 100,
	"skill_name" : "��Գ�׹�������"
]),
([
	"action" : "$N��̤����ǰ������˫�ۣ�����$w�󿪴��أ�����������һ��"HIC"����ӥ����ɨǬ����"NOR"ɨ��$n������",
	"lvl"    : 120,
	"skill_name" : "��ӥ����ɨǬ��"
]),
([
	"action" : "$N���һ����һ��"HIY"��������ˮ�����桹"NOR"��$w���ַɳ������ž�������$n��ǰ�ģ��漴����$n����������ְ�$w��������",
	"lvl"    : 130,
	"skill_name" : "������ˮ������"
]),
([
	"action" : "$N˫ĿԲ��������Ĭ�����ԣ�һ��"HIW"��������ƺ�������"NOR"��$w����ǧ����������ֻ�����$n�ĵ�ͷ����",
	"lvl"    : 150,
	"skill_name" : "������ƺ�����"
]),
});

int valid_enable(string usage) { return (usage=="club") || (usage=="parry"); }
int valid_learn(object me)
{
	if ((int)me->query_skill("ranmu-blade",1) > 1 ||
		(int)me->query_skill("riyue-whip",1) > 1 )
		return notify_fail("������д�Ħ�������Ϊ������ͬʱѧϰ������������\n"); 
	if ((int)me->query("max_neili") < 1500)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("zhanzhuang-gong", 1) < 150)
		return notify_fail("���վ׮�����̫ǳ��\n");
	if ((int)me->query_skill("yijinjing", 1) < 150)
		return notify_fail("����׽�ڹ����̫ǳ��\n");
	if((int)me->query_skill("zui-club",1) < 150)
		return notify_fail("����������㣬��������Τ���ơ�\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "club")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("qi") < 70)
		return notify_fail("�������������Τ�ӹ���\n");
	if ((int)me->query("neili") < 70)
		return notify_fail("�������������Τ�ӹ���\n");
	me->receive_damage("qi", 60);
	if((int)me->query_skill("weituo-chu",1)> 200)
	{
		me->add("neili",-20);
	}
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
	int d_e1 = -60;
	int d_e2 = -40;
	int p_e1 = -5;
	int p_e2 = 10;
	int f_e1 = 300;
	int f_e2 = 400;
	int m_e1 = 150;
	int m_e2 = 450;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("weituo-chu", 1);
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
int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 5; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"weituo-chu/" + action;
}
int help(object me)
{
	write(HIC"\nΤ���ƣ�"NOR"\n");
	write(@HELP

    Τ�����������ֶ���������
    Τ���ơ����±޷���ȼľ��������Ϊ��������������
    ����������ͬʱ��ϰ��

	ѧϰҪ��
		�׽150��
		վ׮��150��
		�������150��
		������Ϊ1500
HELP
	);
	return 1;
}


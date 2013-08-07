// jinding-zhang.c ������
// Oct. 9 1997 by That

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"skill_name" : "������̩" ,
	"action" : "$N����΢�Σ�һ��"RED"��������̩��"NOR"�����������$nֻ����һ��ů��Ϯ��$l",
	"lvl"   : 0
]),
([	"skill_name" : "��������" ,
	"action" : "$N˫�ֱ�ã���ָ�ᵯ��һ��"HIR"���������项"NOR"��������·������ʮ����ץ��$n��$l",
	"lvl"   : 11
]),
([	"skill_name" : "�����" ,
	"action" : "$N����ǰ��������ٿ��������ͷ�һ��"CYN"������ơ�"NOR"����ץ��$n��$l",
	"lvl"   : 22
]),
([	"skill_name" : "������ɳ" ,
	"action" : "$N����Ȧת�����$n�����֣������Ƴ������������Ļ���һ��"BLU"��������ɳ��"NOR"���͵ػ���$n���°�",
	"lvl"   : 33
]),
([	"skill_name" : "�׶�����" ,
	"action" : "$N�������ף�һ�����ȣ���$nһ㶼䣬����һ��"HIB"���׶�������"NOR"��ֱ��$n��$l",
	"lvl"   : 44
]),
([	"skill_name" : "�𶥷��" ,
	"action" : "$N˫��ƽ����ȭ����¶΢Ц��$n��㱼俴��$N����Ϊ�������$N���������һ��"HIY"���𶥷�⡹"NOR"��֪��������ʵ���Ʒ��Ѿ�Ϯ��",
	"lvl"   : 55
]),
([	"skill_name" : "���Ľ�ħ" ,
	"action" : "$Nһ������ׯ�ϣ�ʹ��"YEL"�����Ľ�ħ��"NOR"��������磬����$nƯ�Ʋ���",
	"lvl"   : 66
]),
([	"skill_name" : "����˻�" ,
	"action" : "$Nȫ�����ߣ�˫�ۼ��裬��Ϊ�����Ӱ��һ��"HIC"������˻ġ�"NOR"����ǵ�Ϯ��$nȫ�������Ѩ",
	"lvl"   : 77
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }
int valid_combine(string combo) { return combo=="tiangang-zhi"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�������Ʊ�����֡�\n");
	if ((int)me->query_skill("linji-zhuang", 1) < 10)
		return notify_fail("����ټ�ׯ�ķ���򲻹��������������ơ�\n");
	if ((int)me->query("max_neili") < 30)
		return notify_fail("�������̫�����޷��������ơ�\n");
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��ı�����ֲ�����ϰ��\n");
	if ((int)me->query("qi") < 45)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 40)
		return notify_fail("������������������ơ�\n");
	me->receive_damage("qi", 40);
	me->add("neili", -25);
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
	int d_e1 = -40;
	int d_e2 = -15;
	int p_e1 = 5;
	int p_e2 = 30;
	int f_e1 = 180;
	int f_e2 = 290;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("jinding-zhang", 1);
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
int learn_bonus() { return 15; }
int practice_bonus() { return 15; }
int success() { return 10; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"jinding-zhang/"+ action;
}
int help(object me)
{
	write(HIC"\n�����ƣ�"NOR"\n");
	write(@HELP

    ������Ϊ�������Ʒ���
    �������ָѨ��������

	ѧϰҪ��
		�ټ�ʮ��ׯ20��
		����30
HELP
	);
	return 1;
}


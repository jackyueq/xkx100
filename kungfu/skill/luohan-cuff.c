// Last Modified by winder on May. 29 2001
// luohan-cuff.c �����޺�ȭ ������ֻ��� ���ԡ�����ȭ������ȡ��һ����ʮʽ��

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
mapping *action = ({
([	"action" : "$Nһʽ"+(order[random(13)])+"��������ʽ��"NOR"�����屣��վ�������Ʋ��䣬˫��ƽ��ǰ����˫��ǰ̽��˫����ȭ��ץ��$n����",
	"lvl"   : 0,
	"skill_name" : "������ʽ"
]),
([	"action" : "$N�����̤��һ��"+(order[random(13)])+"��ƽ�����ơ�"NOR"��������Ȼ����վ�������Ʋ��䣬���ֻ��ƣ���ǰֱ�����",
	"lvl"   : 4,
	"skill_name" : "ƽ������"
]),
([	"action" : "$N�ҽ�ԭ�ض岽�����̤ǰ�����������ǲ�������һ��"+(order[random(13)])+"����ű��ҡ�"NOR"���������Һ�������",
	"lvl"   : 8,
	"skill_name" : "��ű���"
]),
([	"action" : "$Nȫ����ǰ��һ��"+(order[random(13)])+"���������ҡ�"NOR"��������ǰֱ�����䣬����ͬʱ����Ӳ�ӣ���Ȼ��������",
	"lvl"   : 12,
	"skill_name" : "��������"
]),
([	"action" : "$N���ƻ�ס���󲻶�������ԭ�����ⷭ��ץ�ɣ���"+(order[random(13)])+"���ɵ���ơ�"NOR"�����ֲ�����������$nֱ�ж���",
	"lvl"   : 16,
	"skill_name" : "�ɵ����"
]),
([	"action" : "$N�ҽ��Ͻ������¶׳��񻷲����������ַ�ȭһʽ"+(order[random(13)])+"���������ҡ�"NOR"��ǰ���䣬���Ƹ����ƶ���",
	"lvl"   : 20,
	"skill_name" : "��������"
]),
([	"action" : "$N�����񻷲������������������ֿ��������Ϸ���"+(order[random(13)])+"��˳�Ʋ��֡�"NOR"���Բ�˿����$n$l�ɳ�",
	"lvl"   : 24,
	"skill_name" : "˳�Ʋ���"
]),
([	"action" : "$N�Ĳ�˿�����²�ѹ������ԭ����������"+(order[random(13)])+"��˫����ӡ�"NOR"��������������$nֱ�Ŷ���",
	"lvl"   : 28,
	"skill_name" : "˫�����"
]),
([	"action" : "$N���ҽż�ع�����ϥ����ǰֱ������"+(order[random(13)])+"����ϥ���ơ�"NOR"��˳����ȭ���������ַ���ǰ��",
	"lvl"   : 32,
	"skill_name" : "��ϥ����"
]),
([	"action" : "$Nһ��"+(order[random(13)])+"���Ʋ����ҡ�"NOR"������΢��������˫������ͬʱ��Ȧ������ǰ�ɳ�����������ǰ�У���ȭ˳����ǰ����$n",
	"lvl"   : 36,
	"skill_name" : "�Ʋ�����"
]),
([	"action" : "$N�������ֱ���ɹ�����վ����һ��"+(order[random(13)])+"��ӭ���мܡ�"NOR"�����ַ����ϼܣ�����˳��ѹ���·�",
	"lvl"   : 40,
	"skill_name" : "ӭ���м�"
]),
([	"action" : "$Nһ��"+(order[random(13)])+"����ѹ�崷��"NOR"���ҽ�ԭ�ض岽��ʹ����ת���������������ѹ��������ǰֱ��$n",
	"lvl"   : 44,
	"skill_name" : "��ѹ�崷"
]),
([	"action" : "$N����"+(order[random(13)])+"��ת�����ء�"NOR"��˳��������ת֮�ƣ�����ȭ�������ƣ�˫�ֽ��棬��$n��������",
	"lvl"   : 48,
	"skill_name" : "ת������"
]),
([	"action" : "$N�ҽ�����̤����ʹ��������ҷ���һ��"+(order[random(13)])+"�������崷��"NOR"�������ֿ��������ֻ�����$nȦ�����",
	"lvl"   : 52,
	"skill_name" : "�����崷"
]),
([	"action" : "$Nһʽ"+(order[random(13)])+"������������"NOR"��������ת�������������������ؿ�ס���ʣ�����˳����$n$l����",
	"lvl"   : 56,
	"skill_name" : "��������"
]),
([	"action" : "$N��һ��"+(order[random(13)])+"�������崷��"NOR"������˳����ǰȦ�ɶ���������������ת֮�ƣ����ֻ�����$nֱ������",
	"lvl"   : 60,
	"skill_name" : "�����崷"
]),
([	"action" : "$Nʹ��"+(order[random(13)])+"���ɵ��ߡ�"NOR"�������Բɵ���������ǰ���䣬ͬʱ�������Թ���ʽ��$n$l���߶���",
	"lvl"   : 64,
	"skill_name" : "�ɵ���"
]),
([	"action" : "$N����������������ţ�ʹ�ҽ�������һ��"+(order[random(13)])+"���ײ��ߡ�"NOR"�������Թ���ʽ������ǰ����",
	"lvl"   : 68,
	"skill_name" : "�ײ���"
]),
([	"action" : "$N�ҽ������䲽���Խż������棬һ��"+(order[random(13)])+"���粽���ҡ�"NOR"������һֱ���粻�����������ҷ�������",
	"lvl"   : 72,
	"skill_name" : "�粽����"
]),
([	"action" : "$N˫��˳��ת����ԭ�ض岽���ɹ�����վ����һ��"+(order[random(13)])+"������б��"NOR"�����ֻ��ƣ���$n$l����",
	"lvl"   : 76,
	"skill_name" : "����б��"
]),
([ 	"action" : "$N����ԭ�����³���������һ��"+(order[random(13)])+"��������ҡ�"NOR"����ȭ�������ϥǰ������������Ӳ��",
	"lvl"   : 80,
	"skill_name" : "�������"
]),
([	"action" : "$Nһ��"+(order[random(13)])+"������мܡ�"NOR"������ų�ֱ���ɹ�����վ������ȭ˳�Ʒ��⣬��$n�ܳ�",
	"lvl"   : 84,
	"skill_name" : "����м�"
]),
([	"action" : "$N���ֻ��ƣ���ǰֱ�ɶ�����ʹ��"+(order[random(13)])+"����������"NOR"���ҽ�ԭ�ض岽��ʹ����ת��$n�߳�",
	"lvl"   : 88,
	"skill_name" : "��������"
]),
([	"action" : "$N�����֣�����ԭ����ǰ�ܲɶ������ҽ�˳����$n$lֱ�ߣ�����һʽ"+(order[random(13)])+"�������ܴ�"NOR"",
	"lvl"   : 92,
	"skill_name" : "�����ܴ�"
]),
([	"action" : "$N�����ķ����ҽţ�ʹ��ŷ��飬һ��"+(order[random(13)])+"���ز��崷��"NOR"������ԭ��ת�أ�ϥ��˳�Ƶ���$n$l",
	"lvl"   : 96,
	"skill_name" : "�ز��崷"
]),
([	"action" : "$N������ǰֱ�ţ���ס���̣�һʽ"+(order[random(13)])+"���а���š�"NOR"������ת���Է�������$n�ų�",
	"lvl"   : 100,
	"skill_name" : "�а����"
]),
([	"action" : "$Nһ��"+(order[random(13)])+"���ɵ���ȡ�"NOR"�����ƻ�ס���󲻶�������ԭ�����ⷭ��ץ�ɣ��������ǰ��$n",
	"lvl"   : 104,
	"skill_name" : "�ɵ����"
]),
([	"action" : "$N����ԭ�ػ�Ȧ����ǰ�����һ��"+(order[random(13)])+"��Ť��Ю�⡹"NOR"���ҽ���Ȼ�Ͻ�����$n������������",
	"lvl"   : 108,
	"skill_name" : "Ť��Ю��"
]),
([	"action" : "$N˫�ֻ�ʮ���֣��������ǰ��ʹ��"+(order[random(13)])+"������ӭ����"NOR"��˫��һԾ������$n$l",
	"lvl"   : 112,
	"skill_name" : "����ӭ��"
]),
([	"action" : "$N��������һ��"+(order[random(13)])+"������ӭ����"NOR"��ʮ����˳������˫���ᣬ˫������ٴ�����$n",
	"lvl"   : 120,
	"skill_name" : "����ӭ��"
]),
});

int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }
int valid_combine(string combo) { return combo=="fengyun-hand";}

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�������޺�ȭ������֡�\n");
	if ((int)me->query_skill("zhanzhuang-gong", 1) < 10)
		return notify_fail("���վ׮����򲻹����޷�ѧ�����޺�ȭ��\n");
	if ((int)me->query_skill("shaolin-cuff", 1) < 10)
		return notify_fail("���������ȭ��򲻹����޷�ѧ�����޺�ȭ��\n");
	if ((int)me->query("max_neili") < 10)
		return notify_fail("�������̫�����޷��������޺�ȭ��\n");
	return 1;
}
int practice_skill(object me)
{
	if ((int)me->query("qi") < 40)
		return notify_fail("�������̫�ͣ������������޺�ȭ��\n");
	if ((int)me->query("neili") < 40)
		return notify_fail("������������������޺�ȭ��\n");
	me->receive_damage("qi", 35);
	me->add("neili", -20);
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
	int d_e1 = 30;
	int d_e2 = 50;
	int p_e1 = -30;
	int p_e2 = -10;
	int f_e1 = 120;
	int f_e2 = 270;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("luohan-cuff", 1);
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
		"damage_type" : "����",
	]);
}
int learn_bonus() { return 20; }
int practice_bonus() { return 20; }
int success() { return 15; }
int power_point(object me) { return 1.0; }

int help(object me)
{
	write(HIC"\n�޺�ȭ��"NOR"\n");
	write(@HELP

    �޺�ȭΪ����ȭ����������ֻ�����

	ѧϰҪ��
		վ׮��10��
		������ȭ10��
		������Ϊ10��
HELP
	);
	return 1;
}


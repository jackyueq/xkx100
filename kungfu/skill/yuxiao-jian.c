// yuxiao-jian.c ���｣��
// Last Modified by sir 10.22.2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([	"action" : "$N����������һ��"+(order[random(13)])+"��Ӣ�������Ҷ��С�"NOR"��ƮȻ����$n��ǰ���漴����$w΢�𣬽��⼲����$n��$l",
	"lvl" : 0,
	"skill_name": "Ӣ�������Ҷ���"
]),
([	"action" : "$Nб��һ����ʹ��һʽ"+(order[random(13)])+"����Ů�鳤ֻ�޶̡�"NOR"���ӽ��������һ��һ�̵Ĺ�Ӱֱ��$n��$l",
	"lvl" : 10,
	"skill_name" : "��Ů�鳤ֻ�޶�"
]),
([	"action" : "$Nһ��"+(order[random(13)])+"����Ȼ��ȥ��˼�项"NOR"��$w��Ȼ���������̻ص������У��漴ת����Ȼ��ȥ��$n��ʱ�Ÿо�����һ�ɾ��������Լ���$l",
	"lvl" : 20,
	"skill_name": "��Ȼ��ȥ��˼��"
]),
([	"action" : "$N˫�־ٽ����죬һ��"+(order[random(13)])+"������Ⱥ�������塹"NOR"��$w���������ף����϶�����$n��ͷ­��ȥ",
	"lvl" : 30,
	"skill_name": "����Ⱥ��������"
]),
([	"action" : "$Nʩչ��"+(order[random(13)])+"�����һЦ������"NOR"������$w���΢΢һЦ��$nֻ����һ����ȴ��һ����Ӱ�������ΰ�Ϯ���Լ���$l�����Լ�ȴû����$N��ʱ������",
	"lvl" : 40,
	"skill_name" : "���һЦ������"
]),
([	"action" : "$N���̤ʵ���ҽ���㣬һ��"+(order[random(13)])+"��һ����ϳ�᡹"NOR"��$w����һ�Ž�����Ʈ�������ر���$n��$l",
	"lvl" : 50,
	"skill_name": "һ����ϳ��"
]),
([	"action" : "$Nһ��"+(order[random(13)])+"������Ū������项"NOR"�������ḧ$w���漴�͵�һ����������ǰһ�ݣ�ֻ��һ����˸�����Ľ�ӰѸ�ٴ���$n��$l",
	"lvl" : 60,
	"skill_name" : "����Ū�������"
]),
([	"action" : "$N������ף���ɫ��Ȼ��һ��"+(order[random(13)])+"��������Թ���˳���"NOR"��$w�������Ʋ����ش���$n��$l",
	"lvl" : 70,
	"skill_name" : "������Թ���˳�"
]),
([	"action" : "$N�������棬һ��"+(order[random(13)])+"���˽�������������"NOR"������$wб���»�����$n΢����֣������ɼ䣬ȴ��$N���е�$w�ѷ������ϣ�ֱ���Լ����ʺ�",
	"lvl" : 80,
	"skill_name": "�˽�����������"
]),
([	"action" : "$N��Ȼ��¶΢Ц��һ��"+(order[random(13)])+"����������Ц���ա�"NOR"������$wһ����������Ž�������$n����������·",
	"lvl" : 90,
	"skill_name" : "��������Ц����"
]),
([	"action" : "$N����ʳָ����$w��һ��"+(order[random(13)])+"���������������项"NOR"��$w����һ���������������ƣ�$nֻ������ǰһ�ƣ�һ����͵ľ��������Լ�",
	"lvl" : 100,
	"skill_name" : "��������������"
]),
([	"action" : "$N����΢��һ��"+(order[random(13)])+"��������������ϡ�"NOR"������$w����������һ����������ĺ�����ɲ�Ǽ��ɳ��ʯ��$n����һ�Ž���������£�������֧����",
	"lvl" : 110,
	"skill_name" : "�������������"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }
int valid_learn(object me)
{
	if (((int)me->query("max_neili") < 500) ||
		((int)me->query_skill("bibo-shengong", 1) < 100) ||
		!(me->query("couple/have_couple")))
		return notify_fail("��ҩʦ˵��: ���｣����ֻ����Ե���㲻���������ˡ�\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("qi") < 55)
		return notify_fail("����������������｣����\n");
	if ((int)me->query("neili") < 40)
		return notify_fail("������������������｣����\n");
	me->receive_damage("qi", 50);
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
	int d_e1 = -20;
	int d_e2 = 0;
	int p_e1 = -50;
	int p_e2 = -30;
	int f_e1 = 150;
	int f_e2 = 200;
	int m_e1 = 190;
	int m_e2 = 290;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("yuxiao-jian", 1);
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
		"damage_type" : random(2) ? "����" : "����",
	]);
}
int learn_bonus() { return 5; }
int practice_bonus() { return 5; }
int success() { return 5; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"yuxiao-jian/" + action;
}
int help(object me)
{
	write(HIC"\n���｣����"NOR"\n");
	write(@HELP

    ���｣���Ƕ����һ�������ҩʦ�Ĳ���֮�ܡ�
    ���һ��������ڡ�����ͤ�����ԣ�����һ�����������һ�Ӱ��
���񽣣��̺��������������Ȼ��ҩʦ��ƽ��������书����Ӣ
��֮��������｣���ˡ�

	ѧϰҪ��
		�̲���100��
		����500
		��Ե
HELP
	);
	return 1;
}


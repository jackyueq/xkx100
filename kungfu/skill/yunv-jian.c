// yunv-jian.c ��Ů����
// Last Modified by sir 10.21.2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
mapping *action = ({
([	"action" : "$Nһ��"+(order[random(13)])+"������б����"NOR"������б�ɣ�����$w�������$n��$l",
	"lvl" : 0,
	"skill_name" : "����б��"
]),
([	"action" : "$N��Ծ����"+(order[random(13)])+"���׺羭�졹"NOR"��$w��Ȼ�´�",
	"lvl" : 4,
	"skill_name" :  "�׺羭��"
]),
([	"action" : "$Nʹ��"+(order[random(13)])+"���˼����ġ�"NOR"���ӽ�ֱ���������ɵ�",
	"lvl" : 9,
	"skill_name" :  "�˼�����"
]),
([	"action" : "$Nʹ"+(order[random(13)])+"����ǰ���¡�"NOR"һ�����϶��²�����ģ����ֺ�ա�����̵صĹ�
��",
	"lvl" : 14,
	"skill_name" :  "��ǰ����"
]),
([	"action" : "$N����$w������һ��"+(order[random(13)])+"���ʻ���չ��"NOR"���ػ�����ֻ�ϵ�$n�ۻ����ң��벻֪��
�ι���",
	"lvl" : 19,
	"skill_name" :  "�ʻ���չ"
]),
([	"action" : "$Nʹ��"+(order[random(13)])+"������С�á�"NOR"�������𣬽�����ָ�����������ƣ�ֱ��$n��
$l",
	"lvl" : 24,
	"skill_name" :  "����С��"
]),
([	"action" : "$N����$w��������һ�̣�������������ʹ��"+(order[random(13)])+"��ɨѩ��衹"NOR"��",
	"lvl" : 29,
	"skill_name" :  "ɨѩ���"
]),
([	"action" : "$N���ƺ����ǰ��������$w����ӷ���ȴ��һ��"+(order[random(13)])+"�����ٰ�����"NOR"",
	"lvl" : 34,
	"skill_name" :  "���ٰ���"
]),
([	"action" : "$Nһ��"+(order[random(13)])+"�����¶��ġ�"NOR"��$w���������һ���󻡣�����$n��$l",
	"lvl" : 39,
	"skill_name" :  "���¶���"
]),
([	"action" : "$N����������ң�������Ϊ������$n��ȴ��һ��"+(order[random(13)])+"���رߵ��ס�"NOR"",
	"lvl" : 44,
	"skill_name" :  "�رߵ���"
]),
([	"action" : "$Nһ��"+(order[random(13)])+"��������Ʈ��"NOR"��$w����ػ�������Բ������$n��$l��ȥ",
	"lvl" : 49,
	"skill_name" :  "������Ʈ"
]),
([	"action" : "$Nһ��"+(order[random(13)])+"��С԰�վա�"NOR"������$wѸ����$n��������������",
	"lvl" : 54,
	"skill_name" :  "С԰�վ�"
]),
([	"action" : "$Nʹ��"+(order[random(13)])+"������ҹ����"NOR"������$w�й�ֱ�룬����$n��$l",
	"lvl" : 59,
	"skill_name" :  "����ҹ��"
]),
([	"action" : "$N��������ҵͣ�һ��"+(order[random(13)])+"���������䡹"NOR"��$w�ڿ��л���һ���⻷������
$n",
	"lvl" : 64,
	"skill_name" :  "��������"
]),
([	"action" : "$N����$w���¶��Ͼ��������������һ�㣬ȴ��"+(order[random(13)])+"�������ٳء�"NOR"",
	"lvl" : 70,
	"skill_name" :  "�����ٳ�"
]),
([	"action" : "$N������״��һ��"+(order[random(13)])+"��ľ�����㡹"NOR"������$wֱ��$n��$l",
	"lvl" : 76,
	"skill_name" :  "ľ������"
]),
([	"action" : "$N���ֽ���һ�죬����$wƽƽ����$n��$l����һ��"+(order[random(13)])+"��˫���Իء�"NOR"",
	"lvl" : 82,
	"skill_name" :  "˫���Ի�"
]),
([	"action" : "$N����$w�����̣�һ��"+(order[random(13)])+"�����Ƴ��ԡ�"NOR"��ֱָ$n��$l",
	"lvl" : 88,
	"skill_name" : "���Ƴ���"
]),
([	"action" : "$Nһ��"+(order[random(13)])+"�������չȡ�"NOR"��$w���������һ�ӣ���$n����˼��ĽǶȹ���
",
	"lvl" : 94,
	"skill_name" :  "�����չ�"
]),
([	"action" : "$Nʹ��"+(order[random(13)])+"���軨��·��"NOR"��һʱ����о���$w��Ӱ�ӣ���$n��֪��εֵ�
",
	"lvl" : 100,
	"skill_name" :  "�軨��·"
]),
([	"action" : "$Nһ��"+(order[random(13)])+"��İ·��ɣ��"NOR"��$w�������㣬����$n��$l",
	"lvl" : 99,
	"skill_name" :  "İ·��ɣ"
]),
([	"action" : "$NͻȻ�̶�������һ��"+(order[random(13)])+"������������"NOR"��$w���¶��ϴ���$n",
	"lvl" : 106,
	"skill_name" :  "��������"
]),
([	"action" : "$N���Ų�������$wͻȻ���Լ������´̳���ȴ��һ��"+(order[random(13)])+"�����Ľ�����"NOR"
",
	"lvl" : 112,
	"skill_name" :  "���Ľ���"
]),
([	"action" : "$N������ˮ�滬��һ�㣬һ��"+(order[random(13)])+"��������ҹ��"NOR"��ƽƽ����$n��$l��ȥ",
	"lvl" : 118,
	"skill_name" :  "������ҹ"
]),
([	"action" : "$Nһ��"+(order[random(13)])+"���������"NOR"������$w�̵�$n������",
	"lvl" : 124,
	"skill_name" :  "�������"
]),
([	"action" : "$Nһ��"+(order[random(13)])+"��ĵ�����᡹"NOR"��$w�Ƴ�������Ȧ��ƽƽ����$n��$l��ȥ",
	"lvl" : 131,
	"skill_name" :  "ĵ������"
]),
([	"action" : "$N��������棬������ǰһ�ˣ�һ��"+(order[random(13)])+"����ҩ���项"NOR"��$w��$n��$l��
ȥ",
	"lvl" : 138,
	"skill_name" :  "��ҩ����"
]),
([	"action" : "$Nһ��"+(order[random(13)])+"����ǰ���ࡹ"NOR"������Ծ������$wɨ��$n��$l",
	"lvl" : 145,
	"skill_name" :  "��ǰ����"
]),

([	"action" : "$N������Ȼ֮ɫ������һ��"+(order[random(13)])+"������Բԡ�"NOR"��$w����$n��$l",
	"lvl" : 159,
	"skill_name" :  "����Բ�"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }
int valid_learn(object me)
{
	if ((int)me->query_skill("yunv-xinfa", 1) < 15)
		return notify_fail("�����Ů�ķ���򲻵����޷�ѧϰ��Ů������\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("qi") < 55)
		return notify_fail("���������������Ů������\n");
	if ((int)me->query("neili") < 40)
		return notify_fail("�����������������Ů������\n");
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
	int d_e2 = 5;
	int p_e1 = -45;
	int p_e2 = -30;
	int f_e1 = 150;
	int f_e2 = 200;
	int m_e1 = 180;
	int m_e2 = 280;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("yunv-jian", 1);
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
int power_point(object me) { 
	if (me->query("gender")== "Ů��")
	return 1.0; 
	else
	return 0.7;
	}

string perform_action_file(string action)
{
	return __DIR__"yunv-jian/" + action;
}
int help(object me)
{
	write(HIC"\n��Ů������"NOR"\n");
	write(@HELP

    ��Ĺ�ɿ�ɽ��ʦ�ֳ�Ӣ�Դ������������������������ҽ�����
�����ס�������ţ��˵���������ۼ�������Ѽ���

	ѧϰҪ��
		��Ů�ķ�15��
HELP
	);
	return 1;
}


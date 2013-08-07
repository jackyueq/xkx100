// haotian-zhang �����
// Last Modified by sir 10.22.2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([	"action" : "$Nʹһ��"+(order[random(13)])+"��������ˮ��"NOR"��˫�ֻ��˸���Ȧ������$n��$l",
	"skill_name" : "������ˮ",
	"lvl" : 0
]),
([	"action" : "$Nʹһ��"+(order[random(13)])+"���������¡�"NOR"����������һ�ӣ�����$n��$l",
	"skill_name" : "��������",
	"lvl" : 5
]),
([	"action" : "$N�����������⣬��������ʹһ��"+(order[random(13)])+"�������沨��"NOR"����$n��$l��ȥ",
	"skill_name" : "�����沨",
	"lvl" : 10
]),
([	"action" : "$Nʹһ��"+(order[random(13)])+"��������ת��"NOR"���ֻ�$n���ؿں�$l",
	"skill_name" : "������ת",
	"lvl" : 15
]),
([	"action" : "$Nʹһ��"+(order[random(13)])+"�����ջ��֡�"NOR"��������ͬʱ�������ڿ���ͻȻ�����Ʒ���
��",
	"skill_name" : "���ջ���",
	"lvl" : 20
]),
([	"action" : "$N���ֲ�ס�ζ�������һ��"+(order[random(13)])+"��������˪��"NOR"����$n��$l��ȥ",
	"skill_name" : "������˪",
	"lvl" : 25
]),
([	"action" : "$N���ֱ���Ϊ�ģ����������絶��һ��"+(order[random(13)])+"��͡�ϰ�ɳ��"NOR"������$n��$l",
	"skill_name" : "͡�ϰ�ɳ",
	"lvl" : 30
]),
([	"action" : "$N����˺�벽������ʹһ��"+(order[random(13)])+"������һɫ��"NOR"�������$n",
	"skill_name" : "����һɫ",
	"lvl" : 35
]),
([	"action" : "$Nһ��"+(order[random(13)])+"������¡�"NOR"�������ȷ������������ƺ󷢶�����",
	"skill_name" : "�����",
	"lvl" : 40
]),
([	"action" : "$N˫���������У�˫�����ɨ��$n��$l��ȴ��һ��"+(order[random(13)])+"��������ˮ��"NOR"����
̬����",
	"skill_name" : "������ˮ",
	"lvl" : 45
]),
([	"action" : "$N�����鰴�����ֻ�������ʹһ��"+(order[random(13)])+"���������ơ�"NOR"����$n��$l��ȥ",
	"skill_name" : "��������",
	"lvl" : 50
]),
([	"action" : "$N˫�ֱ�����ȭ����ǰ��󻮻���һ��"+(order[random(13)])+"��������ϡ�"NOR"����$n��$l",
	"skill_name" : "�������",
	"lvl" : 55
]),
([	"action" : "$N�����黮�����ֱ���Ϊ��һ��"+(order[random(13)])+"��¥����ء�"NOR"����$n��$l",
	"skill_name" : "¥�����",
	"lvl" : 60
]),
([	"action" : "$Nʩ��"+(order[random(13)])+"�������С�"NOR"����������ӳ�������ͬʱ����$n",
	"skill_name" : "������",
	"lvl" : 65
]),
([	"action" : "$N�ɱ۴��֣�����ǰ����������ʹһ��"+(order[random(13)])+"�����㳤�ɡ�"NOR"������$n��$l",
	"skill_name" : "���㳤��",
	"lvl" : 70
]),
([	"action" : "$N����͵أ�����ʹһ��"+(order[random(13)])+"������ǱԾ��"NOR"�����¶�����$n��$l��ȥ",
	"skill_name" : "����ǱԾ",
	"lvl" : 75
]),
([	"action" : "$N�����ɹ����ƣ�˫���������ϣ�������ǰ�Ƴ�һ��"+(order[random(13)])+"���»����ա�"NOR"",
	"skill_name" : "�»�����",
	"lvl" : 80
]),
([	"action" : "$N���Ʋ�ס����ɨ������һʽ"+(order[random(13)])+"����̶�仨��"NOR"��������ת����$n��ȥ",
	"skill_name" : "��̶�仨",
	"lvl" : 85
]),
([	"action" : "$N���־���ǰ��������ǰƲ����ʹһ��"+(order[random(13)])+"����ˮ������"NOR"����$n��$l��ȥ
",
	"skill_name" : "��ˮ����",
	"lvl" : 90
]),
([	"action" : "$Nʹһ��"+(order[random(13)])+"��б�³�����"NOR"����������������Ȧ�����ƴ�Ȧ�д�������$n
",
	"skill_name" : "б�³���",
	"lvl" : 95
]),
([	"action" : "$N�������ϻ�������������ʹһ��"+(order[random(13)])+"����ʯ���桹"NOR"�����Ʋ�ס�ζ�����
��$nͷ������֮��",
	"skill_name" : "��ʯ����",
	"lvl" : 100
])
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry" ; }
int valid_combine(string combo) { return combo=="chunyang-quan"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("������Ʊ�����֡�\n");
	if ((int)me->query_skill("xiantian-qigong", 1) < 20)
		return notify_fail("�������������򲻹����޷�ѧ����ơ�\n");
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��ı�����ֲ�����ϰ��\n");
	if ((int)me->query("qi") < 45)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 40)
		return notify_fail("�����������������ơ�\n");
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
	int d_e2 = -20;
	int p_e1 = 0;
	int p_e2 = 30;
	int f_e1 = 190;
	int f_e2 = 290;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("haotian-zhang", 1);
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
	return __DIR__"haotian-zhang/" + action;
}
int help(object me)
{
	write(HIC"\n����ƣ�"NOR"\n");
	write(@HELP

    �����Ϊȫ�����书��
    ���봿��ȭ������

	ѧϰҪ��
		��������20��
HELP
	);
	return 1;
}


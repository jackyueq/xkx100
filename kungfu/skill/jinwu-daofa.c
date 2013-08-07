// jinwu-dao.c ���ڵ���
// Last Modified by sega on Mar. 10 2000
// �������������������

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }
int power_point(object me) { return 1.0; }

mapping *action = ({
([	"action" : "$N�ص����գ�һ�С�����鮵������������¶��ϻ��˸��뻡����$n��
$l��ȥ",
	"force" : 120,
	"dodge" : -10,
	"parry" : 5,
	"damage": 15,
	"lvl" : 0,
	"skill_name" : "����鮵�",
	"damage_type" : "����"
]),
([	"action" : "$N�����������⣬һ�С�÷ѩ���ġ�������$w��ֱ����$n��$l",
	"force" : 130,
	"dodge" : -10,
	"parry" : 10,
	"damage": 80,
	"lvl" : 12,
	"skill_name" : "÷ѩ����",
	"damage_type" : "����"
]),
([	"action" :"$Nһ�С�ǧ��ѹ�ա���$w�ƾ�������ˢ��һ�����϶�����$n����",
	"force" : 40,
	"dodge" : -5,
	"parry" : 5,
	"damage": 125,
	"lvl" : 18,
	"skill_name" : "ǧ��ѹ��",
	"damage_type" : "����"
]),
([	"action" : "$N���ַ�ִ������һ�С����ս�ġ�����һ����$wֱ��$n�ľ���ն
ȥ",
	"force" : 160,
	"dodge" : -5,
	"parry" : 5,
	"damage": 130,
	"lvl" : 24,
	"skill_name" : "���ս��",
	"damage_type" : "����",
]),
([	"action" : "$Nһ�С��������ء����������⻯����㷱�ǣ���$n��$l��ȥ",
	"force" : 120,
	"dodge" : 10,
	"parry" : 5,
	"damage": 135,
	"lvl" : 30,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([	"action" : "$N˫�ֺ�ִ$w��һ�С�����֮������š��ת������ֱ����$n��˫��
",
	"force" : 210,
	"dodge" : 5,
	"parry" : 15,
	"damage": 140,
	"lvl" : 36,
	"skill_name" : "����֮��",
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С����ò����������$w����һ����ƽʮ�֣���$n�ݺ���ȥ",
	"force" :140,
	"dodge" : -5,
	"parry" : 15,
	"damage": 150,
	"lvl" : 42,
	"skill_name" : "���ò��",
	"damage_type" : "����"
]),
([	"action" : "$N��ת�����׼�Լ���һ�С�������֦����ȫ��һ��������$w��$n��
��նȥ",
	"force" : 180,
	"dodge" : -20,
	"parry" : 10,
	"damage": 260,
	"lvl" : 48,
	"skill_name" : "������֦",
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С��������ס���$w�ĵ���·𻯳�һ�ش����棬��$n����Χ��
",
	"force" : 220,
	"dodge" : -10,
	"parry" : 20,
	"damage": 275,
	"lvl" : 54,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([	"action" : "$N����ƽָ��һ�С��󺣳�ɳ����һƬƬ�йǵ�����쫷�����$n��
ȫ��",
	"force" : 270,
	"dodge" : 5,
	"parry" : 25,
	"damage": 190,
	"lvl" : 60,
	"skill_name" : "�󺣳�ɳ",
	"damage_type" : "����"
]),
});

int valid_enable(string usage) { return (usage == "blade") || (usage == "parry")
; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������������\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	int zhaoshu, level;

	zhaoshu = sizeof(action)-1;
	level = (int) me->query_skill("jinwu-dao",1);

	if (level < 60 ) zhaoshu--;
	if (level < 55 ) zhaoshu--;
	if (level < 50 ) zhaoshu--;
	if (level < 40 ) zhaoshu--;
	if (level < 30 ) zhaoshu--;
	if (level < 20 ) zhaoshu--;
	if (level < 10 ) zhaoshu--;

	return action[random(zhaoshu)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "blade")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("����������������ڵ�����\n");
	me->receive_damage("qi", 30);
	return 1;
}

int help(object me)
{
	write(HIC"\n���ڵ�����"NOR"\n");
	write(@HELP

    ���ڵ���Ϊѩɽ�����ŷ���ʷС��������ʷС������������
���������˵���רΪ����ѩɽ�����������ڸ�ʯ���죬��ͼ��ʯ��
���ܰ���֮�ƣ���ѹ���˷�����棬��һ���Լ���ʮ�걻��ѹ
���������˵���רΪ����ѩɽ������������ѩɽ�������֣�ȴ�ܾ�
����©ʧ��������ٱ��

	ѧϰҪ��
		����100
HELP
	);
	return 1;
}


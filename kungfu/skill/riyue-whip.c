// riyue-whip.c ���±޷�
// Last Modified by sir 10.20.01

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N����������һʽ"HIG"�������ɴ̡�"NOR"��������̧��$w�������裬���������Ҳ���ǰ�����ƣ�����մճ��ɢ",
	"lvl"    : 0,
	"skill_name" : "�����ɴ�",
]),
([	"action" : "$Nһʽ"HIM"��Ŀ�����̡�"NOR"������$w�ж��ñ�ֱ�������ڡ�������$n���̶�������Ю��������$nһ������",
	"lvl"    : 30,
	"skill_name" : "Ŀ������",
]),
([	"action" : "$N�ھ���������$w����ת������ԲȦ��һʽ"HIW"��������̡�"NOR"��Ծ��Ӱ������$n$l����",
	"lvl"    : 60,
	"skill_name" : "�������",
]),
([	"action" : "$N����������һʽ"BLU"����¥�Ǵ̡�"NOR"��$w��$n��ǰ��Ȧ�¹���������ת��������������ʽ����Ȼ��$n$l����������",
	"lvl"    : 90,
	"skill_name" : "��¥�Ǵ�",
]),
([	"action" : "$Nһ���ߺȣ�����������һʽ"HIB"�������Ӵ̡�"NOR"��$w����ת������Ӱ�ݺᣬֱ����Բ��Բ����ֱ�������ƻã�����$n",
	"lvl"    : 120,
	"skill_name" : "�����Ӵ�",
]),
([	"action" : "$N���ذα�������׹�⣬һʽ"MAG"�������̡ܴ�"NOR"�������鶯���ͣ���ʵ����������������˷���$n��ѹ��ȥ",
	"lvl"    : 150,
	"skill_name" : "�����ܴ�",
]),
});

int valid_enable(string usage) { return usage == "whip" || usage == "parry"; }
int valid_learn(object me)
{
	if ((int)me->query_skill("ranmu-blade",1) > 1 ||
		(int)me->query_skill("weituo-chu",1)>1)
		return notify_fail("������д�Ħ�������Ϊ������ͬʱѧϰ��������������\n");
	if ((int)me->query("max_neili") < 1500)
		return notify_fail("���������Ϊ���㣬û�а취�����±޷���\n");
	if ((int)me->query_skill("zhanzhuang-gong", 1) < 150)
		return notify_fail("���վ׮�����̫ǳ��\n");
	if ((int)me->query_skill("yijinjing", 1) < 150)
		return notify_fail("����׽�񹦻��̫ǳ��\n");
	if((int)me->query_skill("xiangmo-whip",1) < 150)
		return notify_fail("��Ľ�ħ�޻���㣬�����������±޷���\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "whip")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("����������������±޷���\n");
	if ((int)me->query("neili") < 50 )
		return notify_fail("����������������±޷���\n");
	me->receive_damage("qi",30);
	me->add("neili",-30);	
	return 1;
}
string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action)-1; i >= 0; i--)
		if(level >= action[i]["lvl"])
			return action[i]["skill_name"];
}
mapping query_action(object me, object weapon)
{
	int d_e1 = -60;
	int d_e2 = -45;
	int p_e1 = -30;
	int p_e2 = -5;
	int f_e1 = 150;
	int f_e2 = 200;
	int m_e1 = 400;
	int m_e2 = 550;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("riyue-whip", 1);
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
	return __DIR__"riyue-whip/" + action;
}
int help(object me)
{
        write(HIC"���±޷���"NOR"\n");
        write(@HELP

    ���±޷��������ֶ����޷���
    Τ���ơ����±޷���ȼľ��������Ϊ��������������
    ����������ͬʱ��ϰ��

        ѧϰҪ��
                �׽150��
                վ׮��150��
                ��ħ��150��
                ������Ϊ1500
HELP
        );
        return 1;
}


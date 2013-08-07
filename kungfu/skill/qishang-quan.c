// qishang-quan.c ����ȭ
// Last Modified by sega on Mar. 10 2000

#include <ansi.h>;
inherit "/inherit/skill/cuff.c";
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N������ɽ��һʽ�����������˫ȭ���ƶ���������$n��$l",
	"lvl" : 0,
	"skill_name" : "�������"
]),
([	"action" : "$N�������أ�����������һʽ��ľ�ѳ��ۡ���������$n�Ƴ�",
	"lvl" : 10,
	"skill_name" : "ľ�ѳ���"
]),
([	"action" : "$N�������飬����������ޣ�һʽ��ˮ�����¡�����$n�޿ɶ���",
	"lvl" : 20,
	"skill_name" : "ˮ������"
]),
([	"action" : "$N����Ծ��һʽ���𺣵�ɽ����˫ȭ���ջ��£��Ʋ��ɵ�",
	"lvl" : 30,
	"skill_name" : "�𺣵�ɽ"
]),
([	"action" : "$N����һ����һʽ�������������ȭ���¶��ϣ�����$n",
	"lvl" : 40,
	"skill_name" : "��������"
]),
([	"action" : "$N����һת��һʽ������Ҳҡ�������$n����ǰ���",
	"lvl" : 48,
	"skill_name" : "����Ҳ�"
]),
([	"action" : "$N���λ�λ������ȭ����һʽ���������ա�������˷�����ȭӰ",
	"lvl" : 54,
	"skill_name" : "��������"
]),
([	"action" : "$N��Хһ������ǰ̤��һ����˫ȭ�й�ֱ����һʽ�����߽��ˡ�����Ȼ����$n��ǰ��",
	"lvl" : 60,
	"skill_name" : "���߽���"
])
});

int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }
int valid_learn(object me)
{
	mapping myfam;
	myfam = (mapping)me->query("family");
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("������ȭ������֡�\n");
	if ((int)me->query_skill("jiuyang-shengong", 1) < 10)
		return notify_fail("��ľ����񹦻�򲻹����޷�ѧ����ȭ��\n");
	if ((int)me->query("max_neili") < 200)
		return notify_fail("�������̫�����޷�������ȭ��\n");
	if ((int)me->query_skill("qishang-quan", 1) > 199)
		return 1;
	if(!myfam || myfam["family_name"] != "����" ||
		myfam["master_id"] != "xie xun")
		return notify_fail("����ȭֻ�����ëʨ��ѧϰ��\n");
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��ı�����ֲ�����ϰ��\n");
	if ((int)me->query("qi") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("�����������������ȭ��\n");
/*
	if ((int)me->query_skill("qishang-quan",1) % 20 == 0 &&
		(int)me->query_skill("qishang-quan",1) < 200)
		return notify_fail("�������ȭ���˹ؼ������ô�����޷�����\n");
*/
	me->receive_damage("qi", 30);
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
	int d_e1 = 5;
	int d_e2 = 30;
	int p_e1 = -50;
	int p_e2 = -5;
	int f_e1 = 250;
	int f_e2 = 450;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("qishang-quan", 1);
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
int learn_bonus() { return 10; }
int practice_bonus() { return 10; }
int success() { return 10; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"qishang-quan/" + action;
}
int help(object me)
{
	write(HIC"\n����ȭ��"NOR"\n");
	write(@HELP

    ����ȭ��ȭ�����ˡ�������ɵĲ���֮�أ�������лѷΪ����
�𣬴���������е���������ȭ�ס����Ӷ����ɡ���Ϊ���ˣ�ʵ��
Ϊÿ��һȭ���������ֲ�ͬ�ھ���ʹ�˲�֪�����֮�࿹��

                    ������������������������
                    ��    ����ȭ�ܾ�      ��
                    ��  ����֮����������  ��
                    ��  �����˷δݸγ���  ��
                    ��  ���뾫ʧ���㱣�  ��
                    ��������������Ƿ�    ��
                    ������������������������

	ѧϰҪ��
		ֻ����лѷѧϰ
		������20��
		����200
HELP
	);
	return 1;
}


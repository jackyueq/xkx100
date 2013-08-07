// anran-zhang.c
// Last Modified by sir 10.21.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action=({
([	"action":"$Ņͷ���죬��������������һ�����Լ�ͷ���տ��ĳ�������б�£��������ɻ��Σ���ɢ���¡���һʽ"HIB"��������졹"NOR"�����®��Բת�㱻��$nʵ���޿ɶ���",
	"skill_name":"�������",
	"lvl":0
]),
([	"action":"$N�ֱ��´������ް�������ʽ������$n�����������ͻȻ�������붯���������䡢˫��ͷ����һ��"HIB"���������С�"NOR"�����ر�������ͬʱ���У���һ�����˵�",
	"skill_name":"��������",
	"lvl":10
]),
([	"action":"$N��������Ʈ����������ˮ������ȴ����֮�������ƴ��ż�ǧ����ɳһ�㡣�����Ǳ�����ˮ֮·����������������֮�ң�һʽ"HIB"�������ˮ��"NOR"������ͣ������֮",
	"skill_name":"�����ˮ",
	"lvl":20
]),
([	"action": "$N������ǰ����׼$n���п�϶��������Ϣ����һ�ƣ�����"HIB"���ǻ��չȡ�"NOR"��",
	"skill_name":"�ǻ��չ�",	
	"lvl":30
]),
([	"action":"$N�˺󼸲����ƺ���սƣ�룬���в������ȵ�$n������ǰ����������һ
�ƣ�һʽ"HIB"���������ġ�"NOR"����$n",
	"skill_name":"��������",
	"lvl":40
]),
([	"action":"$N�˲��ܿ����߳�һ�ţ�ʹ��һ��"HIB"����ʬ���⡹"NOR"����һ�ŷ���ʱ�л�
�㱣�����ԼԼ���������ޣ�����$n�ؿ�",
	"skill_name":"��ʬ����",
	"lvl":60
]),
([	"action":"$NͻȻ�߸�Ծ��һ��"HIB"��������ʩ��"NOR"ͷ�½��ϣ��������ӣ��ĳ�һ��",
	"skill_name":"������ʩ",
	"lvl":70
]),
([	"action":"$N���Ʋ�������$n���н���δ��֮�ʣ����о������䣬����һ����ͻ��
����һ�ƣ�����һ��"HIB"��������ʳ��"NOR"��",
	"skill_name":"������ʳ",
	"lvl":80
]),
([	"action":"$N������������Ȼ���죬��$nϮ�����ϣ���Ȼ�ĳ�һ�ƣ�һ��"HIB "������ֻӰ��"NOR"����$n�米",
	"skill_name":"����ֻӰ",
	"lvl":100
]),
([	"action":"ֻ��$N����Ʈ����������Ȼ���͵�һʽ"HIB"������������"NOR"����������$n����",
	"skill_name":"��������",
	"lvl":110
]),
([	"action":"$N���λζ�������Ʈ�������Ʒ��ʹ��һ��"HIB"�����񲻰���"NOR"����$n��
���Ʒ�֮��",
	"skill_name":"���񲻰�",
	"lvl":120
]),
([	"action":"$N��̾һ��������������У���Ȼ����$n�Ĺ�����ֱ�����һ�̣���Ȼ
������Ц��ת�����һʽ"HIB"����;ĩ·��"NOR"��",
	"skill_name":"��;ĩ·",
	"lvl":140
]),
([	"action":"$Nһ����˻��һʽ"HIB"���ľ�������"NOR"���Ʒ���磬��ʱ���ƺ�ǧ������һ
��ɱ������$n������Ӱ��",
	"skill_name":"�ľ�����",
	"lvl":150
]),
([	"action":"$N����ϲŭ���֣���״�ٳ���$nһ������ʱ�����������ƣ�������$N
��ǰ��$N������������һ��"HIB"��������ɫ��"NOR"����$n�ؿ�",
	"skill_name":"������ɫ",
	"lvl":160
]),
([	"action":"$N������˼���Թ��Լ�������$n��ͻȻ���У�һʽ"HIB"������Ƿǡ�"NOR"������
�磬����$n�����Ʒ�أ�Բ�Ъ���ͻ�$nС��",
	"skill_name":"����Ƿ�",
	"lvl":170
]),
([	"action":"$N������������Ȼ��ʧ���߶�����Ӳ������ס$n��һ�����У���$nδ��
���У���Ȼһʽ"HIB"������ľ����"NOR"������ȫ������ע����",
	"skill_name":"����ľ��",
	"lvl":180
]),
([	"action":"$N��ɫ�Ұף�˫Ŀ�޹⣬�����ң�û����ɵػ��������ĳ�һ�ƣ�
����һ��"HIB"���겻���᡹"NOR"��",
	"skill_name":"�겻����",
	"lvl":200
]),
});

int valid_enable(string usage) {return usage=="unarmed" || usage=="parry";}

int valid_learn(object me)
{
	mapping myfam;
	myfam = (mapping)me->query("family");
	if(myfam["master_id"]!="yang guo")
		return notify_fail("��ֻ�������ѧ�����书��\n");
	if ((int)me->query("max_neili") < 1500)
		return notify_fail("�������̫�����޷�����Ȼ�����ơ�\n");
	if ((int)me->query_skill("yunv-xinfa", 1) < 100)
		return notify_fail("�����Ů�ķ����������޷�����Ȼ�����ơ�\n");
/*
	if((me->query("normal_die")<10)&&(time()-me->query("dietime")>300))
		return notify_fail("��û������������书���ľ���\n");
*/
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("����Ȼ�����Ʊ�����֡�\n");
	return 1;
}
int practice_skill(object me)
{	
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��ı�����ֲ�����ϰ��\n");
	if ((int)me->query("qi") < 40)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 40)
		return notify_fail("���������������Ȼ�����ơ�\n");
	me->receive_damage("qi", 30);
	me->add("neili", -30);
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
	int d_e1 = 10;
	int d_e2 = 30;
	int p_e1 = -45;
	int p_e2 = 25;
	int f_e1 = 300;
	int f_e2 = 400;	
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("anran-zhang", 1);
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
int learn_bonus() { return 10; }
int practice_bonus() { return 10; }
int success() { return 10; }
int power_point(object me) { return 1.0; }
string perform_action_file(string action)
{
	return __DIR__"anran-zhang/" + action;
}
int help(object me)
{
	write(HIC"\n��Ȼ�����ƣ�"NOR"\n");
	write(@HELP

    ����Ժ�С��Ů�ھ���ȶϳ���ǰ���֣����ñ�����������
����֮������������֮�󣬳����ڹ�ѭ�򽥽�֮�⣬����޿�������
�������ռ�˼��С��Ů������������������������Ȥ��һ���ں���
��Ȼ���ã���������֮������ȭ����ߣ���ʱ���ڹ�����ѵ���һ
���־��߼�������������һ�ƣ�����̲��һֻ�󺣹�ı��Ǵ�÷�
�顣���ɴ���˼��������һ���������Ʒ���������Ѱ���书���죬
����֮����ȫ��������һ����һʮ���С�
    �����ƽ�ܹ�������ѧ���ҵ�ָ�㣬��ȫ���ѧ������������
���Ŀھ�����С��Ůѧ�á���Ů�ľ������ڹ�Ĺ�м����������澭
����ŷ�����Ը�󡹦����ת���������߹���������Դ򹷰�������
ҩʦ���Ե�ָ��ͨ�����｣��������һ��ָ֮�⣬��а����������
ؤ������ͨ����ѧ��������������Ĺ�ɵ���ѧ����������֮���
���辶���������ڻ��ͨ��׿Ȼ�ɼң��������Ʒ���ֻ������ʣһ
�ۣ����Բ��������仯ȡʤ��������������ѧͨ���෴����������
������Ϊ����Ȼ�����ơ���ȡ���ǽ��͡��𸳡�����һ�䡰��Ȼ��
���ߣ�Ψ������ӡ�֮�⡣ʵ������С��Ů�Ŀ̹�˼��֮�顣

	ѧϰҪ��
		��Ů�ķ�100��
		����1500
		ֻ�������ѧϰ
HELP
	);
	return 1;
}


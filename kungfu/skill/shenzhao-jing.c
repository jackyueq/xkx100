// shenzhao-jing.c ���վ�
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>;
inherit SKILL;
inherit FORCE;
string type() { return "martial"; }
string martialtype() { return "force"; }

int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 10; }
int power_point(object me) { return 1; }

mapping *action = ({
([	"action":"$NһԾ����$n��࣬����ײ��������$n�ϸ�",
	"lvl": 0
]),
([	"action":"$N�����������$n�۰���Ѹ���ޱȵ�һ����$nһ�ӵ��˳�ȥ",
	"lvl": 10
]),
([	"action":"$N���һ����˫��һ�٣�����ͬʱ��ϥ���͵���ͦ��ײ��$n����",
	"lvl": 20
]),
([	"action":"$N�����ϣ�˫���͵�����$n",
	"lvl": 30
]),
([	"action":"$N����΢�࣬ͻȻ����һ�ţ�����$n����·���ŵ���;���͵�һ̧������$n����",
	"lvl": 40
]),
([	"action":"$NͻȻ������һ�࣬��ס$n��·������������ӿ����",
	"lvl": 50
]),
});

int valid_enable(string usage)
{
	return usage == "unarmed" || usage == "parry" || usage == "force";
}
int valid_learn(object me)
{
	object ding;
	if(!objectp(ding=present("ding dian",environment(me))) || !living(ding))
		return notify_fail("�����õ�����ָ��������ѧ���վ���\n");
	if (me->query("cps")+me->query("cor") !=
		ding->query("cps")+ding->query("cor") )
		return notify_fail("���俴�˿��㣬��Ϣ�ŵ���������ʵ��̫�����Ҿ������\n");
	if ((me->query("kar")%4) > 0 )
		return notify_fail("����ҡ��ҡͷ���������ڹ�̫�������ˡ���ѧҲ�ա�\n");
	return 1;
}
int practice_skill(object me)
{
	return notify_fail("���վ�ֻ����ѧ(learn)�������������ȡ�\n");
}
mapping query_action(object me, object weapon)
{
/* d_e=dodge_effect p_e=parry_effect f_e=force_effect m_e=damage_effect */
	int d_e1 = 25;
	int d_e2 = 45;
	int p_e1 = -30;
	int p_e2 = 10;
	int f_e1 = 140;
	int f_e2 = 240;	
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("shenzhao-jing", 1);
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

string exert_function_file(string func)
{
	return __DIR__"shenzhao-jing/" + func;
}
int help(object me)
{
	write(HIC"\n���վ���"NOR"\n");
	write(@HELP

    �����Ǿ����ˣ��������������ҡ���ĸ˫�����ҲƲ��٣�ȴ��
����ף�ֻ���������䣬�ύ�����ϵ����ѡ�
    ĳ�����˴����Ĵ�������������Ͽ�󣬴���������ƺ�����ϣ�
�ڴ������ð����д򶷵��������Ӵ������������������¹�������
�����������������������Χ��һ�����ߡ�һ��������������ɽ��
��һ����½�������Դ�ƽ����������ʹһ�ڳ������������ǽýݣ�
���������Ὥ�ݳ��������߱�������ī��÷���ϡ����ǵ�ʦ����÷
�����������ȣ��ֵв�ס����ͽ�ܵĶ��У��������ӡ�
    ������ߴ����н�ҩ������÷���Ϻ󣬱��������ˡ�������
������һ���̵ú����ͨ�˷Σ��������β��õ��ˡ���ô������
�죬÷���ϴӻ���ȡ��һ����ֽ�����������䣬����������������
�����ˣ�����ô����ͽ�������������һ�����ף�����û�н�����
������ʲô�ã����ǽ�����Ȼ���棬�������������վ��ˣ��ⲿ��
�վ��������˸��㣬�úõ����գ��˾���Ȼ���ɣ��������ǧ��
�����󴫷��ˡ������վ��������������ġ�

	ѧϰҪ��
		ƾ��Ե�򶡵�ѧϰ
HELP
	);
	return 1;
}


// jinyan-gong.c ���㹦
// Last Modified by sir on 10.18.2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "dodge"; }

string *dodge_msg = ({
	"ȴ����$n����һת��һ��"HIY"�������伣��"NOR"ͻȻת����$N�����\n",
	"$n����ڵ���һ�㣬���ΰεض���"HIC"������˷���"NOR"�㿪����һ�С�\n",
	"$n����$N��������ʽһ��"HIW"���������ա�"NOR"Ʈ������������һƬ΢���е�����һ�㡣\n",
	"$nʹ��"HIY"�����жݱ䡹"NOR"��������һ�Ρ���һ������֪��ô�ģ��ӹ����ļ�϶�����˳�����\n",
	"$nʹ��"HIM"������ת����"NOR"���㲻��ص�Χ��$N����������Ȧ����$N��һ�б��˿�ȥ��\n",
	"$n����������Ȧ����������һ����Ȧ��������㹦��"HIC"�����������"NOR"�����θ߸ߵذ���������\n",
	"$n������ת������Ʈ�����Ƴ����ߣ����ǽ��㹦��"HIB"���������졹"NOR"����̬�����Ѽ���\n",
	"$n����Ʈ�������䷭��һ��"HIW"���������ޡ�"NOR"����������رܿ���$N�Ĺ��ơ�\n",
});

int valid_enable(string usage) { return usage=="dodge" || usage=="move"; }
int valid_learn(object me) 
{      	
	if( (int)me->query_skill("xiantian-qigong", 1) < 10 )
	return notify_fail("������칦�������죬�޷������㹦��\n");
	return 1;
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 20|| (int)me->query("neili") < 4 )
		return notify_fail("�������̫���ˣ����������㹦��\n");
	me->receive_damage("qi", 20);
	me->add("neili", -4);	
	return 1;
}
string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}
int learn_bonus() { return 20; }
int practice_bonus() { return 20; }
int success() { return 20; }
int power_point(object me) { return 1.2; }

int help(object me)
{
	write(HIC"\n���㹦��"NOR"\n");
	write(@HELP

    ���㹦Ϊȫ���ɱ����Ṧ��

	ѧϰҪ��
	  ���칦10��
HELP
	);
	return 1;
}


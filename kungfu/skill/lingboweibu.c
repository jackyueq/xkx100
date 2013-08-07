// lingboweibu.c �貨΢��
// Last Modified by sir on 10.18.2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "dodge"; }
#include <xiaoyao.h>

string *dodge_msg = ({
	"$n�������ɵ���ǰһ��������Ʈ����һʽ"HIW"�����Ʊ��¡�"NOR"��Ӱ����縡�ƣ�\n$Nֻ���ۻ����ҡ�\n",
	"$n����������εض����ڿ���ת��һȦ��һʽ"HIW"�������ѩ��"NOR"��������\n�����裬$NĿѣ���ԣ��治�巽��\n",
	"$ņ�����棬��ȻһЦ����һ�����Ҷ�����б������������һʽ"MAG"������������"NOR"\n�����ȣ�ֻ�������˳����$N�������Σ���������γ��С�\n",
	"$n��$N�������ţ�ͻȻ���κ��������˼�����һʽ"MAG"������ҷ��"NOR"ʩʩȻ\n�����$N��һ�С�\n",
	"$nһʽ"HIM"�����������"NOR"��һ������ƮȻ����ת������$N���\n",
	"$n��չ���壬���Ӿ���һʽ"HIY"��������ɡ�"NOR"Ѹ����磬�����ù���$N���С�\n",
	"$n������Ȼ��һʽ"HIG"������Ū�ġ�"NOR"������ˮ��ʪ���ģ�ɲ�Ǽ们��������\n$N��һ�����˸��ա�\n",
	"$n̩Ȼ�����������������������ţ�һʽ"HIG"�������㡹"NOR"��Ծ�ڼ��ɿ��⡣\n",
	"$n�������У����䲻��������ȴ�Ƿ���ˮ��һʽ"HIB"�������շ硹"NOR"ƮȻ�ܹ�\n$N���С�\n",
	"$n���ν���δ�㣬����������һʽ"HIC"�����󾲲���"NOR"��΢������ˮ�棬ٿ����\n������Ӱ��\n",
});

int valid_enable(string usage) { return (usage=="dodge") || (usage=="move"); }
int valid_learn(object me) 
{      	
	if( (int)me->query_skill("beiming-shengong", 1) < 10 )
	return notify_fail("��ı�ڤ�񹦲������죬�޷�����貨΢����\n");
	return 1;
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 50 || (int)me->query("neili") < 10 )
		return notify_fail("�������̫���ˣ��޷���ϰ�貨΢����\n");
	me->receive_damage("qi", 50);
	me->add("neili", -10);
	return 1;
}
string perform_action_file(string action)
{
	return __DIR__"lingboweibu/" + action;
}
string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 5; }
int power_point(object me) { 
	if (fam_type(me)=="xiaoyao")	return 1.5;
	return 1.0;
}

int help(object me)
{
	write(HIC"\n�貨΢����"NOR"\n");
	write(@HELP

    ���񸳣����貨΢����������������ת���������������ա���
��δ�£�����������������ȣ��������͡��ۺ�ũ���˵��ԣ��޶�
�϶ȣ��������ɣ�������أ��Ӿ������ʳ�¶�������޼ӣ�Ǧ
�����������ٶ�룬��ü���ꡣ�������ʣ������ʡ�����������
��޵��Ȩ���������ݣ��Ǿ����С������̬���������ԡ������̫
������ϼ������ܽ�س��̲�����
    �貨΢��ԭ���ڱ�ڤ�񹦲����ĩ����������ʮ���Զ��ţ���
���б�һ���죬�Ų���̤����ʮ����һ���졣��������Ѹ�ݣ�����
�貨���У����������������Ѽ���
    �貨΢��������֮����Ǻ���֮����Ҳ����֮�а�������һ
����

	ѧϰҪ��
	  ��ڤ��10��
HELP
	);
	return 1;
}


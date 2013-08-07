// yueying-wubu.c ��Ӱ�貽
// Last Modified by sir on 10.18.2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "dodge"; }

string *dodge_msg = ({
"$n����һ�Σ�����һŤ��һ��"HIY"���Ǻ�����"NOR"�����ض���\n",
"$nһ��"HIM"���辡�һ��ȵ׷硹"NOR"��$Nֻ����ǰһ����������$n����Ӱ��\n",
"$nһ��"HIC"��ɨ�����Ʒ粻����"NOR"������΢�Σ��о����յرܿ���$N��һ�С�\n",
"ֻ��$n�������һ����һ��"MAG"������º�Ӱ��"NOR"���󵴶�������һ�ԡ�\n" ,
"$nһ��"HIG"������Ū��Ӱ��"NOR"�����䷭�ɣ����$N��һ�С�\n",
"ȴ��$n"GRN"�����꽭��һ�طɡ�"NOR"���������һ�����ۣ��������ۡ�\n",
"����$nһ��"HIR"����ˮ�仨��ȥҲ��"NOR"������һ�ã�$N��һ�����˸��ա�\n",
"ֻ��$nһ��"HIW"�����ִ���ˮ�޺ۡ�"NOR"���������Σ����������ת���˳����ɿ��⡣\n",
"$n�����������������һ��"HIB"����������Ӱ�ڲ���"NOR"������ƮȻ����\n",
"$n��¶������΢Ц������һת��һ��"HIM"���¶�������"NOR"�����Ų�æ����������$N��ɱ�š�\n",
"$n�����ᆈ"HIM"����������������������ˡ�"NOR"��һ˫��������û�ǧ��˫��$N����ǰ˲����ֺ�
�����˵���Ӱ����֪���ĸ�������ġ�\n",
"ֻ��$nȹ��һ�ڣ�$n����Ӱ��ת��$N��󣬲�����$N¶��ǳǳ��һЦ��\n",
"$n�����ԭ����ת�������"HIM"���仨ɢ�£���ˮҫ�ǡ�"NOR"�����Ӻ����������ǰ����ʵ������
��ʤ�գ�ֻ��$N����վ��������������ʲô��\n",
"$n����������ǣ���������һ��"HIM"����������У���˿���ʡ�"NOR"���������Ӱ�貽�ľ���
��$n��Ӱ����ش�$N�����Ʈ����\n",
"����$n���Ų�æ�������̧��һʽ"HIM"������׷�¡�"NOR"��$n����Ӱ�ѳ����ڰ���У���������㣬�����Ʈ����$N��Ӱ��һ���⡣\n",
"��Ӱ΢���İ��壬"HIM"������Ī��סһ�ţ������ᳪ��Ů����"NOR"����$n���趯�£�����һ��ʢ����
�ʻ������޵Ĳʵ���\n"
});

int valid_enable(string usage) { return (usage=="dodge") || (usage=="move"); }
int valid_learn(object me)
{      	
	if( (int)me->query_skill("bahuang-gong", 1) < 10 )
	return notify_fail("��İ˻�����Ψ�Ҷ��𹦲������죬�޷������Ӱ�貽��\n");
	return 1;
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 10|| (int)me->query("neili") < 2 )
		return notify_fail("�������̫���ˣ���������Ӱ�貽��\n");
	me->receive_damage("qi", 10);
	me->add("neili", -2);	
	return 1;
}
string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}
string perform_action_file(string action)
{
	return __DIR__"yueying-wubu/" + action;
}

int learn_bonus() { return 25; }
int practice_bonus() { return 25; }
int success() { return 20; }
int power_point(object me) { 
	if (me->query("class")=="dancer") return 1.5;
	else return 1.0;
}

int help(object me)
{
	write(HIC"\n��Ӱ�貽��"NOR"\n");
	write(@HELP

    ��Ӱ�貽��ɽ���չ��Ṧ����

	ѧϰҪ��
	�˻�����Ψ�Ҷ���10��
HELP
	);
	return 1;
}


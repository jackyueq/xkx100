// taiji-quan.c ̫��ȭ
// Last Modified by sir 10.21.2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

string *taijin = ({ "����������", "����������", "�����Ǿ���", "���������", "��մ����",  "�����־���","�귭", "����","����","����","����","����"});
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

string *parry_msg = ({
	 "$p�ۼ�$P$w����������ʹ��һ�С���ȸβ�����ҽ�ʵ������飬���𡰼����־���ճ��ճ�棬�����Ѵ�ס$P���󣬺ᾢ������$N����������ǰһ�壬�����������ʼվ����\n",
	 "����$p˫��һȦ���籧̫����һ���ۻ��ޱȵ����������һ�����У�ֻ����$P��ԭ�ؼ�ת�߰��¡�\n",
	 "$p��˫����������������˫�ֳ�Բ�λ������漴��Ȧ��Ȧ��һ��ԲȦ����һ��ԲȦ����Ȧ��СȦ��ƽȦ����Ȧ����Ȧ��бȦ��һ����̫��ԲȦ��������ʱ���׵�$P����ײײ�������������㲻�ȡ�\n",
	 "$pʹ��һ�С����֡������ָߣ����ֵͣ�һ��ԲȦ�ѽ�$P$w��ס��\n",
	 "$p����Ϣ΢�ϣ�����һ�С�б���ơ�����$P$w��ƫ��\n",
	 "$p��һ����������������ת�����ƻӳ���һ��һӭ����$P�������������˻�ȥ��\n",
	 "$p˫��һ����ʹ��һ�С����֡���˫���ᵽ�˼������������飬��$P$w�ļ���������ȥ��\n",
	"$p����˫��һ�ӭ��$w��ȥ������������$P$w����δ��֮�ʣ�ʩ������ȸβʽ������$w����£ס�����¡��𼦶���ʽ��������صأ��������գ�ȫ��ת������һö���ݡ�\n",
	 "��������ʯ���һ˲֮�䣬$p����һ�������ǡ��׺����᡹��ǰ���У�$P�ľ�����ʱ��ա�\n",
});

mapping *action = ({
([	"action" : "$Nʹһ��"+(order[random(13)])+"����ȸβ��"NOR"��˫�ֻ��˸���Ȧ������$n��$l",	
	"skill_name" : "��ȸβ",
	"lvl" : 0
]),
([	"action" : "$Nʹһ��"+(order[random(13)])+"�����ޡ�"NOR"�������������£���������ӳ�������$n��$l",
	"skill_name" : "����",
	"lvl" : 5
]),
([	"action" : "$N���ֻ��գ������ɹ����ƣ���������ʹһ��"+(order[random(13)])+"��������ʽ��"NOR"����$n��$l��ȥ",
	"skill_name" : "������ʽ",
	"lvl" : 10
]),
([	"action" : "$N˫�ֻ������������ϣ��������£�ʹһ��"+(order[random(13)])+"���׺����᡹"NOR"���ֻ�$n�����ź�$l",
	"skill_name" : "�׺�����",
	"lvl" : 15
]),
([	"action" : "$N��������ǰ���£�����΢ת������һ����Ȧ��ʹһ��"+(order[random(13)])+"��§ϥ�ֲ���"NOR"������$n��$l",
	"skill_name" : "§ϥ�ֲ�",
	"lvl" : 20
]),
([	"action" : "$N�������������������ںϣ�ʹһ��"+(order[random(13)])+"���ֻ����á�"NOR"����$n��$l��ȥ",
	"skill_name" : "�ֻ�����",
	"lvl" : 25
]),
([	"action" : "$N���ֱ��ƺ�����ǰ����ȭ�����´�����һ��"+(order[random(13)])+"����׿�����"NOR"������$n��$l",
	"skill_name" : "��׿���",
	"lvl" : 30
]),
([	"action" : "$N���ǰ̤�벽������ʹһ��"+(order[random(13)])+"�������롹"NOR"��ָ������$n��$l��ȥ",
	"skill_name" : "������",
	"lvl" : 35
]),
([	"action" : "$N��"+(order[random(13)])+"����ͨ�ۡ�"NOR"�����һ���������������Ͼ�����Ʋ������$n��$l��ȥ",
	"skill_name" : "��ͨ��",
	"lvl" : 40
]),
([	"action" : "$N��������ԣ�ת�����������·ֱ�ӳ�������ʹһ��"+(order[random(13)])+"��б��ʽ��"NOR"������$n��$l",
	"skill_name" : "б��ʽ",
	"lvl" : 45
]),
([	"action" : "$N�����鰴������ʹһ��"+(order[random(13)])+"���������š�"NOR"����$n��$l��ȥ",
	"skill_name" : "��������",
	"lvl" : 50
]),
([	"action" : "$N˫����ȭ����ǰ��󻮻���һ��"+(order[random(13)])+"��˫������"NOR"����$n��$l",
	"skill_name" : "˫����",
	"lvl" : 55
]),
([	"action" : "$N�����黮������һ��"+(order[random(13)])+"��ָ�ɴ���"NOR"����$n���ɲ�",
	"skill_name" : "ָ�ɴ�",
	"lvl" : 60
]),
([	"action" : "$Nʩ��"+(order[random(13)])+"������ʽ��"NOR"�����ֻ���$n��$l�����ֹ���$n���ɲ�",
	"skill_name" : "����ʽ",
	"lvl" : 65
]),
([	"action" : "$N�ɱ۴��֣�����ǰ����������ʹһ��"+(order[random(13)])+"�����֡�"NOR"������$n��$l",
	"skill_name" : "����",
	"lvl" : 70
]),
([	"action" : "$N������������ʹһ��"+(order[random(13)])+"���𼦶�����"NOR"����$n��$l��ȥ",
	"skill_name" : "�𼦶���",
	"lvl" : 75
]),
([	"action" : "$N�����ɹ����ƣ�˫���������ϣ�������ǰ�Ƴ�һ��"+(order[random(13)])+"����̽��"NOR"",
	"skill_name" : "��̽��",
	"lvl" : 80
]),
([	"action" : "$N����ʹһʽ��"+(order[random(13)])+"����Ů����"NOR"��������$n��$l��ȥ",
	"skill_name" : "��Ů����",
	"lvl" : 85
]),
([	"action" : "$N���־���ǰ��������ǰƲ����ʹһ��"+(order[random(13)])+"������Ʋ����"NOR"����$n��$l��ȥ",
	"skill_name" : "����Ʋ��",
	"lvl" : 90
]),
([	"action" : "$N�����鰴������ʹһ��"+(order[random(13)])+"��ת����ȡ�"NOR"����$n��$l��ȥ",
	"skill_name" : "�������",
	"lvl" : 95
]),
([	"action" : "$N�������ϻ�������������ʹһ��"+(order[random(13)])+"����������"NOR"����$n��$l��ȥ",
	"skill_name" : "��������",
	"lvl" : 100
]),
([	"action" : "$Nʹһ��"+(order[random(13)])+"���Դ���"NOR"������§��ϥ���������´���$n��$l",
	"skill_name" : "�Դ�",
	"lvl" : 120
]),
([	"action" : "$N˫���ȱ�����״�����طֿ������������£�һ��"+(order[random(13)])+"��Ұ����ס�"NOR"����$n��$l�����Ŵ�ȥ",
	"skill_name" : "Ұ�����",
	"lvl" : 150
]),
([	"action" : "$N��������ǰ���£��ұ�΢����ʹһ��"+(order[random(13)])+"��������ɽ��"NOR"����$n��$l��ȥ",
	"skill_name" : "������ɽ",
	"lvl" : 180
]),
([	"action" : "$N˫�־��¸�����������ǰ����ʮ��״��һʽ"+(order[random(13)])+"��ʮ���֡�"NOR"����$n��$l��ȥ",
	"skill_name" : "ʮ����",
	"lvl" : 210
]),
([	"action" : "$N���̤һ���鲽��˫�ֽ����ʮ��ȭ��һ��"+(order[random(13)])+"���������ǡ�"NOR"����$n��$l��ȥ",
	"skill_name" : "��������",
	"lvl" : 240
]),
([	"action" : "$N��������ڳ���������ֱ���ұ�΢����ʹһ��"+(order[random(13)])+"������"NOR"����$n��$l�����Ŵ�ȥ",
	"skill_name" : "�����",
	"lvl" : 270
]),
([	"action" : "$N˫���쿪������Ϊ�ᣬ����������һ����Բ����\nһ��"+(order[random(13)])+"��ת�������"NOR"����$n�������¶�������������Ӱ֮��",
	"skill_name" : "ת�����",
	"lvl" : 300
]),
([	"action" : "$N˫����ȭ�����ֻ����������ʣ����ֻ�����ǰ�Ƴ���\nȭ�������һ��"+(order[random(13)])+"���乭�仢��"NOR"��ֱ��$n���Ѷ�ȥ",
	"skill_name" : "�乭�仢",
	"lvl" : 400
]),
([	"action" : "$N˫������ǰ���ƣ��ɸ�����ǰ�����Ƴ���һ��"+(order[random(13)])+"������Ʊա�"NOR"��һ�ɾ���ֱ��$n",
	"skill_name" : "����Ʊ�",
	"lvl" : 500
]),
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }
int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��̫��ȭ������֡�\n");
	if ((int)me->query_skill("taiji-shengong", 1) < 20)
		return notify_fail("���̫���񹦻�򲻹����޷�ѧ̫��ȭ��\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷���̫��ȭ��\n");
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��ı�����ֲ�����ϰ��\n");
	if ((int)me->query("qi") < 70)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 70)
		return notify_fail("�������������̫��ȭ��\n");
	me->receive_damage("qi", 60);
	me->add("neili", -60);
	return 1;
}
string query_parry_msg(string limb)
{
	return parry_msg[random(sizeof(parry_msg))];
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
/* d_e=dodge_effect p_e=parry_effect f_e=force_effect m_e=damage_effect */
	int d_e1 = 0;
	int d_e2 = 20;
	int p_e1 = -50;
	int p_e2 = 30;
	int f_e1 = 400;
	int f_e2 = 600;	
	int i, lvl, seq, ttl = sizeof(action);
	string msg;
	lvl = (int) me->query_skill("taiji-quan", 1);
/////////yun taiji/////////	
	if( me->query_temp("taiji") && me->query("neili") > 100 )
	{
 		      me->add_temp("taiji_fight", 1);
msg = random(2)==1?
HIW"ֻ��$N���鶥�������ذα����������Ρ�����׹�⣬˫�ֱ��˸�̫��ʽ��ԲȦ����������̫����\n�Ѵ������һ���Ķ������ľ��磬���ʹ����̫��ȭ�е�"NOR:
HIW"ɲʱ��$N����̫��ȭּ�С����ɷ��ɣ���չδչ�������ⲻ�ϡ��ľ�΢����֮����\nʹ��һ������������ˮ�������ޱȡ����ʹ����̫��ȭ�е�"NOR;
msg = msg + order[random(sizeof(order))] + taijin[random(sizeof(taijin))] + NOR;
        if ( lvl > 250 
        && random(lvl) > 200
        && random(10)>5)
        {
	      	me->add("neili", -10);
        	return ([  
                	"action" : msg,
                	"force" :  600,
                	"dodge":   -80,
               // 	"damage":   500,
                	"parry":   -80,
                	"damage_type" : random(2)==1?"����":"����",
        	]);
        }
  }
  //////��ͨ����////////
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

int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 5; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"taiji-quan/" + action;
}

int help(object me)
{
	write(WHT"\n̫��ȭ��"NOR"\n");
	write(@HELP

    ̫��ȭ��Ϊ��ĩԪ���䵱�����������������ϵ���֮˵������
��Ȼ����������˸ա�������ǧ���������죬�Ծ��ƶ�����
���ˣ���Ϊ����֮����ϳ���ѧ��ȭ��ʱ˫��Բת��ÿһ�ж�����
̫��ʽ�������仯����΢���ʵ�ǿ�������ѧ�д���δ�е�����
�ء�����Ϊ�����鶥�������ذα����������Ρ�����׹�⡹ʮ����
�֣��������У���������������һ������·ȭ����Ҫּ��
    ̫��ȭ����Ҫ�����ɷ��ɣ���չδչ�������ⲻ�ϣ��������
��Ϊ����һ����

	ѧϰҪ��
		̫����20��
		����100
HELP
	);
	return 1;
}


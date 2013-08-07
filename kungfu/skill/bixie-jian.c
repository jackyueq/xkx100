// bixie-jian.c ��а����
// Last Modified by sega on Mar. 10 2000

#include <ansi.h>;
inherit SKILL;
inherit F_SSERVER;
string type() { return "martial"; }
string martialtype() { return "skill"; }

string *dodge_msg = ({
	"ͻȻ֮�䣬��Ӱ���ϣ�$n��󻬳����࣬��ʱ�ֻص���ԭ�أ������$N��һ�С�\n",
	"$n�ֱۻ�ת����$N������һ�ƣ�˳������һ�ԡ�\n",
	"$n�����������$N������Ѹ���ޱȵ�һ����˳������һ�ԡ�\n",
	"$n����Ʈ����������ȣ�ת�˼�ת���Ʋ���$N����󣬶����$N��һ�С�\n",
	"$Nֻ����ǰһ�����ƺ�����$n����һ�ϣ����漴�ּ�$n�ص�ԭ�أ�ȴ�ƴ�δ�뿪��\n",
	"$N�۾�һ����$n��û����Ӱ��ͻȻ$n���������һ��$N��ͷ������Ծ����\n",
	"$n��ȻһЦ������֮����$N����֪����Ǻã�ͣס�˹�����\n",
});

mapping *action = ({
([	"action":"ͻȻ֮�䣬��Ӱ���ϣ�$N��󻬳����࣬��ʱ�ֻص���ԭ��",
	"lvl" : 0,
	"skill_name" : "��Ӱ����"
]),
([	"action":"$N�����������$n������Ѹ���ޱȵ�һ����$n��Щ�����Լ�С��",
	"lvl" : 10,
	"skill_name" : "�Լ�С��"
]),
([	"action":"�����$N�����ϣ��ڵ�$n�������Ծ��ԭ��",
	"lvl" : 25,
	"skill_name" : "������"
]),
([	"action":"$NͻȻ���з�һ�䣬$w�����������ʽ������ס�$n����֮�з������",
	"lvl" : 35,
	"skill_name" : "�з�һ��"
]),
([	"action":"$N����Ʈ����������ȣ�ת�˼�ת���Ʋ���$n�����",
	"lvl" : 40,
	"skill_name" : "�������"
]),
([	"action":"$Nһ����Ц������Ｒ����ǰ��һ˲֮�䣬��$n����Ѳ���һ�ߣ�$w�漴�ݳ�",
	"lvl" : 45,
	"skill_name" : "������ǰ"
]),
([	"action":"$N�ȵ������ã������㼴�γ�$w�����ִ̳�������ת����ȥ",
	"lvl" : 45,
	"skill_name" : "���ִ̳�"
]),
([	"action":"$nֻ����ǰһ�����ƺ�����$N����һ�ϣ����漴�ּ�$N�ص�ԭ�أ�ȴ�ƴ�δ�뿪",
	"lvl" : 20,
	"skill_name" : "��ǰһ��"
]),
([	"action":"$N����ˣ�$n��׷������ͻȻ��$N����$n��ǰ������$wֱָ$n��$l",
	"lvl" : 5,
	"skill_name" : "�����"
]),
([	"action":"$N��س嵽$n��ǰ������$wֱ��$n���ۣ�$n��æ�мܣ�����$N��$wͻȻת��",
	"lvl" : 45,
	"skill_name" : "ֱ������"
]),
([	"action":"$N����Ծ��$ņ��һ����������$N����ֱ����£�����$w����$n��$l",
	"lvl" : 64,
	"skill_name" : "����Ծ��"
]),
([	"action":"$N��֦�Ͱڣ�$n��ǰ�·�ͻȻ�������߰˸�$N���߰�ֻ$wһ�����$n",
	"lvl" : 79,
	"skill_name" : "��֦�Ͱ�"
]),
});
int valid_enable(string usage)
{
	return usage == "sword" || usage == "dodge" || usage == "parry";
}
string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}
int valid_learn(object me)
{
	return notify_fail("��а����ֻ��ͨ����ϰ���������䡷��ѧϰ��\n");
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
	int p_e1 = -60;
	int p_e2 = -40;
	int f_e1 = 150;
	int f_e2 = 230;
	int m_e1 = 240;
	int m_e2 = 340;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("bixie-jian", 1);
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
int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 5; }
int power_point(object me)
{
	if(me->query_skill("kuihua-xinfa",1) > 10) return 1.0; 
	else return 0.6;
}

string perform_action_file(string action)
{
	return __DIR__"bixie-jian/" + action;
}

void double_attack(object me, object victim)
{
	int i,j;
	object other=offensive_target(me);
	if (objectp(other)) victim = other;

	i = me->query_skill("bixie-jian",1)/15; // taiji lian��ÿ�е��� sword/15
	j = (me->query_skill("bixie-jian",1)-1)/100; // 100 = 0 101 = 1 200 = 1 201 = 2 

  if ( j > 1 && !me->query_temp("bixie/guimei") && userp(me)) j = 1;
  
	if (userp(me))
	j = 1; //����ƽʱ��double attack�ĳ�pfm����
				 //ע����� query_temp("bixie_hit")��ʾ�������ֵ��ǵڶ�����
         //��������������npcֱ���ڵ�����ʹ�� ���������pfm��ʹ��
	if(  me->query_temp("bixie_hit") < j && 
  objectp(me->query_temp("weapon")) && 
  (me->query_temp("weapon"))->query("skill_type")=="sword"  &&
  me->query_skill_mapped("sword") == "bixie-jian" &&
  me->is_fighting(victim) )
	{
		me->add_temp("bixie_hit", 1);
		me->add_temp("apply/attack", i);
  	me->set_temp("action_flag",1);
		COMBAT_D->do_attack(me,victim,me->query_temp("weapon"),2);
		me->set_temp("action_flag",0);
		me->add_temp("apply/attack", -i);
		me->add_temp("bixie_hit", -1);
	}
}

int help(object me)
{
	write(HIC"\n��а������"NOR"\n");
	write(@HELP

    Ҫ˵��а��������Ҫ�ӡ��������䡷̸��

    ���������䡷��һλ�¹�����������һλ����֣�Ϊʲ���ڻ�
������̫�࣬����˭Ҳ��֪������춱��������ص��书��ȴ�Ǿ���
֮�������ٶ�������ʼ����һ���ܾ������ɡ�������ǰ���ⲿ����
Ϊ����������������Ժ���á���ʱ���������·��ɺ�Ҷ��ʦ������
һλ���Ǵ�۵��˲���������������书���ԣ��õ����ɱ�����
�����书���ǡ������о����ֱ꣬��������ʼ��û����ʼ��������
���书��

    һ�ջ�ɽ�ɵ�����Ͳ��ӷ嵽�������������ͣ�͵����������
���䡷����ʱ�Ҵ�֮�ʣ����˲���ͬʱ�ı�ȫ�飬���¶��˷ֶ���
һ�˶�һ�룬�����ص���ɽ����ͬ�������֡����϶��˽����й���
һ��ӡ֤����Ȼţͷ�������죬ȫȻ�ϲ����������˶����ŶԷ���
�����飬ֻ���Լ����ǵĲ��ǶԵġ���ɽ�Ľ�������֮���ɴ˶���

    ��Ҷ��ʦ���÷��ִ��£���֪���ⲿ����������ѧ��������
���������֮���������ѵĻ��ǵ�һ�أ�ֻ����һ���ܴ�ͨ����
����Ҳûʲ�ᡣ��һ��ֻҪ�а�����ʱ�������ˡ���Ҷ����
��ǲ������Ӷ�Ԫ��ʦǰ����ɽ��Ȱ�����̶�λ��������ϰ������
����ѧ��

    ��Ԫ��ʦ�ϵû�ɽ�����̶��˶��������ྴ������˽�ġ�����
���䡷��һ������Ǹ�⣬һ��ȴ�Ծ���������ѧ������̡��ⲻ֪
��Ԫ���Ǻ�Ҷ�ĵ�����ӣ������е���ѧȴδ�ɴ��ڡ����¶�Ԫ��
ʦ���������������Ǳ��о��ģ���ڼ��Խ��ͣ�����ȴ���Լ��¡�
��Ԫ��ʦ�书�������������Ǿ�������֮�ˣ�����һ�侭�ģ��㼺
�����Ｘ�䣬��ȻҲ˵��ͷͷ�ǵ���

    �������̶������ǵı��Ѳ��࣬��������һת���������ִ���
�ۿۡ���Ԫ��ʦ�ڻ�ɽ��ס�˰��գ�������𣬵��Ӵ�ȴҲû�ٻ�
������������ȥ�����ú�Ҷ��ʦ���յ���Ԫ��ʦ��һͨ���ţ�˵��
���������֣����⻹�ף�����Ŀ�ټ�ʦ�����ơ�

    �����һ���£���ɽ�ɵ���͵�����������䡷֮��Ҳ������⡣
������ʱ��ħ��ʮ����������ɽ���ڻ�ɽ����һ����ս��ħ��ʮ��
�϶��������ˣ���ܶ�ȥ��������Ͳ��ӷ����˾�����һ���б�����
��������¼���������䡷Ҳ��ħ�̶���ȥ��

    ��Ԫ��ʦ����֮�ᣬ����ԭ�գ��������ߵ�����ȡ��Զͼ��Ȣ
�����ӣ������ھ֣��ڽ����Ϻ�����Ҹ���һ����ҵ��

    ���������µĺ�Ҷ��ʦ԰��֮ʱ���ټ����˵��ӣ�˵���ⲿ��
���ǰ��������㼴����Ͷ��¯�л𻯡���Ҷ˵���ⲿ��ѧ���ž�
�������������ؼ�֮���������׫���˲�δ����Ϊ��ͨ��͸��
���µ�����̫�ࡣ�����ǵ�һ���ѹ��������ѹ�����ֱ�ǲ��ܹ���
�ɹ�������������ʵ������֮����

    ��Զͼ�ı�а�������Ǵӡ��������䡷��ƪ��������书����
��ϵ��ͬԴ����а��������ʮ��·����һ���Ӳ��⴫������ʹ�ô�
����֮�˸�������Ѹ�ݹ��죬������˵�֪���з�����Ŀ��ֻ֪��
����ʽ�˷�����˼����Զͼ����¼�ġ���а���ס���������Լ���
���ͣ��ʽ�ħ�����صġ��������䡷�����ţ�������Щ���ݡ�����
�����ϰ�˹�������ѭ��������֮�������εõ�������������
�ţ���һֱ�ǽ����ϱܶ���̸�����ܡ���й¶���أ�������ɱ��֮
����

	ѧϰҪ��
		�Թ���̫��
HELP
	);
	return 1;
}


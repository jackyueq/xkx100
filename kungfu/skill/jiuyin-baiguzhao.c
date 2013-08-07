//jiuyin-baiguzhao.c �����׹�צ
// Last Modified by sega on Mar. 10 2000

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N�����転������аħ��˫צ���ץ�������������󷭴������ּ��죬�����ָץ��$n$l",
]),
([	"action" : "ͻȻ��Ӱ������$N�ȵ�$n�����������֣������ָ��$n$l������ȥ",
]),
([	"action" : "$N�ֱ۹ؽڿ���һ�죬�ֱ۶�Ȼ���˰�ߣ�һ�ư���$n$l����ָ��Ҫ���",
]),
([	"action" : "$N˫��΢�ţ�ʮ������ָ��ӳ���Ұ׹�â��ͻȻ�����צ����ָ�͵ز���",
]),
([	"action" : "$N����ͻȻ��$n��ǰ��Χ�¹���������ת���������߰˰㣬���������һ�죬�����ֱָ��$n$l",
]),
([	"action" : "$N˫�Ʋ�ס�غ���������ֱ۹ؽڿ������죬����һ��������ž��һ�³�$n$l��ȥ",
]),
([	"action" : "$N���δ춯���������������ų�$n�������ƣ�һ�ƿ���һ�ƣ�һ������һ��",
]),
([	"action" : "$N���ر�צΪ�ƣ����Ӳ������ұ۶�����Ǳ��������һ�Ƴ�$n$l��ȥ",
]),
([	"action" : "$Nһ����Х������Ʈ�磬����������е�ֿ������$n����δ������������Ѹ���Ѽ�",
]),
});

int valid_enable(string usage) { return usage=="claw" || usage=="parry"; }
int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�������׹�צ������֡�\n");
	if ((int)me->query("max_neili") < 200)
		return notify_fail("�������̫�����޷��������׹�צ��\n");
	return 1;
}
int practice_skill(object me)
{
	object* ob, obj;
	int i,skill,damage,cost;

	cost = 40;
	skill = me->query_skill("jiuyin-baiguzhao",1);
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��ı�����ֲ�����ϰ��\n");
	if ((int)me->query("qi") < 120)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 50)
		return notify_fail("������������������׹�צ��\n");
	if( environment(me)->query("no_fight") )
		return notify_fail("�����������������ˡ�\n");
	if( environment(me)->query("sleep_room") )
		return notify_fail("������������ű�����Ϣ��\n");
	if( !objectp(obj=present("corpse", environment(me))))
		return notify_fail("�������׹�ץ����ʬ�塣\n");
	if( skill > 100 && me->query("shen") > -100)
		return notify_fail("����а���书��������������ġ�\n");
	if (skill > 150) cost = 80;
	if (skill >= 250) cost = 120;
	me->receive_damage("qi", cost);
	me->add("neili", -40);
//	tell_room(environment(me), 
  message_vision(
HIB"ֻ��$N������Ȧ�¹���������ת���������߰˰㻨�������������һ�죬�۵�
һ�죬�����ֱָ�������ʬ������š���������ָ"HIR"Ѫ����"HIB"���Ὣ������\n"NOR,me);
/*
	ob = all_inventory(environment(me));
	for(i=0; i<sizeof(ob); i++)
	{
		if( !living(ob[i]) || ob[i]->query_temp("noliving") ||
			ob[i]==me ) continue;
		if(skill+random(skill/2)<(int)ob[i]->query("con")*2) continue;
		damage = skill - ((int)ob[i]->query("neili") );
		if( damage > 0 )
		{
			ob[i]->receive_damage("qi", damage );
			if( (int)ob[i]->query("neili") < skill * 2 )
				ob[i]->receive_wound("qi", damage);
			tell_object(ob[i], HIB"��Ȼ��ǰ��Ӱ���裬�������ǰһ������ֱϮ���ţ�ȫ����Ȼ�е�Ҫ��˺�ѿ�һ����\n"NOR);
		}
		if( userp(ob[i]) ) ob[i]->fight_ob(me);
		else if( !ob[i]->is_killing(me) ) ob[i]->kill_ob(me);
	}
*/
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
	int d_e1 = 20;
	int d_e2 = 5;
	int p_e1 = -20;
	int p_e2 = -60;
	int f_e1 = 300;
	int f_e2 = 600;
	int i, lvl, seq, ttl = sizeof(action);

	seq = random(ttl);       /* ѡ������������ */
	return ([
		"action"      : action[seq]["action"],
		"dodge"       : d_e1 + (d_e2 - d_e1) * seq / ttl,
		"parry"       : p_e1 + (p_e2 - p_e1) * seq / ttl,
		"force"       : f_e1 + (f_e2 - f_e1) * seq / ttl,
		"damage_type" : random(2) ? "ץ��" : "����",
	]);
}
int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 5; }
int power_point(object me)
    { 
      if ((int)me->query("shen")<=-100000) return 1; 
      else if ((int)me->query("shen")<0)  return 0.8;
      else return 0.6;
     }

void skill_improved(object me)
{
	tell_object(me, HIR"���Ȼ���ĵ�����һ�ɶ��ɱ��ɱ��ɱ����Ҫɱ�������ˣ�\n" NOR );
//	me->add("shen", -200);
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
	if( damage_bonus < 100 ) return 0;

	if( random(damage_bonus/3) > victim->query_str() ) 
	{
    victim->receive_wound("qi", (damage_bonus - 80) / 3, me);
		return HIR "��������������һ�����죬�����ǹ����������\n" NOR;	
	}
}

int help(object me)
{
	write(HIC"\n�����׹�צ��"NOR"\n");
	write(@HELP

    ���ڻʵ���������䣬���������µ���֮�飬���ӡ�У�һ��
����ǧ�İٰ�ʮһ����Ϊ�����ٵ��ء����ʵ�ί�ɿ���֮�ˣ���
�����ѡ��������ⲿ����ؿ̴����֣��ʵ۷���֮����Ҫɱ����
ͷ�������һ��һ���ϸ��У��������Ȼ����˾�ͨ��ѧ�������
��������书�еĸ����������ʦ��ͨ����ϰ�ڹ��⹦������Ϊ
һλ�书����֡�������漰������ɱ������ɽ�֡���֪��������
������ʮ���꣬���ڶ�ÿһ��������ʹ����������������ͨ���ƽ�
�ķ��ӶԸ������ǳ���ɽ����ȥ����ѩ�ޡ�������Щ����ȫ���Ѳ�
�������ˡ��������룺��ԭ����Ҳ���ˣ���Ҳû����û���������
�����⼸ʮ����Ѫ������˰��������¸��Ҹ��ɹ������ѧ������
���꣬�ⷬ��Ѫ���Ǿʹ���û�������������뵽�ķ���д������
�������飬�Ǿ��ǡ������澭���������׹�צ�������������ɵİ�
������

	ѧϰҪ��
		����200
HELP
	);
	return 1;
}


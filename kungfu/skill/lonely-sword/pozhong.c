// pozhong.c ����

#include <ansi.h>
inherit F_SSERVER;

int perform(object me)
{

	object *ob,weapon,target;
	int i, skill, damage,flag=0;
	string msg;

	if(me->query("family/master_id") != "feng qingyang" && userp(me) && !wizardp(me))
		return notify_fail("�㲻�Ƿ�����մ����ӣ�����ʹ�þ��У�\n");
  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/pozhong") &&
  !me->query("can_perform/lonely-sword/pozhong") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�");

	if( !objectp(target) ) target = offensive_target(me);
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	  !living(target) || target->query_temp("noliving") )
		return notify_fail("���¾Ž�����ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	skill = me->query_skill("lonely-sword",1);
	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if( skill < 80)
		return notify_fail("��Ķ��¾Ž��ȼ����������ܡ����ڡ���\n");
	if( me->query("max_neili") < 800 )
		return notify_fail("���������Ϊ�������޷����á����ڡ���\n");
	if( me->query("neili") < 500 )
		return notify_fail("��������������޷����á����ڡ���\n");
//	if( environment(me)->query("no_fight") )
//		return notify_fail("�����ﲻ�ܹ������ˡ�\n");
	me->add("neili", -250);
	me->receive_damage("qi", 10);
	me->start_busy(1);
	message_combatd(HIC"$N��Хһ�������г�����ת�����Ʊ�ã�������âǧ��������������˷����ٵ����\n"NOR,me);
	ob = all_inventory(environment(me));
	for(i=0; i<sizeof(ob); i++)
	{
		if( !living(ob[i]) ||ob[i]->query_temp("noliving")
		     || ob[i]==me ) continue;
		if( !ob[i]->is_fighting(me))
		          continue;  
		damage=skill-((int)ob[i]->query_skill("dodge",1)/2);
//		if ( damage <= 0 ) continue;
		if( damage>0 )
		{
			ob[i]->receive_damage("jing", damage);
			ob[i]->receive_damage("qi", damage*2);
			ob[i]->receive_wound("qi", damage);
			switch (random(5))
			{
				case 1:
message_combatd(HIC"$N���н����ƿգ�������$n���ʺ�\n"NOR,me,ob[i]);
					break;
				case 2:
message_combatd(HIC"ֻ��$N���ֽ���һ�㣬$n�ؿ���Ѫ��ӿ������\n"NOR,me,ob[i]);
					break;
				case 3:
message_combatd(HIC"$N���н�����������$n�������һ��͸��������\n"NOR,me,ob[i]);
					break;
				case 4:
message_combatd(HIC"$N���н���б����������$n��С����\n"NOR,me,ob[i]);
					break;
				default:
message_combatd(HIC"�㿴��$N���н���һ����������$n��ۼ羮Ѩ�ϣ�\n"NOR,me,ob[i]);
					break;
			}
			tell_object(ob[i],HIC"�������ǰһ�㺮��ֱ���������پ�һ���ʹ���̣���ǰ���ڡ�\n"NOR);
		}
		if(userp(ob[i])) ob[i]->fight_ob(me);
		else if( !ob[i]->is_killing(me)) ob[i]->kill_ob(me);
	}
	return 1;
}

int help(object me)
{
	write(WHT"\n���¾Ž�֮���ڣ�"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		��ȺŹ֮�г��֣��˵о�����Ѫ

	����Ҫ��
		��Ϊ������մ�����
		���¾Ž�80��
		������Ϊ50
		����250
HELP
	);
	return 1;
}


// roar.c ��Ȼ������
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
	object *ob;
	int i, skill, damage;

  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/roar") &&
  !me->query("can_perform/yunv-xinfa/roar") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("����ʹ�õ��ڹ���û�����ֹ��ܡ�");
	if( environment(me)->query("no_fight") )
		return notify_fail("���ﲻ�ܹ�������! \n");

	if( ((int)me->query("neili") < 150 ) || ((int)me->query("max_neili") < 150 ) || ( (int)me->query_skill("yunv-xinfa",1) < 100) )
		return notify_fail("�㳤̾һ�����������һ����\n");

	skill = me->query_skill("force");

	me->add("neili", -150);
	me->receive_damage("qi", 10);

	me->start_busy(3);
	message_combatd(MAG"$N���ָ��أ�����������һ������Ȼ���꡹��\n"NOR, me);

	ob = all_inventory(environment(me));
	for(i=0; i<sizeof(ob); i++)
	{
		if( !living(ob[i]) || ob[i]->query_temp("noliving") ||	ob[i]==me )	continue;

		if( skill/2 + random(skill/2) < (int)ob[i]->query("con") * 2 ) continue;

		if (!userp(ob[i]) && !ob[i]->accept_hit(me)) continue;

		damage = skill - ((int)ob[i]->query("max_neili") / 10);

		if( damage > 0 )
		{
			ob[i]->receive_damage("jing", damage * 2 );
			if( (int)ob[i]->query("neili") < skill * 2 )
				ob[i]->receive_wound("jing", damage);
			tell_object(ob[i], "���Ȼ����һ�����������������������Ư�Ʋ�����\n");
		}
		if( userp(ob[i]) ) ob[i]->fight_ob(me);
		else if( !ob[i]->is_killing(me) ) ob[i]->kill_ob(me);
	}
	return 1;
}

int help(object me)
{
	write(WHT"\n��Ů�ķ�֮��Ȼ��������"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		�˺��Լ���Χ����������ľ���

	����Ҫ��
		��Ů�ķ�100��
	        ����150
HELP
	);
	return 1;
}


// ��󡹦����
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

int exert(object me,object target)
{
	int con1, con2, con3, con;
	con1 = target->query_condition("snake_poison");
//	con2 = target->query_condition("scorpion_poison");
	con3 = target->query_condition("xx_poison");

  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/xidu") &&
  !me->query("can_perform/hamagong/xidu") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("����ʹ�õ��ڹ���û�����ֹ��ܡ�");


	if ( !living(target) || target == me )
		return notify_fail("��ҪΪ˭������\n");
		
	notify_fail("������Ҫץ���ˣ���ʲô���֣�\n");
	if (!userp(target) && !target->accept_hit(me)) return 0;

	if ( !con1 && !con3 )
		return notify_fail("�Է�û���ж���\n");

        if ( target->is_fighting() )
		return notify_fail("ս�����޷��˹�������\n");
		
	if( me->is_fighting() )
		return notify_fail("ս�����˹�������������\n");

	if( (int)me->query("neili") < 100 )
		return notify_fail("�������������\n");

	if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
		return notify_fail("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�\n");

	if ((int)me->query_skill("hamagong", 1) < 50)
		return notify_fail("��ĸ�󡹦��Ϊ��������\n");

	if ((int)me->query_skill("xidu-poison", 1) < 50)
		return notify_fail("�������������Ϊ��������\n");

	if ( con1 > 0 ) {
		if ( (int)me->query("neili") < 100 )
			return notify_fail("�������������\n");
		con = ( ( me->query_skill("hamagong", 1) / 10 ) >= con1 ? con1 : me->query_skill("hamagong", 1) / 10 );
		target->apply_condition("snake_poison", con1 - con);
		message_vision(  HIW "$N��ϥ���½���������$n���ģ��˹���$n���ڵ��߶�����...\nƬ�̹���$N��������ȫ�ʺ�ɫ��\n" NOR , me, target );
//		if ( !con1 )
    if ( (con1 - con)<=0 )
			{
				tell_object( target, HIC "����һ�½�ǣ�����ȫ�����ľ������ȫ��ʧ�ˡ�\n\n" NOR );
		    target->clear_condition("snake_poison");
		  }
		else	
			tell_object( target, HIC "����һ�½�ǣ�����ȫ�����ľ�м����˲��١�\n\n" NOR );			
		me->add("neili", -100);			
		me->apply_condition("snake_poison", me->query_condition("snake_poison") + con);
	}			 
	else if ( con3 > 0 ) {
		if ( (int)me->query_skill("hamagong", 1) < 70 )
			return notify_fail("��ĸ�󡹦��Ϊ������\n");
		if ( (int)me->query("neili") < 150 )
			return notify_fail("�������������\n");
		con = ( ( me->query_skill("hamagong", 1) / 50 ) >= con3 ? con3 : me->query_skill("hamagong", 1) / 50 );
		target->apply_condition("xx_poison", con3 - con);
		message_vision(  HIW "$N��ϥ���½���������$n���ģ��˹���$n���ڵ������ƶ�����...\n"
			 "Ƭ�̹���$N��������ȫ���Ϻ�ɫ��\n" NOR , me, target );
//		if ( !con3 )
    if ( (con3 - con)<=0 )
			{
				tell_object( target, HIY "��ֻ����һ��ů���ӵ�������ȫ���Ⱥ����ģ������ƶ��ƺ���ȫ�����ˡ�\n\n" NOR );
		    target->clear_condition("xx_poison");
      }
		else	
			tell_object( target, HIY "��ֻ����һ��ů���ӵ������𣬲�����ǰ�ǰ㺮���ˡ�\n\n" NOR );			
		me->add("neili", -150);			
		me->apply_condition("xx_poison", me->query_condition("xx_poison") + con);
	}
	me->set("jiali", 0);
	me->start_busy(4);
	return 1;
}
int help(object me)
{
	write(WHT"\n��󡹦֮������"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		Ϊ�ж��������������أ������ж���Ч��
		�߶������޶�

	����Ҫ��
		��󡹦50��
		��������50��
		����100
HELP
	);
	return 1;
}


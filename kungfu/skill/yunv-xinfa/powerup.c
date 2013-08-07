// powerup.c ��Ů�ķ�����
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
	int skill;

  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/powerup") &&
  !me->query("can_perform/yunv-xinfa/powerup") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("����ʹ�õ��ڹ���û�����ֹ��ܡ�");
	if( target != me )
		return notify_fail("��ֻ�������Լ���ս������\n");
	if( (int)me->query("neili")<200)
		return notify_fail("�������������\n");
	if( (int)me->query_temp("powerup"))
		return notify_fail("���Ѿ����˹����ˡ�\n");
	if( (int)me->query_skill("yunv-xinfa",1) < 20)
		return notify_fail("�����Ů�ķ����������졣\n");

	skill = me->query_skill("force");

	message_combatd( HIC"$N��ɫ΢΢һ����˫������һ�֣����������һ��"HIW"��������"HIC"ʢ���ڳ����ĺ����У�\n" NOR, me);

	me->add_temp("apply/attack", skill/3);
	me->add_temp("apply/dodge", skill/3);
	me->set_temp("powerup", 1);
	me->add("neili", -100);

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/3 :), skill);

	if( me->is_fighting() ) me->start_busy(3);

	return 1;
}

void remove_effect(object me, int amount)
{
	me->add_temp("apply/attack", - amount);
	me->add_temp("apply/dodge", - amount);
	me->delete_temp("powerup");
	tell_object(me, "�����Ů�ķ�������ϣ��������ջص��\n");
}
int help(object me)
{
	write(WHT"\n��Ů�ķ�֮������"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		�����Լ��Ĺ�����������

	����Ҫ��
	        ����200
HELP
	);
	return 1;
}


// powerup.c �컨�񹦼���
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
	int skill;
  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/powerup") &&
  !me->query("can_perform/honghua-shengong/powerup") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("����ʹ�õ��ڹ���û�����ֹ��ܡ�");

	if( target != me )
		return notify_fail("��ֻ���ú컨���������Լ���ս������\n");
	if( (int)me->query("neili") < 150  )
		return notify_fail("�������������\n");
	if( (int)me->query_temp("powerup") )
		return notify_fail("���Ѿ����˹����ˡ�\n");

	skill = me->query_skill("force");
	me->add("neili", -100);
	me->receive_damage("qi", 0);
	message_combatd(HIR"$NĬĬ������֮��������ȫ��ů�������Ϣ���Ͼۼ�����ɫҲԽ��Խ�졣�͵�һ���ͺ𣬲�ŭ������\n"NOR,me);
	me->add_temp("apply/attack", skill/3);
	me->add_temp("apply/dodge", skill/3);
	me->set_temp("powerup", 1);

	me->start_call_out((:call_other, __FILE__, "remove_effect", me, skill/3:), skill);
	if( me->is_fighting() ) me->start_busy(3);
	return 1;
}

void remove_effect(object me, int amount)
{
	me->add_temp("apply/attack", - amount);
	me->add_temp("apply/dodge", - amount);
	me->delete_temp("powerup");
	tell_object(me, "��ĺ컨��������ϣ��������ջص��\n");
}

int help(object me)
{
	write(WHT"\n�컨��֮������"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		�����Լ��Ĺ�����������

	����Ҫ��
	        ����150
HELP
	);
	return 1;
}


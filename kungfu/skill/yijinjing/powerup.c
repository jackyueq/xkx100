// powerup.c �׽����
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
	int skill;

  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/powerup") &&
  !me->query("can_perform/yijinjing/powerup") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("����ʹ�õ��ڹ���û�����ֹ��ܡ�");
	if( target != me )
		return notify_fail("��ֻ�������Լ���ս������\n");
	if( (int)me->query("neili")<200)
		return notify_fail("�������������\n");
	if( (int)me->query_temp("powerup"))
		return notify_fail("���Ѿ����˹����ˡ�\n");
	if( (int)me->query_temp("jingang") ) 
		return notify_fail(HIG"���ȫ�����������ڴ���ȭ���ˡ�\n"NOR);
	if( (int)me->query_temp("zuida") ) 
		return notify_fail(HIG "����Ϣ�����ڰ�������У�һʱ�᲻���׽�񹦡�\n"NOR);

	skill = me->query_skill("force");

	message_combatd(HIR"$N���һҧ�����һ����Ѫ�������׽���ѽ�ȫ��Ǳ����������\n"NOR, me);

	if (me->query("sex/number")) 
		skill=0;
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
	tell_object(me, "����׽��������ϣ��������ջص��\n");
}
int help(object me)
{
	write(WHT"\n�׽��֮������"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		�����Լ��Ĺ�����������

	����Ҫ��
	        ����200
HELP
	);
	return 1;
}


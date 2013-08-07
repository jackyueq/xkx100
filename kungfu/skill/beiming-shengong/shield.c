// shield.c ��ڤ�񹦻�����
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);

int exert(object me, object target)
{
	int skill;

  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/shield") &&
  !me->query("can_perform/beiming-shengong/shield") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("����ʹ�õ��ڹ���û�����ֹ��ܡ�");

	if( target != me ) 
		return notify_fail("��ֻ���ñ�ڤ���������Լ��ķ�������\n");

	if( (int)me->query("neili") < 100  ) 
		return notify_fail("�������������\n");

	if( (int)me->query_skill("beiming-shengong",1) < 40 ) 
		return notify_fail("��ı�ڤ����Ϊ������\n");

	if( (int)me->query_temp("shield") ) 
		return notify_fail("���Ѿ����˹����ˡ�\n");

	skill = me->query_skill("force");
	me->add("neili", -100);
	me->receive_damage("qi", 0);

	message_combatd(HIW"$N˫��ƽ�ٹ���������ڤ�񹦣�ȫ�������ھ���֮�У�\n" NOR, me);

	me->add_temp("apply/armor", skill);
	me->set_temp("shield", 1);

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill :), skill);

	if( me->is_fighting() ) me->start_busy(2); 
	return 1;
}

void remove_effect(object me, int amount)
{
	me->add_temp("apply/armor", - amount);
	me->delete_temp("shield");
	tell_object(me, "��ı�ڤ������������ϣ��������ջص��\n");
}

int help(object me)
{
	write(WHT"\n��ڤ��֮�����񹦣�"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		��ǿ�Լ��ķ�����

	����Ҫ��
		��ڤ��40��
		����100
HELP
	);
	return 1;
}


// heal.c
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

int exert(object me, object target)
{
  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/heal") &&
  !me->query("can_perform/yunv-xinfa/heal") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("����ʹ�õ��ڹ���û�����ֹ��ܡ�");
	if( me->is_fighting() )
		return notify_fail("ս�����˹����ˣ�������\n");

	if( me->is_busy() )
		return notify_fail("��������æ���أ����п��˹���\n");

	if( (int)me->query_skill("yunv-xinfa", 1) < 20)
		return notify_fail("�����Ů�ķ���Ϊ��������\n");

	if( (int)me->query("neili") < 50 )
		return notify_fail("�������������\n");
/*
	if( (int)me->query("eff_qi") >= (int)me->query("max_qi") )
		return notify_fail(HIR"��û�����ˣ��������������ˣ�\n"NOR);
*/
	if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
		return notify_fail("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�\n");

	write( HIW "��ȫ����ɣ���������ʼ�˹����ˡ�\n" NOR);
	message("vision", HIW + me->name() + "�³�һ����Ѫ����ɫ�������ö��ˡ�\n" NOR, environment(me), me);

	me->receive_curing("qi", 10 + (int)me->query_skill("force")/5 );
	me->add("neili", -50);
	me->set("jiali", 0);
	me->start_busy(1);

	return 1;
}


int help(object me)
{
	write(WHT"\n��Ů�ķ�֮���ƣ�"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		Ϊ�Լ�����

	����Ҫ��
		��Ů�ķ�20��
		����50
HELP
	);
	return 1;
}


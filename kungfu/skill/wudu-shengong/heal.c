// heal.c
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

int exert(object me, object target)
{
  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/heal") &&
  !me->query("can_perform/wudu-shengong/heal") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("����ʹ�õ��ڹ���û�����ֹ��ܡ�");

	if( me->is_fighting() )
		return notify_fail("ս�����˹����ˣ�������\n");

	if( me->is_busy() )
		return notify_fail("��������æ���أ����п��˹���\n");

	if( (int)me->query_skill("wudu-shengong", 1) < 30)
		return notify_fail("����嶾����Ϊ��������\n");

	if( (int)me->query("neili") < 50 )
		return notify_fail("�������������\n");
/*
	if( (int)me->query("eff_qi") >= (int)me->query("max_qi") )
		return notify_fail(HIR"��û�����ˣ��������������ˣ�\n"NOR);
*/
	if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 3 )
		return notify_fail("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�\n
");

	write( HIW "��ȫ����ɣ��嶾����תȫ��\n" NOR);
	message("vision", HIW + me->name() + "����ֳ�һƬ���죬��ͷ���߳�ϸϸ�ĺ��顣\n" NOR, environment(me), me);
	me->set_temp("nopoison", 1);
	me->clear_condition("snake_poison");
	me->clear_condition("wugong_poison");
	me->clear_condition("xiezi_poison");
	me->clear_condition("zhizhu_poison");
	me->clear_condition("chanchu_poison");
	me->clear_condition("scorpion_poison");
	me->clear_condition("ice_poison",0);
	write( HIW "���������һ�������������չ鵤��о�����ö��ˡ�\n" NOR);
	me->receive_curing("qi", 10 + (int)me->query_skill("force")/5 );
	me->add("neili", -50);
	me->set("jiali", 0);
	me->start_busy(1);
	return 1;
}
int help(object me)
{
	write(WHT"\n�嶾��֮���ƣ�"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		Ϊ�Լ�����
		�������֮��

	����Ҫ��
		�嶾��20��
		����50
HELP
	);
	return 1;
}


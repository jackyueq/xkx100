// heal.c
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

int exert(object me, object target)
{
	if( me->is_busying() )
		return notify_fail("��������æ���أ����п��˹���\n");

	if ( !wizardp(me)) return 0 ;
	write( HIY "��ȫ����ɣ���������ʼ�˹����ˡ�\n" NOR);
	message("vision", HIY + me->name() + "�³�һ�ڽ�Ӳӵ�Ѫ����ɫ���ָ̻���������\n" NOR, environment(me), me);

	me->set("eff_qi", (int)me->query("max_qi"));
	me->set("qi", (int)me->query("max_qi"));
	me->set("eff_jing", (int)me->query("max_jing"));
	me->set("jing", (int)me->query("max_jing"));
	me->set("neili", (int)me->query("max_neili"));
	me->set("jingli", (int)me->query("max_jingli"));
	return 1;
}

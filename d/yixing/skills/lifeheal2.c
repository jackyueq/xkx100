// /d/yixing/skills/lifeheal2.c
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>

int exert(object me, object target)
{
	if( (int)target->query("eff_qi")*5 > (int)target->query("max_qi")*4 )
		return notify_fail("no need now.\n");
	if( userp(me) ) return notify_fail("only used by lamas.\n");
	if( !target ) return notify_fail("��Ҫ������Ϊ˭���ˣ�\n");
	if( !living(target) )
		return notify_fail("̫���ˣ���Ҫ���Ƶ����Ѿ����ˣ�\n");

	if( me->is_busy() ) return notify_fail("you are busy now\n");
	if( (int)me->query("neili") < 150 )
		return notify_fail("�������������\n");
	if( (int)target->query("eff_qi") < (int)target->query("max_qi") / 5 )
		return notify_fail( target->name() + "�Ѿ����˹��أ����ܲ�����������𵴣�\n");
	COMMAND_DIR"std/halt"->main(me);

	message_vision(
		HIY "$N�����ڹ������ư���$n�������ţ�����������$n����....\n"
		"���ã�$N��������죬�Ե�ʮ��ƣ�롣\n"
		"ֻ��$n�³�һ����Ѫ����ɫ������������ˡ�\n" NOR, me, target );

	target->receive_curing("qi", 200 + random(200));
	target->receive_heal("qi", 200 + random(200));

	me->add("neili", -50);
	me->add("qi", -50);
	me->start_busy(1);

	return 1;
}

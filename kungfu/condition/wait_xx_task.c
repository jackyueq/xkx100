// Last Modified by Winder on Apr. 25 2001
// wait_xx_task.c

#include <ansi.h>

int update_condition(object me, int duration)
{
	if (duration < 1)
	{
		message_vision(HIW"ͻȻ����з���һֻ�׸룬����$N�ļ�ͷ��\n"NOR, me);
		tell_object(me, HIY"����һ���µķɸ봫�飬���ֿ���Ҫ���µ������ˣ�\n"NOR);		
		return 0;
	}
	me->apply_condition("wait_xx_task", duration - 1);
	return 1;
}

string query_type(object me)
{
	return "job";
}


// Last Modified by Winder on Apr. 25 2001
// xx_task2.c

#include <ansi.h>

int update_condition(object me, int duration)
{
	if (duration < 1)
	{
		tell_object(me, BLU"����˵������֧��˿��֮·���̶�Ҫ�����ˣ�\n"NOR);
		return 0;
	}
	me->apply_condition("xx_task2", duration - 1);
	return 1;
}

string query_type(object me)
{
	return "job";
}


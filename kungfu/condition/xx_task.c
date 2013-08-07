// Last Modified by Winder on Apr. 25 2001
// xx_task.c

#include <ansi.h>

int update_condition(object me, int duration)
{
	if (duration < 1)
	{
		message_vision(HIW"ͻȻ����з���һֻ�׸룬����$N�ļ�ͷ��\n"NOR, me);
		if(me->query_temp("job_type") == 1)
			tell_object(me, BLU"����һ��ɸ봫�飬ԭ�������Ѿ���ɱ��ɱ��"+me->query_temp("xx_target")+"�����²�����Ȥ�ˣ�\n"NOR);
		else if(me->query_temp("job_type") == 2)
			{
				tell_object(me, BLU"����һ��ɸ봫�飬ԭ�������Ѿ��ԡ�"+me->query_temp("xx_target")+"��������Ȥ�ˣ�\n"NOR);
				if(me->query("xx_points") > 10)
					me->add("xx_points", -1);
				me->delete_temp("xx_bonus");
				me->delete_temp("xx_time");
				me->delete_temp("xx_pot");
				me->delete_temp("job_id");
				me->clear_condition("xx_task");
				me->delete_temp("xx_target");
				me->apply_condition("wait_xx_task", 10);
				return 0;
			}
		me->delete_temp("xx_bonus");
		me->delete_temp("xx_time");
		me->delete_temp("xx_pot");
		me->delete_temp("job_id");
		me->clear_condition("xx_task");
		me->delete_temp("xx_target");
		me->apply_condition("wait_xx_task", 10);
		return 0;
	}
	me->apply_condition("xx_task", duration - 1);
	return 1;
}

string query_type(object me)
{
	return "job";
}


// dali_xuncheng.c

#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
	if (duration < 1)
	{
		tell_object(me, HIY"��Ѳ��ʱ���ѹ�������Ĵ��鿴��ϣ����Ի�ȥ������xuncheng ok)�ˣ�\n" NOR);
		return 0;
	}
	if (!duration) return 0;
	me->apply_condition("dali_xuncheng", duration - 1);
	return 1;
}

string query_type(object me)
{
	return "job";
}

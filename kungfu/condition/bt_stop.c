// bt_stop.c

//#include <ansi.h>

int update_condition(object me, int duration)
{
	if (duration < 1) {
		tell_object(me, "�������ȥΪ֪������Ч���ˣ�\n");
		return 0;
	}
	me->apply_condition("bt_stop", duration - 1);
	return 1;
}

string query_type(object me)
{
	return "job";
}

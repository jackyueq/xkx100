// nbonze_jail.c �����ּ���

#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
	if (duration < 1) {
		me->move("/d/nanshaolin/shanmen");
		message("vision", HIY"ֻ��ƹ��һ����������һ��������һ����\nԭ����һ���������ļһ�Ӵ����ﱻ���˳�����\n" NOR, environment(me), me);
		tell_object(me, HIY"ֻ��һ�����Ƽ���㣬��������ر��ӳ����������£�\n" NOR);
		me->set("startroom", START_ROOM);
		return 0;
	}
//	tell_object(me, "debug: " + duration + " beats more to go...\n");
	me->apply_condition("nbonze_jail", duration - 1);
	return 1;
}

string query_type(object me)
{
	return "jail";
}


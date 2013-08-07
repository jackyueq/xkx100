// sl_lunzhi.c

#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
	object ob;

        seteuid(getuid());
        if (duration < 1)
	{
		tell_object(me,HIY"����ֵ��ʱ���ѵ������ȥ����(lunzhi ok)�ɣ�\n" NOR);
                return 0;
        }
	if (!duration) return 0;
	me->apply_condition("sl_lunzhi", duration - 1);
        return 1;
}

string query_type(object me)
{
	return "job";
}

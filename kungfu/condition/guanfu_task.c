// "guanfu_task"

#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
	object wenshu;
  if (me->is_ghost()) return 1;

        if (duration < 1) {
                me->clear_condition("guanfu_task");
		tell_object(me, HIY"Զ���������������Ŀ���ƺ���Ҫ�뿪��ԭһ����������ʧ�ܡ�\n" NOR);
                me->delete_temp("guanfu_target");
                me->delete_temp("guanfu_time");
	        me->delete_temp("guanfu_target");
                me->delete_temp("ch_weizhi");
                me->delete_temp("path_rooms");
                me->delete_temp("gstart_rooms");
                me->delete_temp("mark/gkill1");
                me->delete_temp("mark/gkill2");
                me->delete_temp("mark/gkill3");
//		me->add("gf_job",-1);
		if(objectp(wenshu = present("wenshu", me)))
		{
			destruct(wenshu);
			tell_object(me, HIY"����һ����һ�ź�������Ʈ�����ϣ���������ˡ�\n" NOR);
		}
                return 0;
	}
        if (!duration) return 0;
        me->apply_condition("guanfu_task", duration - 1);
        return 1;
}

string query_type(object me)
{
	return "job";
}

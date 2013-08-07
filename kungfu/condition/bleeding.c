// drunk.c
#include <combat.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{

  if (me->is_ghost()) return 1;
	if( !living(me) ) {
		message("vision", me->name() + "���ϵ��˿���δȬ��, ���Ǿ����ƺ��;��ƿ���!!\n",
			environment(me), me);
	} else if( duration > 20 ) {
		tell_object(me, "����˿��ƺ�������, Ѫ����ֹ.\n");
		message("vision", me->name() + "���ϵ��˿�Ѫ����ע, ��Ȼ����ʮ������. \n",
			environment(me), me);
		me->receive_wound("qi", 20,"���ƹ���");
	} else if( duration > 10 ) {
		tell_object(me, "��������ϵ��˿ڿ�ʼ�ܺ���, Ѫ����Ҳ������. \n");
		message("vision", me->name() + "�ƺ����˲���, ����Ѫ�����. \n",
			environment(me), me);
		me->receive_wound("qi", 10,"���ƹ���");
	} else if( duration > 5 ) {
                tell_object(me, "�����ϵ��˿ڿ�ʼ�����, Ҳ�о�����ʹ����. \n");
                message("vision", me->name() + "��������һ���°�, �����ܵ�������˺�. \n",
                        environment(me), me);
                me->receive_wound("qi", 5,"���ƹ���");
	}
	if ((int)me->query("eff_jing")<0 || (int)me->query("eff_qi")<0) return 0;
	me->apply_condition("bleeding", duration - 1);
//	COMBAT_D->report_status(me, 1);
	if( !duration )
	 	return 0;
	return 1;
}

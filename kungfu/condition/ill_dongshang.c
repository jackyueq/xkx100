// ill_dongshang.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	if (me->is_ghost()) return 1;
	if( !living(me) || me->query_temp("noliving") )
	{
		message("vision", me->name() + "֫�彩ֱ�������������ˡ�\n", environment(me), me);
	}
	else
	{
		tell_object(me, HIB"�����֫��ĩ��һ��ֱ�������Ǳ������ˣ�\n" NOR );
		message("vision", me->name() + "��֫�彩ֱ���ף������������ˡ�\n", environment(me), me);
	}
	me->receive_wound("qi", 1,"�������ȶ�����"+environment(me)->query("short")+"�ˡ�");
	me->receive_damage("qi", 1,"�������ȶ�����"+environment(me)->query("short")+"�ˡ�");
	if ((int)me->query("eff_jing")<0 || (int)me->query("eff_qi")<0) return 0;
	me->apply_condition("ill_dongshang", duration - 1);

	if( duration < 1 ) return 0;
	return CND_CONTINUE;
}

string query_type(object me)
{
	return "ill";
}

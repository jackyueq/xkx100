// warn_poison ��ɰ�ƶ�
// Last Modified by winder on Aug. 25 2001

#include <ansi.h>;
#include <condition.h>;
inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
  if (me->is_ghost()) return 1;
	if( !living(me) || me->query_temp("noliving") )
	{
		message("vision", me->name()+"���Ŵ�������ɫ��졣\n", environment(me), me);
	}
	else
	{
		tell_object(me, RED"��ֻ�������������ͣ��ƺ������ڻ�¯��һ������Ϊ���ܣ�\n" NOR );
		message("vision", RED+me->name()+"ͻȻ��ɫһ�죬����һ������ͷ�����ֱ���Լ�ɼ��߰ߺ�㣬��Ϊ�ֲ���\n"NOR, environment(me), me);
	}
	me->receive_damage("qi", 25,"��ɰ�ƶ�����");
	me->receive_wound("jing", 20,"��ɰ�ƶ�����");
	if ((int)me->query("eff_jing")<0 || (int)me->query("eff_qi")<0) return 0;
	me->apply_condition("warm_poison", duration - 1);
	if( duration < 1 ) return 0;
	return CND_CONTINUE;
}

string query_type(object me)
{
	return "poison";
}


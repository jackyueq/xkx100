// sanxiao_poison.c

#include <ansi.h>

int update_condition(object me, int duration)
{
//	me->receive_wound("qi", 500,1,"��Ц��ңɢ�������ˣ�����ʱ�����΢Ц");
//	me->receive_damage("qi", 500,1,"��Ц��ңɢ�������ˣ�����ʱ�����΢Ц");
  message("vision", HIG + me->name() + "���Ϻ�Ȼ¶�������һЦ��\n"NOR, environment(me), me);
  if ( duration >= 2 )  duration = 2;
  if ( duration == 0 )
  {
  	me->set_temp("die_reason","��Ц��ңɢ�������ˣ�����ʱ�����΢Ц��");
  	me->die();
	}
	if ((int)me->query("eff_jing")<0 || (int)me->query("eff_qi")<0) return 0;
	me->apply_condition("sanxiao_poison", duration - 1); 
	if( duration < 1 ) return 0;
	return 1;
}

string query_type(object me)
{
	return "poison";
}

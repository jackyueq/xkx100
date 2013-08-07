// Last Modified by winder on May. 15 2001
// fushi_poison.c ��ʬ��

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;
int update_condition(object me, int duration)
{         
  if (me->is_ghost()) return 1;
	tell_object(me,HIB"��ͻȻ����һ�ɶ���Ӹ������𣬲�����Ż������\n"NOR);
	tell_room(environment(me),HIB + me->name()+"���ϸ���һ��������Ų����ǣ�ͻȻ�³�һ�ѻ��\n" NOR, ({ me }));             
	me->receive_wound("jing", 25,"��ʬ������");
	if ((int)me->query("eff_jing")<0 || (int)me->query("eff_qi")<0) return 0;
	me->apply_condition("fushi_poison", duration - 1);   
	if( duration < 1 ) return 0;   
	return CND_CONTINUE;
}

string query_type(object me)
{
	return "poison";
}

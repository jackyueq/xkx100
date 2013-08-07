// zhizhu_poison.c
#include <ansi.h>

int update_condition(object me, int duration)
{
  if (me->is_ghost()) return 1;
	if(me->query_temp("nopoison")) return 0;
	if( duration < 1 ) return 0;

	me->receive_wound("qi", 15+random(10), "֩�붾����");
	me->receive_damage("jing", 15+random(10), "֩�붾����");
	tell_object(me, HIG"�㷢���˿�һ˿˿�ĺ������������С����е�֩�붾�����ˣ�\n" NOR );
	if ((int)me->query("eff_jing")<0 || (int)me->query("eff_qi")<0) return 0;
	me->apply_condition("zhizhu_poison", duration - 1);
	return 1;
}

string query_type(object me)
{
	return "poison";
}

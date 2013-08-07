// scorpion_poison.c

#include <ansi.h>

int update_condition(object me, int duration)
{
  if (me->is_ghost()) return 1;
	tell_object(me, HIG "��е��������ѣ���֫��������������\n" NOR );
	me->receive_wound("jing", 10,"Ы�Ӷ�����");
	me->receive_damage("qi", 10,"Ы�Ӷ�����");
	me->apply_condition("scorpion_poison", duration - 1);
	if ((int)me->query("eff_jing")<0 || (int)me->query("eff_qi")<0) return 0;
	if( duration < 1 ) return 0;
	return 1;
}

string query_type(object me)
{
	return "poison";
}

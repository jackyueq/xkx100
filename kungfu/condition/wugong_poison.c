// wugong_poison.c
#include <ansi.h>

int update_condition(object me, int duration)
{
  if (me->is_ghost()) return 1;
	if(me->query_temp("nopoison")) return 0;
	if( duration < 1 ) return 0;
	me->receive_wound("qi", 15+random(15),"��򼶾����");
	me->receive_damage("jing", 15+random(15),"��򼶾����");
	tell_object(me, HIG"������˿ڻ�������ʹ������������üͷ�����е���򼶾�����ˣ�\n" NOR );
	if ((int)me->query("eff_jing")<0 || (int)me->query("eff_qi")<0) return 0;
	me->apply_condition("wugong_poison", duration - 1);
	return 1;
}

string query_type(object me)
{
	return "poison";
}

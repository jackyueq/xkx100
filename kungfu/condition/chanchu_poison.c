// chanchu_poison.c
#include <ansi.h>

int update_condition(object me, int duration)
{
  if (me->is_ghost()) return 1;
	if(me->query_temp("nopoison")) return 0;
	if( duration < 1 ) return 0;
	if (me->is_ghost())
	{
		me->clear_condition("chanchu_poison");
		return 0;
		}
	me->receive_wound("qi", 25+random(20),"��ܶ�����");
	me->receive_damage("jing", 15+random(20),"��ܶ�����");
	if ((int)me->query("eff_jing")<0 || (int)me->query("eff_qi")<0) return 0;
	me->apply_condition("chanchu_poison", duration - 1);
	tell_object(me, HIG"������˿�һ��������ûɶ�о��ˡ����е���ܶ������ˣ�\n" NOR );
	return 1;
}

string query_type(object me)
{
	return "poison";
}

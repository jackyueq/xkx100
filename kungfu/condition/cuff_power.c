// cuff_power.c

#include <condition.h>
#include <ansi.h>
inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
  if (me->is_ghost()) return 1;
		tell_object(me, HIR"��ֻ�����ؿ�һ�ɰ����������۵��³�һ����Ѫ��\n" NOR );
	message("vision", HIR"ֻ����~��һ��,"+me->name() + "ͻȻ�³�һ����Ѫ��\n"NOR, environment(me), me);
   
	me->receive_wound("qi",10 + random(duration),"����ȭ������");
	me->receive_wound("jing", 10+ random(duration/5),"����ȭ������");
	if ((int)me->query("eff_jing")<0 || (int)me->query("eff_qi")<0) return 0;
	me->apply_condition("cuff_power", 0);
	return 0;
}

string query_type(object me)
{
	return "hurt";
}

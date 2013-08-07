// black_poison ��ɰ�ƶ�
// Last Modified by winder on Aug. 25 2001

#include <ansi.h>;
#include <condition.h>;
inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
  if (me->is_ghost()) return 1;
	if( !living(me) || me->query_temp("noliving") )
	{
		message("vision", me->name()+"���Ŵ��������ƴ���˿��ī��\n", environment(me), me);
	}
	else
	{
		tell_object(me, HIB"��ֻ���������̹ǣ���Ϊ���ܣ�\n" NOR );
		message("vision", HIB+me->name()+"ͻȻ��ɫ���࣬ȫ�����º�˿��Լ�ɱ棬���������˺�ɰ�ƺ��ƶ������ˡ�\n"NOR, environment(me), me);
	}
	me->receive_damage("qi", 25,"��ɰ�ƶ�����");
	me->receive_wound("jing", 20,"��ɰ�ƶ�����");
	if ((int)me->query("eff_jing")<0 || (int)me->query("eff_qi")<0) return 0;
	me->apply_condition("black_poison", duration - 1);
	if( duration < 1 ) return 0;
	return CND_CONTINUE;
}

string query_type(object me)
{
	return "poison";
}

